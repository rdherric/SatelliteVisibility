﻿// main.c : Defines the entry point for the application.

#include <stdlib.h>
#include <stdio.h>
#include "input.h"
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

    // If sufficient input is found, compute the visible satellites and their
    // applicable Doppler shifts

    // Write out the visible satellites to the console
    printf("Latitude: %f\n", latitude);
    printf("Longitude: %f\n", longitude);
    printf("Epoch DateTime: %lld\n", epochDateTime);
    printf("File Path: %s\n", filePath);

    for (int i = 0; i < tleRecordCount; i++)
    {
        printf("%s (%s / %s) - %s: %s => %s / %s\n",
               tleRecords[i].satelliteName,
               tleRecords[i].catalogNumber,
               tleRecords[i].internationalDesignator,
               tleRecords[i].ephemerisEpochYear,
               tleRecords[i].ephemerisEpochDay,
               tleRecords[i].elementSetNumber,
               tleRecords[i].epochRevolutionNumber);

        printf("----- %s : %s : %s\n",
               tleRecords[i].meanMotion1stDerivative,
               tleRecords[i].meanMotion2ndDerivative,
               tleRecords[i].bStarDragTerm);

        printf("+++++ %s : %s : %s\n",
               tleRecords[i].inclination,
               tleRecords[i].rightAscension,
               tleRecords[i].eccentricity);
        printf("+++++ %s : %s : %s\n",
               tleRecords[i].argumentOfPerigee,
               tleRecords[i].meanAnomaly,
               tleRecords[i].meanMotion);
    }

    // Return 0 to indicate success
    return 0;
}
