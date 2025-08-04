//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/address.h>

namespace Has::System::PnP
{

namespace Register
{

    enum
    {
        Write = 0xA79,
        ReadInvalid = 0x000,
        ReadMin = 0x203,
        ReadMax = 0x23F
    };

}

typedef uint8_t Data_t;
namespace Data
{

    enum
    {
        Invalid = 0xFF
    };

    inline void Write(Data_t value)
    {
        SYS_WritePortByte(Register::Write, value);
    }

    inline void Write(Address_t address, Data_t value)
    {
        Address::Write(address);
        Write(value);
    }

    inline Data_t ReadPort(Register_t port)
    {
        return SYS_ReadPortByte(port);
    }

    inline Data_t ReadPort(Register_t port, Address_t address)
    {
        Address::Write(address);
        return ReadPort(port);
    }

    extern Data_t Read();
    extern Data_t Read(Address_t address);

}


}