//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/control/status.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        ResourceData = 0x04
    };
}

typedef uint32_t VendorId_t;
namespace VendorId
{
    enum
    {
        Vendor = 0xF0FFFFFF,
        Revision = 0x0F000000
    };

    namespace Shift
    {
        enum
        {
            Vendor = 0x00,
            Revision = 0x18
        };
    }
}

namespace ResourceData
{

    inline Data_t Read(Register_t port)
    {
        return Data::ReadPort(port, Register::ResourceData);
    }

    template<typename T>
    inline void Read(Register_t port, T& data)
    {
        uint8_t* ptr = (uint8_t*)&data;
        SYS_ClearInterrupts();
        for (uint8_t i = 0; i < sizeof(T); i++)
        {
            Status::Wait(port);
            *(ptr++) = Read(port);
        }
        SYS_RestoreInterrupts();
    }

}

}