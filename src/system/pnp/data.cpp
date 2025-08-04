//Copyright 2025-Present riplin

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

Register_t s_ReadPort = Register::ReadInvalid;

namespace Data
{

    Data_t Read()
    {
        if (s_ReadPort != Register::ReadInvalid)
        {
            return ReadPort(s_ReadPort);
        }
        return Invalid;
    }

    Data_t Read(Address_t address)
    {
        if (s_ReadPort != Register::ReadInvalid)
        {
            return ReadPort(s_ReadPort, address);
        }
    }

}

}