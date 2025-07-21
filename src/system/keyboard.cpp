//Copyright 2025-Present riplin

#include <has/system/pic.h>
#include <has/system/sysasm.h>
#include <has/system/keyboard.h>
#include <has/system/interrup.h>

namespace Has::System::KB
{

ScanCodeHandler_t s_ScanCodeHandler = nullptr;

void SetScanCodeHandler(const ScanCodeHandler_t& scanCodeHandler)
{
    SYS_ClearInterrupts();
    s_ScanCodeHandler = scanCodeHandler;
    SYS_RestoreInterrupts();
}

// Either 0x00 or 0xEx where x = number of incoming bytes minus one.
static uint8_t s_PartialCode = 0;

static void KeyboardHandler()
{
    Data_t data = Data::Read();
    PortB_t portB = PortBCommand::Read();
    PortBCommand::Write(portB | PortBCommand::IRQ1Reset);
    PortBCommand::Write(portB);
    PIC::Control::Write1(PIC::Control::NonspecificEOI);
    if ((s_PartialCode &= ScanCodeSet1::Extended) == ScanCodeSet1::Extended)
    {
        if ((s_PartialCode & ~ScanCodeSet1::Extended) == 0x01)
        {
            s_PartialCode = ScanCodeSet1::Extended;
            //Ignore this byte.
        }
        else
        {
            SYS_ClearInterrupts();
            if (s_ScanCodeHandler != nullptr)
                s_ScanCodeHandler(ScanCode_t(s_PartialCode) << 8 | data);
            s_PartialCode = 0x00;
            SYS_RestoreInterrupts();
        }
    }
    else if ((data & ScanCodeSet1::Extended) == ScanCodeSet1::Extended)
    {
        s_PartialCode = data;
    }
    else
    {
        SYS_ClearInterrupts();
        if (s_ScanCodeHandler != nullptr)
            s_ScanCodeHandler(data);
        SYS_RestoreInterrupts();
    }
}

void InstallKeyboardHandler()
{
    InterruptTable::SetupHandler(InterruptTable::Keyboard, KeyboardHandler);
}

void RemoveKeyboardHandler()
{
    InterruptTable::RestoreHandler(InterruptTable::Keyboard);
}

}
