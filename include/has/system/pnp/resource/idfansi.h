//Copyright 2025-Present riplin

#pragma once

#include <string>
#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.3.2. ANSI Identifier String

// +-------------+-------------------------+---------------------------------------------------+
// | Size        | Field Name              | Definition                                        |
// +-------------+-------------------------+---------------------------------------------------+
// | Byte        | Identifier string       | Value = 10000010B (Type = 1, Large item name = 2) |
// | Byte        | Length, bits[7:0]       | Lower eight bits of identifier string length      |
// | Byte        | Length, bits[15:8]      | Upper eight bits of identifier string length      |
// | N * bytes   | Identifier string       | Device description as an ANSI string              |
// +-------------+-------------------------+---------------------------------------------------+

// The identifier string is 8-bit ANSI. The length of the string is defined in the structure so the string does not
// need to be zero terminated. Display software will insure the proper termination gets added to the string so
// that the termination byte does not need to be stored in the card's non-volatile storage. Each card is required
// to have an identifier string, each logical device may optionally have an identifier string.

struct IdentifierStringAnsi : Tag
{
    inline IdentifierStringAnsi(Item_t item) : Tag(item) {}
    std::string Identifier;
};

}