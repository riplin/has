//Copyright 2025-Present riplin

#include <support/filestrm.h>

namespace Support
{

FileStream::FileStream(const char* fileName, FileStreamMode_t mode)
{
    const char* mod = nullptr;
    switch (mode)
    {
    case FileStreamMode::Read:
        mod = "rb";
        break;
    case FileStreamMode::Create:
        mod = "wb+";
        break;
    case FileStreamMode::OpenExisting:
        mod = "rb+";
        break;
    case FileStreamMode::CreateAppend:
        mod = "ab+";
        break;
    default:
        break;
    }
    if (mod != nullptr)
    m_File = fopen(fileName, mod);
}

FileStream::~FileStream()
{
    Close();
}

bool FileStream::Read(uint32_t size, void* buffer)
{
    if (m_File == nullptr)
        return false;
    
    return fread(buffer, 1, size, m_File) == size;
}

bool FileStream::Write(uint32_t size, void* buffer)
{
    if (m_File == nullptr)
        return false;

    return fwrite(buffer, 1, size, m_File) == size;
}

bool FileStream::SeekFromStart(uint32_t offset)
{
    if (m_File == nullptr)
        return false;

    return fseek(m_File, offset, SEEK_SET) == 0;
}

bool FileStream::SeekFromCurrent(uint32_t offset)
{
    if (m_File == nullptr)
        return false;

    return fseek(m_File, offset, SEEK_CUR) == 0;
}

bool FileStream::SeekFromEnd(uint32_t offset)
{
    if (m_File == nullptr)
        return false;

    return fseek(m_File, offset, SEEK_END) == 0;
}

uint32_t FileStream::Position()
{
    if (m_File == nullptr)
        return 0;

    return ftell(m_File);
}

uint32_t FileStream::Size()
{
    if (m_File == nullptr)
        return 0;

    uint32_t position = Position();

    SeekFromEnd();

    uint32_t size = Position();

    SeekFromStart(position);
    
    return size;
}

bool FileStream::IsOpen()
{
    return m_File != nullptr;
}

bool FileStream::Close()
{
    if (m_File != nullptr)
    {
        return fclose(m_File) == 0;
    }
    return false;
}

}