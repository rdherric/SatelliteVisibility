// Created by Robert Herrick, KI0RDH on 10/24/2022.
// C implementation file for functions defined in `satellite.h`.  Contains
// functions necessary to compute Amateur Radio Satellites that are visible
// from a location on Earth defined by Latitude and Longitude values at a
// date / time in GMT.

#include "tle.h"
#include "satellite.h"

/**
 * \brief computeSatelliteVisibility performs spherical geometry calculations
 * to determine if a satellite in the tleRecord_t array would be visible to a
 * user at the specified location on Earth at the specified date and time.  If
 * the satellite would be visible to the user, the function then calculates
 * any applicable Doppler shift based on the relative motion of the satellite
 * to the user.
 * \param tleRecords The Array of tleRecord_t values with ephemeris data.
 * \param latitude The Latitude on Earth of the user.
 * \param longitude The Longitude on Earth of the user.
 * \param epochDateTime The Date and Time of the user in UNIX Epoch format.
 */
void computeSatelliteVisibility(tleRecord_t* tleRecords, double latitude, double longitude, time_t epochDateTime)
{

}
