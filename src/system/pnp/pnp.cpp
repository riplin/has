//Copyright 2025-Present riplin

#include <stdio.h>
#include <has/system/pit.h>
#include <has/system/pnp/pnp.h>
#include <has/testing/log.h>
#include <has/system/keyboard.h>

namespace Has::System::PnP
{

// The code is generated as follows:

// uint8_t code = 0x6A;
// uint8_t msb = 0;
// write(0x00);
// write(0x00);
// write(code);
// for (uint8_t i = 1; i < 32; i++)
// {
//     msb = ((code & 0x01) ^ ((code & 0x02) >> 1)) << 7;
//     code = (code >> 1) | msb;
//     write(code);
// }

static uint8_t s_PnPKey[66] =
{
    0x00, 0x00,
    0x6A, 0xB5, 0xDA, 0xED, 0xF6, 0xFB, 0x7D, 0xBE, 0xDF, 0x6F, 0x37, 0x1B, 0x0D, 0x86, 0xC3, 0x61,
    0xB0, 0x58, 0x2C, 0x16, 0x8B, 0x45, 0xA2, 0xD1, 0xE8, 0x74, 0x3A, 0x9D, 0xCE, 0xE7, 0x73, 0x39
};

static bool s_Initialized = false;
static CardSelectNumber_t s_MaxCsn = 0;
extern Register_t s_ReadPort; //Defined in data.cpp

void SendKey()
{
    SYS_ClearInterrupts();
    for (uint8_t key = 0; key < (sizeof(s_PnPKey) / sizeof(*s_PnPKey)); ++key)
        Address::Write(s_PnPKey[key]);
    SYS_RestoreInterrupts();
}

static bool FindDeviceInternal(Register_t readPort, VendorId_t& vendorId, CardSelectNumber_t& csn)
{
    uint32_t tmpVendor = 0;

    for(csn = 1; csn <= 10; csn++)
    {
        WakeCsn::Write(csn);
        ResourceData::Read<uint32_t>(readPort, tmpVendor);

        if ((tmpVendor & VendorId::Vendor) == vendorId)
        {
            Config::Write(Config::WaitForKey);
            s_ReadPort = readPort;
            return true;
        }
    }
    return false;
}

bool FindDevice(VendorId_t& vendorId, CardSelectNumber_t& csn)
{
    vendorId &= VendorId::Vendor;

    SendKey();
    SendKey(); // Send the key twice to make sure it was received.
    if (s_ReadPort != Register::ReadInvalid)
    {
        return FindDeviceInternal(s_ReadPort, vendorId, csn);
    }
    else
    {
        for (Register_t readPort = Register::ReadMin; readPort <= Register::ReadMax; readPort += 4)
        {
            if (FindDeviceInternal(readPort, vendorId, csn))
            {
                s_ReadPort = readPort;
                return true;
            }
        }
    }

    return false;
}

static void Delay(uint16_t microseconds)
{
    using namespace Has::System;
    using namespace Has::System;

    uint32_t count = microseconds * 1193;
    count /= 1000;
    uint16_t lastCount = count;
    KB::PortB_t portB = KB::PortBStatus::Read() & ~(KB::PortBCommand::Timer2GateSpeakerEnable | KB::PortBCommand::SpeakerEnable);
    KB::PortBCommand::Write(portB);
    PIT::Command::Write(PIT::Command::SelectChannel2 | PIT::Command::LowByteHighByte);
    PIT::Data::WriteChannel2(uint8_t(count));
    PIT::Data::WriteChannel2(uint8_t(count >> 8));

    KB::PortBCommand::Write(portB | KB::PortBCommand::Timer2GateSpeakerEnable);

    uint16_t currentCount = 0;
    while(currentCount <= count)
    {
        PIT::Command::Write(PIT::Command::SelectChannel2);

        uint8_t tmp = PIT::Data::ReadChannel2();
        currentCount = (uint16_t(PIT::Data::ReadChannel2()) << 8) | tmp;

        if (currentCount > lastCount)
            break;

        lastCount = currentCount;
    }					 

    KB::PortBCommand::Write(portB);
 }

static bool IsolateCards(bool printOutput, CardSelectNumber_t& csn, Register_t& readPort)
{
    csn = 0;
    SendKey();
    SendKey(); // Send the key twice to make sure it was received.

    WakeCsn::Write(0);//Wake up all cards.
    readPort = Register::ReadMin; //Assume default.
    ReadDataPort::Write(uint8_t(readPort >> 2));
    Address::Write(Register::SerialIsolation);
    Delay(250);

    uint8_t iteration = 1;
    if (printOutput) printf("[PnP] Searching port space. This may take some time.");
    while(true)
    {
        LOG("PnP", "Testing read port 0x%03X", readPort);
        if (printOutput) printf(".");

        uint8_t checksum = 0x6A;
        for (uint16_t i = 0; i < 64; ++i)
        {
            uint16_t data = uint16_t(SerialIsolation::ReadDirect(readPort)) << 8;
            data |= SerialIsolation::ReadDirect(readPort);
            //Delay(250);

            uint8_t bit = (data == 0x55AA) ? 0x01 : 0x00;
            checksum = ((((checksum ^ (checksum >> 1)) & 0x01) ^ bit) << 7) | (checksum >> 1);
        }

        uint8_t chksum = 0x00;
        for (uint16_t i = 0; i < 8; ++i)
        {
            uint16_t data = uint16_t(SerialIsolation::ReadDirect(readPort)) << 8;
            //Delay(250);
            data |= SerialIsolation::ReadDirect(readPort);
            //Delay(250);
            if (data == 0x55AA)
                chksum |= 1 << i;
        }

        LOG("PnP", "readport = 0x%02X, checksum = 0x%02X, chksum = 0x%02X", readPort, checksum, chksum);

        if ((checksum != 0x00) && (checksum == chksum))
        {
            ++csn;
            CardSelectNumber::Write(csn);
            ++iteration;
            WakeCsn::Write(0);//Wake up all cards.
            Address::Write(Register::SerialIsolation);
        }

        if (((checksum == 0x00) || (chksum != checksum)) && (iteration == 1))
        {
            if (readPort > Register::ReadMax)
            {
                csn = 0;
                readPort = Register::ReadInvalid;
                if (printOutput) printf("\n");
                return false;
            }

            readPort += 4;
            WakeCsn::Write(0);//Wake up all cards.
            ReadDataPort::Write(uint8_t(readPort >> 2));
            Address::Write(Register::SerialIsolation);
        }

        if(((checksum == 0x00) || (chksum != checksum)) && (iteration > 1))  
            break;
    }
    if (printOutput) printf("\n");

    return true;
}

InitializeError_t Initialize(bool printOutput)
{
    if (!s_Initialized)
    {
        LOG("PnP", "Attempting to isolate cards");

        if (!IsolateCards(printOutput, s_MaxCsn, s_ReadPort))
        {
            LOG("PnP", "No PnP cards found");
            return InitializeError::NoCardsFound;
        }

        LOG("PnP", "Found %i cards at read port 0x%03X", s_MaxCsn, s_ReadPort);
        return InitializeError::Success;
    }
    return InitializeError::AlreadyInitialized;
}

void Shutdown()
{
    if (s_Initialized)
    {


        LOG("PnP", "Shut down");
        s_Initialized = false;
    }
}

}