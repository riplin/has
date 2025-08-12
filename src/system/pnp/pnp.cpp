//Copyright 2025-Present riplin

#include <vector>
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
static std::vector<const Resource::Card*> s_Cards;

void SendKey()
{
    SYS_ClearInterrupts();
    for (uint8_t key = 0; key < (sizeof(s_PnPKey) / sizeof(*s_PnPKey)); ++key)
        Address::Write(s_PnPKey[key]);
    SYS_RestoreInterrupts();
}

bool FindDevice(VendorId_t& vendorId, CardSelectNumber_t& csn)
{
    vendorId &= VendorId::Vendor;

    for (const Resource::Card* card : s_Cards)
    {
        if ((card->VendorId & VendorId::Vendor) == vendorId)
        {
            vendorId = card->VendorId;
            csn = card->CardSelectNumber;
            return true;
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

// 3.3.2. Software Protocol

// The Plug and Play software sends the initiation key to all Plug and Play cards to place them into
// configuration mode. The software is then ready to perform the isolation protocol.

// The Plug and Play software generates 72 pairs of I/O read cycles from the READ_DATA port. The
// software checks the data returned from each pair of I/O reads for the 0x55 and 0xAA driven by the
// hardware. If both 0x55 and 0xAA are read back, then the software assumes that the hardware had a “1”
// bit in that position. All other results are assumed to be a “0.”

// During the first 64 bits, software generates a checksum using the received data. The checksum is compared
// with the checksum read back in the last 8 bits of the sequence.

// There are two other special considerations for the software protocol. During an iteration, it is possible that
// the 0x55 and 0xAA combination is never detected. It is also possible that the checksum does not match. If
// either of these cases occur on the first iteration, it must be assumed that the READ_DATA port is in
// conflict. If a conflict is detected, then the READ_DATA port is relocated. The above process is repeated
// until a non-conflicting location for the READ_DATA port is found. The entire range between 0x200 and
// 0x3FF is available, however in practice it is expected that only a few locations will be tried before software
// determines that no Plug and Play cards are present.

// During subsequent iterations, the occurrence of either of these two special cases should be interpreted as the
// absence of any further Plug and Play cards (i.e. the last card was found in the previous iteration). This
// terminates the isolation protocol.

// NOTE:   The software must delay 1 msec prior to starting the first pair of isolation reads,
//         and must wait 250 µsec between each subsequent pair of isolation reads. This
//         delay gives the ISA card time to access information from possibly very slow
//         storage devices.

// Further down state machine description:

// Isolation - In this state, Plug and Play cards respond to reads of the Serial Isolation register as described
// in the previous chapter on isolation protocol. Once a card is isolated, a unique CSN is assigned. This
// number will later be used by the Wake[CSN] command to select the card. Once the CSN is written,
// the card transitions to the Config state.

static bool IsolateCards(CardSelectNumber_t& csn, Register_t& readPort)
{
    csn = 0;
    SendKey();
    SendKey(); // Send the key twice to make sure it was received.

    WakeCsn::Write(0);//Wake up all cards.
    readPort = Register::ReadMin; //Assume default.
    ReadDataPort::Write(uint8_t(readPort >> 2));
    Address::Write(Register::SerialIsolation);
    Delay(1000);

    uint8_t iteration = 1;

    while(true)
    {
        LOG("PnP", "Testing read port 0x%03X", readPort);

        uint8_t checksum = 0x6A;
        for (uint16_t i = 0; i < 64; ++i)
        {
            uint16_t data = uint16_t(SerialIsolation::ReadDirect(readPort)) << 8;
            data |= SerialIsolation::ReadDirect(readPort);
            Delay(251);
            LOG("PnP", "read port: 0x%03X, data: 0x%04X", readPort, data);

            uint8_t bit = (data == 0x55AA) ? 0x01 : 0x00;
            checksum = ((((checksum ^ (checksum >> 1)) & 0x01) ^ bit) << 7) | (checksum >> 1);
        }

        uint8_t chksum = 0x00;
        for (uint16_t i = 0; i < 8; ++i)
        {
            uint16_t data = uint16_t(SerialIsolation::ReadDirect(readPort)) << 8;
            data |= SerialIsolation::ReadDirect(readPort);
            Delay(251);
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

    return true;
}

static bool DetectCardsInternal(Has::IAllocator& allocator, Register_t readPort, CardSelectNumber_t& maxCardSelectNumber)
{
    bool found = false;
    for (PnP::CardSelectNumber_t csn = 1; csn < 10; ++csn)
    {
        const PnP::Resource::Card* card = PnP::Resource::ParseCard(allocator, readPort, csn);
        if (card != nullptr)
        {
            found = true;
            s_Cards.push_back(card);
            maxCardSelectNumber = csn;
        }
    }
    return found;
}

static bool DetectCards(Has::IAllocator& allocator, Register_t& readPort, CardSelectNumber_t& maxCardSelectNumber)
{
    PnP::SendKey();
    bool found = false;
    for (PnP::Register_t port = PnP::Register::ReadMin; port < PnP::Register::ReadMax; port += 4)
    {
        found = DetectCardsInternal(allocator, port, maxCardSelectNumber);
        if (found)
        {
            readPort = port;
            break;
        }
    }
    return found;
}

bool FindLogicalDevice(const Resource::Card* card, uint32_t& currentIndex)
{
    uint32_t idx = currentIndex + 1;

    while (idx < card->Tags.size())
    {
        if (card->Tags[idx]->Item == Resource::Item::Small::LogicalDeviceId)
        {
            currentIndex = idx;
            return true;
        }
        if (card->Tags[idx]->Item == Resource::Item::Small::End)
        {
            return false;
        }
        ++idx;
    }
    return false;
}

bool FindResource(const Resource::Card* card, uint32_t& currentIndex)
{
    uint32_t idx = currentIndex + 1;
    while (idx <card->Tags.size())
    {
        if ((card->Tags[idx]->Item == Resource::Item::Small::StartDependentFunction) ||
            (card->Tags[idx]->Item == Resource::Item::Small::EndDependentFunction) ||
            (card->Tags[idx]->Item == Resource::Item::Small::End))
        {
            return false;
        }

        if ((card->Tags[idx]->Item == Resource::Item::Small::DmaFormat) ||
            (card->Tags[idx]->Item == Resource::Item::Small::FixedLocationIoPortDescriptor) ||
            (card->Tags[idx]->Item == Resource::Item::Small::InterruptFormat) ||
            (card->Tags[idx]->Item == Resource::Item::Small::IoPortDescriptor) ||
            (card->Tags[idx]->Item == Resource::Item::Large::FixedLocationMemoryRangeDescriptor32Bit) ||
            (card->Tags[idx]->Item == Resource::Item::Large::MemoryRangeDescriptor32Bit) ||
            (card->Tags[idx]->Item == Resource::Item::Large::MemoryRangeDescriptor))
        {
            currentIndex = idx;
            return true;
        }

        ++idx;
    }
    return false;
}

bool FindDependentFunction(const Resource::Card* card, uint32_t& currentIndex)
{
    uint32_t idx = currentIndex + 1;
    while (idx <card->Tags.size())
    {
        if (card->Tags[idx]->Item == Resource::Item::Small::StartDependentFunction)
        {
            currentIndex = idx;
            return true;
        }

        if ((card->Tags[idx]->Item == Resource::Item::Small::EndDependentFunction) ||
            (card->Tags[idx]->Item == Resource::Item::Small::End))
        {
            return false;
        }
        ++idx;
    }
    return false;
}

bool CheckResourceAvailability(const Resource::Card* card, uint32_t tagIndex)
{
    switch (card->Tags[tagIndex]->Item)
    {
    case Resource::Item::Small::DmaFormat:
    {
        const Resource::DmaFormat* dmaFormat = (const Resource::DmaFormat*)card->Tags[tagIndex];
        if (!Resources::Dma::IsAvailable(dmaFormat->Mask))
        {
            LOG("PnP", "No DMA channels available");
            return false;
        }
        break;
    }
    case Resource::Item::Small::FixedLocationIoPortDescriptor:
    {
        const Resource::FixedLocationIoPortDescriptor* fixedIoPort = (const Resource::FixedLocationIoPortDescriptor*)card->Tags[tagIndex];
        if (!Resources::Io::IsAvailable(fixedIoPort->BaseAddress, fixedIoPort->Range))
        {
            LOG("PnP", "Fixed IO range not available");
            return false;
        }
        break;
    }
    case Resource::Item::Small::InterruptFormat:
    {
        const Resource::InterruptFormat* interruptFormat = (const Resource::InterruptFormat*)card->Tags[tagIndex];
        if (!Resources::Interrupt::IsAvailable(interruptFormat->Mask))
        {
            LOG("PnP", "No interruptd available");
            return false;
        }
        break;
    }
    case Resource::Item::Small::IoPortDescriptor:
    {
        const Resource::IoPortDescriptor* ioPortDescriptor = (const Resource::IoPortDescriptor*)card->Tags[tagIndex];
        bool assigned = false;
        for (Resources::Io_t baseAddress = ioPortDescriptor->RangeMinimumAddress;
                baseAddress <= ioPortDescriptor->RangeMaximumAddress;
                baseAddress += ioPortDescriptor->Alignment)
        {
            if (Resources::Io::IsAvailable(baseAddress, ioPortDescriptor->Range))
            {
                assigned = true;
                break;
            }
        }
        if (!assigned)
        {
            LOG("PnP", "IO range not available");
            return false;
        }
        break;
    }
    case Resource::Item::Large::FixedLocationMemoryRangeDescriptor32Bit:
    case Resource::Item::Large::MemoryRangeDescriptor32Bit:
    case Resource::Item::Large::MemoryRangeDescriptor:
        LOG("PnP", "Memory mapping not implemented!");
        return false;
        break;
    default:
        LOG("PnP", "Unknown resource...");
        return false;
        break;
    }
    return true;
}

bool AllocateDeviceResources(const Resource::Card* card, uint32_t tagIndex, bool rangeCheckSupported)
{
    bool assigned = true;
    uint32_t checkIndex = tagIndex;
    while (FindResource(card, checkIndex))
    {
        LOG("PnP", "Checking resource availability 0x%02X", card->Tags[checkIndex]->Item);
        assigned &= CheckResourceAvailability(card, checkIndex);
    }

    if (assigned)
    {
        uint32_t ioIndex = tagIndex;
        Address_t ioPortRegister = Register::Port0High;//Index for io port register
        while (FindResource(card, ioIndex) && assigned)
        {
            LOG("PnP", "Allocating io port range 0x%02X", card->Tags[ioIndex]->Item);

            switch(card->Tags[ioIndex]->Item)
            {
            case Resource::Item::Small::FixedLocationIoPortDescriptor:
            {
                const Resource::FixedLocationIoPortDescriptor* fixedIoDescriptor = (const Resource::FixedLocationIoPortDescriptor*)card->Tags[ioIndex];
                if (Resources::Io::Allocate(fixedIoDescriptor->BaseAddress, fixedIoDescriptor->Range))
                {
                    Data::Write(ioPortRegister, Data_t(fixedIoDescriptor->BaseAddress >> 8));
                    Data::Write(ioPortRegister + 1, Data_t(fixedIoDescriptor->BaseAddress));
                    ioPortRegister += 2;
                    LOG("PnP", "Allocated port range 0x%03X:%i", fixedIoDescriptor->BaseAddress, fixedIoDescriptor->Range);
                }
                else
                {
                    Data::Write(ioPortRegister, 0);
                    Data::Write(ioPortRegister + 1, 0);
                    assigned = false;
                }
                break;
            }
            case Resource::Item::Small::IoPortDescriptor:
            {
                const Resource::IoPortDescriptor* ioPortDescriptor = (const Resource::IoPortDescriptor*)card->Tags[ioIndex];
                assigned = false;
                for (Resources::Io_t baseAddress = ioPortDescriptor->RangeMinimumAddress;
                        baseAddress <= ioPortDescriptor->RangeMaximumAddress;
                        baseAddress += ioPortDescriptor->Alignment)
                {
                    if (Resources::Io::Allocate(baseAddress, ioPortDescriptor->Range))
                    {
                        Data::Write(ioPortRegister, Data_t(baseAddress >> 8));
                        Data::Write(ioPortRegister + 1, Data_t(baseAddress));
                        assigned = !rangeCheckSupported || RangeCheck::RangeCheck(baseAddress, ioPortDescriptor->Range);

                        if (!assigned)
                        {
                            Data::Write(ioPortRegister, 0);
                            Data::Write(ioPortRegister + 1, 0);
                        }
                        else
                        {
                            LOG("PnP", "Allocated port range 0x%03X:%i", baseAddress, ioPortDescriptor->Range);
                            ioPortRegister += 2;
                            break;
                        }
                    }
                }
                break;
            }
            default:
                continue;
            }
        }

        if (assigned)
        {
            uint32_t remainingIndex = tagIndex;
            Address_t interruptRegister = Register::Interrupt0;
            Address_t dmaRegister = Register::DmaChannel0; 
            while (FindResource(card, remainingIndex))
            {
                LOG("PnP", "Allocating remaining resources 0x%02X", card->Tags[remainingIndex]->Item);
                switch(card->Tags[remainingIndex]->Item)
                {
                case Resource::Item::Small::DmaFormat:
                {
                    const Resource::DmaFormat* dmaFormat = (const Resource::DmaFormat*)card->Tags[tagIndex];
                    Resources::Dma_t dma = Resources::Dma::Allocate(dmaFormat->Mask);
                    Data::Write(dmaRegister, dma);
                    ++dmaRegister;
                    LOG("PnP", "Allocated DMA channel %i", dma);
                    break;
                }
                case Resource::Item::Small::InterruptFormat:
                {
                    const Resource::InterruptFormat* interruptFormat = (const Resource::InterruptFormat*)card->Tags[tagIndex];
                    Resources::Interrupt_t interrupt = Resources::Interrupt::Allocate(interruptFormat->Mask);
                    Data::Write(interruptRegister, interrupt);
                    interruptRegister += 2;
                    LOG("PnP", "Allocated Interrupt %i", interrupt);
                    break;
                }
                case Resource::Item::Large::FixedLocationMemoryRangeDescriptor32Bit:
                case Resource::Item::Large::MemoryRangeDescriptor32Bit:
                case Resource::Item::Large::MemoryRangeDescriptor:
                    LOG("PnP", "Memory mapping not implemented!");
                    return false;
                    break;
                default:
                    LOG("PnP", "Unknown resource...");
                    return false;
                    break;
                }
            }
        }
        else
        {
            //Deallocate the allocated port ranges before we failed.
            uint32_t deallocateIndex = tagIndex;
            ioPortRegister = Register::Port0High;//Index for io port register
            while (FindResource(card, deallocateIndex) && (deallocateIndex < ioIndex))
            {
                switch(card->Tags[deallocateIndex]->Item)
                {
                case Resource::Item::Small::FixedLocationIoPortDescriptor:
                {
                    const Resource::FixedLocationIoPortDescriptor* fixedIoDescriptor = (const Resource::FixedLocationIoPortDescriptor*)card->Tags[ioIndex];
                    uint16_t port = (uint16_t(Data::Read(ioPortRegister)) << 8) | Data::Read(ioPortRegister + 1);
                    Resources::Io::Free(port, fixedIoDescriptor->Range);
                    Data::Write(ioPortRegister, 0);
                    Data::Write(ioPortRegister + 1, 0);
                    ioPortRegister += 2;
                    break;
                }
                case Resource::Item::Small::IoPortDescriptor:
                {
                    const Resource::IoPortDescriptor* ioPortDescriptor = (const Resource::IoPortDescriptor*)card->Tags[ioIndex];
                    uint16_t port = (uint16_t(Data::Read(ioPortRegister)) << 8) | Data::Read(ioPortRegister + 1);
                    Resources::Io::Free(port, ioPortDescriptor->Range);
                    Data::Write(ioPortRegister, 0);
                    Data::Write(ioPortRegister + 1, 0);
                    ioPortRegister += 2;
                    break;
                }
                }
            }
        }
    }

    return assigned;
}

bool AllocateResources(const Resource::Card* card)
{
    WakeCsn::Write(card->CardSelectNumber);

    uint32_t currentIndex = 0;
    LogicalDevice_t logicalDevice = 0;
    uint8_t logicalDevicesSetUp = 0;
    while (FindLogicalDevice(card, currentIndex))
    {
        const Resource::LogicalDeviceId* logicalDeviceId = (const Resource::LogicalDeviceId*)card->Tags[currentIndex];
        
        LogicalDevice::Write(logicalDevice);
        Activate::Write(Activate::Disable);
        bool rangeCheckSupported = (logicalDeviceId->Flags0 & Resource::LogicalDeviceIdFlags0::IoRangeCheck) != 0;

        bool assigned = false;
        if (AllocateDeviceResources(card, currentIndex, rangeCheckSupported))
        {
            while (FindDependentFunction(card, currentIndex))
            {
                if (AllocateDeviceResources(card, currentIndex, rangeCheckSupported))
                {
                    assigned = true;
                    break;
                }
            }
        }

        // If a device has no resources assigned, leave it disabled.
        if (assigned)
        {
            Activate::Write(Activate::Enable);
            ++logicalDevicesSetUp;
        }

        ++logicalDevice;
    }

    return logicalDevicesSetUp != 0;
}

InitializeError_t Initialize(Has::IAllocator& allocator)
{
    if (!s_Initialized)
    {
        LOG("PnP", "Detecting cards...");
        if (!DetectCards(allocator, s_ReadPort, s_MaxCsn))
        {
            LOG("PnP", "Isolating cards");
            if (!IsolateCards(s_MaxCsn, s_ReadPort))
            {
                LOG("PnP", "No PnP cards found");
                return InitializeError::NoCardsFound;
            }

            LOG("PnP", "Fetching card resource data...");
            for (CardSelectNumber_t csn = 1; csn <= s_MaxCsn; ++csn)
            {
                const Resource::Card* card = Resource::ParseCard(allocator, s_ReadPort, csn);
                if (card != nullptr)
                    s_Cards.push_back(card);
            }

            LOG("PnP", "Assigning resources...");

            for (const Resource::Card* card : s_Cards)
            {
                if (!AllocateResources(card))
                {
                    LOG("PnP", "Unable to allocate resources");
                }
            }
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
        LOG("PnP", "Cleaning up %i cards", s_Cards.size());
        for (const Resource::Card* card : s_Cards)
        {
            Has::IAllocator& allocator = card->Allocator;
            card->~Card();
            allocator.Free((void*)card);
        }

        LOG("PnP", "Shut down");
        s_Initialized = false;
    }
}

}