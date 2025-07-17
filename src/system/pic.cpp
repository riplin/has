//Copyright 2025-Present riplin

#include <has/system/pic.h>

namespace Has::System::PIC
{

namespace Mask
{

void MaskInterrupt(uint8_t interrupt)
{
    Mask_t mask = 1 << (interrupt & 0x07);

    if (interrupt <= 7)
    {
        SYS_ClearInterrupts();
        Write1(Read1() | mask);
        Control::Write1(Control::SpecificEOI | interrupt);
        SYS_RestoreInterrupts();
    }
    else
    {
        SYS_ClearInterrupts();
        Write2(Read2() | mask);
        Control::Write2(Control::SpecificEOI | (interrupt & 0x7));
        SYS_RestoreInterrupts();
    }
}

void UnmaskInterrupt(uint8_t interrupt)
{
    Mask_t mask = 1 << (interrupt & 0x07);

    if (interrupt <= 7)
    {
        SYS_ClearInterrupts();
        Write1(Read1() & ~mask);
        Control::Write1(Control::SpecificEOI | interrupt);
        SYS_RestoreInterrupts();
    }
    else
    {
        SYS_ClearInterrupts();
        Write2(Read2() & ~mask);
        Control::Write2(Control::SpecificEOI | (interrupt & 0x7));
        SYS_RestoreInterrupts();
    }
}

}

namespace Control
{

void ClearPendingInterrupt(uint8_t interrupt)
{
    if (interrupt <= 7)
    {
        Write1(SpecificEOI | interrupt);
    }
    else
    {
        SYS_ClearInterrupts();
        Write2(SpecificEOI | (interrupt & 0x7));
        Write1(NonspecificEOI);
        SYS_RestoreInterrupts();
    }
}

}

}