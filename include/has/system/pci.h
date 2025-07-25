//Copyright 2023-Present riplin

#pragma once

#include <has/types.h>
#include <has/system/sysasm.h>

namespace Has::System::PCI
{
    typedef uint16_t Device_t;

    typedef uint8_t Register8_t;
    typedef uint16_t Register16_t;
    typedef uint32_t Register_t;

namespace Config
{
    enum
    {
        Address = 0x0CF8,
        Data = 0x0CFC,
    };
}

namespace Vendor
{
    enum
    {
        Invalid = 0xFFFF,
    };
}

namespace Class
{
    enum
    {
        Unclassified = 0x00,
        MassStorageController = 0x01,
        NetworkController = 0x02,
        DisplayController = 0x03,
        MultiMediaController = 0x04,
        MemoryController = 0x05,
        BridgeDevice = 0x06,
        SimpleCommunicationController = 0x07,
        BaseSystemPeripheral = 0x08,
        InputDeviceController = 0x09,
        DockingStation = 0x0A,
        Processor = 0x0B,
        SerialBusController = 0x0C,
        WirelessController = 0x0D,
        IntelligentController = 0x0E,
        SatelliteCommunicationController = 0x0F,
        EncryptionController = 0x10,
        SignalProcessingController = 0x11,
        ProcessingAccelerator = 0x12,
        NonEssentialInstrumentation = 0x13,
        CoProcessor = 0x40,
        UnassignedClass = 0xFF
    };
}

namespace Unclassified
{
    enum
    {
        NonVGACompatibleDevice = 0x00,
        VGACompatibleDevice = 0x01,
    };
}

namespace MassStorageController
{
    enum
    {
        SCSIBusController = 0x00,
        IDEControllerr = 0x01,
        FloppyDiskController = 0x02,
        IPIBusController = 0x03,
        RAIDController = 0x04,
        ATAController = 0x05,
        SerialATAController = 0x06,
        SerialAttachedSCSI = 0x07,
        NonVolatileMemoryController = 0x08,
        Other = 0x80,
    };
}

namespace NetworkController
{
    enum
    {
        EthernetController = 0x00,
        TokenRingController = 0x01,
        FDDIController = 0x02,
        ATMController = 0x03,
        ISDNController = 0x04,
        WorldFipController = 0x05,
        PICMG2_14MultiComputing = 0x06,
        InfinibandController = 0x07,
        FabricController = 0x08,
        Other = 0x80,
    };
}

namespace DisplayController
{
    enum
    {
        VGACompatibleController = 0x00,
        XGAController = 0x01,
        ThreeDController = 0x02, //Not VGA Compatible
        Other = 0x80,
    };
}

namespace MultiMediaController
{
    enum
    {
        MultiMediaVideoController = 0x00,
        MultiMediaAudioController = 0x01,
        ComputerTelephonyDevice = 0x02,
        AudioDevice = 0x03,
        Other = 0x80,
    };
}

namespace MemoryController
{
    enum
    {
        RAMController = 0x00,
        FlashController = 0x01,
        Other = 0x80,
    };
}

namespace BridgeDevice
{
    enum
    {
        HostBridge = 0x00,
        ISABridge = 0x01,
        EISABridge = 0x02,
        MCABridge = 0x03,
        PCItoPCIBridgeA = 0x04,
        PCMCIABridge = 0x05,
        NuBusBridge = 0x06,
        CardBusBridge = 0x07,
        RACEwayBridge = 0x08,
        PCItoPCIBridgeB = 0x09,
        InfiniBandToPCIHostBridge = 0x0A,
        Other = 0x80,
    };
}

namespace PreHeader
{
    enum
    {
        VendorId = 0x00,
        DeviceId = 0x02,
        Command = 0x04,
        Status = 0x06,
        RevisionId = 0x08,
        ProgIF = 0x09,
        SubClass = 0x0A,
        ClassCode = 0x0B,
        CacheLineSize = 0x0C,
        LatencyTimer = 0x0D,
        HeaderType = 0x0E,
        BIST = 0x0F,
    };
}

namespace Header0
{
    enum
    {
        BaseAddress0 = 0x10,
        BaseAddress1 = 0x14,
        BaseAddress2 = 0x18,
        BaseAddress3 = 0x1C,
        BaseAddress4 = 0x20,
        BaseAddress5 = 0x24,
        CarbusCISPointer = 0x28,
        SubsystemVendorId = 0x2C,
        SubsystemId = 0x2E,
        ExpansionROMBaseAddress = 0x30,
        CapabilitiesPointer = 0x34,
        Reserved1 = 0x35,
        Reserved2 = 0x38,
        InterruptLine = 0x3C,
        InterruptPIN = 0x3D,
        MinGrant = 0x3E,
        MaxLatency = 0x3F,
    };
}

namespace Header1
{
    enum
    {
        BaseAddress0 = 0x10,
        BaseAddress1 = 0x14,
        PrimaryBus = 0x18,
        SecondaryBus = 0x19,
        SubordinateBus = 0x1A,
        SecondaryLatencyTimer = 0x1B,
        IOBase = 0x1C,
        IOLimit = 0x1D,
        SecondaryStatus = 0x1E,
        MemoryBase = 0x20,
        MemoryLimit = 0x22,
        PrefetchableMemoryBase = 0x24,
        PrefetchableMemoryLimit = 0x26,
        PrefetchableBaseUpper32Bits = 0x28,
        PrefetchableLimitUpper32Bits = 0xC,
        IOBaseUpper16Bits = 30,
        IOLimitUpper16Bits = 32,
        CapabilitiesPointer = 0x34,
        Reserved = 0x35,
        ExpansionROMBaseAddress = 0x38,
        InterruptLine = 0x3C,
        InterruptPIN = 0x3D,
        BridgeControl = 0x3E,
    };
}

namespace Header2
{
    enum
    {
        CardBusSocketExCaBaseAddress = 0x10,
        CapabilitiesPointer = 0x14,
        Reserved = 0x15,
        SecondaryStatus = 0x16,
        PCIBusNumber = 0x18,
        CardBusBusNumber = 0x19,
        SubordinateBusNumber = 0x1A,
        CardBusLatencyTimer = 0x1B,
        MemoryBaseAddress0 = 0x1C,
        MemoryLimit0 = 0x20,
        MemoryBaseAddress1 = 0x24,
        MemoryLimit1 = 0x28,
        IOBaseAddress0 = 0x2C,
        IOLimit0 = 0x30,
        IOBaseAddress1 = 0x34,
        IOLimit1 = 0x38,
        InterruptLine = 0x3C,
        InterruptPIN = 0x3D,
        BridgeControl = 0x3E,
        SubsystemDeviceId = 0x40,
        SubsystemVendorId = 0x42,
        Legacy16bitPCCardModeBaseAddress = 0x44,
    };
}

namespace HeaderType
{
    enum
    {
        MultiFunction = 0x80,
        MultiFunctionMask = 0x7F,
        GeneralDevice = 0x00,
        PCItoPCI = 0x01,
        CardBus = 0x02,
    };
}

namespace Command
{
    enum
    {
        IOSpace =                       0x00000001, // I/O space. Controls device response to I/O SPACE accesses (VGA registers).
        IOSpaceDisable =                0x00000000, // disable the device response
        IOSpaceEnable =                 0x00000001, // enable the device response
        MemorySpace =                   0x00000002, // Memory space. Controls device response to memory accesses (EPROM, VGA frame
                                                    // buffer, MGA control aperture, MGA direct access aperture, and 8 MByte
                                                    // Pseudo-DMA window).
        MemorySpaceDisable =            0x00000000, // disable the device response
        MemorySpaceEnable =             0x00000002, // enable the device response
        BusMaster =                     0x00000004, // Bus master. Controls a device’s ability to act as a master on the PCI bus (used to
                                                    // access system memory)
        BusMasterDisable =              0x00000000, // prevents the device from generating PCI accesses
        BusMasterEnable =               0x00000004, // allows the device to behave as a bus master
        SpecialCycles =                 0x00000008, // If set to 1 the device can monitor Special Cycle operations; otherwise, the device will ignore them.
        SpecialCyclesDisable =          0x00000000, // Ignore special cycles
        SpecialCyclesEnable =           0x00000008, // Monitor special cycles

        WriteAndInvalidate =            0x00000010, // If set to 1 the device can generate the Memory Write and Invalidate command;
                                                    // otherwise, the Memory Write command must be used.
        WriteAndInvalidateDisable =     0x00000000, // Don't send write and invalidate commands
        WriteAndInvalidateEnable =      0x00000010, // Can send write and invalidate commands
        VGAPaletteSnoop =               0x00000020,
        VGAPaletteSnoopDisable =        0x00000000, // The device will treat palette write accesses like all other accesses.
        VGAPaletteSnoopEnable =         0x00000020, // The device does not respond to palette register writes and will snoop the data.
        ParityErrorResponse =           0x00000040,
        ParityErrorResponseDisable =    0x00000000, // When an error is detected, the device will set bit 15 of the Status register (Detected Parity Error Status Bit), but will not assert the PERR# (Parity Error) pin and will continue operation as normal.
        ParityErrorResponseEnable =     0x00000040, // If set to 1 the device will take its normal action when a parity error is detected.
        SERR =                          0x00000100,
        SERRDisable =                   0x00000000, // The SERR# driver is enabled
        SERREnable =                    0x00000100, // The SERR# driver is disabled
        FastBackToBack =                0x00000200,
        FastBackToBackDisable =         0x00000000, // Fast back-to-back transactions are only allowed to the same agent.
        FastBackToBackEnable =          0x00000200, // Allowed to generate fast back-to-back transactions.
        Interrupt =                     0x00000400,
        InterruptEnable =               0x00000000,
        InterruptDisable =              0x00000400  // The assertion of the devices INTx# signal is disabled.
    };
}

namespace Capability
{
    enum
    {
        PowerManagement = 0x01,
        AcceleratedGraphicsPort = 0x02,
        VitalProductData = 0x03,
        SlotIdentification = 0x04,
        MessageSignalledInterrupts = 0x05,
        CompactPCIHotSwap = 0x06,
        PCIX = 0x07,
        HyperTransport = 0x08,
        VendorSpecific = 0x09,
        DebugPort = 0x0A,
        CompactPCICentralResourceControl = 0x0B,
        PCIStandardHotPlugController = 0x0C,
        BridgeSubsystemVendorDeviceId = 0x0D,
        AGPTargetPCItoPCIBridge = 0x0E,
        PCIExpress = 0x10,
        MSIX = 0x11,
        PCIAdvancedFeatures = 0x13,
    };
}

namespace AGPStatus
{
    enum
    {
        X1 = 0x01,
        X2 = 0x02,
        X4 = 0x04,
        FastWrite = 0x10,
        Over4GB = 0x20,
        SideBandAddressing = 0x200,
    };
}

namespace AGPCommand
{
    enum
    {
        X1Enable = 0x01,
        X2Enable = 0x02,
        X4Enable = 0x04,
        FastWriteEnable = 0x10,
        Over4GBEnable = 0x20,
        AGPEnable = 0x100,
        SideBandAddressingEnable = 0x200,
    };
}

//Device_t bsf = Bus, Slot, Function

#ifndef MOCK
inline Register_t Read32(Device_t bsf, uint8_t offset)
{
    uint32_t address = (uint32_t(bsf) << 8) | uint32_t(offset & 0xFC) | uint32_t(0x80000000);
    SYS_WritePortDouble(Config::Address, address);
    return SYS_ReadPortDouble(Config::Data);
}
#else
extern Register_t Read32(Device_t bsf, uint8_t offset);
#endif

inline Register_t Read32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset)
{
    Device_t bsf = (Device_t(bus) << 8) | (Device_t(slot) << 3) | Device_t(func);
    return Read32(bsf, offset);
}

inline Register16_t Read16(Device_t bsf, uint8_t offset)
{
    uint32_t ret = Read32(bsf, offset);
    return Register16_t(ret >> ((offset & 2) << 3));
}

inline Register16_t Read16(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset)
{
    uint32_t ret = Read32(bus, slot, func, offset);
    return Register16_t(ret >> ((offset & 2) << 3));
}

inline Register8_t Read8(Device_t bsf, uint8_t offset)
{
    uint32_t ret = Read32(bsf, offset);
    return Register8_t(ret >> ((offset & 3) << 3));
}

inline Register8_t Read8(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset)
{
    uint32_t ret = Read32(bus, slot, func, offset);
    return Register8_t(ret >> ((offset & 3) << 3));
}

#ifndef MOCK
inline void Write32(Device_t bsf, uint8_t offset, Register_t value)
{
    uint32_t address = (uint32_t(bsf) << 8) | uint32_t(offset & 0xFC) | uint32_t(0x80000000);
    SYS_WritePortDouble(Config::Address, address);
    SYS_WritePortDouble(Config::Data, value);
}
#else
void Write32(Device_t bsf, uint8_t offset, Register_t value);
#endif

inline void Write32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset, Register_t value)
{
    Device_t bsf = (Device_t(bus) << 8) | (Device_t(slot) << 3) | Device_t(func);
    Write32(bsf, offset, value);
}

#ifndef MOCK
inline void Write16(Device_t bsf, uint8_t offset, Register16_t value)
{
    uint32_t address = (uint32_t(bsf) << 8) | uint32_t(offset & 0xFC) | uint32_t(0x80000000);
    SYS_WritePortDouble(Config::Address, address);
    SYS_WritePortShort(Config::Data + (offset & 0x02), value);
}
#else
extern void Write16(Device_t bsf, uint8_t offset, Register16_t value);
#endif

inline void Write16(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset, Register16_t value)
{
    Device_t bsf = (Device_t(bus) << 8) | (Device_t(slot) << 3) | Device_t(func);
    Write16(bsf, offset, value);
}

#ifndef MOCK
inline void Write8(Device_t bsf, uint8_t offset, Register8_t value)
{
    uint32_t address = (uint32_t(bsf) << 8) | uint32_t(offset & 0xFC) | uint32_t(0x80000000);
    SYS_WritePortDouble(Config::Address, address);
    SYS_WritePortByte(Config::Data + (offset & 0x03), value);
}
#else
extern void Write8(Device_t bsf, uint8_t offset, Register8_t value);
#endif

inline void Write8(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset, Register8_t value)
{
    Device_t bsf = (Device_t(bus) << 8) | (Device_t(slot) << 3) | Device_t(func);
    Write8(bsf, offset, value);
}

inline uint16_t GetVendorId(uint8_t bus, uint8_t slot, uint8_t function)
{
    return Read16(bus, slot, function, PreHeader::VendorId);
}

inline uint16_t GetDeviceId(uint8_t bus, uint8_t slot, uint8_t function)
{
    return Read16(bus, slot, function, PreHeader::DeviceId);
}

inline uint8_t GetClass(uint8_t bus, uint8_t device, uint8_t function)
{
    return Read8(bus, device, function, PreHeader::ClassCode);
}

inline uint8_t GetSubClass(uint8_t bus, uint8_t device, uint8_t function)
{
    return Read8(bus, device, function, PreHeader::SubClass);
}

inline uint8_t GetHeaderType(uint8_t bus, uint8_t device, uint8_t function)
{
    return Read8(bus, device, function, PreHeader::HeaderType);
}

inline uint16_t GetHeader0SubsystemVendorId(uint8_t bus, uint8_t device, uint8_t function)
{
    return Read16(bus, device, function, Header0::SubsystemVendorId);
}

inline uint16_t GetHeader0SubsystemId(uint8_t bus, uint8_t device, uint8_t function)
{
    return Read16(bus, device, function, Header0::SubsystemId);
}

inline uint8_t GetHeader1SecondaryBus(uint8_t bus, uint8_t device, uint8_t function)
{
    return Read8(bus, device, function, Header1::SecondaryBus);
}

typedef bool (*ScanBusCallback_t)(uint8_t bus, uint8_t slot, uint8_t function, void* context);

extern void ScanBus(uint8_t bus, ScanBusCallback_t callback, void* context);

extern bool FindDevice(uint16_t vendorId, uint16_t deviceId, uint8_t& bus, uint8_t& slot, uint8_t& function);

inline bool FindDevice(uint16_t vendorId, uint16_t deviceId, Device_t& bsf)
{
    bool ret = false;
    uint8_t bus = 0;
    uint8_t slot = 0;
    uint8_t function = 0;
    if (FindDevice(vendorId, deviceId, bus, slot, function))
    {
        bsf = (Device_t(bus) << 8) | (Device_t(slot) << 3) | Device_t(function);
        ret = true; 
    }

    return ret;
}

}
