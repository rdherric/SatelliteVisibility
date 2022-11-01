// Created by Robert Herrick, KI0RDH on 10/24/2022.
// Header file for Satellite Visibility functions; contains both public function
// definitions and variable definitions pertinent to computing what satellites
// visible to a location on Earth as defined by Latitude and Longitude values.
#include "stdint.h"
#include "tle.h"

#ifndef SATELLITEVISIBILITY_SATELLITE_H
#define SATELLITEVISIBILITY_SATELLITE_H

/****************************************************************************/
/* Function definitions for computing Satellite visibility and any          */
/* applicable Doppler shifts to frequency based on the motion of the        */
/* satellite relative to the user.                                          */
/****************************************************************************/
void computeSatelliteVisibility(tleRecord_t* tleRecords, double latitude, double longitude, time_t epochDateTime);

#endif //SATELLITEVISIBILITY_SATELLITE_H
