//Copyright 2025-Present riplin

#pragma once

#include <initializer_list>

#ifdef DEBUG

#define LOG_CONFIGURE(fileName) \
Has::Testing::Log::Configure(fileName);

#define LOG_FOCUS(...) \
Has::Testing::Log::FocusCategories(__VA_ARGS__);

#define LOG(category, format, ...) \
Has::Testing::Log::Log(category, format __VA_OPT__(,) __VA_ARGS__)

namespace Has::Testing::Log
{
    extern void Configure(const char* fileName);
    extern void FocusCategory(const char* category);
    extern void Log(const char* category, const char* format, ...);

    template<typename... Categories>
    void FocusCategories(Categories... categories)
    {
        for (auto category : {categories...})
        {
            FocusCategory(category);
        }
    }

}

#else

#define LOG_CONFIGURE(fileName)
#define LOG_FOCUS(...)
#define LOG(category, format, ...)

#endif