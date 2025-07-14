//Copyright 2025-Present riplin

#pragma once

#ifdef __SSE__
#include <has/math/vec/vecmath.h>

namespace Has::Math
{
    using namespace Has::Math::vec;
}
#else
#include <has/math/flt/fltmath.h>

namespace Has::Math
{
    using namespace Has::Math::flt;
}
#endif