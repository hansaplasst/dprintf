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
#include <Arduino.h>

#define DEBUG_ENABLED  // Enable debugging
#ifndef DEBUG_LEVEL
  #define DEBUG_LEVEL 2  // default debug level is WARNING. Other values are: VERBOSE 0, INFO 1, WARNING 2, ERROR 3
#endif

// Debug macro
#ifdef DEBUG_ENABLED
  #define DPRINTF(level, ...)       \
    {                               \
      if (level == DEBUG_LEVEL) {   \
        Serial.print("\033[33m");   \
        Serial.printf(__VA_ARGS__); \
        Serial.println("\033[0m");  \
      }                             \
      if (level > DEBUG_LEVEL) {    \
        Serial.print("\033[31m");   \
        Serial.printf(__VA_ARGS__); \
        Serial.println("\033[0m");  \
      }                             \
    }
#endif

#endif
