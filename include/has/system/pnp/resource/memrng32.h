//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.3.5. 32-bit Memory Range Descriptor

// +-------------+-----------------------------+----------------------------------------------------------------+
// | Size        | Field Name                  | Definition                                                     |
// +-------------+-----------------------------+----------------------------------------------------------------+
// | Byte        | Memory range descriptor     | Value = 10000101B (Type = 1, Large item name = 5)              |
// | Byte        | Length, bits[7:0]           | Value = 00010001B (17)                                         |
// | Byte        | Length, bits[15:8]          | Value = 00000000B                                              |
// | Byte        | Information                 | This field provides extra information about this memory.       |
// |             |                             | Bit[7] Reserved and must be 0                                  |
// |             |                             | Bit[6] Memory is an expansion ROM                              |
// |             |                             | Bit[5] Memory is shadowable.                                   |
// |             |                             | Bits[4:3] Memory control.                                      |
// |             |                             |     Status                                                     |
// |             |                             |     00 8-bit memory only                                       |
// |             |                             |     01 16-bit memory only                                      |
// |             |                             |     10 8- and 16-bit supported.                                |
// |             |                             |     11 32-bit memory only                                      |
// |             |                             | Bit[2] Support type                                            |
// |             |                             |     Status                                                     |
// |             |                             |     1 decode supports high address                             |
// |             |                             |     0 decode supports range length                             |
// |             |                             | Bit[1] Cache support type                                      |
// |             |                             |     Status                                                     |
// |             |                             |     1 read cacheable, write-through                            |
// |             |                             |     0 non-cacheable.                                           |
// |             |                             | Bit[0] Write status                                            |
// |             |                             |     Status                                                     |
// |             |                             |     1 writeable                                                |
// |             |                             |     0 non-writeable (ROM)                                      |
// | Byte        | Range minimum base address  | Address bits[7:0] of the minimum base memory address for       |
// |             |         bits[7:0]           | which the card may be configured.                              |
// | Byte        | Range minimum base address  | Address bits[15:8] of the minimum base memory address for      |
// |             |         bits[15:8]          | which the card may be configured                               |
// | Byte        | Range minimum base address  | Address bits[23:16] of the minimum base memory address for     |
// |             |         bits[23:16]         | which the card may be configured.                              |
// | Byte        | Range minimum base address  | Address bits[31:24] of the minimum base memory address for     |
// |             |         bits[31:24]         | which the card may be configured                               |
// | Byte        | Range maximum base address  | Address bits[7:0] of the maximum base memory address for       |
// |             |         bits[7:0]           | which the card may be configured.                              |
// | Byte        | Range maximum base address  | Address bits[15:8] of the maximum base memory address for      |
// |             |         bits[15:8]          | which the card may be configured                               |
// | Byte        | Range maximum base address  | Address bits[23:16] of the maximum base memory address         |
// |             |         bits[23:16]         | for which the card may be configured.                          |
// | Byte        | Range maximum base address  | Address bits[31:24] of the maximum base memory address         |
// |             |         bits[31:24]         | for which the card may be configured                           |
// | Byte        | Base alignment bits[7:0]    | This field contains Bits[7:0] of the base alignment. The base  |
// |             |                             | alignment provides the increment for the minimum base          |
// |             |                             | address.                                                       |
// | Byte        | Base alignment bits[15:8]   | This field contains Bits[15:8] of the base alignment. The base |
// |             |                             | alignment provides the increment for the minimum base          |
// |             |                             | address.                                                       |
// | Byte        | Base alignment bits[23:16]  | This field contains Bits[23:16] of the base alignment. The     |
// |             |                             | base alignment provides the increment for the minimum base     |
// |             |                             | address.                                                       |
// | Byte        | Base alignment bits[31:24]  | This field contains Bits[31:24] of the base alignment. The     |
// |             |                             | base alignment provides the increment for the minimum base     |
// |             |                             | address.                                                       |
// | Byte        | Range length bits[7:0]      | This field contains Bits[7:0] of the memory range length.      |
// |             |                             | The range length provides the length of the memory range in    |
// |             |                             | 1 byte blocks.                                                 |
// | Byte        | Range length bits[15:8]     | This field contains Bits[15:8] of the memory range length.     |
// |             |                             | The range length provides the length of the memory range in    |
// |             |                             | 1 byte blocks.                                                 |
// | Byte        | Range length bits[23:16]    | This field contains Bits[23:16] of the memory range length.    |
// |             |                             | The range length provides the length of the memory range in    |
// |             |                             | 1 byte blocks.                                                 |
// | Byte        | Range length bits[31:24]    | This field contains Bits[31:24] of the memory range length.    |
// |             |                             | The range length provides the length of the memory range in    |
// |             |                             | 1 byte blocks.                                                 |
// +-------------+-----------------------------+----------------------------------------------------------------+

// NOTE: Mixing of 24-bit and 32-bit memory descriptors is not allowed (see section A.3.1).

typedef uint8_t MemoryRangeFlags32_t;
namespace MemoryRangeFlags32
{
    enum
    {
        WriteStatus = 0x01,
        ReadOnly = 0x00,
        Writeable = 0x01,
        CacheSupport = 0x02,
        NonCacheable = 0x00,
        Cacheable = 0x02,
        SupportType = 0x04,
        DecodeRangeLength = 0x00,
        DecodeHighAddress = 0x04,
        MemorySupport = 0x18,
        Memory8Bit = 0x00,
        Memory16Bit = 0x08,
        Memory8And16Bit = 0x10,
        Memory32Bit = 0x18,
        ShadowStatus  = 0x20,
        ShadowNotSupported = 0x00,
        ShadowSupported = 0x20,
        MemoryType = 0x40,
        MemoryNormal = 0x00,
        MemoryExpansionRom = 0x40
    };
}

struct MemoryRangeDescriptor32Bit : Tag
{
    inline MemoryRangeDescriptor32Bit(Item_t item) : Tag(item) {}
    MemoryRangeFlags32_t Flags;
    uint32_t RangeMinimumBaseAddress;
    uint32_t RangeMaximumBaseAddress;
    uint32_t Alignment;
    uint32_t Range;
};

}