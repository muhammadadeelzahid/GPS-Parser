#ifndef GPS_PARSER_H
#define GPS_PARSER_H

#include <stdbool.h>
#include <stdio.h>
#define MAX_PACKET_LENGTH 128

typedef struct {
    char t[11]; // Time
    char latitude[10]; // Latitude
    char latitude_direction[2]; // Latitude direction (N/S)
    char longitude[11]; // Longitude
    char longitude_direction[2]; // Longitude direction (E/W)
    char fix_quality[2]; // Fix quality
    char num_satellites[3]; // Number of satellites
    char hdop[5]; // Horizontal Dilution of Precision (HDOP)
    char altitude[8]; // Altitude
    char height_geoid[8]; // Height of Geoid above WGS84 ellipsoid
} GPSData;

bool validate_checksum(const char *packet);
void parse_gps_data(const char *packet, GPSData *gpsData);

#endif  // GPS_PARSER_H
