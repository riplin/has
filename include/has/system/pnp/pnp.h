//Copyright 2025-Present riplin

#pragma once

#include <has/system/pnp/id.h>
#include <has/system/pnp/control/csn.h>
#include <has/system/pnp/control/cfg.h>
#include <has/system/pnp/control/rngchk.h>
#include <has/system/pnp/control/seriso.h>
#include <has/system/pnp/control/status.h>
#include <has/system/pnp/control/iobase.h>
#include <has/system/pnp/control/dmaconf.h>
#include <has/system/pnp/control/irqconf.h>
#include <has/system/pnp/control/rcsdata.h>
#include <has/system/pnp/control/wakecsn.h>
#include <has/system/pnp/control/activate.h>
#include <has/system/pnp/control/rddatprt.h>
#include <has/system/pnp/control/logicdev.h>

#include <has/system/pnp/resource/end.h>
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

extern InitializeError_t Initialize(Has::IAllocator& allocator);
extern void Shutdown();
extern bool FindDevice(VendorId_t& vendorId, CardSelectNumber_t& csn);

}