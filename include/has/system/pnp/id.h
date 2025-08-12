//Copyright 2025-Present riplin

#pragma once

#include <has/types.h>

namespace Has::System::PnP
{

typedef uint32_t Identifier_t;
namespace Identifier
{
    inline constexpr uint32_t CodeToUint32(const char code[8])
    {
        return uint32_t(((uint8_t(code[0]) - 0x40) << 2) |
        (((uint8_t(code[1]) - 0x40) >> 3) & 0x03)) |
        (uint32_t(uint8_t(code[1] - 0x40) & 0x07) << 13) |
        (uint32_t((uint8_t(code[2]) - 0x40) & 0x1F) << 8) |
        (uint32_t(uint8_t(code[3] - '0')) << 20) |
        (uint32_t(uint8_t(code[4] - '0')) << 16) |
        (uint32_t(uint8_t(code[5] - '0')) << 28) |
        (uint32_t(uint8_t(code[6] - '0')) << 24);
    }

#define PNP_CONVERTCODE(Code) Code = CodeToUint32(#Code)

    enum
    {
        PNP_CONVERTCODE(ABP0174),   // AdvanSys ABP742 SCSI Controller
        PNP_CONVERTCODE(ABP0175),   // AdvanSys ABP752 Dual-Channel SCSI Controller
        PNP_CONVERTCODE(ABP5401),   // AdvanSys PnP ISA SCSI Host
        PNP_CONVERTCODE(ABP7401),   // AdvanSys EISA SCSI Host
        PNP_CONVERTCODE(ABP7501),   // AdvanSys EISA SCSI Host
        PNP_CONVERTCODE(ACC1660),   // Accton EN166x
        PNP_CONVERTCODE(ACU0101),   // Acculogic EISApport SCSI
        PNP_CONVERTCODE(ADI0730),   // ADI MicroScan 4V
        PNP_CONVERTCODE(ADI0C50),   // ADI MicroScan 5V+ TCO
        PNP_CONVERTCODE(ADP0000),   // Adaptec AHA-1740 SCSI Host Adapter (Early Revision)
        PNP_CONVERTCODE(ADP0001),   // Adaptec AHA-1740A/1742A SCSI Host Adapter (without floppy)
        PNP_CONVERTCODE(ADP0002),   // Adaptec AHA-1742A SCSI Host Adapter (with floppy)
        PNP_CONVERTCODE(ADP0100),   // Adaptec AHA-1540/1542 ISA SCSI Host Adapter
        PNP_CONVERTCODE(ADP0400),   // Adaptec AHA-1744 Differential SCSI Host Adapter
        PNP_CONVERTCODE(ADP1502),   // Adaptec AVA-1502 SCSI Host
        PNP_CONVERTCODE(ADP1505),   // Adaptec AVA-1505 SCSI Host
        PNP_CONVERTCODE(ADP1510),   // Adaptec AHA-1510 SCSI Host
        PNP_CONVERTCODE(ADP1515),   // Adaptec AVA-1515 SCSI Host
        PNP_CONVERTCODE(ADP1520),   // Adaptec AHA-152X/AHA-1510 SCSI Host
        PNP_CONVERTCODE(ADP1522),   // Adaptec AIC-6X60 PnP SCSI Host
        PNP_CONVERTCODE(ADP1532),   // Adaptec AIC-6X60 P&P SCSI Host
        PNP_CONVERTCODE(ADP1540),   // Adaptec AHA-154X/AHA-164X/AHA-1535 SCSI Host
        PNP_CONVERTCODE(ADP1542),   // Adaptec AHA-154X/AHA-1535 PnP SCSI Host
        PNP_CONVERTCODE(ADP1740),   // Adaptec AHA-174X EISA SCSI Host
        PNP_CONVERTCODE(ADP2015),   // Adaptec AHA-152X/AHA-1510 SCSI Host
        PNP_CONVERTCODE(ADP2215),   // Adaptec AIC-6X60 P&P SCSI Host
        PNP_CONVERTCODE(ADP2840),   // Adaptec AHA-284X VESA SCSI Host
        PNP_CONVERTCODE(ADP3015),   // Adaptec AIC-6X60 P&P SCSI Host
        PNP_CONVERTCODE(ADP3215),   // Adaptec AIC-6X60 P&P SCSI Host
        PNP_CONVERTCODE(ADP6360),   // Adaptec AIC-6X60 ISA Single-Chip SCSI
        PNP_CONVERTCODE(ADP7770),   // Adaptec AIC-777X EISA SCSI Host
        PNP_CONVERTCODE(ADP7771),   // Adaptec AIC-7770 (AHA-274X) EISA SCSI Host
        PNP_CONVERTCODE(ADP7880),   // Adaptec AIC-7880 SCSI Host
        PNP_CONVERTCODE(ADV55AA),   // AMD PCNET Family Ethernet/ISA+
        PNP_CONVERTCODE(AEI0218),   // Actiontec PCMCIA Adapter
        PNP_CONVERTCODE(ALI1489),   // ALI EIDE Controller
        PNP_CONVERTCODE(AMI15D1),   // AMI Series-15 Host/A BIOS 1.10
        PNP_CONVERTCODE(AMI15E1),   // AMI Series-15 Host/A BIOS 1.20+
        PNP_CONVERTCODE(AMI16B1),   // AMI Enterprise II
        PNP_CONVERTCODE(AMI2509),   // AMI Enterprise I
        PNP_CONVERTCODE(AMI25B1),   // AMI Enterprise I Rev-B
        PNP_CONVERTCODE(AMI28A1),   // AMI EZ-Flex Base Board
        PNP_CONVERTCODE(AMI44C1),   // AMI Series-44 Host/A BIOS 1.10
        PNP_CONVERTCODE(AMI44D1),   // AMI Series-44 Host/A BIOS 1.20+
        PNP_CONVERTCODE(AMI44D2),   // AMI Series-441 Host/A BIOS 1.20+
        PNP_CONVERTCODE(AMI46E1),   // AMI FastView
        PNP_CONVERTCODE(AMI4801),   // AMI Series-48 Host/A
        PNP_CONVERTCODE(AMI64A1),   // AMI Baby EISA
        PNP_CONVERTCODE(AMI68B1),   // AMI Enterprise III
        PNP_CONVERTCODE(AMI7001),   // AMI Series-70 Host/A
        PNP_CONVERTCODE(AMI87A1),   // AMI Enterprise IV
        PNP_CONVERTCODE(ANS1001),   // Ansel Communications AC3200 EISA Ethernet
        PNP_CONVERTCODE(AOCA566),   // AOC SPECTRUM 5Nlr
        PNP_CONVERTCODE(AOCA782),   // AOC SPECTRUM 7Nlr
        PNP_CONVERTCODE(AOCC346),   // AOC SPECTRUM 4N/4Nlr
        PNP_CONVERTCODE(AOCC564),   // AOC SPECTRUM 5Llr/5LlrA
        PNP_CONVERTCODE(AOCD350),   // AOC SPECTRUM 4V/4VA/4Vlr/4VlrA
        PNP_CONVERTCODE(AOCD566),   // AOC SPECTRUM 5Vlr/5VlrA
        PNP_CONVERTCODE(AOCE570),   // AOC SPECTRUM 5Glr
        PNP_CONVERTCODE(AOCE750),   // AOC SPECTRUM 7Dlr/7DlrA
        PNP_CONVERTCODE(AOCF764),   // AOC SPECTRUM 7Clr
        PNP_CONVERTCODE(APA1460),   // Adaptec APA-1460 SCSI Host
        PNP_CONVERTCODE(APC0001),   // APC Back-UPS Pro
        PNP_CONVERTCODE(API0037),   // AcerView 55
        PNP_CONVERTCODE(API440B),   // AcerView 11D
        PNP_CONVERTCODE(API4421),   // AcerView 33D
        PNP_CONVERTCODE(API4522),   // AcerView 7134e
        PNP_CONVERTCODE(API4536),   // AcerView 7154e
        PNP_CONVERTCODE(API4538),   // AcerView 7156e
        PNP_CONVERTCODE(API454C),   // AcerView 7176ie
        PNP_CONVERTCODE(API454E),   // AcerView 7178ie
        PNP_CONVERTCODE(API4938),   // AcerView 7156i
        PNP_CONVERTCODE(API494C),   // AcerView 76i
        PNP_CONVERTCODE(API494E),   // AcerView 78i
        PNP_CONVERTCODE(API4962),   // AcerView 98i
        PNP_CONVERTCODE(API4C21),   // AcerView 33DL
        PNP_CONVERTCODE(API4C22),   // AcerView 34TL
        PNP_CONVERTCODE(API4C37),   // AcerView 55L
        PNP_CONVERTCODE(API4C38),   // AcerView 56L
        PNP_CONVERTCODE(API4E4C),   // AcerView 76N
        PNP_CONVERTCODE(API5321),   // AcerView 7133s
        PNP_CONVERTCODE(API5322),   // AcerView 7134s
        PNP_CONVERTCODE(API5336),   // AcerView 7154s
        PNP_CONVERTCODE(API5338),   // AcerView 7156s
        PNP_CONVERTCODE(API534C),   // AcerView 7176is
        PNP_CONVERTCODE(API5422),   // AcerView 34T
        PNP_CONVERTCODE(ARC0010),   // Alta EtherTPI/Combo
        PNP_CONVERTCODE(ARC0020),   // Alta TokenCombo-16 S/U
        PNP_CONVERTCODE(ASC1000),   // AdvanSys VL SCSI Host
        PNP_CONVERTCODE(AST8001),   // ASTVision 4V
        PNP_CONVERTCODE(AST8002),   // ASTVision 4I
        PNP_CONVERTCODE(AST8003),   // ASTVision 4N
        PNP_CONVERTCODE(AST8004),   // ASTVision 4L
        PNP_CONVERTCODE(AST8005),   // ASTVision 5L
        PNP_CONVERTCODE(AST8006),   // ASTVision 7L
        PNP_CONVERTCODE(AST8007),   // ASTVision 7H
        PNP_CONVERTCODE(AST8008),   // ASTVision 20H
        PNP_CONVERTCODE(AST8009),   // AST Sabre
        PNP_CONVERTCODE(AST800A),   // ASTVision 5V
        PNP_CONVERTCODE(ATI1C10),   // ATI VGA Wonder XL24
        PNP_CONVERTCODE(ATI3010),   // ATI Graphics Ultra
        PNP_CONVERTCODE(ATI4400),   // ATI Graphics Ultra
        PNP_CONVERTCODE(ATI4402),   // ATI Graphics Ultra Pro (Mach32)
        PNP_CONVERTCODE(ATI4410),   // ATI Graphics Ultra Pro
        PNP_CONVERTCODE(ATI5810),   // ATI GRAPHICS PRO TURBO
        PNP_CONVERTCODE(ATK1500),   // Allied Telesyn AT1510 Ethernet
        PNP_CONVERTCODE(AZT1605),   // Aztech Sound Galaxy Nova 16
        PNP_CONVERTCODE(AZT1608),   // Aztech Sound Galaxy Pro 16
        PNP_CONVERTCODE(AZT2316),   // Aztech Sound Galaxy Washington 16
        PNP_CONVERTCODE(BRI0200),   // Boca Complete Office Communicator (audio)
        PNP_CONVERTCODE(BRI0A49),   // Boca Complete Office Communicator 14.4
        PNP_CONVERTCODE(BRI1001),   // Boca Research BOCALANcard
        PNP_CONVERTCODE(BUS0042),   // BusLogic MultiMaster SCSI Host
        PNP_CONVERTCODE(BUS4201),   // BusLogic MultiMaster EISA SCSI Host
        PNP_CONVERTCODE(CON0071),   // CONTEC C-NET(AT)P Adapter
        PNP_CONVERTCODE(CON0072),   // CONTEC C-NET(AT)P Adapter
        PNP_CONVERTCODE(CPL05F4),   // Compal 562DU
        PNP_CONVERTCODE(CPQ0011),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0012),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0013),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0014),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0015),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0016),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0017),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0018),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0019),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ001A),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0020),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0021),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0022),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0023),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0024),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0025),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0026),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0027),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0028),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0029),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ002A),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ002B),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ002C),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ002D),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ002E),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ002F),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0030),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0031),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0032),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0033),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0040),   // Compaq QVision 172
        PNP_CONVERTCODE(CPQ0041),   // Compaq QVision 172
        PNP_CONVERTCODE(CPQ0042),   // Compaq QVision 172
        PNP_CONVERTCODE(CPQ0043),   // Compaq QVision 200
        PNP_CONVERTCODE(CPQ0044),   // Compaq QVision 200
        PNP_CONVERTCODE(CPQ0045),   // Compaq QVision 200
        PNP_CONVERTCODE(CPQ0046),   // Compaq QVision 200
        PNP_CONVERTCODE(CPQ0047),   // Compaq QVision 200
        PNP_CONVERTCODE(CPQ0048),   // Compaq QVision 200
        PNP_CONVERTCODE(CPQ0049),   // Compaq QVision 200
        PNP_CONVERTCODE(CPQ0100),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0146),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0147),   // Compaq 1024
        PNP_CONVERTCODE(CPQ0346),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0347),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0348),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0349),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ034A),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ034B),   // Compaq 151FS
        PNP_CONVERTCODE(CPQ0546),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0547),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0548),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0549),   // Compaq 171FS
        PNP_CONVERTCODE(CPQ0746),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0747),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0846),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0847),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0848),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0849),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ084A),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ084B),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ084C),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ084D),   // Compaq Presario 140
        PNP_CONVERTCODE(CPQ0946),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0947),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0948),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0949),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0A46),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0A47),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0A48),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0A49),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0A4A),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0A4B),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0A4C),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0A4D),   // Compaq Presario 150
        PNP_CONVERTCODE(CPQ0D46),   // Compaq 140
        PNP_CONVERTCODE(CPQ0D47),   // Compaq 140
        PNP_CONVERTCODE(CPQ0D48),   // Compaq 140
        PNP_CONVERTCODE(CPQ0D49),   // Compaq 140
        PNP_CONVERTCODE(CPQ0D4A),   // Compaq 140
        PNP_CONVERTCODE(CPQ0D4B),   // Compaq 140
        PNP_CONVERTCODE(CPQ0D4C),   // Compaq 140
        PNP_CONVERTCODE(CPQ0D4D),   // Compaq 140
        PNP_CONVERTCODE(CPQ0F46),   // Compaq 150
        PNP_CONVERTCODE(CPQ0F47),   // Compaq 150
        PNP_CONVERTCODE(CPQ0F48),   // Compaq 150
        PNP_CONVERTCODE(CPQ0F49),   // Compaq 150
        PNP_CONVERTCODE(CPQ0F4A),   // Compaq 150
        PNP_CONVERTCODE(CPQ0F4B),   // Compaq 150
        PNP_CONVERTCODE(CPQ0F4C),   // Compaq 150
        PNP_CONVERTCODE(CPQ0F4D),   // Compaq 150
        PNP_CONVERTCODE(CPQ3001),   // Compaq EISA Advanced VGA (AVGA)
        PNP_CONVERTCODE(CPQ3011),   // Compaq QVision 1024/E
        PNP_CONVERTCODE(CPQ3111),   // Compaq QVision 1024/E
        PNP_CONVERTCODE(CPQ3112),   // Compaq QVision 1280/E
        PNP_CONVERTCODE(CPQ3122),   // Compaq QVision 1280/I
        PNP_CONVERTCODE(CPQ4300),   // Compaq Advanced ESDI
        PNP_CONVERTCODE(CPQ4410),   // Compaq Integrated 32-Bit Fast-SCSI-2
        PNP_CONVERTCODE(CPQ4411),   // Compaq EISA 32-Bit Fast-SCSI-2
        PNP_CONVERTCODE(CPQ4430),   // Compaq Integrated 32-Bit Fast-Wide SCSI-2/E
        PNP_CONVERTCODE(CPQ4431),   // Compaq 32-Bit Fast-Wide SCSI-2/E
        PNP_CONVERTCODE(CPQ6001),   // Compaq DualSpeed Token Ring (32-bit)
        PNP_CONVERTCODE(CPQ6002),   // Compaq NetFlex-2 TR
        PNP_CONVERTCODE(CPQ6100),   // Compaq NetFlex ENET/TR
        PNP_CONVERTCODE(CPQ6101),   // Compaq NetFlex-2 ENET/TR
        PNP_CONVERTCODE(CPQ6200),   // Compaq NetFlex-2 DualPort Ethernet
        PNP_CONVERTCODE(CPQ6300),   // Compaq NetFlex-2 DualPort Token-Ring
        PNP_CONVERTCODE(CPQ9A83),   // Compaq Deskpro XL Processor Board
        PNP_CONVERTCODE(CPQA050),   // Compaq SCSI Controller
        PNP_CONVERTCODE(CPQA060),   // Compaq Elite Ethernet
        PNP_CONVERTCODE(CPQA090),   // Compaq SmartStation
        PNP_CONVERTCODE(CPQA0A0),   // Compaq MiniStation/EN
        PNP_CONVERTCODE(CPQA0B0),   // Compaq MiniStation/TR
        PNP_CONVERTCODE(CPQA0D2),   // Compaq Modem Audio
        PNP_CONVERTCODE(CPQA0D4),   // Compaq Modem Audio
        PNP_CONVERTCODE(CPQA0D5),   // Compaq Audio
        PNP_CONVERTCODE(CPQA0D6),   // Compaq Presario Bezel Volume Control
        PNP_CONVERTCODE(CPQA0D7),   // Compaq Enhanced Keyboard
        PNP_CONVERTCODE(CPQA0D8),   // Compaq PS/2 Port Mouse
        PNP_CONVERTCODE(CPQA0D9),   // Compaq Communications Port
        PNP_CONVERTCODE(CPQA0DA),   // Compaq IDE Controller
        PNP_CONVERTCODE(CPQA0DB),   // Compaq Floppy Disk Controller
        PNP_CONVERTCODE(CPQA0DE),   // Compaq PCMCIA Controller
        PNP_CONVERTCODE(CPQA0DF),   // Compaq Notebook Display (WD)
        PNP_CONVERTCODE(CPQA0E0),   // Compaq ECP Printer Port
        PNP_CONVERTCODE(CPQA0E1),   // Compaq TV Tuner
        PNP_CONVERTCODE(CPQA0E2),   // Compaq TV Tuner
        PNP_CONVERTCODE(CPQA0E3),   // Compaq Contura Integrated Ethernet
        PNP_CONVERTCODE(CPQA0E4),   // Compaq Modem Audio
        PNP_CONVERTCODE(CPQAE08),   // Compaq Deskpro Thermal Sensor
        PNP_CONVERTCODE(CPQAE3D),   // Compaq Touchpad Mouse (PS/2 Mouse)
        PNP_CONVERTCODE(CPQF120),   // Compaq NetFlex-3/E Early Modular
        PNP_CONVERTCODE(CPQF140),   // Compaq NetFlex-3/E Modular
        PNP_CONVERTCODE(CPQFA1B),   // Compaq Deskpro 486/50 System Memory Board
        PNP_CONVERTCODE(CPQFD17),   // Compaq SCSI Tape Adapter
        PNP_CONVERTCODE(CPX0301),   // Compex ENET100-VG4 LAN Card
        PNP_CONVERTCODE(CRD0001),   // MVP288IV 28800bps
        PNP_CONVERTCODE(CRD0005),   // MVP144IV2 14400bps
        PNP_CONVERTCODE(CRD1001),   // MVP288XV 28800bps
        PNP_CONVERTCODE(CRD1005),   // MVP144XV2 14400bps
        PNP_CONVERTCODE(CRS3200),   // Cisco C320T FDDI EISA Network Adapter
        PNP_CONVERTCODE(CRS3204),   // Cisco CDDI/FDDI Network Adapter
        PNP_CONVERTCODE(CRX0001),   // Cyrix MediaGX
        PNP_CONVERTCODE(CSC0000),   // Crystal PnP Audio System CODEC
        PNP_CONVERTCODE(CSC0001),   // Crystal PnP Audio System Joystick
        PNP_CONVERTCODE(CSC0002),   // Crystal CS4232 Support Registers
        PNP_CONVERTCODE(CSC0003),   // Crystal PnP Audio System MPU-401
        PNP_CONVERTCODE(CSC0010),   // Crystal PnP Audio System Control Registers
        PNP_CONVERTCODE(CSCFFFF),   // Crystal PnP Audio System CODEC
        PNP_CONVERTCODE(CSI0600),   // Cabletron Systems CSI F70xx EISA FDDI Adapter Card
        PNP_CONVERTCODE(CSI0690),   // Cabletron Systems CSI F70X9 EISA FDDI DNI Adapter Card
        PNP_CONVERTCODE(CSI2201),   // Cabletron DNI series E2200
        PNP_CONVERTCODE(CSI2202),   // Cabletron DNI series E2200
        PNP_CONVERTCODE(CSI2203),   // Cabletron DNI series E2200
        PNP_CONVERTCODE(CTL0001),   // Creative Labs SB16
        PNP_CONVERTCODE(CTL0021),   // Creative Labs AWE32
        PNP_CONVERTCODE(CTL0022),   // Creative Labs AWE64 16-bit Audio
        PNP_CONVERTCODE(CTL0023),   // Creative Labs AWE64 Gold
        PNP_CONVERTCODE(CTL0024),   // Creative Labs AWE64
        PNP_CONVERTCODE(CTL0031),   // Creative Labs SB16
        PNP_CONVERTCODE(CTL0041),   // Creative Labs Audio Device (V16CL/V32D/V32G)
        PNP_CONVERTCODE(CTL0042),   // Creative Labs AWE64 WaveTable MIDI
        PNP_CONVERTCODE(CTL0043),   // Creative Labs SB16
        PNP_CONVERTCODE(CTL0044),   // Creative Labs AWE64 Gold
        PNP_CONVERTCODE(CTL0045),   // Creative Labs AWE64 16-bit Audio
        PNP_CONVERTCODE(CTL0046),   // Creative Labs AWE64 16-bit Audio
        PNP_CONVERTCODE(CTL0047),   // Creative Labs SB16
        PNP_CONVERTCODE(CTL0051),   // Creative Labs 3D Stereo Enhancement
        PNP_CONVERTCODE(CTL0070),   // Creative Labs ViBRA16C
        PNP_CONVERTCODE(CTL009D),   // Creative Labs SB AWE64
        PNP_CONVERTCODE(CTL009E),   // Creative Labs SB AWE64 Gold
        PNP_CONVERTCODE(CTL00C3),   // Creative Labs SB AWE64
        PNP_CONVERTCODE(CTL00E4),   // Creative Labs SB AWE64
        PNP_CONVERTCODE(CTL00F0),   // Creative Labs SB Vibra16X
        PNP_CONVERTCODE(CTL1000),   // Creative Labs 3D Blaster
        PNP_CONVERTCODE(CTL1003),   // Creative Labs 3D Blaster
        PNP_CONVERTCODE(CTL1004),   // Creative Labs 3D Blaster
        PNP_CONVERTCODE(CTL1005),   // Creative Labs 3D Blaster
        PNP_CONVERTCODE(CTL1006),   // Creative Labs 3D Blaster
        PNP_CONVERTCODE(CTL2001),   // Creative Labs IDE Interface
        PNP_CONVERTCODE(CTL2002),   // Creative Labs IDE CD-ROM Drive
        PNP_CONVERTCODE(CTL2011),   // Creative Labs IDE CD-ROM Drive
        PNP_CONVERTCODE(CTL7001),   // Creative Labs Joystick Controller
        PNP_CONVERTCODE(CTL7002),   // Creative Labs Programmable Game Port
        PNP_CONVERTCODE(CTL7005),   // Creative Labs Programmable Game Port
        PNP_CONVERTCODE(CTL8001),   // Creative Labs Legacy SoundBlaster Device
        PNP_CONVERTCODE(CTL9011),   // Creative Labs RT300 Video Blaster
        PNP_CONVERTCODE(CTX1451),   // CTX 1451
        PNP_CONVERTCODE(CTX1551),   // CTX 1551
        PNP_CONVERTCODE(CTX1562),   // CTX 1562
        PNP_CONVERTCODE(CTX1565),   // CTX 1565
        PNP_CONVERTCODE(CTX1765),   // CTX 1765
        PNP_CONVERTCODE(CTX1785),   // CTX 1785
        PNP_CONVERTCODE(CTX2085),   // CTX 2085
        PNP_CONVERTCODE(CTX2185),   // CTX 2185
        PNP_CONVERTCODE(DBK0000),   // Databook ISA PCMCIA Controller
        PNP_CONVERTCODE(DBK0204),   // Databook PnP PCMCIA based on DB86084
        PNP_CONVERTCODE(DBK0214),   // Databook PnP PCMCIA based on DB86184
        PNP_CONVERTCODE(DBK0402),   // Databook PnP PCMCIA based on DB86084
        PNP_CONVERTCODE(DBK1402),   // Databook PnP PCMCIA based on DB86184
        PNP_CONVERTCODE(DEC20A0),   // Digital Ethernet (DE203/DE204/DE205)
        PNP_CONVERTCODE(DEC3001),   // DEC FDDI Controller
        PNP_CONVERTCODE(DEC3002),   // DEC FDDI Controller
        PNP_CONVERTCODE(DEC4250),   // DEC DE425
        PNP_CONVERTCODE(DEL0001),   // Deltec UPS
        PNP_CONVERTCODE(DEL139A),   // Dell Ultrascan 14XE
        PNP_CONVERTCODE(DEL139B),   // Dell Ultrascan 14XE
        PNP_CONVERTCODE(DEL139C),   // Dell Ultrascan 14XE
        PNP_CONVERTCODE(DEL139D),   // Dell Ultrascan 14XE
        PNP_CONVERTCODE(DEL2210),   // Dell Ultrascan V17X
        PNP_CONVERTCODE(DEL2211),   // Dell Ultrascan V17X
        PNP_CONVERTCODE(DEL2212),   // Dell Ultrascan V17X
        PNP_CONVERTCODE(DEL2213),   // Dell Ultrascan V17X
        PNP_CONVERTCODE(DEL2214),   // Dell Ultrascan 21TE
        PNP_CONVERTCODE(DEL2215),   // Dell Ultrascan 21TE
        PNP_CONVERTCODE(DEL2216),   // Dell Ultrascan 21TE
        PNP_CONVERTCODE(DEL2217),   // Dell Ultrascan 21TE
        PNP_CONVERTCODE(DEL3024),   // Dell VS17X
        PNP_CONVERTCODE(DEL3025),   // Dell VS17X
        PNP_CONVERTCODE(DEL3026),   // Dell VS17X
        PNP_CONVERTCODE(DEL3027),   // Dell VS17X
        PNP_CONVERTCODE(DLK2201),   // D-Link DE-220 NE2000 compatible Network Card
        PNP_CONVERTCODE(DPTA401),   // DPT PM2012B1 EISA SCSI Host
        PNP_CONVERTCODE(DPTA402),   // DPT PM2012B2 EISA SCSI Host
        PNP_CONVERTCODE(DPTA410),   // DPT PM2x22A EISA SCSI Host
        PNP_CONVERTCODE(DPTA411),   // DPT Spectre chipset SCSI Adapters
        PNP_CONVERTCODE(DPTA501),   // DPT PM2012B1/9x EISA SCSI Host
        PNP_CONVERTCODE(DPTA502),   // DPT PM2012B2/9x EISA SCSI Host
        PNP_CONVERTCODE(DPTA701),   // DPT PM2011B1/9x ISA SCSI Host
        PNP_CONVERTCODE(DPTBC01),   // DPT ESDI Caching HDC (PM3011/7X)
        PNP_CONVERTCODE(DWE0215),   // Daewoo CMC-1502
        PNP_CONVERTCODE(DWE1423),   // Daewoo CMC-1423B1
        PNP_CONVERTCODE(DWE1427),   // Daewoo CMC-1427X1
        PNP_CONVERTCODE(DWE1502),   // Daewoo CMC-1502B1
        PNP_CONVERTCODE(DWE1505),   // Daewoo CMC-1505X
        PNP_CONVERTCODE(DWE1507),   // Daewoo CMC-1507X1
        PNP_CONVERTCODE(DWE1703),   // Daewoo CMC-1703B
        PNP_CONVERTCODE(DXP0010),   // DataExpert InterWave Synth/Codec
        PNP_CONVERTCODE(DXP0011),   // DataExpert InterWave
        PNP_CONVERTCODE(DXP0013),   // DataExpert InterWave FM/SB Emulation
        PNP_CONVERTCODE(DXP0014),   // DataExpert InterWave MPU-401 Emulation
        PNP_CONVERTCODE(DXP0015),   // DataExpert InterWave 3D Stereo Enhancer
        PNP_CONVERTCODE(DXP3201),   // DataExpert MED3201 Audio Card
        PNP_CONVERTCODE(ECS0001),   // ECS Vertos 1401
        PNP_CONVERTCODE(ECS0002),   // ECS Vertos 1501
        PNP_CONVERTCODE(ECS0003),   // ECS Vertos 1502
        PNP_CONVERTCODE(ECS0004),   // ECS Vertos 1503
        PNP_CONVERTCODE(ECS0005),   // ECS Vertos 1700
        PNP_CONVERTCODE(ECS0006),   // ECS Vertos 1701
        PNP_CONVERTCODE(ECS0007),   // ECS Vertos 1700
        PNP_CONVERTCODE(ECS0008),   // ECS Vertos 2101
        PNP_CONVERTCODE(ECS0009),   // ECS Vertos 2102
        PNP_CONVERTCODE(EIZ0200),   // EIZO FlexScan F351
        PNP_CONVERTCODE(EIZ0201),   // EIZO FlexScan F553
        PNP_CONVERTCODE(EIZ0202),   // EIZO FlexScan F563
        PNP_CONVERTCODE(EIZ0203),   // EIZO FlexScan F764
        PNP_CONVERTCODE(EIZ0204),   // EIZO FlexScan F784
        PNP_CONVERTCODE(EIZ0206),   // EIZO FlexScan 6600
        PNP_CONVERTCODE(EIZ0300),   // EIZO FlexScan 6500
        PNP_CONVERTCODE(EIZ0302),   // EIZO 9060S
        PNP_CONVERTCODE(EIZ0303),   // EIZO 9065S
        PNP_CONVERTCODE(EIZ0305),   // EIZO FlexScan T563
        PNP_CONVERTCODE(EIZ0306),   // EIZO 9070S
        PNP_CONVERTCODE(EIZ0307),   // EIZO 9080i
        PNP_CONVERTCODE(EIZ0308),   // EIZO 9400i
        PNP_CONVERTCODE(EIZ0309),   // EIZO 9500
        PNP_CONVERTCODE(EIZ030A),   // EIZO FlexScan F340iW
        PNP_CONVERTCODE(EIZ030C),   // EIZO FlexScan F552
        PNP_CONVERTCODE(EIZ030D),   // EIZO FlexScan F560iW
        PNP_CONVERTCODE(EIZ030E),   // EIZO FlexScan F750i
        PNP_CONVERTCODE(EIZ030F),   // EIZO FlexScan F760iW
        PNP_CONVERTCODE(EIZ0310),   // EIZO FlexScan F780iW
        PNP_CONVERTCODE(EIZ0311),   // EIZO FlexScan T560i
        PNP_CONVERTCODE(EIZ0312),   // EIZO FlexScan T660i
        PNP_CONVERTCODE(EIZ0313),   // EIZO FlexScan T562
        PNP_CONVERTCODE(EIZ0314),   // EIZO FlexScan T662
        PNP_CONVERTCODE(EIZ038C),   // EIZO FlexScan F550iW
        PNP_CONVERTCODE(ELS00C3),   // ELSA ECOMO 21H95
        PNP_CONVERTCODE(ELS00EA),   // ELSA ECOMO 24H96
        PNP_CONVERTCODE(ELS0121),   // ELSA GDM-20H110
        PNP_CONVERTCODE(ELS01AF),   // ELSA ECOMO 20S96
        PNP_CONVERTCODE(ELS01B1),   // ELSA ECOMO 17H96
        PNP_CONVERTCODE(ELS1302),   // ELSA ECOMO 20H97
        PNP_CONVERTCODE(ELSC040),   // ELSA ECOMO 17H97
        PNP_CONVERTCODE(ESS0000),   // ESS ES1868 Control Interface
        PNP_CONVERTCODE(ESS0004),   // ESS ES1878 Control Interface
        PNP_CONVERTCODE(ESS0100),   // ESS ES688 PnP AudioDrive
        PNP_CONVERTCODE(ESS0102),   // ESS ES1688 PnP AudioDrive
        PNP_CONVERTCODE(ESS0104),   // ESS ES1788 PnP AudioDrive
        PNP_CONVERTCODE(ESS0106),   // ESS ES1888 PnP AudioDrive
        PNP_CONVERTCODE(ESS0108),   // ESS ES888 PnP AudioDrive
        PNP_CONVERTCODE(ESS1481),   // ESS ES1488 AudioDrive
        PNP_CONVERTCODE(ESS1681),   // ESS ES1688 AudioDrive
        PNP_CONVERTCODE(ESS1781),   // ESS ES1788 AudioDrive
        PNP_CONVERTCODE(ESS1868),   // ESS ES1868 PnP AudioDrive
        PNP_CONVERTCODE(ESS1878),   // ESS ES1878 PnP AudioDrive
        PNP_CONVERTCODE(ESS1881),   // ESS ES1888 AudioDrive
        PNP_CONVERTCODE(ESS4881),   // ESS ES488 AudioDrive
        PNP_CONVERTCODE(ESS6880),   // ESS ES688 AudioDrive + game port
        PNP_CONVERTCODE(ESS6881),   // ESS ES688 AudioDrive
        PNP_CONVERTCODE(ESS8881),   // ESS ES888 AudioDrive
        PNP_CONVERTCODE(EXI0001),   // Exide UPS
        PNP_CONVERTCODE(FDC0000),   // Future Domain TMC-18XX SIC SCSI Host
        PNP_CONVERTCODE(FDC0950),   // Future Domain TMC-950 SIC SCSI Host
        PNP_CONVERTCODE(FDC1600),   // Future Domain PNP-1630/1640 PnP SCSI
        PNP_CONVERTCODE(FDC1695),   // Future Domain TMC-1695 PnP SCSI Host
        PNP_CONVERTCODE(FDC9516),   // Future Domain TMC-1695 PnP SCSI Host
        PNP_CONVERTCODE(FPS0001),   // Fiskars UPS
        PNP_CONVERTCODE(GRV0000),   // Gravis UltraSound Synth & Codec
        PNP_CONVERTCODE(GRV0001),   // Gravis UltraSound Plug-and-Play
        PNP_CONVERTCODE(GRV0011),   // Gravis UltraSound CD-Rom
        PNP_CONVERTCODE(GRV0012),   // Gravis UltraSound Game port
        PNP_CONVERTCODE(GRV0013),   // Gravis UltraSound Emulation
        PNP_CONVERTCODE(GRV0014),    // Gravis UltraSound MPU-401
        PNP_CONVERTCODE(GSM36B1),   // LG HiSync 14S
        PNP_CONVERTCODE(GSM36B4),   // LG StudioWorks 44m
        PNP_CONVERTCODE(GSM36B9),   // LG StudioWorks 44i
        PNP_CONVERTCODE(GSM36BB),   // LG StudioWorks 45i
        PNP_CONVERTCODE(GSM3AA0),   // LG 1505s
        PNP_CONVERTCODE(GSM3AA1),   // LG HiSync 15S
        PNP_CONVERTCODE(GSM3AA2),   // LG StudioWorks 56m
        PNP_CONVERTCODE(GSM3AA5),   // LG HiSync 15VH
        PNP_CONVERTCODE(GSM3AA6),   // LG HiSync 15XH
        PNP_CONVERTCODE(GSM3AA8),   // LG StudioWorks 56i
        PNP_CONVERTCODE(GSM3AA9),   // LG StudioWorks 54m
        PNP_CONVERTCODE(GSM3AAA),   // LG HiSync 15VN
        PNP_CONVERTCODE(GSM3AAB),   // LG HiSync 15SF
        PNP_CONVERTCODE(GSM3AAC),   // LG 1537
        PNP_CONVERTCODE(GSM3AAE),   // LG 1535
        PNP_CONVERTCODE(GSM3AAF),   // LG StudioWorks 56T
        PNP_CONVERTCODE(GSM3AB1),   // LG HiSync 15SX
        PNP_CONVERTCODE(GSM3AB6),   // LG StudioWorks 5D
        PNP_CONVERTCODE(GSM3ABD),   // LG StudioWorks 55i
        PNP_CONVERTCODE(GSM426A),   // LG HiSync 17S
        PNP_CONVERTCODE(GSM426C),   // LG StudioWorks 78i
        PNP_CONVERTCODE(GSM426D),   // LG StudioWorks 78T
        PNP_CONVERTCODE(GSM426E),   // LG StudioWorks 76i
        PNP_CONVERTCODE(GSM4270),   // LG HiSync 17XR
        PNP_CONVERTCODE(GSM4271),   // LG HiSync 17XH
        PNP_CONVERTCODE(GSM4272),   // LG HiSync 17SH
        PNP_CONVERTCODE(GSM4273),   // LG StudioWorks 76m
        PNP_CONVERTCODE(GSM4274),   // LG StudioWorks 78m
        PNP_CONVERTCODE(GSM4276),   // LG HiSync 17SF
        PNP_CONVERTCODE(GSM4277),   // LG StudioWorks 74m
        PNP_CONVERTCODE(GSM4278),   // LG StudioWorks 74i
        PNP_CONVERTCODE(GSM4279),   // LG HiSync 17SX
        PNP_CONVERTCODE(GSM427A),   // LG HiSync 17XDR
        PNP_CONVERTCODE(GSM427E),   // LG StudioWorks 7D
        PNP_CONVERTCODE(GSM427F),   // LG StudioWorks 78D
        PNP_CONVERTCODE(GSM4280),   // LG StudioWorks 78DT
        PNP_CONVERTCODE(GSM4281),   // LG StudioWorks 7DT
        PNP_CONVERTCODE(GSM4284),   // LG StudioWorks 76T
        PNP_CONVERTCODE(GSM428A),   // LG StudioWorks 77i
        PNP_CONVERTCODE(GSM42CF),   // LG 1725
        PNP_CONVERTCODE(GSM4E21),   // LG StudioWorks 20i
        PNP_CONVERTCODE(GSM4E22),   // LG 2010i
        PNP_CONVERTCODE(GSM4E23),   // LG HiSync 20VRp
        PNP_CONVERTCODE(GSM520B),   // LG StudioWorks 28i
        PNP_CONVERTCODE(HAY0001),   // Hayes Optima 288 V.34/FAX/Voice/ESP
        PNP_CONVERTCODE(HEI5864),   // HYUNDAI DeluxScan 15 Pro
        PNP_CONVERTCODE(HEIB81E),   // HYUNDAI DeluxScan 17
        PNP_CONVERTCODE(HSL057A),   // Hansol Mazelan 400A
        PNP_CONVERTCODE(HTCAB6F),   // Hitachi CM-1711M
        PNP_CONVERTCODE(HTCABC2),   // Hitachi CM-2112M
        PNP_CONVERTCODE(HTCABC7),   // Hitachi CM-2111M
        PNP_CONVERTCODE(HTCABCC),   // Hitachi CM-2110M
        PNP_CONVERTCODE(HWP0AF0),   // HP D2800A UltraVGA 1600
        PNP_CONVERTCODE(HWP0AF6),   // HP D2806A ErgoUltraVGA
        PNP_CONVERTCODE(HWP0AFF),   // HP D1815A 1024
        PNP_CONVERTCODE(HWP0F11),   // HP D3857A MultiMedia
        PNP_CONVERTCODE(HWP0F12),   // HP D3858A MultiMedia
        PNP_CONVERTCODE(HWP1400),   // HP Dual Serial Interface  (24541B)
        PNP_CONVERTCODE(HWP1461),   // HP ScanJet Plus
        PNP_CONVERTCODE(HWP1820),   // HP EtherTwist Adapter Card/8 (27245-60002)
        PNP_CONVERTCODE(HWP1832),   // HP EtherTwist PC LAN Adapter/16 TP Plus (27247B)
        PNP_CONVERTCODE(HWP1840),   // HP Ethertwist EISA LAN
        PNP_CONVERTCODE(HWP18A0),   // HP EtherTwist PC LAN Adapter/16 TL Plus (27252A)
        PNP_CONVERTCODE(HWP18C0),   // HP EtherTwist PC LAN Adapter NC/16 TP (J2405A)
        PNP_CONVERTCODE(HWP1920),   // HP 27248B 10 MB/s Ethernet Adapter
        PNP_CONVERTCODE(HWP1940),   // HP J2577A 10/100VG EISA LAN
        PNP_CONVERTCODE(HWP1950),   // HP J2573A 10/100VG ISA LAN
        PNP_CONVERTCODE(HWP1C00),   // HP Serial/Parallel Interface  (24540B)
        PNP_CONVERTCODE(HWP1C10),   // HP COM and LPT Ports Combo Card
        PNP_CONVERTCODE(HWP2002),   // HP ScanJet II
        PNP_CONVERTCODE(HWPC0F1),   // HP NetServer 5/133 LC
        PNP_CONVERTCODE(HWPF150),   // HP J2573A 10/100 Ethernet Adapter
        PNP_CONVERTCODE(HWPF180),   // HP J2577A 10/100 Ethernet Adapter
        PNP_CONVERTCODE(IBM0000),   // IBM Auto LANStreamer PCI
        PNP_CONVERTCODE(IBM0001),   // IBM Auto 16/4 ISA Token-Ring
        PNP_CONVERTCODE(IBM0002),   // IBM Thinkpad Infrared Port
        PNP_CONVERTCODE(IBM0003),   // IBM EtherStreamer MC 32
        PNP_CONVERTCODE(IBM0005),   // Power Management
        PNP_CONVERTCODE(IBM0007),   // L2 Cache
        PNP_CONVERTCODE(IBM0008),   // NVRAM
        PNP_CONVERTCODE(IBM0009),   // CMOS
        PNP_CONVERTCODE(IBM000A),   // Memory controller
        PNP_CONVERTCODE(IBM000B),   // Operator's Panel
        PNP_CONVERTCODE(IBM000D),   // PowerPC Extended Interrupt Controller
        PNP_CONVERTCODE(IBM000E),   // Crystal CS4231 Audio Device
        PNP_CONVERTCODE(IBM000F),   // NCR 810 SCSI Controller
        PNP_CONVERTCODE(IBM0010),   // IBM Ethernet
        PNP_CONVERTCODE(IBM0011),   // IBM Service Processor
        PNP_CONVERTCODE(IBM0012),   // Crystal CS4232 Game Port
        PNP_CONVERTCODE(IBM0013),   // Crystal CS4232 MIDI
        PNP_CONVERTCODE(IBM0014),   // Graphics Assist
        PNP_CONVERTCODE(IBM0015),   // ASCII V7310 Video Capture
        PNP_CONVERTCODE(IBM0016),   // AMD 79C970 Ethernet
        PNP_CONVERTCODE(IBM0017),   // Crystal CS4232 Audio Device
        PNP_CONVERTCODE(IBM0018),   // NCR 875 SCSI Controller
        PNP_CONVERTCODE(IBM0019),   // IBM Tablet Controller
        PNP_CONVERTCODE(IBM001B),   // NCR 825 SCSI Controller
        PNP_CONVERTCODE(IBM001C),   // EPP Parallel port
        PNP_CONVERTCODE(IBM001D),   // YMF289B Sound Chip (Yamaha)
        PNP_CONVERTCODE(IBM001E),   // Lightning/Terlingua Support Processor
        PNP_CONVERTCODE(IBM001F),   // Terlingua Mini-SP
        PNP_CONVERTCODE(IBM0034),   // IBM Thinkpad Infrared Port
        PNP_CONVERTCODE(IBM198E),   // IBM G41/G50
        PNP_CONVERTCODE(IBM1990),   // IBM G70
        PNP_CONVERTCODE(IBM1991),   // IBM G200
        PNP_CONVERTCODE(IBM1999),   // IBM P50
        PNP_CONVERTCODE(IBM199A),   // IBM P70
        PNP_CONVERTCODE(IBM199B),   // IBM P200
        PNP_CONVERTCODE(IBM2001),   // IBM EISA Ethernet
        PNP_CONVERTCODE(IBM2112),   // IBM 2112
        PNP_CONVERTCODE(IBM2113),   // IBM 2113
        PNP_CONVERTCODE(IBM2114),   // IBM 2114
        PNP_CONVERTCODE(IBM2115),   // IBM 2115
        PNP_CONVERTCODE(IBM2117),   // IBM 2117
        PNP_CONVERTCODE(IBM2215),   // IBM 2215
        PNP_CONVERTCODE(IBM2238),   // IBM 2238
        PNP_CONVERTCODE(IBM2248),   // IBM 2248
        PNP_CONVERTCODE(IBM2264),   // IBM 2264
        PNP_CONVERTCODE(IBM2535),   // IBM 9525-0X1
        PNP_CONVERTCODE(IBM36E0),   // IBM Mwave DSP Processor
        PNP_CONVERTCODE(IBM36F1),   // IBM Mwave Midi Synthesizer
        PNP_CONVERTCODE(IBM36F2),   // IBM Mwave SoundBlaster
        PNP_CONVERTCODE(IBM5250),   // IBM Enhanced 5250 Emulation Adapter
        PNP_CONVERTCODE(IBM6312),   // IBM 6312
        PNP_CONVERTCODE(IBM6314),   // IBM 6314
        PNP_CONVERTCODE(IBM6315),   // IBM 6315
        PNP_CONVERTCODE(IBM6317),   // IBM 6317
        PNP_CONVERTCODE(IBM6319),   // IBM 6319
        PNP_CONVERTCODE(IBM6321),   // IBM 6321
        PNP_CONVERTCODE(IBM6322),   // IBM 6322
        PNP_CONVERTCODE(IBM6324),   // IBM 6324
        PNP_CONVERTCODE(IBM6325),   // IBM 6324
        PNP_CONVERTCODE(IBM6327),   // IBM 6327
        PNP_CONVERTCODE(IBM8504),   // IBM 8504
        PNP_CONVERTCODE(IBM8511),   // IBM 8511
        PNP_CONVERTCODE(IBM8512),   // IBM 8512
        PNP_CONVERTCODE(IBM8513),   // IBM 8513
        PNP_CONVERTCODE(IBM8514),   // IBM 8514
        PNP_CONVERTCODE(IBM8515),   // IBM 8515
        PNP_CONVERTCODE(IBM8517),   // IBM 8517
        PNP_CONVERTCODE(IBM8518),   // IBM 8518
        PNP_CONVERTCODE(IBM9504),   // IBM 9504
        PNP_CONVERTCODE(IBM9515),   // IBM 9515
        PNP_CONVERTCODE(IBM9517),   // IBM 9517
        PNP_CONVERTCODE(IBM9518),   // IBM 9518
        PNP_CONVERTCODE(IBM9521),   // IBM 9521
        PNP_CONVERTCODE(IBM9524),   // IBM 9524
        PNP_CONVERTCODE(IBM9525),   // IBM 9525-0X1
        PNP_CONVERTCODE(IBM9527),   // IBM 9527
        PNP_CONVERTCODE(ICL0100),   // Fujitsu ICL ErgoPro 211v
        PNP_CONVERTCODE(ICL0200),   // Fujitsu ICL ErgoPro 171p
        PNP_CONVERTCODE(ICL0400),   // Fujitsu ICL ErgoPro 171v
        PNP_CONVERTCODE(ICL0700),   // Fujitsu ICL ErgoPro 151p
        PNP_CONVERTCODE(ICL0800),   // Fujitsu ICL ErgoPro 151p AutoBrite
        PNP_CONVERTCODE(ICL0A00),   // Fujitsu ICL ErgoPro 151v
        PNP_CONVERTCODE(ICL0B00),   // Fujitsu ICL ErgoPro 141v
        PNP_CONVERTCODE(ICL0D00),   // Fujitsu ICL ErgoPro 141p
        PNP_CONVERTCODE(ICL0F00),   // Fujitsu ICL ErgoPro 152v
        PNP_CONVERTCODE(ICL1400),   // Fujitsu ICL ErgoPro 142v
        PNP_CONVERTCODE(ICLA080),   // Fujitsu ICL EtherTeam 32 EISA 32-bit Ethernet Controller
        PNP_CONVERTCODE(ICLA090),   // ICL EtherTeam PCI/ISA Ethernet Adapter
        PNP_CONVERTCODE(ICU0010),   // Intel SatisFAXtion Modem/400
        PNP_CONVERTCODE(ICU0020),   // Intel SatisFAXtion Modem/100
        PNP_CONVERTCODE(ICU0030),   // Digi DigiChannel PC/4E Serial Adapter
        PNP_CONVERTCODE(ICU0040),   // Western Digital WD1003V-MM2(w FIRMWARE) HDC/FDC
        PNP_CONVERTCODE(ICU0041),   // Western Digital WD1003V-MM2(w/o FIRMWARE) HDC/FDC
        PNP_CONVERTCODE(ICU0050),   // Western Digital WD1007A-WA2(w BIOS) HDC/FDC
        PNP_CONVERTCODE(ICU0051),   // Western Digital WD1007A-WA2(w/o BIOS) HDC/FDC
        PNP_CONVERTCODE(ICU0060),   // Archive SC402/VP402 QIC-02 Tape
        PNP_CONVERTCODE(ICU0070),   // Wangtek PC-36 Tape
        PNP_CONVERTCODE(ICU0080),   // Wangtek PC-02 Tape
        PNP_CONVERTCODE(ICU0091),   // Adaptec AHA-1540/1542 SCSI
        PNP_CONVERTCODE(ICU00A1),   // DPT PM2011B1 SmartCache Plus SCSI
        PNP_CONVERTCODE(ICU00B0),   // 3COM Etherlink II (3C503)
        PNP_CONVERTCODE(ICU00C0),   // 3COM Etherlink 16 (3C507)
        PNP_CONVERTCODE(ICU00D0),   // SMC PC600WS
        PNP_CONVERTCODE(ICU00E0),   // SMC PC130E
        PNP_CONVERTCODE(ICU0100),   // Western Digital WD8003E
        PNP_CONVERTCODE(ICU0110),   // Paradise VGA Plus 16
        PNP_CONVERTCODE(ICU0120),   // Paradise VGA 1024
        PNP_CONVERTCODE(ICU0130),   // Orchid Prodesigner IIs
        PNP_CONVERTCODE(ICU0150),   // Orchid Fahrenheit 1280
        PNP_CONVERTCODE(ICU0180),   // Sound Blaster
        PNP_CONVERTCODE(ICU0190),   // Sound Blaster Pro
        PNP_CONVERTCODE(ICU01A0),   // Sound Blaster 16ASP
        PNP_CONVERTCODE(ICU01A1),   // Sound Blaster 16
        PNP_CONVERTCODE(ICU01A2),   // Sound Blaster 16 SCSI-2
        PNP_CONVERTCODE(ICU01A3),   // Sound Blaster 16ASP/CD-ROM
        PNP_CONVERTCODE(ICU01A4),   // JAZZ 16 Audio Card
        PNP_CONVERTCODE(ICU01A5),   // Premium 3-D SCSI2/Pro 3-D SCSI2
        PNP_CONVERTCODE(ICU01B0),   // Gravis Ultra Sound
        PNP_CONVERTCODE(ICU01C0),   // Logitech Soundman 16
        PNP_CONVERTCODE(ICU01D0),   // Media Vision Thunder
        PNP_CONVERTCODE(ICU01E0),   // Pro Audio Spectrum 16
        PNP_CONVERTCODE(ICU01E1),   // Pro AudioStudio
        PNP_CONVERTCODE(ICU01F0),   // Microsoft Windows Sound System
        PNP_CONVERTCODE(ICU0200),   // Intel Above  Plus 8 I/O
        PNP_CONVERTCODE(ICU0210),   // Logitech Bus Mouse
        PNP_CONVERTCODE(ICU0211),   // Microsoft Bus Mouse
        PNP_CONVERTCODE(ICU0220),   // Microfield Graphics V8
        PNP_CONVERTCODE(ICU0230),   // Accton Ringpair-4/16 (TR1605)
        PNP_CONVERTCODE(ICU0231),   // Accton MPX Ethernet Adapter (EN165x)
        PNP_CONVERTCODE(ICU0240),   // CNet CN600E/680E
        PNP_CONVERTCODE(ICU0250),   // CNet CN1000T
        PNP_CONVERTCODE(ICU0260),   // CNet CN850E
        PNP_CONVERTCODE(ICU0270),   // CNet CN800E/880E
        PNP_CONVERTCODE(ICU0280),   // Cogent E/Master II-AT
        PNP_CONVERTCODE(ICU0290),   // Cogent E/Master I-AT
        PNP_CONVERTCODE(ICU02A0),   // D-Link DE-100
        PNP_CONVERTCODE(ICU02B0),   // D-Link DE-200
        PNP_CONVERTCODE(ICU02C0),   // Eagle/Novell NE1000 (810-160-00X)
        PNP_CONVERTCODE(ICU02C1),   // Eagle/Novell NE1000 (950-054401)
        PNP_CONVERTCODE(ICU02D0),   // Eagle/Novell NE1500T
        PNP_CONVERTCODE(ICU02E0),   // Eagle/Novell NE2100
        PNP_CONVERTCODE(ICU02F0),   // Gateway Ethertwist 16 (Fujitsu Chipset)
        PNP_CONVERTCODE(ICU02F1),   // Gateway Ethertwist 16 (National Chipset)
        PNP_CONVERTCODE(ICU0300),   // Gateway Ethertwist PC/PC-WS(National Chipset)
        PNP_CONVERTCODE(ICU0310),   // Proteon ProNET-4/16 Model p1390
        PNP_CONVERTCODE(ICU0320),   // Racal-Datacom InterLan AT
        PNP_CONVERTCODE(ICU0330),   // SMC PC330
        PNP_CONVERTCODE(ICU0340),   // SMC PC500
        PNP_CONVERTCODE(ICU0350),   // SMC PC550
        PNP_CONVERTCODE(ICU0360),   // SMC PC650
        PNP_CONVERTCODE(ICU0370),   // SMC PC270E
        PNP_CONVERTCODE(ICU0380),   // SMC 3008
        PNP_CONVERTCODE(ICU0390),   // SMC 3016
        PNP_CONVERTCODE(ICU03A0),   // Thomas-Conrad TC5045-2
        PNP_CONVERTCODE(ICU03B0),   // Thomas-Conrad TC6042/TC6142/TC6242
        PNP_CONVERTCODE(ICU03C0),   // Thomas-Conrad TC6045
        PNP_CONVERTCODE(ICU03D0),   // Thomas-Conrad TC6245
        PNP_CONVERTCODE(ICU03E0),   // Tiara Lancard 2002/2003
        PNP_CONVERTCODE(ICU03F0),   // Tiara Lancard AT
        PNP_CONVERTCODE(ICU0400),   // Tiara Lancard PC
        PNP_CONVERTCODE(ICU0410),   // Tiara ARCNET Lancard AT
        PNP_CONVERTCODE(ICU0420),   // Tiara Ethernet Lancard * 2000
        PNP_CONVERTCODE(ICU0430),   // Tiara Ethernet Lancard E2000
        PNP_CONVERTCODE(ICU0440),   // Tiara Lancard A-286
        PNP_CONVERTCODE(ICU0450),   // Tiara Lancard E
        PNP_CONVERTCODE(ICU0460),   // Tiara Lancard E * AT
        PNP_CONVERTCODE(ICU0470),   // Tiara Lancard E * AT TP
        PNP_CONVERTCODE(ICU0480),   // Tiara Lancard E * PC
        PNP_CONVERTCODE(ICU0490),   // Tiara Lancard E * PC10BT
        PNP_CONVERTCODE(ICU04A0),   // Tiara Lancard E * PC10TP
        PNP_CONVERTCODE(ICU04B0),   // Tiara Token Ring Lancard*16 AT
        PNP_CONVERTCODE(ICU04C0),   // Zenith LAN10E-MAT/FAT/FL-AT
        PNP_CONVERTCODE(ICU04D0),   // Zenith LAN16TR-AT
        PNP_CONVERTCODE(ICU04E0),   // Zenith LAN16TR-XT
        PNP_CONVERTCODE(ICU04F0),   // Zenith LAN4TR-AT
        PNP_CONVERTCODE(ICU0500),   // Zenith LAN4TR-XT
        PNP_CONVERTCODE(ICU0510),   // Zenith OfficeNIC
        PNP_CONVERTCODE(ICU0520),   // Zenith XT Lancard
        PNP_CONVERTCODE(ICU0530),   // BOCA M1440I 14.4Kbps V.32bis Modem
        PNP_CONVERTCODE(ICU0540),   // Always Technology IN-2000 SCSI
        PNP_CONVERTCODE(ICU0550),   // Data Technology DTC3180A/DTC3280A SCSI
        PNP_CONVERTCODE(ICU0560),   // DTC3150 SCSI
        PNP_CONVERTCODE(ICU0561),   // DTC3150B SCSI
        PNP_CONVERTCODE(ICU0570),   // Data Technology DTC3250 SCSI
        PNP_CONVERTCODE(ICU0580),   // Future Domain TMC-850xx (8-bit) SCSI
        PNP_CONVERTCODE(ICU0590),   // Future Domain TMC-885/TMC-860 SCSI
        PNP_CONVERTCODE(ICU05A0),   // Future Domain TMC-16xx SCSI
        PNP_CONVERTCODE(ICU05B0),   // Future Domain TMC-16xx SCSI
        PNP_CONVERTCODE(ICU05C0),   // Promise Technology DC-2030 IDE
        PNP_CONVERTCODE(ICU05D0),   // Promise Technology DC-2031 IDE
        PNP_CONVERTCODE(ICU05E0),   // Promise Technology DC-2040 SCSI
        PNP_CONVERTCODE(ICU05F0),   // Ultrastor ULTRA14F SCSI
        PNP_CONVERTCODE(ICU0600),   // Ultrastor ULTRA12C/12F ESDI
        PNP_CONVERTCODE(ICU0610),   // Ultrastor ULTRA15C IDE
        PNP_CONVERTCODE(ICU0620),   // Longshine LCS-6624/6624G IDE
        PNP_CONVERTCODE(ICU0630),   // Longshine LCS-6631/6631F SCSI
        PNP_CONVERTCODE(ICU0640),   // Intel EtherExpress TPE Hub
        PNP_CONVERTCODE(ICU0650),   // US Robotics Sportster 9600/PC Modem w/V.42BIS
        PNP_CONVERTCODE(ICU0660),   // Zoom AFC FAX Modem
        PNP_CONVERTCODE(ICU0680),   // DFI DIO-500 Serial/Parallel I/O Card
        PNP_CONVERTCODE(ICU0681),   // DFI DIO-200 Serial/Parallel I/O Card
        PNP_CONVERTCODE(ICU0690),   // Practical Peripherals PM9600FX Modem/FAX
        PNP_CONVERTCODE(ICU06A0),   // Practical Peripherals PM2400 Modem
        PNP_CONVERTCODE(ICU06B0),   // Zoom VFP V.32bis FAX Modem
        PNP_CONVERTCODE(ICU06C0),   // Zoom VP V.32bis Modem
        PNP_CONVERTCODE(ICU06D0),   // Zoom AMC 2400 Modem
        PNP_CONVERTCODE(ICU06E0),   // Cardinal MVP96IF 9600 Baud FAX/Modem
        PNP_CONVERTCODE(ICU06E1),   // Cardinal MVP144DSP Modem
        PNP_CONVERTCODE(ICU06E2),   // Cardinal MVP144IF Modem
        PNP_CONVERTCODE(ICU06E3),   // Cardinal MVP192I Modem
        PNP_CONVERTCODE(ICU06E4),   // Cardinal MVP24IF Soft V.42 Modem
        PNP_CONVERTCODE(ICU06E5),   // PC Logic FAX144DM
        PNP_CONVERTCODE(ICU06E6),   // PC Logic FAX144I
        PNP_CONVERTCODE(ICU06E7),   // PC Logic FAX192I
        PNP_CONVERTCODE(ICU06E8),   // PC Logic 24I-SRF-Soft V.42
        PNP_CONVERTCODE(ICU06F0),   // Cardinal MB2296SR 9600 Baud FAX/Modem
        PNP_CONVERTCODE(ICU06F1),   // Zoom/Voice FaxModem VFP 14.4V
        PNP_CONVERTCODE(ICU0700),   // Hayes Accura 2400B Modem
        PNP_CONVERTCODE(ICU0710),   // US Robotics Sportster 2400/PC Modem
        PNP_CONVERTCODE(ICU0720),   // US Robotics Sportster 14,400/PC FAX/Modem
        PNP_CONVERTCODE(ICU0730),   // Intel SatisFAXtion Modem/200
        PNP_CONVERTCODE(ICU0740),   // Racal InterLan NI5210-10BT
        PNP_CONVERTCODE(ICU0750),   // Racal InterLan NI6510-UTP
        PNP_CONVERTCODE(ICU0760),   // Intel Smart Video Recorder
        PNP_CONVERTCODE(ICU0770),   // Diamond Stealth Pro
        PNP_CONVERTCODE(ICU0780),   // Diamond SpeedStar 24X VGA
        PNP_CONVERTCODE(ICU0790),   // Video Seven WIN.PRO card
        PNP_CONVERTCODE(ICU0800),   // Video Seven WIN.VGA card
        PNP_CONVERTCODE(ICU0810),   // BOCA Super X Accelerator VGA
        PNP_CONVERTCODE(ICU0820),   // Metheus Premier 928
        PNP_CONVERTCODE(ICU0830),   // GraphicsENGINE ULTRA Series
        PNP_CONVERTCODE(ICU0840),   // Cardinal VIDEO spectrum
        PNP_CONVERTCODE(ICU0850),   // SigmaDesigns Legend 24LX
        PNP_CONVERTCODE(ICU0860),   // Hercules Graphite Card
        PNP_CONVERTCODE(ICU0870),   // Focus GUIVGA
        PNP_CONVERTCODE(ICU0880),   // AIR AVIEW2V SVGA
        PNP_CONVERTCODE(ICU0890),   // NDI Volante Warp Series Warp10
        PNP_CONVERTCODE(ICU0900),   // NDI Volante Warp Series Warp10LB & 24LB
        PNP_CONVERTCODE(ICU0910),   // Alpha Cyber Audio
        PNP_CONVERTCODE(ICU0920),   // Genoa SuperVGA 6000 Series
        PNP_CONVERTCODE(ICU0950),   // Acculogic sIDE-3/plus
        PNP_CONVERTCODE(ICU0960),   // Alpha Research S4251 ISA
        PNP_CONVERTCODE(ICU0970),   // CMS Enhancement Universal AT/XT Card
        PNP_CONVERTCODE(ICU0980),   // Eastern IDC-747
        PNP_CONVERTCODE(ICU1000),   // NCL538/NCL539
        PNP_CONVERTCODE(ICU1010),   // NCL538B
        PNP_CONVERTCODE(ICU1020),   // NCL538C
        PNP_CONVERTCODE(ICU1030),   // easyCACHE IDE/easyCACHEPro IDE
        PNP_CONVERTCODE(ICU1040),   // Plus Development HARDCARD II XL
        PNP_CONVERTCODE(ICU1050),   // Plus Development HARDCARD II
        PNP_CONVERTCODE(ICU1060),   // Seagate ST05A
        PNP_CONVERTCODE(ICU1080),   // Silicon ADP60
        PNP_CONVERTCODE(ICU1090),   // Silicon ADP65
        PNP_CONVERTCODE(ICU1100),   // Adaptec AHA-1520/1522 SCSI/FDC
        PNP_CONVERTCODE(ICU1120),   // Bustek BT-542B
        PNP_CONVERTCODE(ICU1130),   // Bustek BT-542S/BT-542D
        PNP_CONVERTCODE(ICU1140),   // Computer Electronik Infosys C5610
        PNP_CONVERTCODE(ICU1150),   // Computer Electronik Infosys C5630
        PNP_CONVERTCODE(ICU1160),   // Computer Electronik Infosys C5635
        PNP_CONVERTCODE(ICU1181),   // DPT PM2001 SmartConnex SCSI
        PNP_CONVERTCODE(ICU1190),   // Quantum ISA-200S
        PNP_CONVERTCODE(ICU1200),   // easyCACHE SCSI/easyCACHEPro SCSI
        PNP_CONVERTCODE(ICU1230),   // Procomp S-DCB
        PNP_CONVERTCODE(ICU1240),   // Procomp USA, Incorporated S-DCB
        PNP_CONVERTCODE(ICU1250),   // Rancho RT10-AT
        PNP_CONVERTCODE(ICU1260),   // SMS OMTI-810/812/820/822
        PNP_CONVERTCODE(ICU1300),   // IBM Token-Ring 16/4 Adapter
        PNP_CONVERTCODE(ICU1310),   // Thomas TC-4045
        PNP_CONVERTCODE(ICU1331),   // DPT PM2011 SmartCache Plus SCSI
        PNP_CONVERTCODE(ICU1341),   // DPT PM2021 SmartCache III SCSI
        PNP_CONVERTCODE(ICU1360),   // SyQuest SQ08 IDE
        PNP_CONVERTCODE(ICU1550),   // Accton Etherpair-8 (EN1801)
        PNP_CONVERTCODE(ICU1560),   // Alta EtherCombo-16 T/C
        PNP_CONVERTCODE(ICU1570),   // Cabletron E2110
        PNP_CONVERTCODE(ICU1580),   // IBM Token-Ring PC Adapter
        PNP_CONVERTCODE(ICU1581),   // IBM Token-Ring PC Adapter II
        PNP_CONVERTCODE(ICU1590),   // InvisibleLAN Ethernet Combo/2000
        PNP_CONVERTCODE(ICU1600),   // Kodiak ~16 10BT
        PNP_CONVERTCODE(ICU1610),   // Ansel NC2000 Rev. D
        PNP_CONVERTCODE(ICU1620),   // IMC EtherNIC/8
        PNP_CONVERTCODE(ICU1630),   // GVC NIC-2000BT
        PNP_CONVERTCODE(ICU1640),   // Katron 16TB
        PNP_CONVERTCODE(ICU1650),   // Longshine LCS-8634T (REV.A)
        PNP_CONVERTCODE(ICU1660),   // Madge Smart 16/4 PC Ringnode
        PNP_CONVERTCODE(ICU1670),   // Madge Smart AT Ringnode
        PNP_CONVERTCODE(ICU1680),   // Micom NP600/A
        PNP_CONVERTCODE(ICU1690),   // Novell NE1000(Assembly #950-054401)
        PNP_CONVERTCODE(ICU1700),   // Novell RX-Net 810-114-001 (Rev. B,C and D)
        PNP_CONVERTCODE(ICU1710),   // Novell RX-Net 810-114-001 (Rev. E,F and G)
        PNP_CONVERTCODE(ICU1720),   // PureLAN
        PNP_CONVERTCODE(ICU1730),   // Pure PDI515
        PNP_CONVERTCODE(ICU1740),   // Western Digital WD8013E
        PNP_CONVERTCODE(ICU1750),   // 3COM 3C501 EtherLink
        PNP_CONVERTCODE(ICU1751),   // 3COM 3C509 EtherLink
        PNP_CONVERTCODE(ICU1900),   // Generic PCMCIA to ISA Adapter with 82366SL
        PNP_CONVERTCODE(ICU1910),   // OAK OTI-087
        PNP_CONVERTCODE(ICU1911),   // OAK OTI-107
        PNP_CONVERTCODE(ICU1920),   // Oak Mozart Audio
        PNP_CONVERTCODE(ICU1930),   // Turtle Beach MultiSound 16-bit
        PNP_CONVERTCODE(ICU1940),   // Gateway2000 16BA,16AZ, & 16A Audio Card
        PNP_CONVERTCODE(ICU1950),   // Gateway2000 16MV Sound Card
        PNP_CONVERTCODE(ICU1951),   // Gateway2000 16MVL Sound Card
        PNP_CONVERTCODE(ICU1952),   // LMSI CD_ROM Card
        PNP_CONVERTCODE(ICU1960),   // Intel 82091AA (AIP) Evaluation
        PNP_CONVERTCODE(ICU1970),   // Sony CD-ROM
        PNP_CONVERTCODE(ICU1980),   // Mitsumi CD-ROM (FX001D)
        PNP_CONVERTCODE(ICU1990),   // Cardinal Digital Sound Pro
        PNP_CONVERTCODE(ICU1991),   // Cardinal Digital Sound Pro Plus
        PNP_CONVERTCODE(ICU1992),   // Cardinal Digital Sound Pro Wavetable
        PNP_CONVERTCODE(ICU1993),   // Cardinal Digital Sound Pro Plus Wavetable
        PNP_CONVERTCODE(ICU1994),   // PC Logic Sonic 16
        PNP_CONVERTCODE(ICU1995),   // PC Logic Sonic Wave
        PNP_CONVERTCODE(ICU19A0),   // Cardinal SnapPlus Video Capture w VGA
        PNP_CONVERTCODE(ICU19B0),   // Gateway2000 Telepath 14.4 ISA Modem
        PNP_CONVERTCODE(ICU19C0),   // MIO-400KF Card
        PNP_CONVERTCODE(ICU19D0),   // NE 2000plus
        PNP_CONVERTCODE(IIN0B01),   // Intel TokenExpress(tm) ISA/8
        PNP_CONVERTCODE(INI6100),   // Initio INI-6100/6102 SCSI Host
        PNP_CONVERTCODE(INT0011),   // Intel i486 82350DT EISA Evaluation Board
        PNP_CONVERTCODE(INT0021),   // Intel i386 82350DT EISA Evaluation Board
        PNP_CONVERTCODE(INT0031),   // Intel i486 SX 82350DT EISA Evaluation Board
        PNP_CONVERTCODE(INT0051),   // Intel i486 50 MHz WT 82350DT EISA Evaluation Board
        PNP_CONVERTCODE(INT0701),   // Intel TokenExpress(tm) ISA 16/4
        PNP_CONVERTCODE(INT0703),   // Intel TokenExpress(tm) ISA/16s
        PNP_CONVERTCODE(INT0902),   // Intel TokenExpress EISA 16/4 Token-Ring
        PNP_CONVERTCODE(INT1000),   // Intel EtherExpress16/16TP
        PNP_CONVERTCODE(INT1010),   // Intel EtherExpress Flash32 Ethernet Adapter
        PNP_CONVERTCODE(INT1020),   // Intel TokenExpress(TM) PRO
        PNP_CONVERTCODE(INT1028),   // Intel TokenExpress(TM) ISA 16/P
        PNP_CONVERTCODE(INT1030),   // Intel EtherExpress PRO/10 PnP
        PNP_CONVERTCODE(INT1031),   // Intel EtherExpress(TM) PRO/10+
        PNP_CONVERTCODE(INT1050),   // Intel Video Capture Board
        PNP_CONVERTCODE(INT1060),   // Intel EtherExpress PRO/100 EISA
        PNP_CONVERTCODE(INT1070),   // Intel Audio/Video Board Device 0
        PNP_CONVERTCODE(INT1071),   // Intel Audio/Video Board Device 1
        PNP_CONVERTCODE(INT1080),   // Intel Audio/ISDN Board
        PNP_CONVERTCODE(INT1201),   // Intel TokenExpress 32bit EISA 16/4
        PNP_CONVERTCODE(INT31A0),   // Intel Xxpress-Premium Motherboard
        PNP_CONVERTCODE(ISA0000),   // Standard I/O Card (2xSerial, 1xParallel)
        PNP_CONVERTCODE(ISA0001),   // Standard VGA Card
        PNP_CONVERTCODE(ISA0002),   // Sound Card
        PNP_CONVERTCODE(ISAB701),   // Iomega PC2x SCSI Adapter
        PNP_CONVERTCODE(ISAB702),   // Iomega PC2F 8-bit SCSI Host Adapters
        PNP_CONVERTCODE(ISAB703),   // Iomega PC1600/PC800 SCSI Adapter
        PNP_CONVERTCODE(ISAB704),   // Iomega PC80/90 SCSI Adapter
        PNP_CONVERTCODE(ITC1001),   // Intel i486 EISA Evaluation Board
        PNP_CONVERTCODE(IVM0000),   // Iiyama LP-10xx ProLite
        PNP_CONVERTCODE(IVM0200),   // Iiyama Vision Master MF-8617
        PNP_CONVERTCODE(IVM0300),   // Iiyama Vision Master MF-8617A
        PNP_CONVERTCODE(IVM0400),   // Iiyama MT-0017
        PNP_CONVERTCODE(IVM1500),   // Iiyama Vision Master MF-8515G
        PNP_CONVERTCODE(IVM1510),   // Iiyama Vision Master MF-8515F
        PNP_CONVERTCODE(IVM1700),   // Iiyama Vision Master MF-8617E/T
        PNP_CONVERTCODE(IVM1701),   // Iiyama Vision Master MF-8617ES
        PNP_CONVERTCODE(IVM1730),   // Iiyama Vision Master Pro MT-9017E/T
        PNP_CONVERTCODE(IVM1731),   // Iiyama Vision Master Pro MT-9017ES
        PNP_CONVERTCODE(IVM2100),   // Iiyama Vision Master MF-8221E/T
        PNP_CONVERTCODE(IVM2130),   // Iiyama Vision Master Pro MT-9021E/T
        PNP_CONVERTCODE(KML0001),   // Mouse Kensington Expert
        PNP_CONVERTCODE(KTC0201),   // Kingston EtheRx KNE21xx Series
        PNP_CONVERTCODE(KTC2000),   // Kingston EtheRx KNE20 PnP ISA Adapter
        PNP_CONVERTCODE(KYE0001),   // Genius Easy Mouse
        PNP_CONVERTCODE(KYE0003),   // Genius NetMouse
        PNP_CONVERTCODE(LCS1001),   // LCS-8734 Ethernet
        PNP_CONVERTCODE(LGI8001),   // Mouse Logitech
        PNP_CONVERTCODE(LGI8002),   // Mouse Logitech
        PNP_CONVERTCODE(LGI800D),   // Mouse Logitech
        PNP_CONVERTCODE(LNE2000),   // Linksys Ether16 LAN Card
        PNP_CONVERTCODE(MAG00E3),   // MAG InnoVision DX17T
        PNP_CONVERTCODE(MAG11A6),   // MAG InnoVision DX1495
        PNP_CONVERTCODE(MAG15F4),   // MAG InnoVision DX1595
        PNP_CONVERTCODE(MAG4561),   // MAG InnoVision 410V2
        PNP_CONVERTCODE(MAG5541),   // MAG InnoVision DX500AV
        PNP_CONVERTCODE(MAG5620),   // MAG InnoVision DX1595
        PNP_CONVERTCODE(MAG5624),   // MAG InnoVision DX15T
        PNP_CONVERTCODE(MAG5662),   // MAG InnoVision 510V2
        PNP_CONVERTCODE(MAG5743),   // MAG InnoVision DJ530
        PNP_CONVERTCODE(MAG7626),   // MAG InnoVision DX1795
        PNP_CONVERTCODE(MAG7663),   // MAG InnoVision 710V2
        PNP_CONVERTCODE(MAG7740),   // MAG InnoVision DX700T
        PNP_CONVERTCODE(MAG7746),   // MAG InnoVision DJ700
        PNP_CONVERTCODE(MAG7747),   // MAG InnoVision DJ702e
        PNP_CONVERTCODE(MAG7748),   // MAG InnoVision DJ702e
        PNP_CONVERTCODE(MAG7752),   // MAG InnoVision DJ707
        PNP_CONVERTCODE(MAG7764),   // MAG InnoVision 720V2
        PNP_CONVERTCODE(MAG7842),   // MAG InnoVision DX715T
        PNP_CONVERTCODE(MAG7854),   // MAG InnoVision DJ717
        PNP_CONVERTCODE(MAG9156),   // MAG InnoVision DJ920
        PNP_CONVERTCODE(MAG9157),   // MAG InnoVision DJ925T
        PNP_CONVERTCODE(MDG0002),   // Madge Smart 16/4 EISA Ringnode
        PNP_CONVERTCODE(MDG0004),   // Madge Smart 16/4 EISA Ringnode Mk3
        PNP_CONVERTCODE(MDG0101),   // Madge Smart 16/4 ISA Client PnP Ringnode
        PNP_CONVERTCODE(MDY1900),   // Microdyne NE2500 Ethernet Adapter
        PNP_CONVERTCODE(MDY1901),   // Microdyne NE2500T Ethernet Adapter
        PNP_CONVERTCODE(MEI1604),   // Panasonic TX-D2151W-ES
        PNP_CONVERTCODE(MEI1610),   // Panasonic TX-D2151NM
        PNP_CONVERTCODE(MEL0040),   // Mitsubishi Diamond Pro 21TX (THN9105)
        PNP_CONVERTCODE(MEL2040),   // Mitsubishi Diamond Pro 20X (FR8905)
        PNP_CONVERTCODE(MEL4040),   // Mitsubishi Diamond Pro 17TX (TFG8705)
        PNP_CONVERTCODE(MEL408F),   // Mitsubishi Diamond Scan 15VX (SD58xx)
        PNP_CONVERTCODE(MEL409F),   // Mitsubishi RD15M
        PNP_CONVERTCODE(MEL40C0),   // Mitsubishi Diamond Pro 87TXM (TFM8705)
        PNP_CONVERTCODE(MEL6040),   // Mitsubishi Diamond Scan 17H (FFF8705)
        PNP_CONVERTCODE(MEL6140),   // Mitsubishi Diamond Scan 17HX
        PNP_CONVERTCODE(MEL8040),   // Mitsubishi Diamond Pro 15H (SD57xxC)
        PNP_CONVERTCODE(MIR0101),   // miroMAGIC Intelligent Graphics Board
        PNP_CONVERTCODE(MIR0721),   // miroPROOFSCREEN C21107
        PNP_CONVERTCODE(MIR0928),   // miroCRYSTAL / MAGIC / RAINBOW Video Adapter
        PNP_CONVERTCODE(MIR6815),   // miroD1568
        PNP_CONVERTCODE(MIR6817),   // miroPROOFSCREEN C1768
        PNP_CONVERTCODE(MIR6917),   // miroD1769
        PNP_CONVERTCODE(MIR8217),   // miroPROOFSCREEN C1782
        PNP_CONVERTCODE(MIR8520),   // miroPROOFSCREEN C2085 E
        PNP_CONVERTCODE(MIR8521),   // miroPROOFSCREEN C2185
        PNP_CONVERTCODE(MIR9321),   // miroPROOFSCREEN C2193
        PNP_CONVERTCODE(MON1423),   // Daewoo CMC-1423B1
        PNP_CONVERTCODE(MON1427),   // Daewoo CMC-1427X1
        PNP_CONVERTCODE(MON1502),   // Daewoo CMC-1502B1
        PNP_CONVERTCODE(MON1505),   // Daewoo CMC-1505X
        PNP_CONVERTCODE(MON1507),   // Daewoo CMC-1507X1
        PNP_CONVERTCODE(MON1703),   // Daewoo CMC-1703B
        PNP_CONVERTCODE(MON1704),   // Daewoo CMC-1704C
        PNP_CONVERTCODE(MOT1190),   // Motorola Lifestyle 28.8 Internal
        PNP_CONVERTCODE(MTC0001),   // MITAC 1450FV
        PNP_CONVERTCODE(MTC0002),   // MITAC 1564FS/D
        PNP_CONVERTCODE(MTC0003),   // MITAC 1450FD
        PNP_CONVERTCODE(MTC0004),   // MITAC 1769FD
        PNP_CONVERTCODE(MTX0150),   // Matrox MGA Graphics Accelerator Card
        PNP_CONVERTCODE(NAN0400),   // NANAO USA F2-15
        PNP_CONVERTCODE(NAN0401),   // NANAO USA F2-17
        PNP_CONVERTCODE(NAN0402),   // NANAO USA F2-17EX
        PNP_CONVERTCODE(NAN0403),   // NANAO USA F2-21
        PNP_CONVERTCODE(NAN0404),   // NANAO USA FX2-21
        PNP_CONVERTCODE(NAN0405),   // NANAO USA FlexScan T2-17TS
        PNP_CONVERTCODE(NAN0406),   // NANAO FlexScan 6600
        PNP_CONVERTCODE(NAN0502),   // NANAO 9060S
        PNP_CONVERTCODE(NAN0503),   // NANAO 9065S
        PNP_CONVERTCODE(NAN0506),   // NANAO 9070U
        PNP_CONVERTCODE(NAN0507),   // NANAO 9080i
        PNP_CONVERTCODE(NAN0508),   // NANAO 9400i
        PNP_CONVERTCODE(NAN0509),   // NANAO 9500
        PNP_CONVERTCODE(NAN050A),   // NANAO FlexScan F340iW
        PNP_CONVERTCODE(NAN050B),   // NANAO FlexScan F550i
        PNP_CONVERTCODE(NAN050C),   // NANAO FlexScan F550iW
        PNP_CONVERTCODE(NAN050D),   // NANAO FlexScan F560iW
        PNP_CONVERTCODE(NAN050E),   // NANAO FlexScan F750i
        PNP_CONVERTCODE(NAN050F),   // NANAO FlexScan F760iW
        PNP_CONVERTCODE(NAN0510),   // NANAO FlexScan F780iW
        PNP_CONVERTCODE(NAN0511),   // NANAO FlexScan T560i
        PNP_CONVERTCODE(NAN0512),   // NANAO FlexScan T660i
        PNP_CONVERTCODE(NAN0513),   // NANAO USA FlexScan T2-17
        PNP_CONVERTCODE(NAN0514),   // NANAO USA FlexScan T2-20
        PNP_CONVERTCODE(NAN0580),   // NANAO USA FlexScan 6300
        PNP_CONVERTCODE(NAN0800),   // NANAO FlexScan 33F
        PNP_CONVERTCODE(NAN0802),   // NANAO FlexScan 88F
        PNP_CONVERTCODE(NAN0805),   // NANAO FlexScan 54T
        PNP_CONVERTCODE(NAN0882),   // NANAO FlexScan 52F
        PNP_CONVERTCODE(NAN0900),   // NANAO FlexScan 6500
        PNP_CONVERTCODE(NAN0902),   // NANAO 9060S
        PNP_CONVERTCODE(NAN0906),   // NANAO 9070U
        PNP_CONVERTCODE(NAN0907),   // NANAO 9080i
        PNP_CONVERTCODE(NAN090A),   // NANAO FlexScan F347
        PNP_CONVERTCODE(NAN090B),   // NANAO FlexScan F550i
        PNP_CONVERTCODE(NAN090C),   // NANAO FlexScan F557
        PNP_CONVERTCODE(NAN090F),   // NANAO FlexScan 77F
        PNP_CONVERTCODE(NAN0910),   // NANAO FlexScan F780iJ
        PNP_CONVERTCODE(NAN0911),   // NANAO FlexScan T560iJ
        PNP_CONVERTCODE(NAN0912),   // NANAO FlexScan T660iJ
        PNP_CONVERTCODE(NAN0913),   // NANAO FlexScan 56T
        PNP_CONVERTCODE(NAN0914),   // NANAO FlexScan 68T
        PNP_CONVERTCODE(NAN098A),   // NANAO FlexScan F347II
        PNP_CONVERTCODE(NAN098C),   // NANAO FlexScan 55F
        PNP_CONVERTCODE(NAN098F),   // NANAO FlexScan 76F
        PNP_CONVERTCODE(NAN0991),   // NANAO FlexScan T567
        PNP_CONVERTCODE(NAN0993),   // NANAO FlexScan 53T
        PNP_CONVERTCODE(NEC2FB2),   // NEC LCD200
        PNP_CONVERTCODE(NEC3782),   // NEC LCD400
        PNP_CONVERTCODE(NEC37FA),   // NEC MultiSync XV14
        PNP_CONVERTCODE(NEC37FB),   // NEC MultiSync XV14
        PNP_CONVERTCODE(NEC3A66),   // NEC MultiSync C400
        PNP_CONVERTCODE(NEC3C00),   // NEC MultiSync XE15
        PNP_CONVERTCODE(NEC3C0A),   // NEC MultiSync XP15
        PNP_CONVERTCODE(NEC3C14),   // NEC MultiSync XV15
        PNP_CONVERTCODE(NEC3C1E),   // NEC MultiSync XE15
        PNP_CONVERTCODE(NEC3D5E),   // NEC MultiSync XV15+
        PNP_CONVERTCODE(NEC3D68),   // NEC MultiSync M500
        PNP_CONVERTCODE(NEC3D86),   // NEC MultiSync E500
        PNP_CONVERTCODE(NEC3D90),   // NEC MultiSync A500
        PNP_CONVERTCODE(NEC3E4E),   // NEC MultiSync C500
        PNP_CONVERTCODE(NEC43A8),   // NEC MultiSync XE17
        PNP_CONVERTCODE(NEC43B2),   // NEC MultiSync XE17
        PNP_CONVERTCODE(NEC43BC),   // NEC MultiSync XV17/XV17+
        PNP_CONVERTCODE(NEC43C6),   // NEC MultiSync M700
        PNP_CONVERTCODE(NEC43D0),   // NEC MultiSync A700
        PNP_CONVERTCODE(NEC4416),   // NEC MultiSync XP17
        PNP_CONVERTCODE(NEC4420),   // NEC MultiSync P750
        PNP_CONVERTCODE(NEC442A),   // NEC MultiSync XV17+ (-2)
        PNP_CONVERTCODE(NEC4434),   // NEC MultiSync E700
        PNP_CONVERTCODE(NEC533E),   // NEC MultiSync XE21
        PNP_CONVERTCODE(NEC53B6),   // NEC MultiSync XP21
        PNP_CONVERTCODE(NEC53C0),   // NEC MultiSync E1100
        PNP_CONVERTCODE(NEC53CA),   // NEC MultiSync P1150
        PNP_CONVERTCODE(NEC8201),   // NEC EISA SCSI Host Adapter
        PNP_CONVERTCODE(NIC1601),   // Tulip NCC16/NCC16HUB
        PNP_CONVERTCODE(NIC1602),   // Tulip NCC16/NCC16HUB
        PNP_CONVERTCODE(NMX0010),   // NeoMagic MagicGraph 128 VL
        PNP_CONVERTCODE(NOK0085),   // NOKIA 449E
        PNP_CONVERTCODE(NOK008D),   // NOKIA 449M
        PNP_CONVERTCODE(NOK0093),   // NOKIA 44BS
        PNP_CONVERTCODE(NOK0098),   // NOKIA 449X
        PNP_CONVERTCODE(NOK00A1),   // NOKIA 447Xa
        PNP_CONVERTCODE(NOK00A2),   // NOKIA 447B
        PNP_CONVERTCODE(NOK00A3),   // NOKIA 447KC
        PNP_CONVERTCODE(NOK00A5),   // NOKIA 447E
        PNP_CONVERTCODE(NOK00A9),   // NOKIA 447Xi
        PNP_CONVERTCODE(NOK00AB),   // NOKIA 447KA
        PNP_CONVERTCODE(NOK00AC),   // NOKIA 447L
        PNP_CONVERTCODE(NOK00AD),   // NOKIA 447M
        PNP_CONVERTCODE(NOK00B1),   // NOKIA 417X
        PNP_CONVERTCODE(NOK00B2),   // NOKIA 417M
        PNP_CONVERTCODE(NOK00B4),   // NOKIA 417TV
        PNP_CONVERTCODE(NOK00B6),   // NOKIA 447V
        PNP_CONVERTCODE(NOK00B7),   // NOKIA 447W
        PNP_CONVERTCODE(NOK00B8),   // NOKIA 447X
        PNP_CONVERTCODE(NOK00BB),   // NOKIA 447XAV
        PNP_CONVERTCODE(NOK00BC),   // NOKIA 447K
        PNP_CONVERTCODE(NOK00C1),   // NOKIA 445XAV
        PNP_CONVERTCODE(NOK00C7),   // NOKIA 445G
        PNP_CONVERTCODE(NOK00C9),   // NOKIA 445Xi
        PNP_CONVERTCODE(NOK00CB),   // NOKIA 445K
        PNP_CONVERTCODE(NOK00CD),   // NOKIA 445M
        PNP_CONVERTCODE(NOK00D0),   // NOKIA 445P
        PNP_CONVERTCODE(NOK00D2),   // NOKIA 445R
        PNP_CONVERTCODE(NOK00D8),   // NOKIA 445X
        PNP_CONVERTCODE(NOK01A0),   // NOKIA 447Xavc
        PNP_CONVERTCODE(NOK01C0),   // NOKIA 445Xavc
        PNP_CONVERTCODE(NSC8400),   // National Semiconductor NF3500 Network Adapter
        PNP_CONVERTCODE(NVL0701),   // Novel EISA NE3200 Ethernet
        PNP_CONVERTCODE(NVL0702),   // Novell/Anthem NE3200T
        PNP_CONVERTCODE(OEM5120),   // Token-Ring Network 16/4 Adapter II
        PNP_CONVERTCODE(OLC0701),   // HP ISA 16/4 Token-Ring (D2378A)
        PNP_CONVERTCODE(OLC0902),   // Olicom EISA 16/4 Token-Ring
        PNP_CONVERTCODE(OLC1201),   // Olicom 32 Bit EISA 16/4 Token-Ring
        PNP_CONVERTCODE(OLC9430),   // Olicom PnP Token-Ring ISA 16/4 (OC-3118)
        PNP_CONVERTCODE(OLC94A5),   // Olicom Ethernet ISA/IV Adapter
        PNP_CONVERTCODE(OPT0000),   // OPTi SoundExpression SRS Sound System
        PNP_CONVERTCODE(OPT0001),   // OPTi SoundExpression Game Port
        PNP_CONVERTCODE(OPT0002),   // OPTi SoundExpression MPU-401
        PNP_CONVERTCODE(OPT0005),   // OPTi SoundExpression SRS Sound Controller
        PNP_CONVERTCODE(OPT0006),   // OPTi PNP COM Port
        PNP_CONVERTCODE(OPT0007),   // OPTi PNP IDE Controller
        PNP_CONVERTCODE(OPT0931),   // OPTi 86C931 Audio Card
        PNP_CONVERTCODE(OPT9300),   // OPTi 930 Sound/OPL3 Device
        PNP_CONVERTCODE(OPT9301),   // OPTi 930 MPU-401 Device
        PNP_CONVERTCODE(OPT9310),   // OPTi PNP Sound System
        PNP_CONVERTCODE(OQI3138),   // OptiQuest VA656
        PNP_CONVERTCODE(OQI3232),   // OptiQuest 1562A
        PNP_CONVERTCODE(OQI3233),   // OptiQuest 1769DC
        PNP_CONVERTCODE(OQI3234),   // OptiQuest 1000S
        PNP_CONVERTCODE(OQI3332),   // OptiQuest V655
        PNP_CONVERTCODE(OQI3333),   // OptiQuest V775
        PNP_CONVERTCODE(OQI3432),   // OptiQuest V650
        PNP_CONVERTCODE(OQI4131),   // OptiQuest V641
        PNP_CONVERTCODE(OQI4431),   // OptiQuest V651
        PNP_CONVERTCODE(OQI4432),   // OptiQuest V655
        PNP_CONVERTCODE(OQI4637),   // OptiQuest 1769DC
        PNP_CONVERTCODE(OQI4731),   // OptiQuest V770
        PNP_CONVERTCODE(OQI4732),   // OptiQuest V775
        PNP_CONVERTCODE(PCT2880),   // PCtel HSP 336-Deluxe PnP
        PNP_CONVERTCODE(PGS003A),   // Princeton EO14
        PNP_CONVERTCODE(PGS003B),   // Princeton EO15
        PNP_CONVERTCODE(PGS003C),   // Princeton EO75
        PNP_CONVERTCODE(PGS003D),   // Princeton EO17
        PNP_CONVERTCODE(PGS003E),   // Princeton Ultra 17+
        PNP_CONVERTCODE(PGS003F),   // Princeton Ultra 20
        PNP_CONVERTCODE(PGS0049),   // Princeton Ultra 70F
        PNP_CONVERTCODE(PGS004D),   // Princeton Ultra 50
        PNP_CONVERTCODE(PGS004E),   // Princeton EO40
        PNP_CONVERTCODE(PGS004F),   // Princeton EO50
        PNP_CONVERTCODE(PGS0050),   // Princeton EO70
        PNP_CONVERTCODE(PGS0051),   // Princeton Ultra 40
        PNP_CONVERTCODE(PGS0052),   // Princeton EO72
        PNP_CONVERTCODE(PGS0055),   // Princeton EO74/74T
        PNP_CONVERTCODE(PGS0056),   // Princeton EO76/76T
        PNP_CONVERTCODE(PHL0045),   // Philips Brilliance AX4500
        PNP_CONVERTCODE(PHL0107),   // Philips Brilliance 107 (CM8800)
        PNP_CONVERTCODE(PHL0200),   // Philips CM0200 (15C)
        PNP_CONVERTCODE(PHL0201),   // Philips Brilliance 201CS (CM0900)
        PNP_CONVERTCODE(PHL0500),   // Philips CM0500 (20C)
        PNP_CONVERTCODE(PHL0700),   // Philips CM0700 (20T)
        PNP_CONVERTCODE(PHL0800),   // Philips CM0800 (15B)
        PNP_CONVERTCODE(PHL1021),   // Philips 201B
        PNP_CONVERTCODE(PHL104B),   // Philips 104B (CM1300)
        PNP_CONVERTCODE(PHL105A),   // Philips Brilliance 105 (CM2200)
        PNP_CONVERTCODE(PHL105B),   // Philips 105B (CM1200)
        PNP_CONVERTCODE(PHL105C),   // Philips 105S (CM1300)
        PNP_CONVERTCODE(PHL107B),   // Philips 107B (CM6800)
        PNP_CONVERTCODE(PHL107C),   // Philips 107S (CM6800)
        PNP_CONVERTCODE(PHL1107),   // Philips Brilliance 107
        PNP_CONVERTCODE(PHL1109),   // Philips Brilliance 109
        PNP_CONVERTCODE(PHL1121),   // Philips Brilliance 201
        PNP_CONVERTCODE(PHL114B),   // Magnavox MB4010 (CM1300)
        PNP_CONVERTCODE(PHL115B),   // Magnavox MB5314 (CM1200)
        PNP_CONVERTCODE(PHL115C),   // Magnavox MV5011 (CM1300)
        PNP_CONVERTCODE(PHL1200),   // Philips CM1200 (15A)
        PNP_CONVERTCODE(PHL1800),   // Philips CM1800 (15A)
        PNP_CONVERTCODE(PHL2000),   // Philips CM0200 (14B)
        PNP_CONVERTCODE(PHL200B),   // Philips 200B (CM5600)
        PNP_CONVERTCODE(PHL200D),   // Philips 200T (CM0700)
        PNP_CONVERTCODE(PHL201A),   // Philips Brilliance 201 (CM1700)
        PNP_CONVERTCODE(PHL201B),   // Philips 201B (CM0770)
        PNP_CONVERTCODE(PHL207C),   // Philips 17C6822E (107S)
        PNP_CONVERTCODE(PHL2600),   // Philips 17TCM26
        PNP_CONVERTCODE(PHL2800),   // Philips 17BCM28
        PNP_CONVERTCODE(PHL3800),   // Philips 17ACM38
        PNP_CONVERTCODE(PHL4500),   // Philips Brilliance AX4500
        PNP_CONVERTCODE(PHL5600),   // Philips CM5600 (200B)
        PNP_CONVERTCODE(PHL6800),   // Philips 107B (CM6800)
        PNP_CONVERTCODE(PHL700B),   // Philips CM0700 (21B)
        PNP_CONVERTCODE(PHL8000),   // Philips CM0800 (14A)
        PNP_CONVERTCODE(PHLA15B),   // Philips 105B (CM1300)
        PNP_CONVERTCODE(PHLA17B),   // Magnavox MB7000 (CM6800)
        PNP_CONVERTCODE(PHLA17C),   // Philips 107S (CM1300)
        PNP_CONVERTCODE(PNP0000),   // AT Interrupt Controller
        PNP_CONVERTCODE(PNP0001),   // EISA Interrupt Controller
        PNP_CONVERTCODE(PNP0002),   // MCA Interrupt Controller
        PNP_CONVERTCODE(PNP0003),   // APIC
        PNP_CONVERTCODE(PNP0004),   // Cyrix SLiC MP interrupt controller
        PNP_CONVERTCODE(PNP0100),   // AT Timer
        PNP_CONVERTCODE(PNP0101),   // EISA Timer
        PNP_CONVERTCODE(PNP0102),   // MCA Timer
        PNP_CONVERTCODE(PNP0200),   // AT DMA Controller
        PNP_CONVERTCODE(PNP0201),   // EISA DMA Controller
        PNP_CONVERTCODE(PNP0202),   // MCA DMA Controller
        PNP_CONVERTCODE(PNP0300),   // IBM PC/XT keyboard controller (83-key)
        PNP_CONVERTCODE(PNP0301),   // IBM PC/AT keyboard controller (86-key)
        PNP_CONVERTCODE(PNP0302),   // IBM PC/XT keyboard controller (84-key)
        PNP_CONVERTCODE(PNP0303),   // IBM Enhanced keyboard controller (101/2-key)
        PNP_CONVERTCODE(PNP0304),   // Olivetti Keyboard (83-key)
        PNP_CONVERTCODE(PNP0305),   // Olivetti Keyboard (102-key)
        PNP_CONVERTCODE(PNP0306),   // Olivetti Keyboard (86-key)
        PNP_CONVERTCODE(PNP0307),   // Microsoft Windows(R) Keyboard
        PNP_CONVERTCODE(PNP0308),   // General Input Device Emulation Interface (GIDEI)
        PNP_CONVERTCODE(PNP0309),   // Olivetti Keyboard (A101/102 key)
        PNP_CONVERTCODE(PNP030A),   // AT&T 302 keyboard
        PNP_CONVERTCODE(PNP030B),   // Reserved by Microsoft
        PNP_CONVERTCODE(PNP0320),   // Japanese 106-key keyboard A01
        PNP_CONVERTCODE(PNP0321),   // Japanese 101-key keyboard
        PNP_CONVERTCODE(PNP0322),   // Japanese AX keyboard
        PNP_CONVERTCODE(PNP0323),   // Japanese 106-key keyboard 002/003
        PNP_CONVERTCODE(PNP0324),   // Japanese 106-key keyboard 001
        PNP_CONVERTCODE(PNP0325),   // Japanese Toshiba Desktop keyboard
        PNP_CONVERTCODE(PNP0326),   // Japanese Toshiba Laptop keyboard
        PNP_CONVERTCODE(PNP0327),   // Japanese Toshiba Notebook keyboard
        PNP_CONVERTCODE(PNP0340),   // Korean 84-key keyboard
        PNP_CONVERTCODE(PNP0341),   // Korean 86-key keyboard
        PNP_CONVERTCODE(PNP0342),   // Korean Enhanced keyboard
        PNP_CONVERTCODE(PNP0343),   // Korean Enhanced keyboard 101b/c
        PNP_CONVERTCODE(PNP0344),   // Korean Enhanced keyboard 103
        PNP_CONVERTCODE(PNP0400),   // Standard LPT printer port
        PNP_CONVERTCODE(PNP0401),   // ECP printer port
        PNP_CONVERTCODE(PNP0500),   // Standard PC COM port
        PNP_CONVERTCODE(PNP0501),   // 16550A-compatible COM port
        PNP_CONVERTCODE(PNP0502),   // Multiport serial device (non-intelligent 16550)
        PNP_CONVERTCODE(PNP0510),   // Generic IRDA-compatible device
        PNP_CONVERTCODE(PNP0600),   // Generic ESDI/IDE/ATA compatible hard disk controller
        PNP_CONVERTCODE(PNP0601),   // Plus Hardcard II
        PNP_CONVERTCODE(PNP0602),   // Plus Hardcard IIXL/EZ
        PNP_CONVERTCODE(PNP0603),   // Generic IDE supporting Microsoft Device Bay
        PNP_CONVERTCODE(PNP0604),   // PC standard floppy disk controller
        PNP_CONVERTCODE(PNP0605),   // HP Omnibook floppy disk controller	
        PNP_CONVERTCODE(PNP0680),   // Bus Master E-IDE controller
        PNP_CONVERTCODE(PNP0700),   // PC standard floppy disk controller
        PNP_CONVERTCODE(PNP0701),   // Standard floppy controller supporting MS Device Bay
        PNP_CONVERTCODE(PNP0800),   // AT standard speaker sound
        PNP_CONVERTCODE(PNP0802),   // Microsoft Sound System compatible device
        PNP_CONVERTCODE(PNP0900),   // VGA Compatible
        PNP_CONVERTCODE(PNP0901),   // Video Seven VRAM/VRAM II/1024i 
        PNP_CONVERTCODE(PNP0902),   // 8514/A Compatible
        PNP_CONVERTCODE(PNP0903),   // Trident VGA
        PNP_CONVERTCODE(PNP0904),   // Cirrus Logic Laptop VGA
        PNP_CONVERTCODE(PNP0905),   // Cirrus Logic VGA
        PNP_CONVERTCODE(PNP0906),   // Tseng Labs ET4000
        PNP_CONVERTCODE(PNP0907),   // Western Digital VGA
        PNP_CONVERTCODE(PNP0908),   // Western Digital Laptop VGA
        PNP_CONVERTCODE(PNP0909),   // S3 Inc. 911/924 VGA
        PNP_CONVERTCODE(PNP090A),   // ATI Ultra Pro/Plus (Mach 32)
        PNP_CONVERTCODE(PNP090B),   // ATI Ultra (Mach 8)
        PNP_CONVERTCODE(PNP090C),   // XGA Compatible
        PNP_CONVERTCODE(PNP090D),   // ATI VGA Wonder
        PNP_CONVERTCODE(PNP090E),   // Weitek P9000 Graphics Adapter
        PNP_CONVERTCODE(PNP090F),   // Oak Technology VGA
        PNP_CONVERTCODE(PNP0910),   // Compaq QVision
        PNP_CONVERTCODE(PNP0911),   // IBM XGA/2
        PNP_CONVERTCODE(PNP0912),   // Tseng Labs W32/W32i/W32p
        PNP_CONVERTCODE(PNP0913),   // S3 Inc. 801/928/964
        PNP_CONVERTCODE(PNP0914),   // Cirrus Logic 5429/5434 (memory mapped)
        PNP_CONVERTCODE(PNP0915),   // Compaq Advanced VGA (AVGA)
        PNP_CONVERTCODE(PNP0916),   // ATI Ultra Pro Turbo (Mach64)
        PNP_CONVERTCODE(PNP0917),   // Reserved by Microsoft
        PNP_CONVERTCODE(PNP0918),   // Matrox MGA
        PNP_CONVERTCODE(PNP0919),   // Compaq QVision 2000
        PNP_CONVERTCODE(PNP091A),   // Tseng W128
        PNP_CONVERTCODE(PNP0930),   // Chips & Technologies Super VGA
        PNP_CONVERTCODE(PNP0931),   // Chips & Technologies Accelerator
        PNP_CONVERTCODE(PNP0940),   // NCR 77c22e Super VGA
        PNP_CONVERTCODE(PNP0941),   // NCR 77c32blt
        PNP_CONVERTCODE(PNP09FF),   // Plug and Play Monitors (VESA DDC)
        PNP_CONVERTCODE(PNP0A00),   // ISA Bus
        PNP_CONVERTCODE(PNP0A01),   // EISA Bus
        PNP_CONVERTCODE(PNP0A02),   // MCA Bus
        PNP_CONVERTCODE(PNP0A03),   // PCI Bus
        PNP_CONVERTCODE(PNP0A04),   // VESA/VL Bus
        PNP_CONVERTCODE(PNP0A05),   // Generic ACPI Bus
        PNP_CONVERTCODE(PNP0A06),   // Generic ACPI Extended-IO Bus (EIO bus)
        PNP_CONVERTCODE(PNP0B00),   // AT Real-Time Clock
        PNP_CONVERTCODE(PNP0C00),   // Plug and Play BIOS 
        PNP_CONVERTCODE(PNP0C01),   // System Board
        PNP_CONVERTCODE(PNP0C02),   // Motherboard registers
        PNP_CONVERTCODE(PNP0C03),   // Plug and Play BIOS Event Notification Interrupt
        PNP_CONVERTCODE(PNP0C04),   // Math Coprocessor
        PNP_CONVERTCODE(PNP0C05),   // APM BIOS (Version independent)
        PNP_CONVERTCODE(PNP0C06),   // Reserved for early Plug and Play BIOS implementation
        PNP_CONVERTCODE(PNP0C07),   // Reserved for early Plug and Play BIOS implementation
        PNP_CONVERTCODE(PNP0C08),   // ACPI system board hardware
        PNP_CONVERTCODE(PNP0C09),   // ACPI Embedded Controller
        PNP_CONVERTCODE(PNP0C0A),   // ACPI Control Method Battery
        PNP_CONVERTCODE(PNP0C0B),   // ACPI Fan
        PNP_CONVERTCODE(PNP0C0C),   // ACPI power button device
        PNP_CONVERTCODE(PNP0C0D),   // ACPI lid device
        PNP_CONVERTCODE(PNP0C0E),   // ACPI sleep button device
        PNP_CONVERTCODE(PNP0C0F),   // PCI interrupt link device
        PNP_CONVERTCODE(PNP0C10),   // ACPI system indicator device
        PNP_CONVERTCODE(PNP0C11),   // ACPI thermal zone
        PNP_CONVERTCODE(PNP0C12),   // Device Bay Controller
        PNP_CONVERTCODE(PNP0CF0),   // Compaq LTE Lite Support
        PNP_CONVERTCODE(PNP0CF1),   // Compaq LTE Elite Support
        PNP_CONVERTCODE(PNP0E00),   // Intel 82365-Compatible PCMCIA Controller
        PNP_CONVERTCODE(PNP0E01),   // Cirrus Logic CL-PD6720 PCMCIA Controller
        PNP_CONVERTCODE(PNP0E02),   // VLSI VL82C146 PCMCIA Controller
        PNP_CONVERTCODE(PNP0E03),   // Intel 82365-compatible CardBus controller
        PNP_CONVERTCODE(PNP0F00),   // Microsoft Bus Mouse
        PNP_CONVERTCODE(PNP0F01),   // Microsoft Serial Mouse
        PNP_CONVERTCODE(PNP0F02),   // Microsoft InPort Mouse
        PNP_CONVERTCODE(PNP0F03),   // Microsoft PS/2-style Mouse
        PNP_CONVERTCODE(PNP0F04),   // Mouse Systems Mouse
        PNP_CONVERTCODE(PNP0F05),   // Mouse Systems 3-Button Mouse (COM2)
        PNP_CONVERTCODE(PNP0F06),   // Genius Mouse (COM1)
        PNP_CONVERTCODE(PNP0F07),   // Genius Mouse (COM2)
        PNP_CONVERTCODE(PNP0F08),   // Logitech Serial Mouse
        PNP_CONVERTCODE(PNP0F09),   // Microsoft BallPoint Serial Mouse
        PNP_CONVERTCODE(PNP0F0A),   // Microsoft Plug and Play Mouse
        PNP_CONVERTCODE(PNP0F0B),   // Microsoft Plug and Play BallPoint Mouse
        PNP_CONVERTCODE(PNP0F0C),   // Microsoft-compatible Serial Mouse
        PNP_CONVERTCODE(PNP0F0D),   // Microsoft-compatible InPort-compatible Mouse
        PNP_CONVERTCODE(PNP0F0E),   // Microsoft-compatible PS/2-style Mouse
        PNP_CONVERTCODE(PNP0F0F),   // Microsoft-compatible Serial BallPoint-compatible Mouse
        PNP_CONVERTCODE(PNP0F10),   // Texas Instruments QuickPort Mouse
        PNP_CONVERTCODE(PNP0F11),   // Microsoft-compatible Bus Mouse
        PNP_CONVERTCODE(PNP0F12),   // Logitech PS/2-style Mouse
        PNP_CONVERTCODE(PNP0F13),   // PS/2 Port for PS/2-style Mice
        PNP_CONVERTCODE(PNP0F14),   // Microsoft Kids Mouse
        PNP_CONVERTCODE(PNP0F15),   // Logitech bus mouse
        PNP_CONVERTCODE(PNP0F16),   // Logitech SWIFT device
        PNP_CONVERTCODE(PNP0F17),   // Logitech-compatible serial mouse
        PNP_CONVERTCODE(PNP0F18),   // Logitech-compatible bus mouse
        PNP_CONVERTCODE(PNP0F19),   // Logitech-compatible PS/2-style Mouse
        PNP_CONVERTCODE(PNP0F1A),   // Logitech-compatible SWIFT Device
        PNP_CONVERTCODE(PNP0F1B),   // HP Omnibook Mouse
        PNP_CONVERTCODE(PNP0F1C),   // Compaq LTE Trackball PS/2-style Mouse
        PNP_CONVERTCODE(PNP0F1D),   // Compaq LTE Trackball Serial Mouse
        PNP_CONVERTCODE(PNP0F1E),   // Microsoft Kids Trackball Mouse
        PNP_CONVERTCODE(PNP0F1F),   // Reserved by Microsoft Input Device Group
        PNP_CONVERTCODE(PNP0F20),   // Reserved by Microsoft Input Device Group
        PNP_CONVERTCODE(PNP0F21),   // Reserved by Microsoft Input Device Group
        PNP_CONVERTCODE(PNP0F22),   // Reserved by Microsoft Input Device Group
        PNP_CONVERTCODE(PNP0F23),   // Reserved by Microsoft Input Device Group
        PNP_CONVERTCODE(PNP0FFF),   // Reserved by Microsoft Systems
        PNP_CONVERTCODE(PNP8000),   // Network Adapter
        PNP_CONVERTCODE(PNP8001),   // Novell/Anthem NE3200
        PNP_CONVERTCODE(PNP8004),   // Compaq NE3200
        PNP_CONVERTCODE(PNP8006),   // Intel EtherExpress/32
        PNP_CONVERTCODE(PNP8008),   // HP EtherTwist EISA LAN Adapter/32 (HP27248A)
        PNP_CONVERTCODE(PNP8065),   // Ungermann-Bass NIUps or NIUps/EOTP
        PNP_CONVERTCODE(PNP8072),   // DEC (DE211) EtherWorks MC/TP
        PNP_CONVERTCODE(PNP8073),   // DEC (DE212) EtherWorks MC/TP_BNC
        PNP_CONVERTCODE(PNP8074),   // HP MC LAN Adapter/16 TP (PC27246)
        PNP_CONVERTCODE(PNP8078),   // DCA 10 Mb MCA
        PNP_CONVERTCODE(PNP807F),   // Racal NI9210
        PNP_CONVERTCODE(PNP8081),   // Pure Data Ethernet
        PNP_CONVERTCODE(PNP8096),   // Thomas-Conrad TC4046
        PNP_CONVERTCODE(PNP80C9),   // IBM Token Ring
        PNP_CONVERTCODE(PNP80CA),   // IBM Token Ring II
        PNP_CONVERTCODE(PNP80CB),   // IBM Token Ring II/Short
        PNP_CONVERTCODE(PNP80CC),   // IBM Token Ring 4/16Mbs
        PNP_CONVERTCODE(PNP80D3),   // Novell/Anthem NE1000
        PNP_CONVERTCODE(PNP80D4),   // Novell/Anthem NE2000
        PNP_CONVERTCODE(PNP80D5),   // NE1000 Compatible
        PNP_CONVERTCODE(PNP80D6),   // NE2000 Compatible
        PNP_CONVERTCODE(PNP80D7),   // Novell/Anthem NE1500T
        PNP_CONVERTCODE(PNP80D8),   // Novell/Anthem NE2100
        PNP_CONVERTCODE(PNP80D9),   // NE2000 Plus
        PNP_CONVERTCODE(PNP80DD),   // SMC ARCNETPC
        PNP_CONVERTCODE(PNP80DE),   // SMC ARCNET PC100, PC200
        PNP_CONVERTCODE(PNP80DF),   // SMC ARCNET PC110, PC210, PC250
        PNP_CONVERTCODE(PNP80E0),   // SMC ARCNET PC130/E
        PNP_CONVERTCODE(PNP80E1),   // SMC ARCNET PC120, PC220, PC260
        PNP_CONVERTCODE(PNP80E2),   // SMC ARCNET PC270/E
        PNP_CONVERTCODE(PNP80E5),   // SMC ARCNET PC600W, PC650W
        PNP_CONVERTCODE(PNP80E7),   // DEC DEPCA
        PNP_CONVERTCODE(PNP80E8),   // DEC (DE100) EtherWorks LC
        PNP_CONVERTCODE(PNP80E9),   // DEC (DE200) EtherWorks Turbo
        PNP_CONVERTCODE(PNP80EA),   // DEC (DE101) EtherWorks LC/TP
        PNP_CONVERTCODE(PNP80EB),   // DEC (DE201) EtherWorks Turbo/TP
        PNP_CONVERTCODE(PNP80EC),   // DEC (DE202) EtherWorks Turbo/TP_BNC
        PNP_CONVERTCODE(PNP80ED),   // DEC (DE102) EtherWorks LC/TP_BNC
        PNP_CONVERTCODE(PNP80EE),   // DEC EE101 (Built-In)
        PNP_CONVERTCODE(PNP80EF),   // DECpc 433 WS (Built-In)
        PNP_CONVERTCODE(PNP80F1),   // 3Com EtherLink Plus
        PNP_CONVERTCODE(PNP80F3),   // 3Com EtherLink II or IITP (8 or 16-bit)
        PNP_CONVERTCODE(PNP80F4),   // 3Com TokenLink
        PNP_CONVERTCODE(PNP80F6),   // 3Com EtherLink 16
        PNP_CONVERTCODE(PNP80F7),   // 3Com EtherLink III
        PNP_CONVERTCODE(PNP80F8),   // 3Com Generic Etherlink Plug and Play Device
        PNP_CONVERTCODE(PNP80FB),   // Thomas Conrad TC6045
        PNP_CONVERTCODE(PNP80FC),   // Thomas Conrad TC6042
        PNP_CONVERTCODE(PNP80FD),   // Thomas Conrad TC6142
        PNP_CONVERTCODE(PNP80FE),   // Thomas Conrad TC6145
        PNP_CONVERTCODE(PNP80FF),   // Thomas Conrad TC6242
        PNP_CONVERTCODE(PNP8100),   // Thomas Conrad TC6245
        PNP_CONVERTCODE(PNP8101),   // Thomas-Conrad TC4045
        PNP_CONVERTCODE(PNP8104),   // Thomas-Conrad TC4035
        PNP_CONVERTCODE(PNP8105),   // DCA 10 MB
        PNP_CONVERTCODE(PNP8106),   // DCA 10 MB Fiber Optic
        PNP_CONVERTCODE(PNP8107),   // DCA 10 MB Twisted Pair
        PNP_CONVERTCODE(PNP8113),   // Racal NI6510
        PNP_CONVERTCODE(PNP8114),   // Racal NI5210/8 or NI5210/16
        PNP_CONVERTCODE(PNP8119),   // UB pcNIU
        PNP_CONVERTCODE(PNP811A),   // UB pcNIU/ex 128K
        PNP_CONVERTCODE(PNP811B),   // UB pcNIU/ex 512K
        PNP_CONVERTCODE(PNP811C),   // Ungermann-Bass NIUpc
        PNP_CONVERTCODE(PNP811D),   // UB NIUpc/3270
        PNP_CONVERTCODE(PNP8120),   // Ungermann-Bass NIUpc/EOTP
        PNP_CONVERTCODE(PNP8123),   // SMC StarCard PLUS (WD/8003S)
        PNP_CONVERTCODE(PNP8124),   // SMC StarCard PLUS With On Board Hub (WD/8003SH)
        PNP_CONVERTCODE(PNP8125),   // SMC EtherCard PLUS (WD/8003E)
        PNP_CONVERTCODE(PNP8126),   // SMC EtherCard PLUS With Boot ROM Socket (WD/8003EBT)
        PNP_CONVERTCODE(PNP8127),   // SMC EtherCard PLUS With Boot ROM Socket (WD/8003EB)
        PNP_CONVERTCODE(PNP8128),   // SMC EtherCard PLUS TP (WD/8003WT)
        PNP_CONVERTCODE(PNP812A),   // SMC EtherCard PLUS 16 With Boot ROM Socket (WD/8013EBT)
        PNP_CONVERTCODE(PNP812D),   // Intel EtherExpress 16 or 16TP
        PNP_CONVERTCODE(PNP812F),   // Intel TokenExpress 16/4
        PNP_CONVERTCODE(PNP8130),   // Intel TokenExpress MCA 16/4
        PNP_CONVERTCODE(PNP8132),   // Intel EtherExpress 16 (MCA)
        PNP_CONVERTCODE(PNP8133),   // Compaq Ethernet 16E
        PNP_CONVERTCODE(PNP8137),   // Artisoft AE-1
        PNP_CONVERTCODE(PNP8138),   // Artisoft AE-2 or AE-3
        PNP_CONVERTCODE(PNP8141),   // Amplicard AC 210/XT
        PNP_CONVERTCODE(PNP8142),   // Amplicard AC 210/AT
        PNP_CONVERTCODE(PNP814B),   // Everex SpeedLink /PC16 (EV2027)
        PNP_CONVERTCODE(PNP8155),   // HP PC LAN Adapter/8 TP (HP27245)
        PNP_CONVERTCODE(PNP8156),   // HP PC LAN Adapter/16 TP (HP27247A)
        PNP_CONVERTCODE(PNP8157),   // HP PC LAN Adapter/8 TL (HP27250)
        PNP_CONVERTCODE(PNP8158),   // HP PC LAN Adapter/16 TP Plus (HP27247B)
        PNP_CONVERTCODE(PNP8159),   // HP PC LAN Adapter/16 TL Plus (HP27252)
        PNP_CONVERTCODE(PNP815F),   // National Semiconductor Ethernode *16AT
        PNP_CONVERTCODE(PNP8160),   // National Semiconductor AT/LANTIC EtherNODE 16-AT3
        PNP_CONVERTCODE(PNP8169),   // NCR StarCard
        PNP_CONVERTCODE(PNP816A),   // NCR Token-Ring 4 Mbs ISA
        PNP_CONVERTCODE(PNP816B),   // NCR WaveLAN AT
        PNP_CONVERTCODE(PNP816C),   // NCR WaveLan MC
        PNP_CONVERTCODE(PNP816D),   // NCR Token-Ring 16/4 Mbs ISA
        PNP_CONVERTCODE(PNP8191),   // Olicom 16/4 Token-Ring Adapter
        PNP_CONVERTCODE(PNP81A5),   // Research Machines Ethernet
        PNP_CONVERTCODE(PNP81B9),   // ToshibaLAN (internal)
        PNP_CONVERTCODE(PNP81C3),   // SMC EtherCard PLUS Elite (WD/8003EP)
        PNP_CONVERTCODE(PNP81C4),   // SMC EtherCard PLUS 10T (WD/8003W)
        PNP_CONVERTCODE(PNP81C5),   // SMC EtherCard PLUS Elite 16 (WD/8013EP)
        PNP_CONVERTCODE(PNP81C6),   // SMC EtherCard PLUS Elite 16T (WD/8013W)
        PNP_CONVERTCODE(PNP81C7),   // SMC EtherCard PLUS Elite 16 Combo (WD/8013EW or 8013EWC)
        PNP_CONVERTCODE(PNP81C8),   // SMC EtherElite Ultra 16
        PNP_CONVERTCODE(PNP81C9),   // SMC TigerCard (8216L, 8216LC, 8216LT)
        PNP_CONVERTCODE(PNP81CA),   // SMC EtherEZ (8416)
        PNP_CONVERTCODE(PNP81D7),   // Madge Smart 16/4 PC Ringnode
        PNP_CONVERTCODE(PNP81D8),   // Madge Smart 16/4 Ringnode ISA
        PNP_CONVERTCODE(PNP81E4),   // Pure Data PDI9025-32 (Token Ring)
        PNP_CONVERTCODE(PNP81E6),   // Pure Data PDI508+ (ArcNet)
        PNP_CONVERTCODE(PNP81E7),   // Pure Data PDI516+ (ArcNet)
        PNP_CONVERTCODE(PNP81EB),   // Proteon Token Ring (P1390)
        PNP_CONVERTCODE(PNP81EC),   // Proteon Token Ring (P1392)
        PNP_CONVERTCODE(PNP81ED),   // Proteon ISA Token Ring (1340)
        PNP_CONVERTCODE(PNP81EE),   // Proteon ISA Token Ring (1342)
        PNP_CONVERTCODE(PNP81EF),   // Proteon ISA Token Ring (1346)
        PNP_CONVERTCODE(PNP81F0),   // Proteon ISA Token Ring (1347)
        PNP_CONVERTCODE(PNP81FF),   // Cabletron E2000 Series DNI
        PNP_CONVERTCODE(PNP8200),   // Cabletron E2100 Series DNI
        PNP_CONVERTCODE(PNP8201),   // Cabletron T2015 4/16 Mbit/s DNI
        PNP_CONVERTCODE(PNP8209),   // Zenith Data Systems Z-Note
        PNP_CONVERTCODE(PNP820A),   // Zenith Data Systems NE2000-Compatible
        PNP_CONVERTCODE(PNP8213),   // Xircom Pocket Ethernet II
        PNP_CONVERTCODE(PNP8214),   // Xircom Pocket Ethernet I
        PNP_CONVERTCODE(PNP8215),   // Xircom Pocket Ethernet III Adapter
        PNP_CONVERTCODE(PNP821D),   // RadiSys EXM-10
        PNP_CONVERTCODE(PNP8227),   // SMC 3000 Series
        PNP_CONVERTCODE(PNP8228),   // SMC 91C2 controller
        PNP_CONVERTCODE(PNP8231),   // Advanced Micro Devices AM2100/AM1500T
        PNP_CONVERTCODE(PNP824F),   // RCE 10Base-T (16 bit)
        PNP_CONVERTCODE(PNP8250),   // RCE 10Base-T (8 bit)
        PNP_CONVERTCODE(PNP8263),   // Tulip NCC-16
        PNP_CONVERTCODE(PNP8277),   // Exos 105
        PNP_CONVERTCODE(PNP828A),   // Intel '595 based Ethernet
        PNP_CONVERTCODE(PNP828B),   // TI2000-style Token Ring
        PNP_CONVERTCODE(PNP828C),   // AMD PCNet Family cards
        PNP_CONVERTCODE(PNP828D),   // AMD PCNet32 (VL version)
        PNP_CONVERTCODE(PNP8294),   // IrDA Infrared NDIS driver (Microsoft-supplied)
        PNP_CONVERTCODE(PNP82BD),   // IBM PCMCIA-NIC
        PNP_CONVERTCODE(PNP82C0),   // Eagle Technology NE200T
        PNP_CONVERTCODE(PNP82C2),   // Xircom CE10
        PNP_CONVERTCODE(PNP82C3),   // Xircom CEM2
        PNP_CONVERTCODE(PNP82C4),   // Xircom CE2
        PNP_CONVERTCODE(PNP8321),   // DEC Ethernet (All Types)
        PNP_CONVERTCODE(PNP8323),   // SMC EtherCard (All Types except 8013/A)
        PNP_CONVERTCODE(PNP8324),   // ARCNET Compatible
        PNP_CONVERTCODE(PNP8325),   // SMC TokenCard PLUS (8115T)
        PNP_CONVERTCODE(PNP8326),   // Thomas Conrad (All Arcnet Types)
        PNP_CONVERTCODE(PNP8327),   // IBM Token Ring (All Types)
        PNP_CONVERTCODE(PNP8328),   // UB NIU
        PNP_CONVERTCODE(PNP8329),   // Proteon ProNET-4/16 ISA Token Ring (P1392+,P1392,1390)
        PNP_CONVERTCODE(PNP8385),   // Remote Network Access Driver
        PNP_CONVERTCODE(PNP8387),   // RNA Point-to-point Protocol Driver
        PNP_CONVERTCODE(PNP8388),   // Reserved for Microsoft Networking components
        PNP_CONVERTCODE(PNP8389),   // Peer IrLAN infrared driver (Microsoft-supplied)
        PNP_CONVERTCODE(PNP8390),   // Generic network adapter
        PNP_CONVERTCODE(PNP9000),   // Modem
        PNP_CONVERTCODE(PNPA000),   // Adaptec 154x compatible SCSI controoler
        PNP_CONVERTCODE(PNPA001),   // Adaptec 174x compatible SCSI controller
        PNP_CONVERTCODE(PNPA002),   // Future Domain 16-700 compatible controller
        PNP_CONVERTCODE(PNPA003),   // Panasonic proprietary CD-ROM adapter (SBPro/SB16)
        PNP_CONVERTCODE(PNPA01B),   // Trantor 128 SCSI Controller
        PNP_CONVERTCODE(PNPA01D),   // Trantor T160 SCSI Controller
        PNP_CONVERTCODE(PNPA01E),   // Trantor T338 Parallel SCSI controller
        PNP_CONVERTCODE(PNPA01F),   // Trantor T348 Parallel SCSI controller
        PNP_CONVERTCODE(PNPA020),   // Trantor Media Vision SCSI controller
        PNP_CONVERTCODE(PNPA022),   // Always IN-2000 SCSI controller
        PNP_CONVERTCODE(PNPA02B),   // Sony proprietary CD-ROM controller
        PNP_CONVERTCODE(PNPA02D),   // Trantor T13b 8-bit SCSI controller
        PNP_CONVERTCODE(PNPA02F),   // Trantor T358 Parallel SCSI controller
        PNP_CONVERTCODE(PNPA030),   // Mitsumi LU-005 Single Speed CD-ROM controller + drive
        PNP_CONVERTCODE(PNPA031),   // Mitsumi FX-001 Single Speed CD-ROM controller + drive
        PNP_CONVERTCODE(PNPA032),   // Mitsumi FX-001 Double Speed CD-ROM controller + drive
        PNP_CONVERTCODE(PNPB000),   // Sound Blaster 1.5 sound device
        PNP_CONVERTCODE(PNPB001),   // Sound Blaster 2.0 sound device
        PNP_CONVERTCODE(PNPB002),   // Sound Blaster Pro sound device
        PNP_CONVERTCODE(PNPB003),   // Sound Blaster 16 sound device
        PNP_CONVERTCODE(PNPB004),   // Thunderboard-compatible sound device
        PNP_CONVERTCODE(PNPB005),   // Adlib-compatible FM synthesizer device
        PNP_CONVERTCODE(PNPB006),   // MPU401 compatible 
        PNP_CONVERTCODE(PNPB007),   // Microsoft Windows Sound System-compatible sound device
        PNP_CONVERTCODE(PNPB008),   // Compaq Business Audio
        PNP_CONVERTCODE(PNPB009),   // Plug and Play Microsoft Windows Sound System Device
        PNP_CONVERTCODE(PNPB00A),   // MediaVision Pro Audio Spectrum (Trantor SCSI enabled, Thunder Chip Disabled)
        PNP_CONVERTCODE(PNPB00B),   // MediaVision Pro Audio 3D
        PNP_CONVERTCODE(PNPB00C),   // MusicQuest MQX-32M
        PNP_CONVERTCODE(PNPB00D),   // MediaVision Pro Audio Spectrum Basic (No Trantor SCSI, Thunder Chip Enabled)
        PNP_CONVERTCODE(PNPB00E),   // MediaVision Pro Audio Spectrum (Trantor SCSI enabled, Thunder Chip Enabled)
        PNP_CONVERTCODE(PNPB00F),   // MediaVision Jazz-16 chipset (OEM Versions)
        PNP_CONVERTCODE(PNPB010),   // Auravision VxP500 chipset - Orchid Videola
        PNP_CONVERTCODE(PNPB018),   // MediaVision Pro Audio Spectrum 8-bit
        PNP_CONVERTCODE(PNPB019),   // MediaVision Pro Audio Spectrum Basic (no Trantor SCSI, Thunder chip Disabled)
        PNP_CONVERTCODE(PNPB020),   // Yamaha OPL3-compatible FM synthesizer device
        PNP_CONVERTCODE(PNPB02F),   // Joystick/Game port
        PNP_CONVERTCODE(PNPB077),   // OAK Mozart Sound System
        PNP_CONVERTCODE(PNPB078),   // OAK Mozart Sound System MPU-401
        PNP_CONVERTCODE(PNPC000),   // Compaq 14400 Modem (TBD)
        PNP_CONVERTCODE(PNPC001),   // Compaq 2400/9600 Modem (TBD)
        PNP_CONVERTCODE(PNPD300),   // SK-NET TR4/16+ Token-Ring
        PNP_CONVERTCODE(PNPE000),   // SK-NET G16, G16/TP Ethernet
        PNP_CONVERTCODE(PNPF000),   // SK-NET FDDI-FI FDDI LAN
        PNP_CONVERTCODE(PNPFFFF),   // Non-PnP Device(s) Resource(s) (Added by Windows 95)
        PNP_CONVERTCODE(PRO6000),   // Proteon ProNET-4/16 EISA Token Ring (P1990)
        PNP_CONVERTCODE(PRO6001),   // Proteon ProNET-4/16 EISA Token Ring (P1990)
        PNP_CONVERTCODE(PRO6002),   // Proteon ProNET-4/16 EISA Token Ring (P1990) Plus
        PNP_CONVERTCODE(RII0100),   // Racal InterLAN ES3210 Network Adapter
        PNP_CONVERTCODE(RII0101),   // Racal ES3210 EISA Adapter
        PNP_CONVERTCODE(ROK0010),   // Rockwell RCV144ACF DP V.32b CK2
        PNP_CONVERTCODE(RTI1600),   // RT1600/E SCSI Miniport Driver
        PNP_CONVERTCODE(RTL8019),   // Realtek RTL8019 Ethernet NIC
        PNP_CONVERTCODE(RTL8029),   // Realtek RTL8029 Ethernet NIC
        PNP_CONVERTCODE(SAM0000),   // Samsung SyncMaster 3Ne
        PNP_CONVERTCODE(SAM0100),   // Samsung SyncMaster 4S
        PNP_CONVERTCODE(SAM1530),   // Samsung SyncMaster 15GLsi
        PNP_CONVERTCODE(SAM1C53),   // Samsung SyncMaster 500(M)b
        PNP_CONVERTCODE(SAM1C54),   // Samsung SAMTRON 5(M)B
        PNP_CONVERTCODE(SAM1C73),   // Samsung SyncMaster 500(M)p
        PNP_CONVERTCODE(SAM1CB3),   // Samsung SyncMaster 700(M)s
        PNP_CONVERTCODE(SAM1CB4),   // Samsung SAMTRON 7(M)E
        PNP_CONVERTCODE(SAM1D13),   // Samsung SyncMaster 700(M)p
        PNP_CONVERTCODE(SAM1D73),   // Samsung SyncMaster 500(M)s
        PNP_CONVERTCODE(SAM1D74),   // Samsung SAMTRON 5(M)E
        PNP_CONVERTCODE(SAM1DB3),   // Samsung SyncMaster 700(M)b
        PNP_CONVERTCODE(SAM1DB4),   // Samsung SAMTRON 7(M)B
        PNP_CONVERTCODE(SAM1F13),   // Samsung SyncMaster 1000p
        PNP_CONVERTCODE(SAM4610),   // Samsung SyncMaster 21GLs
        PNP_CONVERTCODE(SAM4613),   // Samsung SyncMaster 3Ne/4S
        PNP_CONVERTCODE(SAM4690),   // Samsung SyncMaster 20GLsi
        PNP_CONVERTCODE(SAM4D50),   // Samsung SyncMaster 15GLe
        PNP_CONVERTCODE(SAM4D51),   // Samsung SyncMaster 15GLi
        PNP_CONVERTCODE(SAM4D52),   // Samsung SyncMaster 15M
        PNP_CONVERTCODE(SAM4D53),   // Samsung CMQ5387L
        PNP_CONVERTCODE(SAM4D70),   // Samsung SyncMaster 17GLi
        PNP_CONVERTCODE(SAM4D71),   // Samsung SyncMaster 17GLsi
        PNP_CONVERTCODE(SAM4D72),   // Samsung SyncMaster 6Ne
        PNP_CONVERTCODE(SAM4D73),   // Samsung SyncMaster 17GLi
        PNP_CONVERTCODE(SAM4D74),   // Samsung SyncMaster 17GLsi
        PNP_CONVERTCODE(SAM4EED),   // Samsung SyncMaster 2400(U)W (SWM400*)
        PNP_CONVERTCODE(SAM5450),   // Samsung SyncMaster 15Me
        PNP_CONVERTCODE(SAM6024),   // Samsung SyncMaster 400TFT (LXA41*)
        PNP_CONVERTCODE(SAM6D20),   // Samsung SyncMaster 15GLe
        PNP_CONVERTCODE(SCM0469),   // SCM SwapBox Family PnP PCMCIA
        PNP_CONVERTCODE(SDI1428),   // Samtron SC-428PT/PTL
        PNP_CONVERTCODE(SDI1528),   // Samtron SC-528TXL
        PNP_CONVERTCODE(SDI1529),   // Samtron SC-528UXL
        PNP_CONVERTCODE(SDI1530),   // Samtron SC-528MXLJ
        PNP_CONVERTCODE(SDI4690),   // Samtron SC-208DXL+
        PNP_CONVERTCODE(SDI4D70),   // Samtron SC-728FXL
        PNP_CONVERTCODE(SDI4D71),   // Samtron SC-726GXL
        PNP_CONVERTCODE(SDI4D73),   // Samtron SC-728FXLJ
        PNP_CONVERTCODE(SDI5451),   // Samtron SC-528MDL
        PNP_CONVERTCODE(SKD0100),   // SysKonnect SK-NET FDDI-FE EISA 32-Bit FDDI LAN
        PNP_CONVERTCODE(SKD0200),   // SysKonnect SK-NET G32+ EISA 32-Bit Ethernet/IEEE802.3
        PNP_CONVERTCODE(SKD8000),   // SysKonnect SK-NET Flash Ethernet
        PNP_CONVERTCODE(SKDD300),   // SysKonnect SK-NET TR4/16+ Token-Ring
        PNP_CONVERTCODE(SKDE000),   // SysKonnect SK-NET G16 LAN
        PNP_CONVERTCODE(SKDF000),   // SysKonnect SK-NET FDDI-FI LAN
        PNP_CONVERTCODE(SMC0469),   // SMC SwapBox Family Plug-and-Play PCMCIA controller
        PNP_CONVERTCODE(SMC8000),   // SMC SMC8232 Network Adapter
        PNP_CONVERTCODE(SMC8003),   // SMC EtherCard PLUS Elite
        PNP_CONVERTCODE(SMC8010),   // SMC EtherCard Elite Ultra 32
        PNP_CONVERTCODE(SMC8013),   // SMC EtherCard PLUS Elite16
        PNP_CONVERTCODE(SMC8115),   // SMC TokenCard Elite Family LAN Adapters
        PNP_CONVERTCODE(SMC8216),   // SMC EtherCard Elite16 ULTRA
        PNP_CONVERTCODE(SMC8416),   // SMC EtherEZ (8416)
        PNP_CONVERTCODE(SMC9000),   // SMC 9000 Ethernet Adapter
        PNP_CONVERTCODE(SMCA010),   // SMC Ether 10/100 Fast Ethernet EISA Network Adapter
        PNP_CONVERTCODE(SML0933),   // Smile MA0933
        PNP_CONVERTCODE(SML1414),   // Smile CB1414VL
        PNP_CONVERTCODE(SML1706),   // Smile CA1706M2
        PNP_CONVERTCODE(SML2011),   // Smile CA2011M2
        PNP_CONVERTCODE(SML2111),   // Smile CA2111M2
        PNP_CONVERTCODE(SML6013),   // Smile CA6013DS
        PNP_CONVERTCODE(SML6719),   // Smile CA6719
        PNP_CONVERTCODE(SML8819),   // Smile MM/CA6536DL/SL(NF)
        PNP_CONVERTCODE(SNY0000),   // Sony CPD-15SF2/SX1/17SF2/17SE2T/20SF2
        PNP_CONVERTCODE(SNY0050),   // Sony CPD-100VS
        PNP_CONVERTCODE(SNY00E0),   // Sony GDM-W900
        PNP_CONVERTCODE(SNY0170),   // Sony GDM-17SE2T
        PNP_CONVERTCODE(SNY0270),   // Sony CPD-200SF
        PNP_CONVERTCODE(SNY03A0),   // Sony CPD-300SFT
        PNP_CONVERTCODE(SNY0570),   // Sony CPD-200SX
        PNP_CONVERTCODE(SNY06A0),   // Sony GDM-20SE2T
        PNP_CONVERTCODE(SNY8050),   // Sony CPD-100SX
        PNP_CONVERTCODE(SRC0048),   // ShamRock C072
        PNP_CONVERTCODE(SRC0066),   // ShamRock C102
        PNP_CONVERTCODE(SRC0197),   // ShamRock C407
        PNP_CONVERTCODE(SRC01F6),   // ShamRock C502
        PNP_CONVERTCODE(SRC01F9),   // ShamRock C505
        PNP_CONVERTCODE(SRC01FB),   // ShamRock C507
        PNP_CONVERTCODE(SRC0239),   // ShamRock M569
        PNP_CONVERTCODE(SRC02BF),   // ShamRock C703
        PNP_CONVERTCODE(SRC02C1),   // ShamRock C705
        PNP_CONVERTCODE(SRC02C2),   // ShamRock C706
        PNP_CONVERTCODE(SRC0301),   // ShamRock M769
        PNP_CONVERTCODE(SRC057E),   // ShamRock SRC1406
        PNP_CONVERTCODE(SRC057F),   // ShamRock SRC1407
        PNP_CONVERTCODE(SRC05DE),   // ShamRock SRC1502
        PNP_CONVERTCODE(SRC05E1),   // ShamRock SRC1505
        PNP_CONVERTCODE(SRC05E3),   // ShamRock SRC15O7
        PNP_CONVERTCODE(SRC06A6),   // ShamRock SRC1702
        PNP_CONVERTCODE(SRC06A7),   // ShamRock SRC1703
        PNP_CONVERTCODE(SRC06A9),   // ShamRock SRC1705
        PNP_CONVERTCODE(SRC06AA),   // ShamRock SRC1706
        PNP_CONVERTCODE(SRC07D2),   // ShamRock SRC2002
        PNP_CONVERTCODE(SRC0836),   // ShamRock SRC2102
        PNP_CONVERTCODE(SSC0000),   // Sierra 14,4k SQ3228
        PNP_CONVERTCODE(SSC0001),   // Sierra 14,4k SQ3262
        PNP_CONVERTCODE(SUP0980),   // SupraFAXModem V.32bis PnP
        PNP_CONVERTCODE(SUP1150),   // SupraExpress 144 Plus PnP
        PNP_CONVERTCODE(SUP1200),   // SupraFAXModem 288 PnP
        PNP_CONVERTCODE(SUP1230),   // SupraExpress 144i PnP
        PNP_CONVERTCODE(SUP1250),   // SupraExpress 288
        PNP_CONVERTCODE(SUP1330),   // SupraSonic 288V+ PnP
        PNP_CONVERTCODE(SUP1620),   // SupraExpress 336i Sp ASVD
        PNP_CONVERTCODE(SVE0001),   // SVEC FD0421 EtherPlug-ISA
        PNP_CONVERTCODE(SZV4953),   // OvisLink NE-2000 Compatible Ethernet NIC
        PNP_CONVERTCODE(TAT1F65),   // Tatung Intelliscan TM651x
        PNP_CONVERTCODE(TAT1F67),   // Tatung Intelliscan TM671x
        PNP_CONVERTCODE(TAT2F44),   // Tatung Intelliscan TM442x
        PNP_CONVERTCODE(TAT2F45),   // Tatung Intelliscan TM452x
        PNP_CONVERTCODE(TAT434D),   // Tatung CM-17MC
        PNP_CONVERTCODE(TAT4855),   // Tatung CM-14UH
        PNP_CONVERTCODE(TCI00D0),   // Tulip NCC-16 ISA+
        PNP_CONVERTCODE(TCJA001),   // Teac 4x CD-ROM Drive with 8-bit Card
        PNP_CONVERTCODE(TCJA002),   // Teac 4x CD-ROM Drive with 16-bit Card
        PNP_CONVERTCODE(TCM5090),   // 3Com EtherLink III ISA (3C509-TP)
        PNP_CONVERTCODE(TCM5091),   // 3Com EtherLink III ISA (3C509)
        PNP_CONVERTCODE(TCM5092),   // 3Com EtherLink III EISA (3C579-TP)
        PNP_CONVERTCODE(TCM5093),   // 3Com EtherLink III EISA (3C579)
        PNP_CONVERTCODE(TCM5094),   // 3Com EtherLink III ISA (3C509-Combo)
        PNP_CONVERTCODE(TCM5095),   // 3Com EtherLink III ISA (3C509-TPO)
        PNP_CONVERTCODE(TCM5920),   // 3Com Etherlink III EISA BM Ethernet
        PNP_CONVERTCODE(TCM5970),   // 3Com Fast Etherlink 10/100Mb EISA BM Ethernet
        PNP_CONVERTCODE(TCM6190),   // 3Com 3C619B Network Adapter
        PNP_CONVERTCODE(TCM619B),   // 3Com TokenLink III ISA (3C619B)
        PNP_CONVERTCODE(TCM619C),   // 3Com 3C619C Network Adapter
        PNP_CONVERTCODE(TCM7700),   // 3Com 3C770 FDDI Adapter
        PNP_CONVERTCODE(TCO4145),   // Thomas-Conrad Token Ring TC4145
        PNP_CONVERTCODE(TEX0011),   // Texas Instruments 33600/Fax
        PNP_CONVERTCODE(TEX1100),   // Texas Instruments V.34+ Internal PnP FAX
        PNP_CONVERTCODE(TOS7400),   // Toshiba AcuPoint
        PNP_CONVERTCODE(TRL0510),   // TRL/RIC DH-1764
        PNP_CONVERTCODE(TRL061C),   // TRL/RIC DL-1564
        PNP_CONVERTCODE(USC0140),   // UltraStor 14F ISA SCSI Host
        PNP_CONVERTCODE(USC0141),   // UltraStor 34F/34FA VESA SCSI Host
        PNP_CONVERTCODE(USC0142),   // UltraStor 14FB ISA SCSI Host
        PNP_CONVERTCODE(USC0143),   // UltraStor 34FB VESA SCSI Host
        PNP_CONVERTCODE(USC0240),   // UltraStor 24F/24FA EISA SCSI Host
        PNP_CONVERTCODE(USC1240),   // UltraStor 124F EISA SCSI Disk Array
        PNP_CONVERTCODE(USR0000),   // USR Sportster 14.4 FAX
        PNP_CONVERTCODE(USR0007),   // USR Sportster Voice 33600 Fax
        PNP_CONVERTCODE(USR0011),   // USR Sportster Voice 33600 Fax
        PNP_CONVERTCODE(VDM0469),   // Vadem PCIC compatible PnP PCMCIA
        PNP_CONVERTCODE(VSC0C00),   // ViewSonic 17GS
        PNP_CONVERTCODE(VSC0C0F),   // ViewSonic 17PS
        PNP_CONVERTCODE(VSC0C1F),   // ViewSonic 17GA
        PNP_CONVERTCODE(VSC1600),   // ViewSonic 21PS
        PNP_CONVERTCODE(VSC2601),   // ViewSonic 15GS
        PNP_CONVERTCODE(VSC3141),   // ViewSonic 14ES
        PNP_CONVERTCODE(VSC3145),   // ViewSonic 15GS
        PNP_CONVERTCODE(VSC3245),   // ViewSonic 15GA
        PNP_CONVERTCODE(VSC3254),   // ViewSonic PJ800
        PNP_CONVERTCODE(VSC3345),   // ViewSonic E655
        PNP_CONVERTCODE(VSC3351),   // ViewSonic PT810
        PNP_CONVERTCODE(VSC3441),   // ViewSonic E641
        PNP_CONVERTCODE(VSC3445),   // ViewSonic E51
        PNP_CONVERTCODE(VSC3451),   // ViewSonic PT810
        PNP_CONVERTCODE(VSC3541),   // ViewSonic VP140
        PNP_CONVERTCODE(VSC354A),   // ViewSonic PF770
        PNP_CONVERTCODE(VSC354D),   // ViewSonic GT800
        PNP_CONVERTCODE(VSC3551),   // ViewSonic P810
        PNP_CONVERTCODE(VSC3552),   // ViewSonic P810-E
        PNP_CONVERTCODE(VSC3553),   // ViewSonic P810-A
        PNP_CONVERTCODE(VSC3641),   // ViewSonic E641-2
        PNP_CONVERTCODE(VSC3644),   // ViewSonic 15GA
        PNP_CONVERTCODE(VSC3645),   // ViewSonic G653
        PNP_CONVERTCODE(VSC3646),   // ViewSonic 15GA
        PNP_CONVERTCODE(VSC364A),   // ViewSonic PT770
        PNP_CONVERTCODE(VSC3651),   // ViewSonic P815
        PNP_CONVERTCODE(VSC3741),   // ViewSonic E41
        PNP_CONVERTCODE(VSC3744),   // ViewSonic 15G
        PNP_CONVERTCODE(VSC3745),   // ViewSonic E655-2
        PNP_CONVERTCODE(VSC374D),   // ViewSonic G800
        PNP_CONVERTCODE(VSC3751),   // ViewSonic G810
        PNP_CONVERTCODE(VSC3844),   // ViewSonic 15ES
        PNP_CONVERTCODE(VSC3845),   // ViewSonic VP150
        PNP_CONVERTCODE(VSC384A),   // ViewSonic 17EA
        PNP_CONVERTCODE(VSC384D),   // ViewSonic G790
        PNP_CONVERTCODE(VSC3851),   // ViewSonic PT810-3
        PNP_CONVERTCODE(VSC3941),   // ViewSonic VPA145
        PNP_CONVERTCODE(VSC3945),   // ViewSonic VPL150
        PNP_CONVERTCODE(VSC394A),   // ViewSonic 17GS
        PNP_CONVERTCODE(VSC4141),   // ViewSonic VPA138
        PNP_CONVERTCODE(VSC4145),   // ViewSonic GA655
        PNP_CONVERTCODE(VSC414D),   // ViewSonic P795
        PNP_CONVERTCODE(VSC4151),   // ViewSonic PT813
        PNP_CONVERTCODE(VSC4241),   // ViewSonic VP133
        PNP_CONVERTCODE(VSC4244),   // ViewSonic EA771B
        PNP_CONVERTCODE(VSC4245),   // ViewSonic P655
        PNP_CONVERTCODE(VSC424A),   // ViewSonic GT770
        PNP_CONVERTCODE(VSC4345),   // ViewSonic VPA150
        PNP_CONVERTCODE(VSC434A),   // ViewSonic 17PS
        PNP_CONVERTCODE(VSC4439),   // ViewSonic 15GS
        PNP_CONVERTCODE(VSC444A),   // ViewSonic 17GA
        PNP_CONVERTCODE(VSC4637),   // OptiQuest 1769DC
        PNP_CONVERTCODE(VSC474A),   // ViewSonic PT775
        PNP_CONVERTCODE(VSC4851),   // ViewSonic P810-3
        PNP_CONVERTCODE(VSC4951),   // ViewSonic G810-2
        PNP_CONVERTCODE(VSC4B4A),   // ViewSonic GT775
        PNP_CONVERTCODE(VSC4C4A),   // ViewSonic G771
        PNP_CONVERTCODE(VSC4D4A),   // ViewSonic EA771
        PNP_CONVERTCODE(VSC4E4A),   // ViewSonic E71
        PNP_CONVERTCODE(VSC504A),   // ViewSonic P775
        PNP_CONVERTCODE(VSC5135),   // ViewSonic P810
        PNP_CONVERTCODE(VSC514A),   // ViewSonic GA771
        PNP_CONVERTCODE(VSC5235),   // ViewSonic P810-ER
        PNP_CONVERTCODE(VSC524A),   // ViewSonic G773
        PNP_CONVERTCODE(VSC564A),   // ViewSonic E771
        PNP_CONVERTCODE(VSC594A),   // ViewSonic GS771
        PNP_CONVERTCODE(VSC5A4A),   // ViewSonic PT771
        PNP_CONVERTCODE(WDC2001),   // Western Digital 7000EX EISA SCSI Host
        PNP_CONVERTCODE(WTC00A1),   // WEN JD093A
        PNP_CONVERTCODE(WTC00A3),   // WEN JD103A
        PNP_CONVERTCODE(WTC00A7),   // WEN JD144/US144
        PNP_CONVERTCODE(WTC00AA),   // WEN WD145L/US145L
        PNP_CONVERTCODE(WTC00AD),   // WEN WD145S/US145S
        PNP_CONVERTCODE(WTC00B1),   // WEN JD156/US156G
        PNP_CONVERTCODE(WTC00B3),   // WEN JD156H/US156H
        PNP_CONVERTCODE(WTC00B7),   // WEN WD156S/US156F
        PNP_CONVERTCODE(WTC00BA),   // WEN JD176/US176
        PNP_CONVERTCODE(WTC00BD),   // WEN WD176L/US176L
        PNP_CONVERTCODE(WTC00C1),   // WEN WD176LE/US176LE
        PNP_CONVERTCODE(WTC00C3),   // WEN JK1775
        PNP_CONVERTCODE(WTC00C7),   // WEN JD178/US178
        PNP_CONVERTCODE(WTC00CA),   // WEN JK2060/2066
        PNP_CONVERTCODE(WTC00CD),   // WEN WD208S/US208S
        PNP_CONVERTCODE(WTC00D1),   // WEN WD218M/US218M
        PNP_CONVERTCODE(WYS0001),   // WYSE WY-17E
        PNP_CONVERTCODE(WYS0003),   // WYSE WY-15E
        PNP_CONVERTCODE(YMH0001),   // Yamaha OPL3-SA Sound Controller
        PNP_CONVERTCODE(YMH0002),   // Yamaha OPL3-SA Sound Blaster Playback System
        PNP_CONVERTCODE(YMH0003),   // Yamaha OPL3-SA Windows Sound System CODEC
        PNP_CONVERTCODE(YMH0004),   // Yamaha OPL3-SA FM Synthesizer
        PNP_CONVERTCODE(YMH0005),   // Yamaha OPL3-SA MPU401
        PNP_CONVERTCODE(YMH0006),   // Yamaha OPL3-SA Game Port
        PNP_CONVERTCODE(YMH0007),   // Yamaha OPL3-SA Sound System
        PNP_CONVERTCODE(YMH000F),   // Yamaha OPL3-SA Legacy Board
        PNP_CONVERTCODE(YMH0021),   // Yamaha OPL3-SAx Sound System
        PNP_CONVERTCODE(YMH0022),   // Yamaha OPL3-SAx GamePort
        PNP_CONVERTCODE(YMH0023),   // Yamaha OPL3-SAx COM Port
        PNP_CONVERTCODE(YMH0024),   // Yamaha OPL3-SAx IDE
        PNP_CONVERTCODE(YMH002F),   // Yamaha OPL3-SAx (Reserved)
        PNP_CONVERTCODE(ZDS2000),   // Zenith SCSI/IDE/Floppy EISA
        PNP_CONVERTCODE(ZDS2010),   // Zenith EISA IDE Controller
    };

    const char* ToString(Identifier_t id);
}

}