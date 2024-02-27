#ifndef MAPAOV_H_INCLUDED
#define MAPAOV_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <map>

#include "Vector.h"
#include "SensorRecType.h"
#include "SensorMeasurementType.h"

using namespace std;

/**
 * @brief A class representing a map consisting array of Vectors of sensor data.
 *
 * This class provides functionality to manage sensor data organized by month and year.
 * It supports operations such as insertion of sensor data, computation of mean and standard deviation,
 * and display of aggregated data for specific months or years.
 */
class MapAov
{
public:
    static const unsigned NUM_MTH = 12;     ///< Number of months in a year.

    /**
     * @brief Get a constant reference to the sensor data map.
     *
     * @return Constant reference to the sensor data map.
     */
    const map<unsigned, array<Vector<SensorRecType>, NUM_MTH>>& GetSensorData() const;

    /**
     * @brief Get a reference to the sensor data map.
     *
     * @return Reference to the sensor data map.
     */
    map<unsigned, array<Vector<SensorRecType>, NUM_MTH>>& GetSensorData();

    /**
     * @brief Insert sensor data into the map consisted with array of Vectors.
     *
     * @param sensorData The sensor data to be inserted.
     */
    void InsertSensorData(const SensorRecType &sensorData);

    /**
     * @brief Switch function to compute the sum of different types of measurements.
     *
     * @param[in] sensorRecords The vector of sensor records.
     * @param[in] sensorMeasurementType The type of measurement to compute.
     *
     * @return The computed measurement based on the switch case.
     */
    float SumOfMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const;

    /**
     * @brief Switch function to compute the mean of different types of measurements.
     *
     * @param[in] sensorRecords The vector of sensor records.
     * @param[in] sensorMeasurementType The type of measurement to compute.
     *
     * @return The computed measurement based on the switch case.
     */
    float MeanOfMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const;

    /**
     * @brief Switch function to compute the sample standard deviation of different types of measurements.
     *
     * @param[in] sensorRecords The vector of sensor records.
     * @param[in] sensorMeasurementType The type of measurement to compute.
     *
     * @return The computed measurement based on the switch case.
     */
    float SampleStandardDeviationMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const;


private:
    map<unsigned, array<Vector<SensorRecType>, NUM_MTH>> m_data;    ///< Map storing arrays of sensor data vectors organized by month and year.

};


#endif // MAPAOV_H_INCLUDED
