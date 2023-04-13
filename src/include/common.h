#ifndef clox_common_h
#define clox_common_h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Debugging commands.
// Comment these out for release or tests
//#define DEBUG_PRINT_CODE
//#define DEBUG_TRACE_EXECUTION


//#define DEBUG_STRESS_GC
//#define DEBUG_LOG_GC

// Except for this.
#define UINT8_COUNT (UINT8_MAX + 1)

#define ANSI_COLOR_BLACK "\e[0;30m"
#define ANSI_COLOR_RED "\e[0;31m"
#define ANSI_COLOR_YELLOW "\e[0;33m"
#define ANSI_COLOR_GREEN "\e[0;32m"
#define ANSI_COLOR_BLUE "\e[0;34m"
#define ANSI_COLOR_MAG "\e[0;35m"
#define ANSI_COLOR_RESET "\e[0m"

#endif