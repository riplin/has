#include <crt0.h>

// No paging. We want to handle interrupts, so we can't have our code and data pulled out from under us.

int _crt0_startup_flags = _CRT0_FLAG_LOCK_MEMORY;
