//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        Interrupt0 = 0x70,
        Interrupt0Type = 0x71,
        Interrupt1 = 0x72,
        Interrupt1Type = 0x73,
    };
}

typedef Data_t Interrupt_t;
namespace Interrupt
{
    inline Interrupt_t Read0()
    {
        return Data::Read(Register::Interrupt0);
    }

    inline Interrupt_t Read1()
    {
        return Data::Read(Register::Interrupt1);
    }

    inline void Write0(Interrupt_t interrupt)
    {
        Data::Write(Register::Interrupt0, interrupt);
    }

    inline void Write1(Interrupt_t interrupt)
    {
        Data::Write(Register::Interrupt1, interrupt);
    }
}

typedef Data_t InterruptType_t;
namespace InterruptType
{

    enum
    {
        Type = 0x01,
        Edge = 0x00,
        Level = 0x01,
        Polarity = 0x02,
        Low = 0x00,
        High = 0x02
    };

    inline InterruptType_t Read0()
    {
        return Data::Read(Register::Interrupt0Type);
    }

    inline InterruptType_t Read1()
    {
        return Data::Read(Register::Interrupt1Type);
    }

    inline void Write0(InterruptType_t interruptType)
    {
        Data::Write(Register::Interrupt0Type, interruptType);
    }

    inline void Write1(InterruptType_t interruptType)
    {
        Data::Write(Register::Interrupt1Type, interruptType);
    }
}


}