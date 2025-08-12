//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// There are two types of descriptors for I/O ranges. The first descriptor is a full function descriptor for
// programmable ISA cards. The second descriptor is a minimal descriptor for old ISA cards with fixed I/O
// requirements that use a 10-bit ISA address decode. The first type descriptor can also be used to describe
// fixed I/O requirements for ISA cards that require a 16-bit address decode. This is accomplished by setting
// the range minimum base address and range maximum base address to the same fixed I/O value.

// +-------------+---------------------------------+----------------------------------------------------------------------+
// | Offset      | Field Name                      | Definition                                                           |
// +-------------+---------------------------------+----------------------------------------------------------------------+
// | Byte 0      | I/O port descriptor             | Value = 01000111B (Type = 0, Small item name = 0x8, Length = 7)      |
// | Byte 1      | Information                     | Bits[7:1] are reserved and must be 0                                 |
// |             |                                 | Bit[0], if set, indicates the logical device decodes the full 16 bit |
// |             |                                 | ISA address. If bit[0] is not set, this indicates the logical device |
// |             |                                 | only decodes ISA address bits[9:0].                                  |
// | Byte 2      | Range minimum base address      | Address bits[7:0] of the minimum base I/O address that the           |
// |             |         bits[7:0]               | card may be configured for.                                          |
// | Byte 3      | Range minimum base address      | Address bits[15:8] of the minimum base I/O address that the          |
// |             |         bits[15:8]              | card may be configured for.                                          |
// | Byte 4      | Range maximum base address      | Address bits[7:0] of the maximum base I/O address that the           |
// |             |         bits[7:0]               | card may be configured for.                                          |
// | Byte 5      | Range maximum base address      | Address bits[15:8] of the maximum base I/O address that the          |
// |             |         bits[15:8]              | card may be configured for.                                          |
// | Byte 6      | Base alignment                  | Alignment for minimum base address, increment in 1 byte blocks.      |
// | Byte 7      | Range length                    | The number of contiguous I/O ports requested.                        |
// +-------------+---------------------------------+----------------------------------------------------------------------+

typedef uint8_t IoInformation_t;
namespace IoInformation
{
    enum
    {
        IsaDecodeStatus = 0x01,
        IsaDecode10Bit = 0x00,
        IsaDecode16Bit = 0x01,
    };
}

struct IoPortDescriptor : Tag
{
    inline IoPortDescriptor(Item_t item) : Tag(item) {}
    IoInformation_t Information;
    uint16_t RangeMinimumAddress;
    uint16_t RangeMaximumAddress;
    uint8_t Alignment;
    uint8_t Range;
};

}