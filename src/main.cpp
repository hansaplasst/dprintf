#include <Arduino.h>

#define DEBUG_LEVEL 1  // Define your project debug level: 0 = VERBOSE, 1 = INFO, 2 = WARNING, 3 = ERROR
#include <dprintf.h>

char myString[] = "debug level";

void setup() {
  Serial.begin(BAUDRATE);                                   // Initialize serial communication at the defined BAUDRATE in platformio.ini
  delay(3000);                                              // Wait a few seconds for the console to settle
  DPRINTF(0, "VERBOSE: Verbose strings are NOT compiled");  // Debug levels < 1 are not compiled because DEBUG_LEVEL is 1 (See: dprintf.h)
  DPRINTF(1, "INFO: Is the defined %s", myString);          // Debug levels >= 1 are printed to the console
  DPRINTF(2, "WARNING: This warning is visible");
  DPRINTF(3, "ERROR: This error is also visible");
}

void loop() {
}
