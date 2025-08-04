//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        Config = 0x02
    };
}

typedef Data_t Config_t;
namespace Config
{

    // A write to bit[0] of this register performs a reset
    // function on all logical devices. This resets the contents
    // of configuration registers to their default state. All
    // card's logical devices enter their default state and the
    // CSN is preserved.

    // A write to bit[1] of this register causes all cards to enter
    // the Wait for Key state but all CSNs are preserved and
    // logical devices are not affected.

    // A write to bit[2] of this register causes all cards to reset
    // their CSN to zero .

    // This register is write-only. The values are not sticky,
    // that is, hardware will automatically clear them and
    // there is no need for software to clear the bits.

    enum
    {
        Reset = 0x01,           // Bit[0] - Reset all logical devices and restore
                                //          configuration registers to their power-up values.
        WaitForKey = 0x02,      // Bit[1] - Return to the Wait for Key state
        ResetCSN = 0x04         // Bit[2] - Reset CSN to 0
    };

    inline void Write(Config_t config)
    {
        Data::Write(Register::Config, config);
    }

}

}