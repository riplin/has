//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.11. End Tag
// The End tag identifies an end of resource data. treated as if it checksummed properly. Note: Configuration proceeds normally.
// If the checksum field is zero, the resource data is

// +-------------+----------------------------------------------------------------------------------------------------+
// | Offset      | Field Name                                                                                         |
// +-------------+----------------------------------------------------------------------------------------------------+
// | Byte 0      | Value = 01111001B (Type = 0, small item name = 0xF, length = 1)                                    |
// | Byte 1      | Check sum covering all resource data after the serial identifier. This check sum is generated such |
// |             | that adding it to the sum of all the data bytes will produce a zero sum.                           |
// +-------------+----------------------------------------------------------------------------------------------------+

struct End : Tag
{
    inline End(Item_t item) : Tag(item) {}
    uint8_t Checksum;
};

}