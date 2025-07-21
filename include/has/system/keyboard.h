//Copyright 2025-Present riplin

#pragma once

#include <functional>
#include <has/types.h>
#include <has/system/sysasm.h>

namespace Has::System::KB
{

typedef uint16_t ScanCode_t;
    
namespace ScanCodeSet1
{
    enum
    {
        PressStatus =                   0x0080,
        Pressed =                       0x0000,
        Released =                      0x0080,

        Escape =                        0x0001,
        One =                           0x0002,
        Two =                           0x0003,
        Three =                         0x0004,
        Four =                          0x0005,
        Five =                          0x0006,
        Six =                           0x0007,
        Seven =                         0x0008,
        Eight =                         0x0009,
        Nine =                          0x000A,
        Zero =                          0x000B,
        Minus =                         0x000C,
        Equals =                        0x000D,
        Backspace =                     0x000E,
        Tab =                           0x000F,
        Q =                             0x0010,
        W =                             0x0011,
        E =                             0x0012,
        R =                             0x0013,
        T =                             0x0014,
        Y =                             0x0015,
        U =                             0x0016,
        I =                             0x0017,
        O =                             0x0018,
        P =                             0x0019,
        BracketOpen =                   0x001A,
        BracketClose =                  0x001B,
        Enter =                         0x001C,
        ControlLeft =                   0x001D,
        A =                             0x001E,
        S =                             0x001F,
        D =                             0x0020,
        F =                             0x0021,
        G =                             0x0022,
        H =                             0x0023,
        J =                             0x0024,
        K =                             0x0025,
        L =                             0x0026,
        Semicolon =                     0x0027,
        SingleQuote =                   0x0028,
        BackTick =                      0x0029,
        ShiftLeft =                     0x002A,
        Backslash =                     0x002B,
        Z =                             0x002C,
        X =                             0x002D,
        C =                             0x002E,
        V =                             0x002F,
        B =                             0x0030,
        N =                             0x0031,
        M =                             0x0032,
        Comma =                         0x0033,
        Period =                        0x0034,
        Forwardslash =                  0x0035,
        ShiftRight =                    0x0036,
        KeypadAsterisk =                0x0037,
        AltLeft =                       0x0038,
        Spacebar =                      0x0039,
        CapsLock =                      0x003A,
        F1 =                            0x003B,
        F2 =                            0x003C,
        F3 =                            0x003D,
        F4 =                            0x003E,
        F5 =                            0x003F,
        F6 =                            0x0040,
        F7 =                            0x0041,
        F8 =                            0x0042,
        F9 =                            0x0043,
        F10 =                           0x0044,
        NumberLock =                    0x0045,
        ScrollLock =                    0x0046,
        KeypadSeven =                   0x0047,
        KeypadEight =                   0x0048,
        KeypadNine =                    0x0049,
        KeypadMinus =                   0x004A,
        KaypadFour =                    0x004B,
        KeypadFive =                    0x004C,
        KeypadSix =                     0x004D,
        KeypadPlus =                    0x004E,
        KeypadOne =                     0x004F,
        KeypadTwo =                     0x0050,
        KeypadThree =                   0x0051,
        KeypadZero =                    0x0052,
        KeypadPeriod =                  0x0053,
        F11 =                           0x0057,
        F12 =                           0x0058,
        MultiMediaPreviousTrack =       0xE010,
        MultiMediaNextTrack =           0xE019,
        KeypadEnter =                   0xE01C,
        ControlRight =                  0xE01D,
        MultiMediaMute =                0xE020,
        MultiMediaCalculator =          0xE021,
        MultiMediaPlay =                0xE022,
        MultiMediaStop =                0xE024,
        MultiMediaVolumeDown =          0xE02E,
        MultiMediaVolumeUp =            0xE030,
        MultiMediaWWWHome =             0xE032,
        KeypadForwardslash =            0xE035,
        AltRight =                      0xE038,
        Home =                          0xE047,
        CursorUp =                      0xE048,
        PageUp =                        0xE049,
        CursorLeft =                    0xE04B,
        CursorRight =                   0xE04D,
        End =                           0xE04F,
        CursorDown =                    0xE050,
        PageDown =                      0xE051,
        Insert =                        0xE052,
        Delete =                        0xE053,
        GUILeft =                       0xE05B,
        GUIRight =                      0xE05C,
        Apps =                          0xE05D,
        ACPIPower =                     0xE05E,
        ACPISleep =                     0xE05F,
        ACPIWake =                      0xE063,
        MultiMediaWWWSearch =           0xE065,
        MultiMediaWWWFavorites =        0xE066,
        MultiMediaWWWRefresh =          0xE067,
        MultiMediaWWWStop =             0xE068,
        MultiMediaWWWForward =          0xE069,
        MultiMediaWWWBack =             0xE06A,
        MultiMediaMyComputer =          0xE06B,
        MultiMediaEmail =               0xE06C,
        MultiMediaMediaSelect =         0xE06D,
        PrintScreenPart1 =              0xE02A,
        PrintScreenPart2 =              0xE037,
        PrintScreen =                   PrintScreenPart2,   //Just respond to this. Ignore the first part.

        // Full sequence is 0xE1, 0x1D, 0x45 for "press", immediately followed by
        // 0xE1, 0x9D, 0xC5 as a release. 0xE01D = ControlRight, so we just drop the middle byte and use 0xE045 instead.
        // If we assume that 0xEx = extended where x = number of bytes minus one, then it loads fine.
        Pause =                         0xE045,

        Extended =                      0xE0,
    };
}

typedef std::function<void(ScanCode_t scanCode)> ScanCodeHandler_t; //Make sure this function is mean and lean!
extern void SetScanCodeHandler(const ScanCodeHandler_t& scanCodeHandler);

extern void InstallKeyboardHandler();
extern void RemoveKeyboardHandler();

namespace Register
{
    enum
    {
        Data = 0x60,
        PortB = 0x61,
        PortXT = 0x62,
        Status = 0x64,
    };
}

typedef uint8_t Register_t;

inline uint8_t Read(Register_t reg) { return SYS_ReadPortByte(reg); }
inline void Write(Register_t reg, uint8_t value) { SYS_WritePortByte(reg, value); }

typedef uint8_t PortB_t;
namespace PortBCommand
{
    enum
    {
        Timer2GateSpeakerEnable = 0x01,
        SpeakerEnable = 0x02,
        RamParityCheckDisable = 0x04,
        IOChanParityCheckDisable = 0x08,
        IRQ1Reset = 0x80
    };

    inline PortB_t Read() { return KB::Read(Register::PortB); }
    inline void Write(PortB_t value) { KB::Write(Register::PortB, value); }
}

namespace PortBStatus
{
    enum
    {
        Timer2ClkGateSpeakerStatus = 0x01,
        SpeakerStatus = 0x02,
        NMIParityCheckStatus = 0x04,
        NMIIOChanCheckStatus = 0x08,
        LowerNibbleMask = 0x0f,
        ToggleRefreshRequest = 0x10,
        MirrorTimer2OutputCond = 0x20,
        IOChannelParityError = 0x40,
        RAMParityError = 0x80
    };

    inline PortB_t Read() { return KB::Read(Register::PortB); }
}

// 0060 RW  KB controller data port or keyboard input buffer (ISA, EISA)
// 	        should only be read from after status port bit0 = 1
// 	        should only be written to if status port bit1 = 0

typedef uint8_t Data_t;
namespace Data
{
    inline Data_t Read() { return KB::Read(Register::Data); }
}

// 0064  R-  keyboard controller read status (see #P0398,#P0399,#P0400)

// Bitfields for keyboard controller read status (ISA, EISA):
// Bit(s)       Description	(Table P0398)
//  7           parity error on transmission from keyboard
//  6           receive timeout
//  5           transmit timeout
//  4           keyboard interface inhibited by keyboard lock
//              or by password server mode (IBM PS/2-286 [model bytes FCh/09h],
//              "Tortuga" [model F8h/19h]) (see #00515 at INT 15/AH=C0h)
//  3           = 1 data written to input register is command (PORT 0064h)
//              = 0 data written to input register is data (PORT 0060h)
//  2           system flag status: 0=power up or reset	 1=selftest OK
//  1           input buffer full (input 60/64 has data for 8042)
// 	            no write access allowed until bit clears
//  0           output buffer full (output 60 has data for system)
// 	            bit is cleared after read access
// SeeAlso: PORT 0064h-R,#P0399,#P0400,#P0401

typedef uint8_t Status_t;
namespace Status
{
    enum
    {
        OutputFull = 0x01,
        InputFull = 0x02,
        SystemFlagStatus = 0x04,
        PowerUp = 0x00,
        SelfTestOk = 0x04,
        DataType = 0x08,
        DataIsData = 0x00,
        DataIsCommand = 0x08,
        KeyboardState = 0x10,
        KeyboardUnlocked = 0x00,
        KeyboardLocked = 0x10,
        TransmitStatus = 0x20,
        TransmitOk = 0x00,
        TransmitTimeout = 0x20,
        ReceiveStatus = 0x40,
        ReceiveOk = 0x00,
        ReceiveTimeout = 0x40,
        ParityStatus = 0x80,
        ParityOk = 0x00,
        ParityError = 0x80
    };
}

}