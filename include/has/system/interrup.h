//Copyright 2023-Present riplin

#pragma once

#include <has/types.h>
#include <has/farptr.h>

namespace Has::System::InterruptTable
{

    typedef uint16_t Interrupt_t;

    enum
    {
        Keyboard = 0x09,
        GraphicsFont8x8 = 0x1f,
        CharacterTable = 0x43
    };

    template <Interrupt_t intr>
    inline static FARPointer& Pointer() { return *FARPointer(0x0000, intr << 2).ToPointer<FARPointer>(); }

    extern void SetupHandler(uint8_t interrupt, void (*handler)());
    extern void RestoreHandler(uint8_t interrupt);

    extern void ChainHandler(uint8_t interrupt, void (*handler)());
    extern void UnchainHandler(uint8_t interrupt);

}