//Copyright 2025-Present riplin

#pragma once

#include <has/system/sysasm.h>
#include <has/system/pnp/regtype.h>

namespace Has::System::PnP
{

namespace Register
{

enum
{
    Address = 0x279
};

}

typedef uint8_t Address_t;
namespace Address
{

inline void Write(Address_t value)
{
    SYS_WritePortByte(Register::Address, value);
}

}


}