#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "gps_parser.h"

int main() {
    // Correct GPS packet
    const char *packet1 = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";

    // GPS packet with missing longitude information
    const char *packet2 = "$GPGGA,002153.000,3342.6618,N,,W,1,10,1.2,27.0,M,-34.2,M,,0000*60";

    // Validate checksum and parse GPS data for packet1
    if (validate_checksum(packet1)) {
        GPSData gpsData1;
        parse_gps_data(packet1, &gpsData1);

        printf("Packet 1 - Valid\n");
        printf("String: %s\n", packet1);
        printf("Time: %s\n", gpsData1.t);
        printf("Latitude: %s\n", gpsData1.latitude);
        printf("Latitude Direction: %s\n", gpsData1.latitude_direction);
        printf("Longitude: %s\n", gpsData1.longitude);
        printf("Longitude Direction: %s\n", gpsData1.longitude_direction);
        printf("Fix Quality: %s\n", gpsData1.fix_quality);
        printf("Number of Satellites: %s\n", gpsData1.num_satellites);
        printf("HDOP: %s\n", gpsData1.hdop);
        printf("Altitude: %s\n", gpsData1.altitude);
        printf("Height of Geoid: %s\n", gpsData1.height_geoid);
        printf("\n");
    } else {
        printf("Packet 1 - Invalid checksum\n\n");
    }
    
    if (validate_checksum(packet2))
    {
        GPSData gpsData2;
        parse_gps_data(packet2, &gpsData2);

        printf("Packet 1 - Valid\n");
        printf("String: %s\n", packet2);
        printf("Time: %s\n", gpsData2.t);
        printf("Latitude: %s\n", gpsData2.latitude);
        printf("Latitude Direction: %s\n", gpsData2.latitude_direction);
        printf("Longitude: %s\n", gpsData2.longitude);
        printf("Longitude Direction: %s\n", gpsData2.longitude_direction);
        printf("Fix Quality: %s\n", gpsData2.fix_quality);
        printf("Number of Satellites: %s\n", gpsData2.num_satellites);
        printf("HDOP: %s\n", gpsData2.hdop);
        printf("Altitude: %s\n", gpsData2.altitude);
        printf("Height of Geoid: %s\n", gpsData2.height_geoid);
        printf("\n");
    }
    else
    {
        printf("Packet 2 - invalid checksum");
    }
    
    return 0;
}
