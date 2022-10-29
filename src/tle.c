// Created by Robert Herrick, KI0RDH on 10/28/2022.
// C implementation file for functions defined in `tle.h`.  Contains
// functions necessary to read a Two-Line Element file into a format
// suitable to compute visibility of a Satellite from a location on Earth.
#include "tle.h"

/**
 * \brief getTleRecordCount reads the specified Two-Line Element file to get the number of valid records in it.
 * \param filePath The path to the Two-Line Element file to read.
 * \return The number of valid TLE records in the file.
 */
size_t getTleRecordCount(char* filePath)
{
	return 0;
}


/**
 * \brief readTleData reads all valid Two-Line Element records from a file.
 * \param filePath The path to the Two-Line Element file to read.
 * \param tleRecords A tleRecord_t buffer in which to store the TLE records.
 * \param recordBufferSize The max size of the buffer in which TLE records are stored.
 */
void readTleData(char* filePath, tleRecord_t* tleRecords, size_t recordBufferSize)
{
	
}
