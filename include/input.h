// Created by Robert Herrick, KI0RDH on 10/29/2022.
// Header file for Satellite Visibility input functions; contains public function
// definitions to get user input for operating the application.

#ifndef SATELLITEVISIBILITY_INPUT_H
#define SATELLITEVISIBILITY_INPUT_H

#include "time.h"

/****************************************************************************/
/* Function definitions for computing Satellite visibility and ancillary    */
/* functionality, including reading two-line element (TLE) files.           */
/****************************************************************************/
double getUserLatitude(double defaultLatitude);
double getUserLongitude(double defaultLongitude);
time_t getUserEpochDateTime(time_t defaultEpochDateTime);
void getTleFilePath(const char* defaultFilePath, char* filePath);

#endif //SATELLITEVISIBILITY_INPUT_H
