//Copyright 2025-Present riplin

#pragma once

#include <has/system/rcs.h>
#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.2.5. DMA Format
// The DMA data structure indicates that the device uses a DMA channel and supplies a mask with bits set
// indicating the channels actually implemented in this device. This structure is repeated for each separate
// channel required.

// +-------------+--------------------------------------------------------------------+
// | Offset      | Field Name                                                         |
// +-------------+--------------------------------------------------------------------+
// | Byte 0      | Value = 00101010B (Type = 0, small item name = 0x5, length = 2)    |
// | Byte 1      | DMA channel mask bits[7:0]. Bit[0] is channel 0.                   |
// | Byte 2      | Bit[7] Reserved and must be 0                                      |
// |             | Bits[6:5] DMA channel speed supported                              |
// |             |     Status                                                         |
// |             |     00 Indicates compatibility mode                                |
// |             |     01 Indicates Type A DMA as described in the EISA Specification |
// |             |     10 Indicates Type B DMA                                        |
// |             |     11 Indicates Type F                                            |
// |             | Bit[4] DMA word mode                                               |
// |             |     Status                                                         |
// |             |     0 DMA may not execute in count by word mode                    |
// |             |     1 DMA may execute in count by word mode                        |
// |             | Bit[3] DMA byte mode status                                        |
// |             |     Status                                                         |
// |             |     0 DMA may not execute in count by byte mode                    |
// |             |     1 DMA may execute in count by byte mode                        |
// |             | Bit[2] Logical device bus master status                            |
// |             |     Status                                                         |
// |             |     0 Logical device is not a bus master                           |
// |             |     1 Logical device is a bus master                               |
// |             | Bits[1:0] DMA transfer type preference                             |
// |             |     Status                                                         |
// |             |     00 8-bit only                                                  |
// |             |     01 8- and 16-bit                                               |
// |             |     10 16-bit only                                                 |
// |             |     11 Reserved                                                    |
// +-------------+--------------------------------------------------------------------+


typedef uint8_t DmaFlags_t;
namespace DmaFlags
{
    enum
    {
        TransferType = 0x03,
        Type8Bit = 0x00,
        TypeBoth = 0x01,
        Type16Bit = 0x02,
        BusMastering = 0x04,
        NotBusMaster = 0x00,
        IsBusMaster = 0x04,
        CountByByteStatus = 0x08,
        CountByByteIncapable = 0x00,
        CountByByteCapable = 0x08,
        CountByWordStatus = 0x10,
        CountByWordIncapable = 0x00,
        CountByWordCapable = 0x10,
        ChannelSpeed = 0x60,
        SpeedCompatibilityMode = 0x00,
        SpeedTypeA = 0x20,
        SpeedTypeB = 0x40,
        SpeedTypeF = 0x60
    };
}

struct DmaFormat : Tag
{
    inline DmaFormat(Item_t item) : Tag(item) {}
    Resources::Dma::Mask_t Mask;
    DmaFlags_t Flags;
};

}