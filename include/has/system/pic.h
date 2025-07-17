//Copyright 2025-Present riplin

#pragma once

#include <has/types.h>
#include <has/system/sysasm.h>

namespace Has::System::PIC
{

namespace Register
{
    enum
    {
        Control1 = 0x20,
        Mask1 = 0x21,
        Control2 = 0xa0,
        Mask2 = 0xa1
    };
}

// Bitfields for PIC output control word OCW1:
// Bit(s)	    Description	(Table P0014)
//  7	        disable IRQ7 (parallel printer interrupt)
//  6	        disable IRQ6 (diskette interrupt)
//  5	        disable IRQ5 (fixed disk interrupt)
//  4	        disable IRQ4 (serial port 1 interrupt)
//  3	        disable IRQ3 (serial port 2 interrupt)
//  2	        disable IRQ2 (video interrupt)
//  1	        disable IRQ1 (keyboard, mouse, RTC interrupt)
//  0	        disable IRQ0 (timer interrupt)

// Bitfields for PIC2 output control word OCW1:
// Bit(s)	    Description	(Table P0418)
//  7	        disable IRQ15 (reserved)
//  6	        disable IRQ14 (fixed disk interrupt)
//  5	        disable IRQ13 (coprocessor exception interrupt)
//  4	        disable IRQ12 (mouse interrupt)
//  3	        disable IRQ11 (reserved)
//  2	        disable IRQ10 (reserved)
//  1	        disable IRQ9  (redirect cascade)
//  0	        disable IRQ8  (real-time clock interrupt)

typedef uint8_t Mask_t;
namespace Mask
{
    enum
    {
        Interrupt0 = 0x01,
        Interrupt1 = 0x02,
        Interrupt2 = 0x04,
        Interrupt3 = 0x08,
        Interrupt4 = 0x10,
        Interrupt5 = 0x20,
        Interrupt6 = 0x40,
        Interrupt7 = 0x80,
        Interrupt8 = 0x01,
        Interrupt9 = 0x02,
        Interrupt10 = 0x04,
        Interrupt11 = 0x08,
        Interrupt12 = 0x10,
        Interrupt13 = 0x20,
        Interrupt14 = 0x40,
        Interrupt15 = 0x80
    };

    inline Mask_t Read1() { return Mask_t(SYS_ReadPortByte(Register::Mask1)); }
    inline Mask_t Read2() { return Mask_t(SYS_ReadPortByte(Register::Mask2)); }

    inline void Write1(Mask_t mask) { SYS_WritePortByte(Register::Mask1, mask); }
    inline void Write2(Mask_t mask) { SYS_WritePortByte(Register::Mask2, mask); }
}

// Bitfields for PIC output control word OCW2:
// Bit(s)   Description (Table P0015)
//  7-5	    operation
// 	        000 rotate in auto EOI mode (clear)
// 	        001 (WORD_A) nonspecific EOI
// 	        010 (WORD_H) no operation
// 	        011 (WORD_B) specific EOI
// 	        100 (WORD_F) rotate in auto EOI mode (set)
// 	        101 (WORD_C) rotate on nonspecific EOI command
// 	        110 (WORD_E) set priority command
// 	        111 (WORD_D) rotate on specific EOI command
//  4-3	    reserved (00 - signals OCW2)
//  2-0	    interrupt request to which the command applies
// 	        (only used by WORD_B, WORD_D, and WORD_E)

typedef uint8_t Control_t;
namespace Control
{
    enum
    {
        Interrupt = 0x07,
        Operation = 0xe0,
        RotateInAutoEOIModeClear = 0x00,
        NonspecificEOI = 0x20,
        Nop = 0x40,
        SpecificEOI = 0x60,
        RotateInAutoEOIModeSet = 0x80,
        RotateOnNonSpecificEOI = 0xa0,
        SetPriority = 0xc0,
        RotateOnSpecificEOI = 0xe0
    };

    namespace Shift
    {
        enum
        {
            Interrupt = 0x00,
            Operation = 0x05,
        };
    }

    inline Control_t Read1() { return Control_t(SYS_ReadPortByte(Register::Control1)); }
    inline Control_t Read2() { return Control_t(SYS_ReadPortByte(Register::Control2)); }

    inline void Write1(Control_t mask) { SYS_WritePortByte(Register::Control1, mask); }
    inline void Write2(Control_t mask) { SYS_WritePortByte(Register::Control2, mask); }
}

}