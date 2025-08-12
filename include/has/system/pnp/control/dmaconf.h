//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        DmaChannel0 = 0x74,
        DmaChannel1 = 0x75
    };
}

typedef Data_t DmaChannel_t;
namespace DmaChannel
{
    inline DmaChannel_t Read0()
    {
        return Data::Read(Register::DmaChannel0);
    }

    inline DmaChannel_t Read1()
    {
        return Data::Read(Register::DmaChannel1);
    }

    inline void Write0(DmaChannel_t dmaChannel)
    {
        Data::Write(Register::DmaChannel0, dmaChannel);
    }

    inline void Write1(DmaChannel_t dmaChannel)
    {
        Data::Write(Register::DmaChannel1, dmaChannel);
    }
}

}