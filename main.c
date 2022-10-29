// main.c : Defines the entry point for the application.
#include <stdio.h>

#include "input.h"

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
    getTleFilePath(defaultFilePath, filePath, sizeof filePath);

	// Get TLE data for Satellites

    // If sufficient input is found, compute the visible satellites and their
    // applicable Doppler shifts

    // Write out the visible satellites to the console
    printf("Latitude: %f\n", latitude);
    printf("Longitude: %f\n", longitude);
    printf("Epoch DateTime: %lld\n", epochDateTime);
    printf("File Path: %s\n", filePath);

    // Return 0 to indicate success
}
