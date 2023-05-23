#ifndef GPS_PARSER_H
#define GPS_PARSER_H

#include <stdbool.h>
#include <stdio.h>
#define MAX_PACKET_LENGTH 128

typedef struct {
    char t[11];
    char latitude[12];
    char longitude[13];
    // Add more fields as per your requirements
} GPSData;

bool validate_checksum(const char *packet);
void parse_gps_data(const char *packet, GPSData *gpsData);

#endif  // GPS_PARSER_H
