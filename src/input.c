// Created by Robert Herrick, KI0RDH on 10/28/2022.
// C implementation file for functions defined in `input.h`.  Contains
// functions necessary to get user input to operate the application.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"

/**
 * \brief getUserLatitude prompts the user for the Latitude at which to find visible satellites.
 * \param defaultLatitude The default value for the user's Latitude so that no entry is necessary.
 * \return Either the user's input value or the default Latitude if none is entered.
 */
double getUserLatitude(double defaultLatitude)
{
	// Declare a variable to return
	double rtn = defaultLatitude;
	double tempInput = 0;
	char buf[64];

	// Request Latitude, showing default value
	printf("Enter Latitude [%f]: ", defaultLatitude);

	// Get input into temp variable - assign if valid
	if (fgets(buf, sizeof buf, stdin) != NULL)
	{
		// If ENTER was pressed, use default.  Otherwise,
		// try to convert.
		if (buf[0] != '\n')
		{
            // Convert to a double
            tempInput = strtod(buf, NULL);

            // If the value is valid, return it
            if (tempInput != 0)
            {
                rtn = tempInput;
            }
		}
	}

	// Return the result
	return rtn;
}


/**
 * \brief getUserLongitude prompts the user for the Longitude at which to find visible satellites.
 * \param defaultLongitude The default value for the user's Longitude so that no entry is necessary.
 * \return Either the user's input value or the default Longitude if none is entered.
 */
double getUserLongitude(double defaultLongitude)
{
	// Declare a variable to return
	double rtn = defaultLongitude;
	double tempInput = 0;
	char buf[64];

	// Request Longitude, showing default value
	printf("Enter Longitude [%f]: ", defaultLongitude);

	// Get input into temp variable - assign if valid
	if (fgets(buf, sizeof buf, stdin) != NULL)
	{
        // If ENTER was pressed, use default.  Otherwise,
        // try to convert.
        if (buf[0] != '\n')
        {
            // Convert to a double
            tempInput = strtod(buf, NULL);

            // If the value is valid, return it
            if (tempInput != 0)
            {
                rtn = tempInput;
            }
        }
	}

	// Return the result
	return rtn;
}


/**
 * \brief getUserEpochDateTime prompts the user for the Epoch DateTime at which to find visible satellites.
 * \param defaultEpochDateTime The default value for the user's Epoch DateTime so that no entry is necessary.
 * \return Either the user's input value or the default Epoch DateTime if none is entered.
 */
time_t getUserEpochDateTime(time_t defaultEpochDateTime)
{
	// Declare a variable to return
	time_t rtn = defaultEpochDateTime;
	time_t tempInput = 0;
	char buf[64];

	// Request DateTime, showing default value
	printf("Enter Epoch DateTime [%lld]: ", defaultEpochDateTime);

	// Get input into temp variable - assign if valid
	if (fgets(buf, sizeof buf, stdin) != NULL)
	{
        // If ENTER was pressed, use default.  Otherwise,
        // try to convert.
        if (buf[0] != '\n')
        {
            // Convert to a double
            tempInput = strtoll(buf, NULL, 10);

            // If the value is valid, return it
            if (tempInput != 0)
            {
                rtn = tempInput;
            }
        }
	}

	// Return the result
	return rtn;
}


/**
 * \brief getTleFilePath prompts the user for the path to the TLE file with satellite information.
 * \param defaultFilePath The default value for the TLE file path so that no entry is necessary.
 * \param filePath A buffer to hold a file path if the user enters one.
 * \param filePathLength The length of the char* in filePath for copy.
 */
void getTleFilePath(const char* defaultFilePath, char* filePath, size_t filePathLength)
{
	// Variables
	char buf[256];

	// Request file path, showing default value
	printf("Enter Two-Line Element File Path [%s]: ", defaultFilePath);

	// Get input into temp variable - assign if valid
	if (fgets(buf, sizeof buf, stdin) != NULL)
	{
		// If ENTER was pressed, use default.  Otherwise,
		// return the input.
		if (buf[0] != '\n')
		{
			strncpy(filePath, buf, filePathLength);
		}
		else
		{
			strcpy(filePath, defaultFilePath);
		}
	}
}

