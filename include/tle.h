// Created by Robert Herrick, KI0RDH on 10/28/2022.
// Header file for Two-Line Element file reading; contains public function
// definitions to read a TLE file into a format that can be used to compute
// where the Satellite is relative to a location on Earth.

#ifndef SATELLITEVISIBILITY_TLE_H
#define SATELLITEVISIBILITY_TLE_H

#include "stdint.h"

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
    char satelliteName[24];
    char catalogNumber[5];
    char classification;
    char internationalDesignator[8];

    // Ephemeris dates
    char ephemerisEpochYear[2];
    char ephemerisEpochDay[12];

    // Ephemeris motion data
    char meanMotion1stDerivative[10];
    char meanMotion2ndDerivative[8];
    char bStarDragTerm[8];
    char inclination[8];
    char rightAscension[8];
    char eccentricity[7];
    char argumentOfPerigee[8];
    char meanAnomaly[8];
    char meanMotion[11];

    // TLE data
	char ephemerisType[1];
    char elementSetNumber[4];
    char epochRevolutionNumber[5];
} tleRecord_t;


/****************************************************************************/
/* Function definitions for reading Satellite information from a TLE file.  */
/****************************************************************************/
size_t getTleRecordCount(char* filePath);
void readTleData(char* filePath, tleRecord_t* tleRecords, size_t recordBufferSize);

#endif //SATELLITEVISIBILITY_TLE_H
