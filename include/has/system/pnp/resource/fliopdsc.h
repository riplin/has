//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.9. Fixed Location I/O Port Descriptor

// +-------------+-----------------------------------------+-----------------------------------------------------------------+
// | Offset      | Field Name                              | Definition                                                      |
// +-------------+-----------------------------------------+-----------------------------------------------------------------+
// | Byte 0      | Fixed Location I/O port descriptor      | Value = 01001011B (Type = 0, Small item name = 0x9, Length = 3) |
// | Byte 1      | Range base address                      | Address bits[7:0] of the base I/O address that the card may     |
// |             |     bits[7:0]                           | be configured for. This descriptor assumes a 10 bit ISA         |
// |             |                                         | address decode.                                                 |
// | Byte 2      | Range base address                      | Address bits[9:8] of the base I/O address that the card may     |
// |             |     bits[9:8]                           | be configured for. This descriptor assumes a 10 bit ISA         |
// |             |                                         | address decode.                                                 |
// | Byte 3      | Range length                            | The number of contiguous I/O ports requested.                   |
// +-------------+-----------------------------------------+-----------------------------------------------------------------+

struct FixedLocationIoPortDescriptor : Tag
{
    inline FixedLocationIoPortDescriptor(Item_t item) : Tag(item) {}
    uint16_t BaseAddress;
    uint8_t Range;
};

}