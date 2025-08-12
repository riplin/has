//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.7. End Dependent Functions

// +-------------+---------------------------------------------------------------+
// | Offset      | Field Name                                                    |
// +-------------+---------------------------------------------------------------+
// | Byte 0      | Value = 00111000B (Type = 0, small item name = 0x7 length =0) |
// +-------------+---------------------------------------------------------------+

// Note that only one End Dependent Function item is allowed per logical device. This enforces the fact that
// Dependent Functions are not nestable (see section 7.0).

struct EndDependentFunction : Tag
{
    inline EndDependentFunction(Item_t item) : Tag(item) {}
};

}