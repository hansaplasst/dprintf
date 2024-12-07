/**
 * @file dprintf.h
 *
 * DPRINTF is an efficient Arduino debug macro for streamlined debugging.
 * When debugging is disabled, ALL DPRINTF statements are eliminated during compilation, freeing memory for runtime tasks.
 *
 * @copyright (c) 2024 hansaplasst
 * @author hansaplasst
 *
 * @version 0.0.1
 * @license GPL 3.0
 */

#ifndef DPRINTF_H
#define DPRINTF_H

#include <PrintEx.h>

#define DEBUG_ENABLED  // Enable debugging
#define DEBUG_LEVEL 1  // VERBOSE 0, INFO 1, WARNING 2, ERROR 3

// Debug macro
#ifdef DEBUG_ENABLED
  #define DPRINTF(level, ...) \
    (level >= DEBUG_LEVEL) ? mySerial.printf(__VA_ARGS__) : 0
#else
  #define DPRINTF(level, ...)
#endif

#endif
