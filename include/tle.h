// Created by Robert Herrick, KI0RDH on 10/28/2022.
// Header file for Two-Line Element file reading; contains public function
// definitions to read a TLE file into a format that can be used to compute
// where the Satellite is relative to a location on Earth.

#ifndef SATELLITEVISIBILITY_TLE_H
#define SATELLITEVISIBILITY_TLE_H

#include <stdint.h>

/****************************************************************************/
/* Structs necessary to pass around associated data related to Satellite    */
/* information stored in a TLE file.                                        */
/****************************************************************************/

// Struct to hold TLE information - see links below for more detail
// https://celestrak.org/norad/documentation/tle-fmt.php
// https://en.wikipedia.org/wiki/Two-line_element_set
typedef struct
{
    // Satellite user-friendly properties
    char satelliteName[25];
    char catalogNumber[7];
    char internationalDesignator[9];

    // Ephemeris dates
    char ephemerisEpochYear[3];
    char ephemerisEpochDay[13];

    // Ephemeris motion data
    char meanMotion1stDerivative[11];
    char meanMotion2ndDerivative[9];
    char bStarDragTerm[9];
    char inclination[9];
    char rightAscension[9];
    char eccentricity[8];
    char argumentOfPerigee[9];
    char meanAnomaly[9];
    char meanMotion[12];

    // TLE data
	char ephemerisType[2];
    char elementSetNumber[5];
    char epochRevolutionNumber[6];
} tleRecord_t;


/****************************************************************************/
/* Function definitions for reading Satellite information from a TLE file.  */
/****************************************************************************/
size_t getTleRecordCount(char* filePath);
void readTleData(char* filePath, tleRecord_t* tleRecords, size_t recordBufferSize);

#endif //SATELLITEVISIBILITY_TLE_H
