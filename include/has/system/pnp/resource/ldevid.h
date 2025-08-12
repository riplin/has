//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.2. Logical Device ID
// The Logical Device ID provides a mechanism for uniquely identifying multiple logical devices embedded in a
// The format of the logical device ID is identical to the Vendor ID field (see Table 2,
// single physical board. Sec. 6.1).

//     • bits[15:0] - three character compressed ASCII EISA ID.
//         Compressed ASCII is defined as 5 bits per character, "00001" = "A" ... "11010" = "Z". This field
//         must contain a valid EISA ID, although it is not required to have the same 3 letters as the Vendor
//         ID.
//     • bits[31:16] - manufacturer-specific function number and revision. It is the manufacturer's
//         responsibility to have unique bits[31:16] for different functions.

// This identifier may be used to select a device driver for the device. Because of this, Logical Device IDs
// must be uniquely associated with a specific function. However, there is no need for the Logical Device ID
// itself to have a unique value, either on a card, or across cards. For instance, a card that implements two
// communications ports may use the exact same Logical Device ID for both. Similarly, two different products
// (different Vendor IDs) may both implement the same function, and therefore will use the same Logical
// Device ID for it. The Logical Device ID is required on all cards. On single-function cards, the Logical
// Device ID may be the same as the card’s vendor ID

// The Logical Device ID includes information about what optional commands are supported. Also, bit zero of
// the flags field is used to indicate that this device should be activated by the BIOS at boot time if this system
// includes a Plug and Play BIOS. Refer to the section on Plug and Play boot devices (Appendix C, Sec. C-2)
// for details.

// +-------------+-----------------------------------------------------------------------------------------------------+
// | Offset      | Field Name                                                                                          |
// +-------------+-----------------------------------------------------------------------------------------------------+
// | Byte 0      | Value = 000101xxB (Type = 0, small item name = 0x2, length = (5 or 6))                              |
// | Byte 1      | Logical device ID bits[7:0]                                                                         |
// | Byte 2      | Logical device ID bits[15:8]                                                                        |
// | Byte 3      | Logical device ID bits[23:16]                                                                       |
// | Byte 4      | Logical device ID bits[31:24]                                                                       |
// | Byte 5      | Flags:                                                                                              |
// |             |     Bits[7:1], if set, indicate commands supported per logical device for registers in the range of |
// |             |     0x31 to 0x37 respectively.                                                                      |
// |             |                                                                                                     |
// |             |     Bit[0], if set, indicates this logical device is capable of participating in the boot process   |
// |             |     Note: Cards that power-up active MUST have this bit set. However, if this bit is set, the       |
// |             |     card may or may not power-up active.                                                            |
// | Byte 6      | Flags:                                                                                              |
// |             |     Bit[7:0], if set, indicate commands supported per logical device for registers in the range     |
// |             |     of 0x38 to 0x3F respectively.                                                                   |
// +-------------+-----------------------------------------------------------------------------------------------------+

typedef uint8_t LogicalDeviceIdFlags0_t;
namespace LogicalDeviceIdFlags0
{
    enum
    {
        BootDevice = 0x01,
        IoRangeCheck = 0x02
        // Other registers aren't defined.
    };
}

typedef uint8_t LogicalDeviceIdFlags1_t;
namespace LogicalDeviceIdFlags1
{
    enum
    {
        // Vendor defined.
    };
}

struct LogicalDeviceId : Tag
{
    inline LogicalDeviceId(Item_t item) : Tag(item) {}
    uint32_t DeviceId;
    LogicalDeviceIdFlags0_t Flags0;
    LogicalDeviceIdFlags1_t Flags1;
};

}