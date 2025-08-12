//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.10. Vendor Defined

// The vendor defined resource data type is for vendor use.

// +-----------------+---------------------------------------------------------------------+
// | Offset          | Field Name                                                          |
// +-----------------+---------------------------------------------------------------------+
// | Byte 0          | Value = 01110xxxB (Type = 0, small item name = 0xE, length = (1-7)) |
// | Byte 1 to 7     | Vendor defined                                                      |
// +-----------------+---------------------------------------------------------------------+



// 6.2.3.4. Vendor Defined

// The vendor defined resource data type is for vendor use.

// +-------------+---------------------+---------------------------------------------------+
// | Size        | Field Name          | Definition                                        |
// +-------------+---------------------+---------------------------------------------------+
// | Byte        | Vendor defined      | Value = 10000100B (Type = 1, Large item name = 4) |
// | Byte        | Length, bits[7:0]   | Lower eight bits of vendor defined data           |
// | Byte        | Length, bits[15:8]  | Upper eight bits of vendor defined data           |
// | N * bytes   | Vendor Defined      | Vendor defined data bytes                         |
// +-------------+---------------------+---------------------------------------------------+

struct VendorDefined : Tag
{
    inline VendorDefined(Item_t item, Has::IAllocator& allocator) : Tag(item), Allocator(allocator) {}
    inline virtual ~VendorDefined() { if (Data != nullptr) Allocator.Free(Data); }

    Has::IAllocator& Allocator;
    uint8_t* Data;
    uint8_t Size;
};

}