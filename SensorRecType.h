#ifndef SENSORRECTYPE_H_INCLUDED
#define SENSORRECTYPE_H_INCLUDED

#include<iostream>
#include<string>

#include "Date.h"
#include "Time.h"
#include "WindSpeed.h"
#include "SolarRadiation.h"
#include "Temperature.h"

using namespace std;

/**
 * @class SensorRecType
 * @brief Represents a sensor record type with date, time, wind speed, temperature, solar radiation components.
 *
 * The SensorRecType class encapsulates information about a specific sensor record,
 * including date, time, wind speed, solar radiation, and temperature. It provides methods to retrieve and set
 * these components.
 */
class SensorRecType
{
public:

    /**
     * @brief Default constructor for the SensorRecType class.
     *
     * Initializes a SensorRecType object with default values.
     */
    SensorRecType();

    /**
    * @brief Parameterized constructor for the SensorRecType class.
    *
    * Initializes a SensorRecType object with specified date, and time.
    *
    * @param[in] date The date component of the wind record.
    * @param[in] time The time component of the wind record.
    * @param[in] windSpeed The windSpeed component of the wind record.
    * @param[in] solarRadiation The solarRadiation component of the wind record.
    * @param[in] temperature The temperature component of the wind record.
    */
    SensorRecType( const Date &date, const Time &time, const WindSpeed &windSpeed, const SolarRadiation &solarRadiation, const Temperature &temperature );

    /**
    * @brief Get the date component of the sensor record.
    *
    * @return The date as a Date object.
    */
    Date GetSensorDate() const;

    /**
     * @brief Get the time component of the sensor record.
     *
     * @return The time as a Time object.
     */
    Time GetSensorTime() const;

    /**
     * @brief Get the wind speed component of the sensor record.
     *
     * @return The wind speed as a WindSpeed object.
     */
    WindSpeed GetSensorWindSpeed() const;

    /**
     * @brief Get the solar radiation component of the sensor record.
     *
     * @return The solar radiation as a SolarRadiation object.
     */
    SolarRadiation GetSensorSolarRadiation() const;

    /**
     * @brief Get the temperature component of the sensor record.
     *
     * @return The temperature as a Temperature Measurement object.
     */
    Temperature GetSensorTemperature() const;

    /**
     * @brief Set the date component of the sensor record.
     *
     * @param[in] date The new date to set.
     */
    void SetSensorDate( const Date &date );

    /**
     * @brief Set the time component of the sensor record.
     *
     * @param[in] time The new time to set.
     */
    void SetSensorTime( const Time &time );

    /**
    * @brief Set the wind speed component of the sensor record.
    *
    * @param[in] windSpeed The new wind speed measurement to set.
    */
    void SetSensorWindSpeed( const WindSpeed &windSpeed );

    /**
    * @brief Set the solar radiation component of the sensor record.
    *
    * @param[in] solarRadiation The new solar radiation measurement to set.
    */
    void SetSensorSolarRadiation( const SolarRadiation &solarRadiation );

    /**
    * @brief Set the temperature component of the sensor record.
    *
    * @param[in] temperature The new temperature measurement to set.
    */
    void SetSensorTemperature( const Temperature &temperature );


private:
    Date m_date;                        /**< The date component of the sensor record. */
    Time m_time;                        /**< The time component of the sensor record. */
    WindSpeed m_windSpeed;              /**< The wind speed component of the sensor record. */
    SolarRadiation m_solarRadiation;    /**< The solar radiation component of the sensor record. */
    Temperature m_temperature;          /**< The temperature component of the sensor record. */
};

/**
 * @brief Overloaded stream insertion operator for outputting SensorRecType to an ostream.
 *
 * @param[out] output The output stream.
 * @param[in] SRT The SensorRecType object to output.
 * @return A reference to the output stream.
 */
ostream &operator << ( ostream &output, const SensorRecType &SRT );

/**
 * @brief Overloaded stream extraction operator for reading SensorRecType from an istream.
 *
 * @param[in,out] input The input stream.
 * @param[in,out] SRT The SensorRecType object to populate from the input.
 * @return A reference to the input stream.
 */
istream &operator >> ( istream &input, SensorRecType &SRT );


#endif // SENSORRECTYPE_H_INCLUDED
