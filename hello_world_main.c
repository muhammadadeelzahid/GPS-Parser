#include <stdio.h>
#include "gps_parser.h"

int main() {
    // Correct GPS packet
    const char *packet1 = "                                                                           \0";
    // Validate checksum and parse GPS data for packet
    if (validate_checksum(packet1)) {
        GPSData gpsData1;
        parse_gps_data(packet1, &gpsData1);
        

        printf("Packet 1 - Valid\n");
        printf("Packet: %s\n",packet1);
        printf("Time: %s\n", gpsData1.time);
        printf("Latitude: %.4f %c\n", gpsData1.latitude, gpsData1.latitude_dir);
        printf("Longitude: %.4f %c\n", gpsData1.longitude, gpsData1.longitude_dir);
        printf("Fix Quality: %d\n", gpsData1.fix_quality);
        printf("Number of Satellites: %d\n", gpsData1.num_satellites);
        printf("HDOP: %.2f\n", gpsData1.hdop);
        printf("Altitude: %.2f %c\n", gpsData1.altitude, gpsData1.altitude_dir);
        printf("Geoid Height: %.2f %c\n", gpsData1.geoid_height, gpsData1.geoid_height_dir);
        printf("Time since last DGPS update: %.2f\n", gpsData1.time_since_dgps_update);
        printf("Checksum: %s\n", gpsData1.checksum);
        printf("\n");
    } else {
        printf("Packet 1 - Invalid checksum\n\n");
    }

    
    const char *packet2 = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
    if (validate_checksum(packet2)) {
        GPSData gpsData2;
        parse_gps_data(packet2, &gpsData2);
        

        printf("Packet 2 - Valid\n");
        printf("Packet: %s\n",packet2);
        printf("Time: %s\n", gpsData2.time);
        printf("Latitude: %.4f %c\n", gpsData2.latitude, gpsData2.latitude_dir);
        printf("Longitude: %.4f %c\n", gpsData2.longitude, gpsData2.longitude_dir);
        printf("Fix Quality: %d\n", gpsData2.fix_quality);
        printf("Number of Satellites: %d\n", gpsData2.num_satellites);
        printf("HDOP: %.2f\n", gpsData2.hdop);
        printf("Altitude: %.2f %c\n", gpsData2.altitude, gpsData2.altitude_dir);
        printf("Geoid Height: %.2f %c\n", gpsData2.geoid_height, gpsData2.geoid_height_dir);
        printf("Time since last DGPS update: %.2f\n", gpsData2.time_since_dgps_update);
        printf("Checksum: %s\n", gpsData2.checksum);
        printf("\n");
    } else {
        printf("Packet 2 - Invalid checksum\n\n");
    }
    


    return 0;
}
