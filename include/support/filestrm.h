//Copyright 2025-Present riplin

#pragma once

#include <stdio.h>
#include <has/istream.h>

namespace Support
{
    typedef uint8_t FileStreamMode_t;
    namespace FileStreamMode
    {
        enum
        {
            Read = 0x01,            // Opens an existing file for reading
            Create = 0x02,          // Creates a new file for reading and writing, destroys exising files.
            OpenExisting = 0x03,    // Opens an existing file for reading and writing.
            CreateAppend = 0x04     // Opens an existing file for append and read, creates a new one if none exists.
        };
    }

    class FileStream : public Has::IStream
    {
    public:
        FileStream(const char* fileName, FileStreamMode_t mode);
        ~FileStream();
        virtual bool Read(uint32_t size, void* buffer) override;
        virtual bool Write(uint32_t size, void* buffer) override;
        virtual bool SeekFromStart(uint32_t offset = 0) override;
        virtual bool SeekFromCurrent(uint32_t offset) override;
        virtual bool SeekFromEnd(uint32_t offset = 0) override;
        virtual uint32_t Position() override;
        virtual uint32_t Size() override;
        virtual bool IsOpen() override;
        virtual bool Close() override;
    private:
        FILE* m_File;
    };

}