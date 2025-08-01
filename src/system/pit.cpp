//Copyright 2025-Present riplin

#include <has/system/pit.h>
#include <has/system/machid.h>
#include <has/system/keyboard.h>

namespace Has::System::PIT
{

uint16_t CalculateDivisor(uint16_t frequencyInHz)
{
    return uint16_t(1193180 / frequencyInHz);
}

static void SetupSquareWave()
{
    Command::Write(Command::ModeSquareWaveGenerator | Command::LowByteHighByte | Command::SelectChannel2);
    Data::WriteChannel2(0xA9);
    Data::WriteChannel2(0x04);
}

void Sleep(uint8_t count)//count * 8 * 1193 ticks time
{
    SetupSquareWave();

    KB::Register_t port = (BIOS::MachineID::Read() == 0xFC) ? KB::Register::PortB : KB::Register::PortXT;

    count <<= 3;

    if (count != 0)
    {
        KB::PortB_t orgValue = KB::PortBStatus::Read();
        KB::PortBCommand::Write(orgValue |= KB::PortBCommand::Timer2GateSpeakerEnable);

        do
        {
            volatile KB::PortB_t status;
            do
            {
                status = KB::Read(port);
            } while ((status & KB::PortBStatus::MirrorTimer2OutputCond) != 0);

            do
            {
                status = KB::Read(port);
            } while ((status & KB::PortBStatus::MirrorTimer2OutputCond) != 0);
            --count;
        } while (count != 0);

        KB::PortBCommand::Write(orgValue);
    }
}

void MiniSleep()//1193 ticks time
{
    using namespace Has::System;

    SetupSquareWave();

    KB::Register_t port = (BIOS::MachineID::Read() == 0xFC) ? KB::Register::PortB : KB::Register::PortXT;

    KB::PortB_t orgValue = KB::PortBStatus::Read();
    KB::PortBCommand::Write(orgValue |= KB::PortBCommand::Timer2GateSpeakerEnable);

    volatile KB::PortB_t status;
    do
    {
        status = KB::Read(port);
    } while ((status & KB::PortBStatus::MirrorTimer2OutputCond) != 0);
    KB::PortBCommand::Write(orgValue);
}

}