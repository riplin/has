//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        CardSelectNumber = 0x06
    };
}

typedef Data_t CardSelectNumber_t;
namespace CardSelectNumber
{

    inline void Write(CardSelectNumber_t csn)
    {
        Data::Write(Register::CardSelectNumber, csn);
    }

}

}