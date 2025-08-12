//Copyright 2025-Present riplin

#pragma once

#include <has/system/rcs.h>
#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.4. IRQ Format
// The IRQ data structure indicates that the device uses an interrupt level and supplies a mask with bits set
// indicating the levels implemented in this device. For standard ISA implementation there are 16 possible
// interrupt levels so a two byte field is used. This structure is repeated for each separate interrupt level
// required.

// +-------------+--------------------------------------------------------------------------------------------------------+
// | Offset      | Field Name                                                                                             |
// +-------------+--------------------------------------------------------------------------------------------------------+
// | Byte 0      | Value = 0010001XB (Type = 0, small item name = 0x4, length = (2 or 3))                                 |
// | Byte 1      | IRQ mask bits[7:0]. Bit[0] represents IRQ0, bit[1] is IRQ1, and so on.                                 |
// | Byte 2      | IRQ mask bits[15:8]. Bit[0] represents IRQ8, bit[1] is IRQ9, and so on.                                |
// | Byte 3      | IRQ Information. Each bit, when set, indicates this device is capable of driving a certain type of     |
// |             | interrupt. (Optional--if not included then assume ISA compatible edge sensitive, high true interrupts) |
// |             | Bit[7:4] Reserved and must be 0                                                                        |
// |             | Bit[3] Low true level sensitive                                                                        |
// |             | Bit[2] High true level sensitive                                                                       |
// |             | Bit[1] Low true edge sensitive                                                                         |
// |             | Bit[0] High true edge sensitive (Must be supported for ISA compatibility)                              |
// +-------------+--------------------------------------------------------------------------------------------------------+

// NOTE: Low true, level sensitive interrupts may be electrically shared, the process of how
// this might work is beyond the scope of this specification. Only IRQs that exist on
// the ISA bus connectors are valid.


typedef uint8_t InterruptFlags_t;
namespace InterruptFlags
{
    enum
    {
        HighTrueEdgeSensitive = 0x01,
        LowTrueEdgeSensitive = 0x02,
        HighTrueLevelSensitive = 0x04,
        LowTrueLevelSensitive = 0x08
    };
}

struct InterruptFormat : Tag
{
    inline InterruptFormat(Item_t item) : Tag(item) {}
    Resources::Interrupt::Mask_t Mask;
    InterruptFlags_t Flags;
};

}