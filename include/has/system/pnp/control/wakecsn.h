//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/control/csn.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        WakeCsn = 0x03,
    };
}

namespace WakeCsn
{

    // Puts the device in the configuration state (if it wasn't in the Wait For Key state)
    inline void Write(CardSelectNumber_t csn)
    {
        Data::Write(Register::WakeCsn, csn);
    }

}

}