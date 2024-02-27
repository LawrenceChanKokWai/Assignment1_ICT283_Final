/**
* @file Processor.h
* @brief Processor class definition.
*
* This file contains the definition of the Processor class.
* The class allows FileI/O operations with singleton pattern.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#ifndef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED

#include<iostream>
#include<fstream>
#include<string>

#include "MapAov.h"
#include "Constant.h"

using namespace std;

/**
 * @brief The Processor class handles processing of CSV data as a singleton.
 *
 * This class provides functionality to load CSV file paths from a txt file and processes data into vectors,
 * and perform other processing tasks. It follows the singleton design pattern.
 */
class Processor
{
public:

    /**
     * @brief Returns the singleton instance of Processor.
     *
     * @return Processor& A reference to the singleton instance.
     */
    static Processor &GetInstance();

    /**
     * @brief Loads the CSV file paths from an txt file and stream into a vector.
     *
     * @param[in] csvFilePath The vector to store the CSV file paths.
     * @param[in] input The input stream from which to read the file paths.
     * @param[in] filename The name of the txt file being loaded.
     */
    void LoadCSVFilePathToVector( Vector<string> &csvFilePath, ifstream &input, const string &filename );

    /**
     * @brief Loads CSV data from a vector of file paths into a vector of WindRecType objects.
     *
     * @param[in] csvFilePath The vector containing the CSV file paths.
     * @param[in] windRecTypeVec The vector to store the WindRecType objects.
     * @param[in] windRecType An object of type WindRecType.
     */
    void LoadCSVData( Vector<string> &csvFilePath, MapAov &mapAov );

    /**
     * @brief Records sensor data to an output file and computes statistical measurements.
     *
     * This function records sensor data to the specified output file and calculates statistical measurements
     * including mean and standard deviation for speed and temperature readings, as well as the sum of sensor readings.
     *
     * @param[in] sensorRecType Reference to the sensor record type.
     * @param[in] outputFile Reference to the ofstream.
     * @param[in] month Reference to the month for which data is recorded.
     * @param[in] speedMean Reference to store the mean value of speed readings.
     * @param[in] speedSsd Reference to store the standard deviation of speed readings.
     * @param[in] tempMean Reference to store the mean value of temperature readings.
     * @param[in] tempSsd Reference to store the standard deviation of temperature readings.
     * @param[in] srSum Reference to store the sum of sensor readings.
     */
    bool OutputStreamMeasurement(
        SensorRecType &sensorRecType,
        ofstream &outputFile,
        unsigned &month,
        float &speedMean,
        float &speedSsd,
        float &tempMean,
        float &tempSsd,
        float &srSum );



private:
    static Processor *s_instance;   /**< Pointer to the singleton instance. */
    unsigned m_dataRead;            /**< Counter for the number of data read. */
    unsigned m_dataInserted;        /**< Counter for the number of data inserted. */

    /**
    * @brief Private constructor to prevent instantiation.
    */
    Processor();

    /**
     * @brief Loads the display count.
     *
     * This function loads the display count for the Processor instance.
     */
    void LoadDisplayCount();
};

#endif // PROCESSOR_H_INCLUDED
