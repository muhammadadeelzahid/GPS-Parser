# GPS Parser Library

This project implements a library for parsing GPS data in NMEA format (specifically the GGA packet) using the ESP-IDF v5.0 stable framework for ESP32 microcontrollers. The library provides functions to validate the checksum of the GPS packet and extract individual parameters such as time, latitude, and longitude, etc.

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
5. This project was also tested with ESP-IDF v5.0.
   - To properly link gps_parser.c with your CMake Project, make sure to include it as a source file in the SRCS list in the innermost CMakeList.txt
   - Open your CMakeLists.txt file in a text editor.
   - Locate the `idf_component_register` command.
   - Inside the `idf_component_register` command, find the `SRCS` variable declaration.
   - Add `"gps_parser.c"` to the `SRCS` list, ensuring it is enclosed in double quotation marks.
   - Verify that the file path provided matches the actual location of `gps_parser.c` in your project directory structure.
   - Here's an example of how the modified line would look:
```cmake
idf_component_register(SRCS "hello_world_main.c"
                             "gps_parser.c"
                              INCLUDE_DIRS "")
 ```   
## Usage

1. Create an instance of the `GPSData` struct to store the parsed GPS data.
2. Call the `validate_checksum` function to check the integrity of the GPS packet.
3. If the checksum is valid, call the `parse_gps_data` function to extract the individual parameters.
4. Access the extracted GPS data from the `GPSData` struct fields.
5. Refer to the example in the `hello_world_main.c` file for a usage demonstration.
6. Find above "ESP IDF v5.0 Build result.png" file which shows build results with ESP-IDF v5.0
7. Find above "Usage Example.png" which shows output of the test main file "hello_world_main.c" 



