#include <Arduino.h>

#define DEBUG_LEVEL 1  // Define your project debug level: 0 = VERBOSE, 1 = INFO, 2 = WARNING, 3 = ERROR
#include <dprintf.h>

char myString[] = "World";

void setup() {
  Serial.begin(57600);                                 // Setup the serial console
  delay(3000);                                         // Wait a few seconds for the console to settle
  DPRINTF(0, "VERBOSE: This string is NOT compiled");  // Debug levels < 1 are not compiled because DEBUG_LEVEL is 1 (See: dprintf.h)
  DPRINTF(1, "INFO: Hello %s\n", myString);            // Print: "INFO: Hello World"
  DPRINTF(2, "WARNING: This string is visible");       // Debug levels >= 1 are printed to the console
}

void loop() {
}
