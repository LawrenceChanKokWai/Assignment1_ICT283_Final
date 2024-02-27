
/**
* @file Measurement.h
* @brief Measurement class definition.
*
* This file contains the definition of the Measurement base class.
* The class allows setting and retrieving the measurement associated with the sensor measurements.
* It also overloads stream operators for input and output to facilitate I/O operations.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED

#include<cmath>

/**
 * @name Measurement
 * @brief Represents a base class.
 * @{
 */

/**
* @brief Represents a base class.
*/
class Measurement
{

public:

    /**
    * @brief Default constructor.
    * @post Creates a Measurement object with initial values.
    */
    Measurement();

    /**
     * @brief Parameterized constructor.
     * @param[in] measurement The measurement of the reading.
     * @post Creates a Measurement object with specified measurement.
     */
    Measurement( const float &measurement );

    /**
     * @brief Getter for the measurement variable.
     *
     * @return The measurement variable of the Observations.
     */
    float GetMeasurement() const;

    /**
     * @brief Setter for the measurement variable.
     *
     * @param[in] measurement The new measurement variable to set.
     * @post Sets the measurement variable to the specified value.
     */
    void SetMeasurement( const float &measurement );

private:
    unsigned INITIAL_VALUE = 0.0;   ///< Initial value for the Measurement.

    float m_measurement;            ///< measurement component of the Measurement Object.

};

#endif // MEASUREMENT_H_INCLUDED
