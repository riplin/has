//Copyright 2025-Present riplin

#pragma once

#include <string>
#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// 6.2.3.3. Unicode Identifier String

// +-------------+---------------------------------+---------------------------------------------------+
// | Size        | Field Name                      | Definition                                        |
// +-------------+---------------------------------+---------------------------------------------------+
// | Byte        | Identifier string               | Value = 10000011B (Type = 1, Large item name = 3) |
// | Byte        | Length, bits[7:0]               | Lower eight bits of length of string plus four    |
// | Byte        | Length, bits[15:8]              | Upper eight bits of length of string plus four    |
// | Byte        | Country identifier, bits[7:0]   | To be determined                                  |
// | Byte        | Country identifier, bits[15:8]  | To be determined                                  |
// | N * bytes   | Identifier string               | Device description characters                     |
// +-------------+---------------------------------+---------------------------------------------------+

// Currently, only ANSI identifier strings are defined. The definition for Unicode will be added at a later time.

struct IdentifierStringUnicode : Tag
{
    inline IdentifierStringUnicode(Item_t item) : Tag(item) {}
    uint16_t CountryIdentifier;
    std::string Identifier;
};

}