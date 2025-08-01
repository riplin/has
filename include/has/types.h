//Copyright 2023-Present riplin

#pragma once

#include <stdint.h>

//These are defined to clearly communicate the number of bits that are expected.
typedef unsigned char uint1_t;
typedef unsigned char uint2_t;
typedef unsigned char uint3_t;
typedef unsigned char uint4_t;
typedef unsigned char uint5_t;
typedef unsigned char uint6_t;
typedef unsigned char uint7_t;
typedef unsigned short uint9_t;
typedef unsigned short uint10_t;
typedef unsigned short uint11_t;
typedef unsigned short uint12_t;
typedef unsigned short uint13_t;
typedef unsigned short uint14_t;
typedef unsigned short uint15_t;
typedef unsigned int uint17_t;
typedef unsigned int uint18_t;
typedef unsigned int uint19_t;
typedef unsigned int uint20_t;

#ifndef forceinline
#define forceinline __attribute__((always_inline)) inline
#endif

#define HAS_LIKELY [[likely]]
#define HAS_UNLIKELY [[unlikely]]

#define HAS_NOCOPY(Type)                    \
public:                                     \
    Type(const Type&) = delete;             \
    Type& operator=(const Type&) = delete;

namespace Has
{
    template<typename T> T min(T a, T b) { return a < b ? a : b; }
    template<typename T> T max(T a, T b) { return a > b ? a : b; }
    template<typename T> T bound(T a, T v, T b) { return min<T>(max<T>(a, v), b); }
    template<typename T> T abs(T a) { return a < T(0) ? -a : a; }
    template<typename T> T alignup(T a, T alignment) { return (a + (alignment - 1)) & ~(alignment - 1); }
    template<typename T> T aligndown(T a, T alignment) { return a & ~(alignment - 1); }

    consteval int numbits(int val)
    {
        int ret = 0;
        while (val != 0)
        {
            ret += val & 1;
            val >>= 1;
        }
        return ret;
    }

}
