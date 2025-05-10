[![License](https://img.shields.io/github/license/bitfireAT/davx5-ose?style=flat-square)](https://github.com/bitfireAT/davx5-ose/blob/main/LICENSE)

# DPRINTF

An efficient Arduino debug macro for streamlined debugging.

Utilize the DPRINTF macro to format debug output to the serial console. 

DPRINTF operates similarly to the [printf](https://en.cppreference.com/w/c/io/fprintf) function from the [Standard C Library](https://en.cppreference.com/w/c/io/fprintf).
It incorporates a debug level that allows you to control the verbosity of the output during debugging sessions. This means you can adjust the amount of information displayed based on the defined `DEBUG_LEVEL`. 

DPRINTF only compiles the relevant code for the specified debug level, making it a very efficient choice for debugging while optimizing memory usage.

## Syntax

`DPRINTF(const int debuglevel, const char* format, ...) ;` 

### Usage

Set the preferred debugging level in `dprintf.h`.

```
#define DEBUG_ENABLED  // Enable debugging
#define DEBUG_LEVEL 1  // VERBOSE 0, INFO 1, WARNING 2, ERROR 3
```

### Example

```
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
```

## Release code

For release versions, simply comment `#undef DEBUG_LEVEL in` in your project.

#undef DEBUG_LEVEL

# Contribution
This is an open source project. You are welcome to make suggestions or contributions. Feel free to contact me if you have any questions.
