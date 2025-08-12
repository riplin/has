//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/memrng32.h>

namespace Has::System::PnP::Resource
{

// 6.2.3.6. 32-bit Fixed Location Memory Range Descriptor

// +---------+-----------------------------+---------------------------------------------------------------+
// | Size    | Field Name                  | Definition                                                    |
// +---------+-----------------------------+---------------------------------------------------------------+
// | Byte    | Memory range descriptor     | Value = 10000110B (Type = 1, Large item name = 6)             |
// | Byte    | Length, bits[7:0]           | Value = 00001001B (9)                                         |
// | Byte    | Length, bits[15:8]          | Value = 00000000B                                             |
// | Byte    | Information                 | This field provides extra information about this memory.      |
// |         |                             | Bit[7] Reserved and must be 0.                                |
// |         |                             | Bit[6] Memory is an expansion ROM.                            |
// |         |                             | Bit[5] Memory is shadowable.                                  |
// |         |                             | Bits[4:3] Memory control.                                     |
// |         |                             |     Status                                                    |
// |         |                             |     00 8-bit memory only                                      |
// |         |                             |     01 16-bit memory only                                     |
// |         |                             |     10 8- and 16-bit supported                                |
// |         |                             |     11 32-bit memory only                                     |
// |         |                             | Bit[2] Support type                                           |
// |         |                             |     Status                                                    |
// |         |                             |     1 decode supports high address                            |
// |         |                             |     0 decode supports range length                            |
// |         |                             | Bit[1] Cache support type                                     |
// |         |                             |     Status                                                    |
// |         |                             |     1 read cacheable, write-through                           |
// |         |                             |     0 non-cacheable                                           |
// |         |                             | Bit[0] Write status.                                          |
// |         |                             |     Status                                                    |
// |         |                             |     1 writeable                                               |
// |         |                             |     0 non-writeable (ROM)                                     |
// | Byte    | Range base address          | Address bits[7:0] of the base memory address for which the    |
// |         |     bits[7:0]               | card may be configured.                                       |
// | Byte    | Range base address          | Address bits[15:8] of the base memory address for which the   |
// |         |     bits[15:8]              | card may be configured.                                       |
// | Byte    | Range base address          | Address bits[23:16] of the base memory address for which      |
// |         |     bits[23:16]             | the card may be configured.                                   |
// | Byte    | Range base address          | Address bits[31:24] of the base memory address for which      |
// |         |     bits[31:24]             | the card may be configured.                                   |
// | Byte    | Range length bits[7:0]      | This field contains Bits[7:0] of the memory range length.     |
// |         |                             | The range length provides the length of the memory range in   |
// |         |                             | 1 byte blocks.                                                |
// | Byte    | Range length bits[15:8]     | This field contains Bits[15:8] of the memory range length.    |
// |         |                             | The range length provides the length of the memory range in   |
// |         |                             | 1 byte blocks.                                                |
// | Byte    | Range length bits[23:16]    | This field contains Bits[23:16] of the memory range length.   |
// |         |                             | The range length provides the length of the memory range in   |
// |         |                             | 1 byte blocks.                                                |
// | Byte    | Range length bits[31:24]    | This field contains Bits[31:24] of the memory range length.   |
// |         |                             | The range length provides the length of the memory range in   |
// |         |                             | 1 byte blocks.                                                |
// +---------+-----------------------------+---------------------------------------------------------------+

// NOTE: Mixing of 24-bit and 32-bit memory descriptors is not allowed (see section A.3.1).

struct FixedLocationMemoryRangeDescriptor32Bit : Tag
{
    inline FixedLocationMemoryRangeDescriptor32Bit(Item_t item) : Tag(item) {}
    MemoryRangeFlags32_t Flags;
    uint32_t BaseAddress;
    uint32_t Range;
};

}