//Copyright 2025-Present riplin

#include <has/testing/log.h>
#include <has/system/pnp/resource/end.h>
#include <has/system/pnp/control/wakecsn.h>
#include <has/system/pnp/control/rcsdata.h>
#include <has/system/pnp/resource/ldevid.h>
#include <has/system/pnp/resource/irqfmt.h>
#include <has/system/pnp/resource/dmafmt.h>
#include <has/system/pnp/resource/vendef.h>
#include <has/system/pnp/resource/memrng.h>
#include <has/system/pnp/resource/idfuni.h>
#include <has/system/pnp/resource/flmr32.h>
#include <has/system/pnp/resource/enddepf.h>
#include <has/system/pnp/resource/version.h>
#include <has/system/pnp/resource/idfansi.h>
#include <has/system/pnp/resource/memrng32.h>
#include <has/system/pnp/resource/cmpdevid.h>
#include <has/system/pnp/resource/strtdepf.h>
#include <has/system/pnp/resource/fliopdsc.h>
#include <has/system/pnp/resource/ioprtdsc.h>
#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

static void UpdateChecksum(uint8_t& checksum, uint8_t data)
{
    for (uint8_t i = 0; i < 8; ++i)
    {
        uint8_t bit = data & 0x01;
        data >>= 1;
        checksum = (((( checksum ^ (checksum >> 1)) & 0x01) ^ bit) << 7) | (checksum >> 1);
    }
}

static const Tag* Read(Has::IAllocator& allocator, Register_t port, bool& done)
{
    PnP::Status::Wait(port);
    uint8_t item = ResourceData::Read(port);
    uint16_t size = 0;
    if ((item & Type::Type) == Type::Small)
    {
        size = item & Item::Small::Size;
        switch (item & Item::Small::Item)
        {
        case Item::Small::Version:
        {
            Version* tag = ::new(allocator.Allocate(sizeof(Version))) Version(item & Item::Small::Item);
            ResourceData::Read<uint8_t>(port, tag->PlugAndPlayVersion);
            ResourceData::Read<uint8_t>(port, tag->VendorVersion);
 
            LOG("PnP", "PnP version: %i.%i, Vendor version: %i.%i", tag->PlugAndPlayVersion >> 4, tag->PlugAndPlayVersion & 0xF, tag->VendorVersion >> 4, tag->VendorVersion & 0xF);
            return tag;
        }
        case Item::Small::LogicalDeviceId:
        {
            LogicalDeviceId* tag = ::new(allocator.Allocate(sizeof(LogicalDeviceId))) LogicalDeviceId(item & Item::Small::Item);
            ResourceData::Read<uint32_t>(port, tag->DeviceId);
            ResourceData::Read<uint8_t>(port, tag->Flags0);
            if (size > 5)
                ResourceData::Read<uint8_t>(port, tag->Flags1);
            else
                tag->Flags1 = 0;
 
            LOG("PnP", "Logical Device Id: %c%c%c%02X%02X Flags0: 0x%02X, Flags1: 0x%02X",
                uint8_t((tag->DeviceId >> 2) & 0x1F) + 0x40,
                ((uint8_t(tag->DeviceId & 0x03) << 3) | (uint8_t(tag->DeviceId >> 13) & 0x7)) + 0x40,
                uint8_t((tag->DeviceId >> 8) & 0x1F) + 0x40,
                uint8_t(tag->DeviceId >> 16), uint8_t(tag->DeviceId >> 24), tag->Flags0, tag->Flags1);
            return tag;
        }
    case Item::Small::CompatibleDeviceId:
        {
            CompatibleDeviceId* tag = ::new(allocator.Allocate(sizeof(CompatibleDeviceId))) CompatibleDeviceId(item & Item::Small::Item);
            ResourceData::Read<uint32_t>(port, tag->Id);

            LOG("PnP", "Compatible Device Id: %c%c%c%02X%02X",
                uint8_t((tag->Id >> 2) & 0x1F) + 0x40,
                ((uint8_t(tag->Id & 0x03) << 3) | (uint8_t(tag->Id >> 13) & 0x7)) + 0x40,
                uint8_t((tag->Id >> 8) & 0x1F) + 0x40,
                uint8_t(tag->Id >> 16), uint8_t(tag->Id >> 24));
            return tag;
        }
        case Item::Small::InterruptFormat:
        {
            InterruptFormat* tag = ::new(allocator.Allocate(sizeof(InterruptFormat))) InterruptFormat(item & Item::Small::Item);
            ResourceData::Read<uint16_t>(port, tag->Mask);
            if (size > 2)
                ResourceData::Read<uint8_t>(port, tag->Flags);
            else
                tag->Flags = 0x01;

            LOG("PnP", "Interrupt Mask: 0x%02X, Flags 0x%02X", tag->Mask, tag->Flags);
            return tag;
        }
        case Item::Small::DmaFormat:
        {
            DmaFormat* tag = ::new(allocator.Allocate(sizeof(DmaFormat))) DmaFormat(item & Item::Small::Item);
            ResourceData::Read<uint8_t>(port, tag->Mask);
            ResourceData::Read<uint8_t>(port, tag->Flags);

            LOG("PnP", "DMA Mask: 0x%02X, Flags 0x%02X", tag->Mask, tag->Flags);
            return tag;
        }
        case Item::Small::StartDependentFunction:
        {
            StartDependentFunction* tag = ::new(allocator.Allocate(sizeof(StartDependentFunction))) StartDependentFunction(item & Item::Small::Item);
            if (size > 0)
                ResourceData::Read<uint8_t>(port, tag->ConfigurationLevel);
            else
                tag->ConfigurationLevel = 0;

            LOG("PnP", "Dependent Function Level: 0x%02X", tag->ConfigurationLevel);
            return tag;
        }
        case Item::Small::EndDependentFunction:
        {
            EndDependentFunction* tag = ::new(allocator.Allocate(sizeof(EndDependentFunction))) EndDependentFunction(item & Item::Small::Item);

            LOG("PnP", "End dependent functions");
            return tag;
        }
        case Item::Small::IoPortDescriptor:
        {
            IoPortDescriptor* tag = ::new(allocator.Allocate(sizeof(IoPortDescriptor))) IoPortDescriptor(item & Item::Small::Item);
            ResourceData::Read<uint8_t>(port, tag->Information);
            ResourceData::Read<uint16_t>(port, tag->RangeMinimumAddress);
            ResourceData::Read<uint16_t>(port, tag->RangeMaximumAddress);
            ResourceData::Read<uint8_t>(port, tag->Alignment);
            ResourceData::Read<uint8_t>(port, tag->Range);

            LOG("PnP", "IO: Flags 0x%02X, Range Min: 0x%04X, Max: 0x%04X, Align: 0x%02X, Range: %i", tag->Information, tag->RangeMinimumAddress, tag->RangeMaximumAddress, tag->Alignment, tag->Range);
            return tag;
        }
        case Item::Small::FixedLocationIoPortDescriptor:
        {
            FixedLocationIoPortDescriptor* tag = ::new(allocator.Allocate(sizeof(FixedLocationIoPortDescriptor))) FixedLocationIoPortDescriptor(item & Item::Small::Item);
            ResourceData::Read<uint16_t>(port, tag->BaseAddress);
            ResourceData::Read<uint8_t>(port, tag->Range);

            LOG("PnP", "IO: Fixed: 0x%04X, Range: %i", tag->BaseAddress, tag->Range);
            return tag;
        }
        case Item::Small::VendorDefined:
        {
            VendorDefined* tag = ::new(allocator.Allocate(sizeof(VendorDefined))) VendorDefined(item & Item::Small::Item, allocator);
            tag->Size = size;
            tag->Data = nullptr;
            if (size > 0)
            {
                tag->Data = allocator.AllocateAs<uint8_t>(size);
                for (uint16_t i = 0; i < size; ++i)
                    ResourceData::Read<uint8_t>(port, tag->Data[i]);
            }

            LOG("PnP", "Vendor: %i bytes", tag->Size);
            for (uint16_t i = 0; i < tag->Size; ++i)
            {
                LOG("PnP", "Data[%i] = 0x%02X", i, tag->Data[i]);
            }
            return tag;
        }
        case Item::Small::End:
        {
            done = true;

            End* tag = ::new(allocator.Allocate(sizeof(End))) End(item & Item::Small::Item);
            ResourceData::Read<uint8_t>(port, tag->Checksum);

            LOG("PnP", "End checksum: 0x%02X", tag->Checksum);
            return tag;
        }
        default:
        {
            LOG("PnP", "Unknown item: 0x%02X of size: %i", item, size);
            uint8_t skip;
            for (uint16_t i = 0; i < size; ++i)
            {
                ResourceData::Read<uint8_t>(port, skip);
                LOG("PnP", "Data[%i] = 0x%02X", i, skip);
            }
            return nullptr;
        }
        }
    }
    else
    {
        ResourceData::Read<uint16_t>(port, size);
        switch(item & Item::Large::Item)
        {
        case Item::Large::MemoryRangeDescriptor:
        {
            MemoryRangeDescriptor* tag = ::new(allocator.Allocate(sizeof(MemoryRangeDescriptor))) MemoryRangeDescriptor(item & Item::Large::Item);
            ResourceData::Read<uint8_t>(port, tag->Flags);
            ResourceData::Read<uint16_t>(port, tag->RangeMinimumBaseAddress);
            ResourceData::Read<uint16_t>(port, tag->RangeMaximumBaseAddress);
            ResourceData::Read<uint16_t>(port, tag->Alignment);
            ResourceData::Read<uint16_t>(port, tag->Range);

            LOG("PnP", "Mem range: Flags: 0x%02X, Range Min: 0x%04X00, Max: 0x%04X00, Align: %i, Range: 0x%04X", tag->Flags, tag->RangeMinimumBaseAddress, tag->RangeMaximumBaseAddress, tag->Alignment, tag->Range);
            return tag;
        }
        case Item::Large::IdentifierStringAnsi:
        {
            IdentifierStringAnsi* tag = ::new(allocator.Allocate(sizeof(IdentifierStringAnsi))) IdentifierStringAnsi(item & Item::Large::Item);
            for (uint16_t i = 0; i < size; ++i)
            {
                Status::Wait(port);
                tag->Identifier += char(ResourceData::Read(port));
            }

            LOG("PnP", "Identifier: [%s]", tag->Identifier.c_str());
            return tag;
        }
        case Item::Large::IdentifierStringUnicode:
        {
            IdentifierStringUnicode* tag = ::new(allocator.Allocate(sizeof(IdentifierStringUnicode))) IdentifierStringUnicode(item & Item::Large::Item);
            ResourceData::Read<uint16_t>(port, tag->CountryIdentifier);
            // TODO: Not proper unicode parsing.
            for (uint16_t i = 0; i < size - 2; ++i)
            {
                Status::Wait(port);
                tag->Identifier += char(ResourceData::Read(port));
            }

            LOG("PnP", "Unicode Identifier: [%s]", tag->Identifier.c_str());
            return tag;
        }
        case Item::Large::VendorDefined:
        {
            VendorDefined* tag = ::new(allocator.Allocate(sizeof(VendorDefined))) VendorDefined(item & Item::Large::Item, allocator);
            tag->Size = size;
            tag->Data = nullptr;
            if (size > 0)
            {
                tag->Data = allocator.AllocateAs<uint8_t>(size);
                for (uint16_t i = 0; i < size; ++i)
                    ResourceData::Read<uint8_t>(port, tag->Data[i]);
            }

            LOG("PnP", "Vendor: %i bytes", tag->Size);
            for (uint16_t i = 0; i < tag->Size; ++i)
            {
                LOG("PnP", "Data[%i] = 0x%02X", i, tag->Data[i]);
            }
            return tag;
        }
        case Item::Large::MemoryRangeDescriptor32Bit:
        {
            MemoryRangeDescriptor32Bit* tag = ::new(allocator.Allocate(sizeof(MemoryRangeDescriptor32Bit))) MemoryRangeDescriptor32Bit(item & Item::Large::Item);
            ResourceData::Read<uint8_t>(port, tag->Flags);
            ResourceData::Read<uint32_t>(port, tag->RangeMinimumBaseAddress);
            ResourceData::Read<uint32_t>(port, tag->RangeMaximumBaseAddress);
            ResourceData::Read<uint32_t>(port, tag->Alignment);
            ResourceData::Read<uint32_t>(port, tag->Range);

            LOG("PnP", "32 bit Mem range: Flags: 0x%02X, Range Min: 0x%08lX, Max: 0x%08lX00, Align: %lu, Range: 0x%08lX", tag->Flags, tag->RangeMinimumBaseAddress, tag->RangeMaximumBaseAddress, tag->Alignment, tag->Range);
            return tag;
        }
        case Item::Large::FixedLocationMemoryRangeDescriptor32Bit:
        {
            FixedLocationMemoryRangeDescriptor32Bit* tag = ::new(allocator.Allocate(sizeof(FixedLocationMemoryRangeDescriptor32Bit))) FixedLocationMemoryRangeDescriptor32Bit(item & Item::Large::Item);
            ResourceData::Read<uint8_t>(port, tag->Flags);
            ResourceData::Read<uint32_t>(port, tag->BaseAddress);
            ResourceData::Read<uint32_t>(port, tag->Range);

            LOG("PnP", "32 bit Fixed Mem range: 0x%02X, Base Address: 0x%08lX, Range: 0x%08lX", tag->Flags, tag->BaseAddress, tag->Range);
            return tag;
        }
        default:
        {
            LOG("PnP", "Unknown item: 0x%02X of size: %i", item, size);
            uint8_t skip;
            for (uint16_t i = 0; i < size; ++i)
            {
                ResourceData::Read<uint8_t>(port, skip);
                LOG("PnP", "Data[%i] = 0x%02X", i, skip);
            }
            return nullptr;
        }
        }
    }
}

const Card* ParseCard(Has::IAllocator& allocator, Register_t port, CardSelectNumber_t csn)
{
    uint8_t checksum = 0x6A;
    SYS_ClearInterrupts();
    PnP::WakeCsn::Write(csn);
    PnP::Data_t serialIdentifier[8]; 
    for (uint8_t i = 0; i < (sizeof(serialIdentifier)); i++)
    {
        PnP::Status::Wait(port);
        serialIdentifier[i] = PnP::ResourceData::Read(port);
        UpdateChecksum(checksum, serialIdentifier[i]);
    }
    PnP::Status::Wait(port);
    PnP::Data_t cs = PnP::ResourceData::Read(port);
    SYS_RestoreInterrupts();

    if (checksum != cs)
        return nullptr;

    LOG("PnP", "Card found at read port: 0x%03X, csn %i", port, csn);
    LOG("PnP", "Vendor code: %c%c%c%02X%02X",
        ((serialIdentifier[0] >> 2) & 0x1F) + 0x40,
        (((serialIdentifier[0] & 0x3) << 3) | ((serialIdentifier[1] >> 5) & 0x7)) + 0x40,
        (serialIdentifier[1] & 0x1F) + 0x40,
        serialIdentifier[2], serialIdentifier[3]);
    LOG("PnP", "Serial: %02X%02X%02X%02X", serialIdentifier[4], serialIdentifier[5], serialIdentifier[6], serialIdentifier[7]);

    Card* card = ::new(allocator.Allocate(sizeof(Card))) Card(allocator);
    card->VendorId = uint32_t(serialIdentifier[0]) |
                    (uint32_t(serialIdentifier[1]) << 8) |
                    (uint32_t(serialIdentifier[2]) << 16) |
                    (uint32_t(serialIdentifier[3]) << 24);
    card->Serial = uint32_t(serialIdentifier[4]) |
                    (uint32_t(serialIdentifier[5]) << 8) |
                    (uint32_t(serialIdentifier[6]) << 16) |
                    (uint32_t(serialIdentifier[7]) << 24);
    card->CardSelectNumber = csn;
    
    bool done = false;
    while (!done)
    {
        const Tag* tag = Read(allocator, port, done);
        if (tag == nullptr)
        {
            card->~Card();
            allocator.Free(card);
            return nullptr;
        }
        card->Tags.push_back(tag);
    }

    return card;
}

}