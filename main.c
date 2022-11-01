// main.c : Defines the entry point for the application.

#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "satellite.h"
#include "tle.h"

int main()
{
    // Default values for input - change as necessary while
    // running the application multiple times
    const double defaultLatitude = 34.15917;
    const double defaultLongitude = -118.50028;
    const time_t defaultEpochDateTime = time(NULL);
    const char defaultFilePath[] = "nasabare.txt";
    char filePath[256];

    // Read input from the console
    const double latitude = getUserLatitude(defaultLatitude);
    const double longitude = getUserLongitude(defaultLongitude);
    const time_t epochDateTime = getUserEpochDateTime(defaultEpochDateTime);
    getTleFilePath(defaultFilePath, filePath, 256);

	// Get the number of valid TLE records in the file
    const size_t tleRecordCount = getTleRecordCount(filePath);

    // Create the TLE Record buffer and read all data
    tleRecord_t* tleRecords = malloc(sizeof(tleRecord_t) * tleRecordCount);
    readTleData(filePath, tleRecords, tleRecordCount);

    // Compute the visible satellites from the location on Earth and the
    // time that was input.  For satellites that are visible, compute any
    // applicable Doppler shifts based on the motion of the satellite relative
    // to the location of the user.
    computeSatelliteVisibility(tleRecords, latitude, longitude, epochDateTime);

    // Write out the visible satellites to the console
    printf("Latitude: %f\n", latitude);
    printf("Longitude: %f\n", longitude);
    printf("Epoch DateTime: %lld\n", epochDateTime);
    printf("File Path: %s\n", filePath);

    // Write out the visible Satellites to the console
    printf("\nVisible Satellites:\n");
    for (int i = 0; i < tleRecordCount; i++)
    {
        // If the Satellite is visible, print its properties

        // Satellite name and Designator
        printf("%s (%s / %s):\n",
               tleRecords[i].satelliteName,
               tleRecords[i].catalogNumber,
               tleRecords[i].internationalDesignator);

        // Satellite frequency properties
        printf("\tBase Rx:\t%u\tBase Tx: %u \n\tDoppler Shifted Rx: %u\tDoppler Shifted Tx: %u\n\n",
               tleRecords[i].receiveFrequency,
               tleRecords[i].transmitFrequency,
               tleRecords[i].actualReceiveFrequency,
               tleRecords[i].actualTransmitFrequency);
    }

    // Return 0 to indicate success
    return 0;
}
