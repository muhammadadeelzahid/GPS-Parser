# ESP32 GPS-Parser Library

This library provides a simple and efficient way to parse GPS data in NMEA format (NMEA 0183) using the ESP-IDF v5.0 stable framework for ESP32 microcontrollers.

## Features

- Parses GPS data packets in NMEA format and extracts individual parameters
- Handles empty or malformed packets gracefully
- Validates packet integrity using checksum validation

## Getting Started

To use this library in your ESP-IDF project, follow these steps:

1. Clone this repository to your local machine.

2. Start a new ESP-IDF project using the ESP-IDF framework with the "hello_world" example. If you already have an existing ESP-IDF project, you can skip this step.

3. Copy the contents of the "GPS-Parser/main" into the "main' folder of ESP-IDF project replacing previous files.

4. Build your project using the CMake build system. Make sure you modify the CMakeLists.txt file to include main.c and gps_parser.c file

5. Make sure you have the necessary toolchain and dependencies installed.


