//Copyright 2025-Present riplin

#pragma once

#include <has/types.h>

namespace Has
{

    class IStream
    {
    public:
        virtual bool Read(uint32_t size, void* buffer) = 0;
        virtual bool Write(uint32_t size, void* buffer) = 0;
        virtual bool SeekFromStart(uint32_t offset = 0) = 0;
        virtual bool SeekFromCurrent(uint32_t offset) = 0;
        virtual bool SeekFromEnd(uint32_t offset = 0) = 0;
        virtual uint32_t Position() = 0;
        virtual uint32_t Size() = 0;
        virtual bool IsOpen() = 0;
        virtual bool Close() = 0;
    };

}