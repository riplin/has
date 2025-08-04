//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        SerialIsolation = 0x01
    };
}

typedef Data_t SerialIsolation_t;
namespace SerialIsolation
{

    // Does not set address
    inline SerialIsolation_t ReadDirect()
    {
        return Data::Read(Register::SerialIsolation);
    }

    // Does not set address
    inline SerialIsolation_t ReadDirect(Register_t port)
    {
        return Data::ReadPort(port);
    }

}


}