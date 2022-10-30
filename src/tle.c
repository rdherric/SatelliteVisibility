// Created by Robert Herrick, KI0RDH on 10/28/2022.
// C implementation file for functions defined in `tle.h`.  Contains
// functions necessary to read a Two-Line Element file into a format
// suitable to compute visibility of a Satellite from a location on Earth.

#include <stdio.h>
#include <string.h>
#include "tle.h"

/**
 * \brief copyString is a utility function to copy a string from the fixed-width TLE file into a c-string.
 * \param destination The destination string to which to copy.
 * \param source The source string from which to copy.
 * \param maxLength The maximum number of characters to copy.
 */
void copyString(char* destination, char* source, size_t maxLength)
{
    // Reset all momory to the null-termination character
    memset(destination, '\0', maxLength);

    // Copy as much of the string as possible
    memcpy(destination, source, maxLength);

    // Find either a newline or a space
    char* nl = strchr(destination, '\n');
    char* spc = strchr(destination, ' ');

    // Replace newlines with null-termination character
    size_t endPtr = maxLength - 1;
    if (nl != NULL)
    {
        endPtr = nl - destination;
    }
    else if (spc != NULL && spc != destination)
    {
        endPtr = spc - destination;
    }

    // Set the null-termination character
    destination[endPtr] = '\0';
}


/**
 * \brief getTleRecordCount reads the specified Two-Line Element file to get the number of valid records in it.
 * \param filePath The path to the Two-Line Element file to read.
 * \return The number of valid TLE records in the file.
 */
size_t getTleRecordCount(char* filePath)
{
    // Declare a variable to return
    size_t rtn = 0;

	// Open the specified file
	FILE* file = fopen(filePath, "r");

	// Read three lines at a time, counting the results
    if (file != NULL)
    {
        // Read the file
        char line[256];
        int lineCount = 0;
        while (fgets(line, sizeof(line), file) != NULL)
        {
            // If three lines were read, increase rtn by one and reset
            lineCount++;
            if (lineCount == 3)
            {
                lineCount = 0;
                rtn++;
            }
        }

        // Close the file
        fclose(file);
    }

    // Return the result
    return rtn;
}


/**
 * \brief readTleData reads all valid Two-Line Element records from a file.
 * \param filePath The path to the Two-Line Element file to read.
 * \param tleRecords A tleRecord_t buffer in which to store the TLE records.
 * \param recordBufferSize The max size of the buffer in which TLE records are stored.
 */
void readTleData(char* filePath, tleRecord_t* tleRecords, size_t recordBufferSize)
{
    // Open the specified file
    FILE* file = fopen(filePath, "r");

    // Read three lines at a time, parsing the results
    if (file != NULL)
    {
        // Read valid records from the file
        for (int i = 0; i < recordBufferSize; i++)
        {
            // Parse three lines from the file for the tleRecord_t
            char line[256];

            // TLE Record friendly name
            if (fgets(line, sizeof(line), file) != NULL)
            {
                copyString(tleRecords[i].satelliteName, line, sizeof(tleRecords[i].satelliteName));
            }

            // TLE Record Line 1
            if (fgets(line, sizeof(line), file) != NULL)
            {
                // String pointer for tokens - start on char 3
                char* lineOne = line + (sizeof(char) * 2);

                // Catalog Number
                copyString(tleRecords[i].catalogNumber, lineOne, sizeof(tleRecords[i].catalogNumber));

                // International Designator
                lineOne = lineOne + sizeof(tleRecords[i].catalogNumber);
                copyString(tleRecords[i].internationalDesignator, lineOne, sizeof(tleRecords[i].internationalDesignator));

                // Ephemeris Epoch Year
                lineOne = lineOne + sizeof(tleRecords[i].internationalDesignator);
                copyString(tleRecords[i].ephemerisEpochYear, lineOne, sizeof(tleRecords[i].ephemerisEpochYear));

                // Ephemeris Epoch Day
                lineOne = lineOne + sizeof(tleRecords[i].ephemerisEpochYear) - 1;
                copyString(tleRecords[i].ephemerisEpochDay, lineOne, sizeof(tleRecords[i].ephemerisEpochDay));

                // Mean Motion First Derivative
                lineOne = lineOne + sizeof(tleRecords[i].ephemerisEpochDay);
                copyString(tleRecords[i].meanMotion1stDerivative, lineOne, sizeof(tleRecords[i].meanMotion1stDerivative));

                // Mean Motion Second Derivative
                lineOne = lineOne + sizeof(tleRecords[i].meanMotion1stDerivative);
                copyString(tleRecords[i].meanMotion2ndDerivative, lineOne, sizeof(tleRecords[i].meanMotion2ndDerivative));

                // B* Drag Term
                lineOne = lineOne + sizeof(tleRecords[i].meanMotion2ndDerivative);
                copyString(tleRecords[i].bStarDragTerm, lineOne, sizeof(tleRecords[i].bStarDragTerm));

                // Ephemeris Type
                copyString(tleRecords[i].ephemerisType, "0", 1);

                // Element Set Number
                lineOne = lineOne + sizeof(tleRecords[i].bStarDragTerm) + 2;
                copyString(tleRecords[i].elementSetNumber, lineOne, sizeof(tleRecords[i].elementSetNumber));
            }

            // TLE Record Line 2
            if (fgets(line, sizeof(line), file) != NULL)
            {
                // String pointer for tokens - start on char 9
                char* lineOne = line + (sizeof(char) * 8);

                // Inclination
                copyString(tleRecords[i].inclination, lineOne, sizeof(tleRecords[i].inclination));

                // Right Ascension
                lineOne = lineOne + sizeof(tleRecords[i].inclination);
                copyString(tleRecords[i].rightAscension, lineOne, sizeof(tleRecords[i].rightAscension));

                // Eccentricity
                lineOne = lineOne + sizeof(tleRecords[i].rightAscension);
                copyString(tleRecords[i].eccentricity, lineOne, sizeof(tleRecords[i].eccentricity));

                // Argument of Perigee
                lineOne = lineOne + sizeof(tleRecords[i].eccentricity);
                copyString(tleRecords[i].argumentOfPerigee, lineOne, sizeof(tleRecords[i].argumentOfPerigee));

                // Mean Anomaly
                lineOne = lineOne + sizeof(tleRecords[i].argumentOfPerigee);
                copyString(tleRecords[i].meanAnomaly, lineOne, sizeof(tleRecords[i].meanAnomaly));

                // Mean Motion
                lineOne = lineOne + sizeof(tleRecords[i].meanAnomaly);
                copyString(tleRecords[i].meanMotion, lineOne, sizeof(tleRecords[i].meanMotion));

                // Epoch Revolution Number
                lineOne = lineOne + sizeof(tleRecords[i].meanMotion) - 1;
                copyString(tleRecords[i].epochRevolutionNumber, lineOne, sizeof(tleRecords[i].epochRevolutionNumber));
            }
        }

        // Close the file
        fclose(file);
    }
}
