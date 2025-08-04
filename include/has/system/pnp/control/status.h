//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        Status = 0x05
    };
}

typedef Data_t Status_t;
namespace Status
{

    enum
    {
        Ready = 0x01
    };

    inline Status_t ReadPort(Register_t port)
    {
        return Data::ReadPort(port, Register::Status);
    }

    inline void Wait(Register_t port)
    {
        Address::Write(Register::Status);
        while (true) if ((ReadPort(port) & Ready) != 0) break;
    }

}

}