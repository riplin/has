//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.3.1. Memory Range Descriptor

// +---------+-----------------------------+----------------------------------------------------------+
// | Size    | Field Name                  | Definition                                               |
// +---------+-----------------------------+----------------------------------------------------------+
// | Byte    | Memory range descriptor     | Value = 10000001B (Type = 1, Large item name = 1)        |
// | Byte    | Length, bits[7:0]           | Value = 00001001B (9)                                    |
// | Byte    | Length, bits[15:8]          | Value = 00000000B                                        |
// | Byte    | Information                 | This field provides extra information about this memory. |
// |         |                             | Bit[7] Reserved and must be 0                            |
// |         |                             | Bit[6] Memory is an expansion ROM                        |
// |         |                             | Bit[5] Memory is shadowable.                             |
// |         |                             | Bits[4:3] Memory control.                                |
// |         |                             |     Status                                               |
// |         |                             |     00 8-bit memory only                                 |
// |         |                             |     01 16-bit memory only                                |
// |         |                             |     10 8- and 16-bit supported.                          |
// |         |                             |     11 Reserved                                          |
// |         |                             | Bit[2] Support type                                      |
// |         |                             |     Status                                               |
// |         |                             |     1 decode supports high address                       |
// |         |                             |     0 decode supports range length.                      |
// |         |                             | Bit[1] Cache support type                                |
// |         |                             |     Status                                               |
// |         |                             |     1 read cacheable, write-through                      |
// |         |                             |     0 non-cacheable.                                     |
// |         |                             | Bit[0] Write status                                      |
// |         |                             |     Status                                               |
// |         |                             |     1 writeable                                          |
// |         |                             |     0 non-writeable (ROM)                                |
// | Byte    | Range minimum base address  | Address bits[15:8] of the minimum base memory address    |
// |         |         bits[7:0]           | for which the card may be configured.                    |
// | Byte    | Range minimum base address  | Address bits[23:16] of the minimum base memory address   |
// |         |         bits[15:8]          | for which the card may be configured                     |
// | Byte    | Range maximum base address  | Address bits[15:8] of the maximum base memory address    |
// |         |         bits[7:0]           | for which the card may be configured.                    |
// | Byte    | Range maximum base address  | Address bits[23:16] of the maximum base memory address   |
// |         |         bits[15:8]          | for which the card may be configured                     |
// | Byte    | Base alignment bits[7:0]    | This field contains the lower eight bits of the          |
// |         |                             | base alignment.                                          |
// |         |                             | The base alignment provides the increment for the        |
// |         |                             | minimum base address. (0x0000 = 64 KByte)                |
// | Byte    | Base alignment bits[15:8]   | This field contains the upper eight bits of the          |
// |         |                             | base alignment.                                          |
// |         |                             | The base alignment provides the increment for the        |
// |         |                             | minimum base address. (0x0000 = 64 KByte)                |
// | Byte    | Range length bits[7:0]      | This field contains the lower eight bits of the          |
// |         |                             | memory range length. The range length provides the       |
// |         |                             | length of the memory range in 256 byte blocks.           |
// | Byte    | Range length bits[15:8]     | This field contains the upper eight bits of the          |
// |         |                             | memory range length. The range length field provides the |
// |         |                             | length of the memory range in 256 byte blocks.           |
// +---------+-----------------------------+----------------------------------------------------------+

// NOTE: Address bits [7:0] of memory base addresses are assumed to be 0.
// NOTE: A Memory range descriptor can be used to describe a fixed memory address by setting the range
// minimum base address and the range maximum base address to the same value.
// NOTE: Mixing of 24-bit and 32-bit memory descriptors is not allowed (see section A.3.1).

typedef uint8_t MemoryRangeFlags_t;
namespace MemoryRangeFlags
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
        ShadowStatus  = 0x20,
        ShadowNotSupported = 0x00,
        ShadowSupported = 0x20,
        MemoryType = 0x40,
        MemoryNormal = 0x00,
        MemoryExpansionRom = 0x40
    };
}

struct MemoryRangeDescriptor : Tag
{
    inline MemoryRangeDescriptor(Item_t item) : Tag(item) {}
    MemoryRangeFlags_t Flags;
    uint16_t RangeMinimumBaseAddress;
    uint16_t RangeMaximumBaseAddress;
    uint16_t Alignment;
    uint16_t Range;
};

}