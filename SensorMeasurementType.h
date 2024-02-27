
/**
* @file SensorMeasurementType.h
* @brief SensorMeasurementType class definition.
*
* This file contains the definition of the enum SensorMeasurementType class.
* This class is provides identifiers for different types of sensor measurements
* using a factory pattern.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#ifndef SENSORMEASUREMENTTYPE_H_INCLUDED
#define SENSORMEASUREMENTTYPE_H_INCLUDED

/**
 * @brief Enumeration representing different types of sensor measurements.
 *
 * This enumeration provides identifiers for different types of sensor measurements,
 * including wind speed, ambient temperature, and solar radiation.
 */
enum class SensorMeasurementType
{
    WIND_SPEED,                      ///< Identifier for wind speed measurement.
    AMBIENT_TEMPERATURE,    ///< Identifier for ambient temperature measurement.
    SOLAR_RADIATION             ///< Identifier for solar radiation measurement.
};

#endif // SENSORMEASUREMENTTYPE_H_INCLUDED
