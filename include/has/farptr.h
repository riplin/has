//Copyright 2023-Present riplin

#pragma once

#include <has/types.h>
#include <sys/nearptr.h>

struct FARPointer
{
    inline FARPointer() : Offset(0), Segment(0) {}
    inline FARPointer(uint16_t seg, uint16_t offs) : Offset(offs), Segment(seg){}
    inline bool IsNull() { return (Offset == 0x0000) && (Segment == 0x0000);}
    inline void Set(uint16_t seg, uint16_t offs) { Segment = seg; Offset = offs; }

#ifdef MOCK
    extern uint8_t& Ref(uint16_t offset, uint16_t size, uint16_t count = 1);
    template<typename T> T*ToPointer(uint32_t size = sizeof(T)) { return (T*)(&Ref((uint32_t(Segment) << 4) + Offset, size)); }
#else
    template<typename T> T*ToPointer(uint32_t size = sizeof(T)) { return (T*)(((uint32_t(Segment) << 4) + Offset) + __djgpp_conventional_base); }
#endif

    uint16_t Offset;
    uint16_t Segment;
};
