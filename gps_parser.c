#include "gps_parser.h"
#include <string.h>
#include <stdlib.h>

bool validate_checksum(const char *packet) {
    int i = 1;
    char checksum = 0;

    while (packet[i] != '*' && packet[i] != '\0') {
        checksum = checksum ^ packet[i];
        i++;
    }

    char extracted_checksum[3];
    extracted_checksum[0] = packet[i + 1];
    extracted_checksum[1] = packet[i + 2];
    extracted_checksum[2] = '\0';

    char *endptr;
    char calculated_checksum = strtol(extracted_checksum, &endptr, 16);

    return (checksum == calculated_checksum);
}

void parse_gps_data(const char *packet, GPSData *gpsData) {
    if (packet == NULL || gpsData == NULL) {
        return;
    }

    if (strncmp(packet, "$GPGGA,", 7) != 0) {
        // Not a GGA packet
        return;
    }

    // Copy the time data
    int tokenStart = 7; // Start index of the time token
    int tokenEnd = tokenStart;
    while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
        tokenEnd++;
    }
    strncpy(gpsData->t, &packet[tokenStart], tokenEnd - tokenStart);
    gpsData->t[tokenEnd - tokenStart] = '\0';

    // Copy the latitude data
    tokenStart = tokenEnd + 1; // Start index of the latitude token
    tokenEnd = tokenStart;
    while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
        tokenEnd++;
    }
    strncpy(gpsData->latitude, &packet[tokenStart], tokenEnd - tokenStart);
    gpsData->latitude[tokenEnd - tokenStart] = '\0';

    // Copy the latitude direction data
    tokenStart = tokenEnd + 1; // Start index of the latitude direction token
    strncpy(gpsData->latitude_direction, &packet[tokenStart], 1);
    gpsData->latitude_direction[1] = '\0';

    // Copy the longitude data
    tokenStart = tokenEnd + 4; // Start index of the longitude token
    tokenEnd = tokenStart;
    while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
        tokenEnd++;
    }
    strncpy(gpsData->longitude, &packet[tokenStart], tokenEnd - tokenStart);
    gpsData->longitude[tokenEnd - tokenStart] = '\0';

    // Copy the longitude direction data
    tokenStart = tokenEnd + 1; // Start index of the longitude direction token
    strncpy(gpsData->longitude_direction, &packet[tokenStart], 1);
    gpsData->longitude_direction[1] = '\0';

    // Copy the fix quality data
    tokenStart = tokenEnd + 3; // Start index of the fix quality token
    tokenEnd = tokenStart;
    while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
        tokenEnd++;
    }
    strncpy(gpsData->fix_quality, &packet[tokenStart], tokenEnd - tokenStart);
    gpsData->fix_quality[tokenEnd - tokenStart] = '\0';

    // Copy the number of satellites data
    tokenStart = tokenEnd + 1; // Start index of the number of satellites token
    tokenEnd = tokenStart;
    while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
        tokenEnd++;
    }
    strncpy(gpsData->num_satellites, &packet[tokenStart], tokenEnd - tokenStart);
    gpsData->num_satellites[tokenEnd - tokenStart] = '\0';

    // Copy the HDOP data
    tokenStart = tokenEnd + 1; // Start index of the HDOP token
    tokenEnd = tokenStart;
    while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
        tokenEnd++;
    }
    strncpy(gpsData->hdop, &packet[tokenStart], tokenEnd - tokenStart);
    gpsData->hdop[tokenEnd - tokenStart] = '\0';

    // Copy the altitude data
    tokenStart = tokenEnd + 1; // Start index of the altitude token
    tokenEnd = tokenStart;
    while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
        tokenEnd++;
    }
    strncpy(gpsData->altitude, &packet[tokenStart], tokenEnd - tokenStart);
    gpsData->altitude[tokenEnd - tokenStart] = '\0';

    // Copy the height of geoid data
    tokenStart = tokenEnd + 3; // Start index of the height of geoid token
    tokenEnd = tokenStart;
    while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
        tokenEnd++;
    }
    strncpy(gpsData->height_geoid, &packet[tokenStart], tokenEnd - tokenStart);
    gpsData->height_geoid[tokenEnd - tokenStart] = '\0';
}
