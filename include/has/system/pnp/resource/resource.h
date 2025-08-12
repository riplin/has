//Copyright 2025-Present riplin

#pragma once

#include <vector>
#include <has/ialloc.h>
#include <has/system/pnp/control/csn.h>

namespace Has::System::PnP::Resource
{

namespace Type
{
    enum
    {
        Type = 0x80,
        Small = 0x00,
        Large = 0x80
    };
}

typedef uint8_t Item_t;
namespace Item
{

namespace Small
{
enum
{
    Size = 0x07,

    Item = 0x78,
    Version = 0x08,
    LogicalDeviceId = 0x10,
    CompatibleDeviceId = 0x18,
    InterruptFormat = 0x20,
    DmaFormat = 0x28,
    StartDependentFunction = 0x30,
    EndDependentFunction = 0x38,
    IoPortDescriptor = 0x40,
    FixedLocationIoPortDescriptor = 0x48,
    VendorDefined = 0x70,
    End = 0x78
};
}

namespace Large
{
    enum
    {
        Item = 0x7F,
        MemoryRangeDescriptor = 0x01,
        IdentifierStringAnsi = 0x02,
        IdentifierStringUnicode = 0x03,
        VendorDefined = 0x04,
        MemoryRangeDescriptor32Bit = 0x05,
        FixedLocationMemoryRangeDescriptor32Bit = 0x06
    };
}

}

struct Tag
{
    inline Tag(Item_t item) : Item(item) {}
    inline virtual ~Tag() {}

    Item_t Item;
};

struct Card
{
    inline Card(Has::IAllocator& allocator) : Allocator(allocator) {}
    inline ~Card() { for (const Tag* tag : Tags) { tag->~Tag(); Allocator.Free((void*)tag); } Tags.clear(); }

    Has::IAllocator& Allocator;
    std::vector<const Tag*> Tags;
    uint32_t VendorId;
    uint32_t Serial;
    CardSelectNumber_t CardSelectNumber;
};

const Card* ParseCard(Has::IAllocator& allocator, Register_t port, CardSelectNumber_t csn);

}