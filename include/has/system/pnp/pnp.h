//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/control/csn.h>
#include <has/system/pnp/control/cfg.h>
#include <has/system/pnp/control/seriso.h>
#include <has/system/pnp/control/status.h>
#include <has/system/pnp/control/wakecsn.h>
#include <has/system/pnp/control/rcsdata.h>
#include <has/system/pnp/control/rddatprt.h>
#include <has/system/pnp/control/logicdev.h>

namespace Has::System::PnP
{

typedef uint16_t InitializeError_t;
namespace InitializeError
{
    enum
    {
        Success = 0x00,
        AlreadyInitialized = 0x01,
        NoCardsFound = 0x02,
    };
}

extern void SendKey();

extern InitializeError_t Initialize(bool printOuptut);
extern void Shutdown();
extern bool FindDevice(VendorId_t& vendorId, CardSelectNumber_t& csn);

}