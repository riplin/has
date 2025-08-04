//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        ReadDataPort = 0x00
    };
}

typedef Data_t ReadDataPort_t;
namespace ReadDataPort
{

inline void Write(ReadDataPort_t port)
{
    Data::Write(Register::ReadDataPort, port);
}

}


}