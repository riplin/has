//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/data.h>

namespace Has::System::PnP
{

namespace Register
{
    enum
    {
        Port0High = 0x60,
        Port0Low = 0x61,
        Port1High = 0x62,
        Port1Low = 0x63,
        Port2High = 0x64,
        Port2Low = 0x65,
        Port3High = 0x66,
        Port3Low = 0x67,
        Port4High = 0x68,
        Port4Low = 0x69,
        Port5High = 0x6A,
        Port5Low = 0x6B,
        Port6High = 0x6C,
        Port6Low = 0x6D,
        Port7High = 0x6E,
        Port7Low = 0x6F
    };
}

typedef uint16_t IoBaseAddress_t;
namespace IoBaseAddress
{
    inline IoBaseAddress_t Read0()
    {
        return (IoBaseAddress_t(Data::Read(Register::Port0High)) << 8) | Data::Read(Register::Port0Low);
    }

    inline IoBaseAddress_t Read1()
    {
        return (IoBaseAddress_t(Data::Read(Register::Port1High)) << 8) | Data::Read(Register::Port1Low);
    }

    inline IoBaseAddress_t Read2()
    {
        return (IoBaseAddress_t(Data::Read(Register::Port2High)) << 8) | Data::Read(Register::Port2Low);
    }

    inline IoBaseAddress_t Read3()
    {
        return (IoBaseAddress_t(Data::Read(Register::Port3High)) << 8) | Data::Read(Register::Port3Low);
    }

    inline IoBaseAddress_t Read4()
    {
        return (IoBaseAddress_t(Data::Read(Register::Port4High)) << 8) | Data::Read(Register::Port4Low);
    }

    inline IoBaseAddress_t Read5()
    {
        return (IoBaseAddress_t(Data::Read(Register::Port5High)) << 8) | Data::Read(Register::Port5Low);
    }

    inline IoBaseAddress_t Read6()
    {
        return (IoBaseAddress_t(Data::Read(Register::Port6High)) << 8) | Data::Read(Register::Port6Low);
    }

    inline IoBaseAddress_t Read7()
    {
        return (IoBaseAddress_t(Data::Read(Register::Port7High)) << 8) | Data::Read(Register::Port7Low);
    }

    inline void Write0(IoBaseAddress_t ioBaseAddress)
    {
        Data::Write(Register::Port0High, Data_t(ioBaseAddress >> 8));
        Data::Write(Register::Port0Low, Data_t(ioBaseAddress));
    }

    inline void Write1(IoBaseAddress_t ioBaseAddress)
    {
        Data::Write(Register::Port1High, Data_t(ioBaseAddress >> 8));
        Data::Write(Register::Port1Low, Data_t(ioBaseAddress));
    }

    inline void Write2(IoBaseAddress_t ioBaseAddress)
    {
        Data::Write(Register::Port2High, Data_t(ioBaseAddress >> 8));
        Data::Write(Register::Port2Low, Data_t(ioBaseAddress));
    }

    inline void Write3(IoBaseAddress_t ioBaseAddress)
    {
        Data::Write(Register::Port3High, Data_t(ioBaseAddress >> 8));
        Data::Write(Register::Port3Low, Data_t(ioBaseAddress));
    }

    inline void Write4(IoBaseAddress_t ioBaseAddress)
    {
        Data::Write(Register::Port4High, Data_t(ioBaseAddress >> 8));
        Data::Write(Register::Port4Low, Data_t(ioBaseAddress));
    }

    inline void Write5(IoBaseAddress_t ioBaseAddress)
    {
        Data::Write(Register::Port5High, Data_t(ioBaseAddress >> 8));
        Data::Write(Register::Port5Low, Data_t(ioBaseAddress));
    }

    inline void Write6(IoBaseAddress_t ioBaseAddress)
    {
        Data::Write(Register::Port6High, Data_t(ioBaseAddress >> 8));
        Data::Write(Register::Port6Low, Data_t(ioBaseAddress));
    }

    inline void Write7(IoBaseAddress_t ioBaseAddress)
    {
        Data::Write(Register::Port7High, Data_t(ioBaseAddress >> 8));
        Data::Write(Register::Port7Low, Data_t(ioBaseAddress));
    }
}

}