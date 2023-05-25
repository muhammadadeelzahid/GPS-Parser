# GPS Parser Library

This project implements a library for parsing GPS data in NMEA format (specifically the GGA packet) using the ESP-IDF v5.0 stable framework for ESP32 microcontrollers. The library provides functions to validate the checksum of the GPS packet and extract individual parameters such as time, latitude, and longitude etc.

## Features

- Validate the checksum of the GPS packet for integrity verification.
- Extract individual parameters from the GGA packet.
- Handle empty or malformed packets gracefully.
- Store the extracted GPS data parameters in a structured format using a `GPSData` struct.

## Installation

1. Clone the repository or download the source code.
2. Include the `gps_parser.h` header file in your project.
3. Implement the functions in the `gps_parser.c` source file.
4. Compile and link the code with the ESP-IDF framework or you can use any C compiler to test its functionality.

## Usage

1. Create an instance of the `GPSData` struct to store the parsed GPS data.
2. Call the `validate_checksum` function to check the integrity of the GPS packet.
3. If the checksum is valid, call the `parse_gps_data` function to extract the individual parameters.
4. Access the extracted GPS data from the `GPSData` struct fields.

Refer to the example in the `main.c` file for a usage demonstration.

