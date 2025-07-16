//Copyright 2025-Present riplin

#include <stdlib.h>
#include <support/env.h>

namespace Support
{

const char* GetEnv(const char* env)
{
    return getenv(env);
}

}