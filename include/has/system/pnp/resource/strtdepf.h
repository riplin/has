//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/resource/resource.h>

namespace Has::System::PnP::Resource
{

// Each logical device requires a set of resources. This set of resources may have interdependencies that need
// to be expressed to allow arbitration software to make resource allocation decisions about the logical device.
// Dependent functions are used to express these interdependencies. The data structure definitions for dependent
// functions are shown here. For a detailed description of the use of dependent functions refer to the next
// section.

// +-------------+-----------------------------------------------------------------------+
// | Offset      | Field Name                                                            |
// +-------------+-----------------------------------------------------------------------+
// | Byte 0      | Value = 0011000xB (Type = 0, small item name = 0x6, length =(0 or 1)) |
// +-------------+-----------------------------------------------------------------------+

// Start Dependent Function fields may be of length 0 or 1 bytes. The extra byte is optionally used to denote
// priority for the resource group following the Start DF tag. If the extra byte is not included, this indicates the
// dependent function priority is ‘acceptable’. If the Priority byte is included, the priorities are defined as:

// +-------------+------------------------------------------------------------------------+
// | Value       | Definition                                                             |
// +-------------+------------------------------------------------------------------------+
// | 0           | Good configuration - Highest Priority and preferred configuration      |
// | 1           | Acceptable configuration - Lower Priority but acceptable configuration |
// | 2           | Sub-optimal configuration - Functional configuration but not optimal   |
// | 3 - 255     | Reserved                                                               |
// +-------------+------------------------------------------------------------------------+

// Note that if multiple Dependent Functions have the same priority, they are further prioritized by the order in
// which they appear in the resource data structure. The Dependent Function which appears earliest (nearest the
// beginning) in the structure has the highest priority, and so on.

typedef uint8_t ConfigurationLevel_t;
namespace ConfigurationLevel
{
    enum
    {
        Good = 0x00,
        Acceptable = 0x01,
        SubOptimal = 0x02
    };
}

struct StartDependentFunction : Tag
{
    inline StartDependentFunction(Item_t item) : Tag(item) {}
    ConfigurationLevel_t ConfigurationLevel;
};

}