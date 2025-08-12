//Copyright 2025-Present riplin

#pragma once

#include <has/types.h>

namespace Has::System::Resources
{

typedef uint8_t Dma_t;
namespace Dma
{
    typedef uint8_t Mask_t;
    namespace Mask
    {
        enum
        {
            Channel0 = 0x01,
            Channel1 = 0x02,
            Channel2 = 0x04,
            Channel3 = 0x08,
            Channel4 = 0x10,
            Channel5 = 0x20,
            Channel6 = 0x40,
            Channel7 = 0x80
        };
    }

    enum
    {
        Channel0 = 0x00,
        Channel1 = 0x01,
        Channel2 = 0x02,
        Channel3 = 0x03,
        Channel4 = 0x04,
        Channel5 = 0x07,
        Channel6 = 0x06,
        Channel7 = 0x07,
        Invalid = 0xFF
    };

    extern bool IsAvailable(Mask_t mask);
    extern Dma_t Allocate(Mask_t mask);
    extern void Free(Dma_t channel);
}

typedef uint8_t Interrupt_t;
namespace Interrupt
{
    typedef uint16_t Mask_t;
    namespace Mask
    {
        enum
        {
            Interrupt0 = 0x0001,
            Interrupt1 = 0x0002,
            Interrupt2 = 0x0004,
            Interrupt3 = 0x0008,
            Interrupt4 = 0x0010,
            Interrupt5 = 0x0020,
            Interrupt6 = 0x0040,
            Interrupt7 = 0x0080,
            Interrupt8 = 0x0100,
            Interrupt9 = 0x0200,
            Interrupt10 = 0x0400,
            Interrupt11 = 0x0800,
            Interrupt12 = 0x1000,
            Interrupt13 = 0x2000,
            Interrupt14 = 0x4000,
            Interrupt15 = 0x8000,
        };
    }

    enum
    {
        Interrupt0 = 0x00,
        Interrupt1 = 0x01,
        Interrupt2 = 0x02,
        Interrupt3 = 0x03,
        Interrupt4 = 0x04,
        Interrupt5 = 0x05,
        Interrupt6 = 0x06,
        Interrupt7 = 0x07,
        Interrupt8 = 0x08,
        Interrupt9 = 0x09,
        Interrupt10 = 0x0A,
        Interrupt11 = 0x0B,
        Interrupt12 = 0x0C,
        Interrupt13 = 0x0D,
        Interrupt14 = 0x0E,
        Interrupt15 = 0x0F,
        Invalid = 0xFF,
    };

    extern bool IsAvailable(Mask_t mask);
    extern Interrupt_t Allocate(Mask_t mask);
    extern void Free(Interrupt_t channel);
}

//This is far from optimal.
typedef uint16_t Io_t;
namespace Io
{
    extern bool IsAvailable(Io_t baseAddress, uint16_t range);
    extern bool Allocate(Io_t baseAddress, uint16_t range);
    extern void ForceAllocate(Io_t baseAddress, uint16_t range);   // Fixed IO resources.
    extern void Free(Io_t baseAddress, uint16_t range);
}

}