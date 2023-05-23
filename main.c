#include <stdio.h>
#include "gps_parser.h"

int main() {
    // Correct GPS packet
    const char *packet1 = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";

    // GPS packet with missing longitude information
    const char *packet2 = "$GPGGA,002153.000,3342.6618,N,,W,1,10,1.2,27.0,M,-34.2,M,,0000*60";

    // GPS packet with missing latitude and checksum information
    const char *packet3 = "$GPGGA,002153.000,,,,,1,10,1.2,27.0,M,-34.2,M,,0000";

    // Validate checksum and parse GPS data for packet1
    if (validate_checksum(packet1)) {
        GPSData gpsData1;
        parse_gps_data(packet1, &gpsData1);

        printf("Packet 1 - Valid\n");
        printf("String: %s\n",packet1);
        printf("Time: %s\n", gpsData1.t);
        printf("Latitude: %s\n", gpsData1.latitude);
        printf("Longitude: %s\n", gpsData1.longitude);
        printf("\n");
    } else {
        printf("Packet 1 - Invalid checksum\n\n");
    }

    // Validate checksum and parse GPS data for packet2
    if (validate_checksum(packet2)) {
        GPSData gpsData2;
        parse_gps_data(packet2, &gpsData2);

        printf("Packet 2 - Valid\n");
        printf("Time: %s\n", gpsData2.t);
        printf("Latitude: %s\n", gpsData2.latitude);
        printf("Longitude: %s\n", gpsData2.longitude);
        printf("\n");
    } else {
        printf("Packet 2 - Invalid checksum\n\n");
    }

    // Validate checksum and parse GPS data for packet3
    if (validate_checksum(packet3)) {
        GPSData gpsData3;
        parse_gps_data(packet3, &gpsData3);

        printf("Packet 3 - Valid\n");
        printf("Time: %s\n", gpsData3.t);
        printf("Latitude: %s\n", gpsData3.latitude);
        printf("Longitude: %s\n", gpsData3.longitude);
        printf("\n");
    } else {
        printf("Packet 3 - Invalid checksum\n\n");
    }

    return 0;
}
