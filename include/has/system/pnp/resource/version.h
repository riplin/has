//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.1. Plug and Play Version Number
// The Plug and Play Version Number identifies the version of the Plug and Play specification with which this
// card is compatible. A vendor specific version number is included and may be used by a device driver to
// verify the version of the card.

// +-------------+------------------------------------------------------------------------------------------------+
// | Offset      | Field Name                                                                                     |
// +-------------+------------------------------------------------------------------------------------------------+
// | Byte 0      | Value = 00001010B (Type = 0, small item name = 0x1, length = 2)                                |
// | Byte 1      | Plug and Play version number (in packed BCD format, major bits[7:4], minor bits[3:0]) Example: |
// |             | Version 1.0 = 0x10, Version 2.3 = 0x23, Version 2.91= 0x29                                     |
// | Byte 2      | Vendor specific version number                                                                 |
// +-------------+------------------------------------------------------------------------------------------------+

struct Version : Tag
{
    inline Version(Item_t item) : Tag(item) {}
    uint8_t PlugAndPlayVersion;
    uint8_t VendorVersion;
};

}