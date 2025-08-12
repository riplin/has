//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.3. Compatible Device ID
// The compatible device ID provides the IDs of other devices with which this device is compatible. The
// operating system uses this information to load compatible device drivers if necessary. There can be several
// compatible device identifiers for each logical device. The order of these device IDs may be used by the
// operating system as a criteria for determining which driver should be searched for and loaded first.

// +-------------+---------------------------------------------------------------+
// | Offset      | Field Name                                                    |
// +-------------+---------------------------------------------------------------+
// | Byte 0      | Value = 00011100B (Type = 0, small item name 0x3, length = 4) |
// | Byte 1      | Compatible device ID bits[7:0]                                |
// | Byte 2      | Compatible device ID bits[15:8]                               |
// | Byte 3      | Compatible device ID bits[23:16]                              |
// | Byte 4      | Compatible device ID bits[31:24]                              |
// +-------------+---------------------------------------------------------------+

// As an example of the use of compatible IDs, consider a card vendor who ships a device with logical ID
// 0xABCD0000. At a later date, this vendor ships a new device with a logical ID 0xABCD0001. This new
// device is 100% compatible with the old device but also has added functionality. For this device, the vendor
// could include the Compatible device ID 0xABCD0000. In this case, the exact driver for 0xABCD0001 will be
// loaded if it can be located. If the driver for 0xABCD0001 can not be found, the driver for device
// 0xABCD0000 will be loaded for the device.

// A list of standard compatible device drivers is available from the Plug and Play Association as file
// “devids.txt” on the Association’s Compuserve forum, PLUGPLAY.

struct CompatibleDeviceId : Tag
{
    inline CompatibleDeviceId(Item_t item) : Tag(item) {}
    uint32_t Id;
};

}