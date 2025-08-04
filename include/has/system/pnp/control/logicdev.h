//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        LogicalDevice = 0x07
    };
}

typedef Data_t LogicalDevice_t;
namespace LogicalDevice
{

    enum
    {
        Card = 0x00,
        Device1 = 0x01,
        Device2 = 0x02,
        Device3 = 0x03,
        Device4 = 0x04,
        Device5 = 0x05,
        Device6 = 0x06,
        Device7 = 0x07,
        Device8 = 0x08,
        Device9 = 0x09,
        Device10 = 0x0A
    };

    inline LogicalDevice_t Read()
    {
        return Data::Read(Register::LogicalDevice);
    }

    inline void Write(LogicalDevice_t logicalDevice)
    {
        Data::Write(Register::LogicalDevice, logicalDevice);
    }

}

}