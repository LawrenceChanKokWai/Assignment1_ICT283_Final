
#include "MapAov.h"

const map<unsigned, array<Vector<SensorRecType>, MapAov::NUM_MTH>>& MapAov::GetSensorData() const
{
    return m_data;
}

map<unsigned, array<Vector<SensorRecType>, MapAov::NUM_MTH>>& MapAov::GetSensorData()
{
    return m_data;
}



void MapAov::InsertSensorData(const SensorRecType &sensorData)
{
    unsigned year = sensorData.GetSensorDate().GetYear();
    unsigned month = sensorData.GetSensorDate().GetMonth();

    // Check if the entry for the year exists
    auto yearIter = m_data.find(year);
    if (yearIter == m_data.end())
    {
        // If the entry doesn't exist, create it and initialize the array
        array<Vector<SensorRecType>, NUM_MTH> emptyArray;
        for (auto& vec : emptyArray)
        {
            vec = Vector<SensorRecType>();
        }
        m_data[year] = emptyArray;
        yearIter = m_data.find(year); // Reacquire iterator after insertion
    }

    // Access the array for the month and add the sensor data
    yearIter->second[month - 1].InsertLast(sensorData);
}

// Display sensor records by year
void MapAov::displayByYear() const
{
    cout << "Sensor records by year:" << endl;

    for (auto it = m_data.begin(); it != m_data.end(); ++it)
    {
        unsigned year = it->first;
        const auto& sensorRecordsByMonth = it->second;

        cout << "Year: " << year << endl;

        // Iterate through months and print the sensor records
        for (unsigned month = 1; month <= NUM_MTH; ++month)
        {
            cout << "  Month " << setw(2) << month << ": ";
            const auto& sensorRecords = sensorRecordsByMonth[month - 1];
            for ( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
            {
                cout << sensorRecords[i] << " ";
            }
            cout << endl;
        }
    }
}

// Display sensor records by year and month
void MapAov::displayByYearAndMonth() const
{
    cout << "Sensor records by year and month:" << endl;

    for (auto it = m_data.begin(); it != m_data.end(); ++it)
    {
        unsigned year = it->first;
        const auto& sensorRecordsByMonth = it->second;

        cout << "Year: " << year << endl;

        // Iterate through months and print the sensor records
        for (unsigned month = 1; month <= NUM_MTH; ++month)
        {
            cout << "  Month " << setw(2) << month << ": ";
            const auto& sensorRecords = sensorRecordsByMonth[month - 1];
            for ( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
            {
                cout << sensorRecords[i] << " ";
            }
            cout << endl;
        }
    }
}

// Display sensor records for a specific year and return them as a vector
Vector<SensorRecType> MapAov::displayByYearByUserInput(const unsigned& userInputYear) const
{
    cout << "Sensor records for year " << userInputYear << ":" << endl;

    Vector<SensorRecType> sensorRecords; // Vector to store sensor records

    auto it = m_data.find(userInputYear);
    if (it != m_data.end())
    {
        const auto& sensorRecordsByMonth = it->second;

        // Iterate through months and add sensor records to the vector
        for (unsigned month = 1; month <= NUM_MTH; ++month)
        {
            const auto& records = sensorRecordsByMonth[month - 1];
            for (unsigned i = 0; i < records.GetUsed(); ++i)
            {
                sensorRecords.InsertLast(records[i]);
            }
        }
    }
    else
    {
        cout << "No sensor records found for year " << userInputYear << endl;
    }

    return sensorRecords; // Return the vector of sensor records
}

// Modify the displayByYearAndMonthByUserInput function to return the sensor records
Vector<SensorRecType> MapAov::DisplayMeanSsdFromMonthAndYear(const unsigned& userInputYear, const unsigned& userInputMonth)
{
    Vector<SensorRecType> sensorRecords; // Container to hold sensor records

    auto it = m_data.find(userInputYear);
    if (it != m_data.end())
    {
        const auto& sensorRecordsByMonth = it->second;

        // Add sensor records for the specified month to the container
        const auto& records = sensorRecordsByMonth[userInputMonth - 1];
        for (unsigned i = 0; i < records.GetUsed(); ++i)
        {
            sensorRecords.InsertLast(records[i]);
        }
    }
    return sensorRecords; // Return the collected sensor records
}

float MapAov::GetSampleStandardDeviation(const Vector<SensorRecType>& sensorRecords) const
{
    float mean = 0;
    float variance = 0;

    // Calculate mean
    for (unsigned i = 0; i < sensorRecords.GetUsed(); ++i)
    {
        mean += sensorRecords[i].GetSensorWindSpeed().GetMeasurement();
    }
    mean /= sensorRecords.GetUsed();

    // Calculate variance
    for (unsigned i = 0; i < sensorRecords.GetUsed(); ++i)
    {
        float deviation = sensorRecords[i].GetSensorWindSpeed().GetMeasurement() - mean;
        variance += deviation * deviation;
    }
    variance /= sensorRecords.GetUsed() - 1;

    // Return square root of variance as sample standard deviation
    return sqrt(variance);
}

void MapAov::DisplayMeanSsdEachMonthOfYear(const unsigned& userInputYear) const
{
    SensorRecType sensorRecType;
    auto it = m_data.find(userInputYear);
    if (it != m_data.end())
    {
        const auto& sensorRecordsByMonth = it->second;

        for (unsigned month = 1; month <= NUM_MTH; ++month)
        {
            cout << sensorRecType.GetSensorDate().GetMonthInStr( month ) << ": ";

            const auto& records = sensorRecordsByMonth[month - 1];
            if (!records.IsEmpty())
            {
                // Calculate average ambient air temperature
                float sumTemperature = 0;
                for (unsigned i = 0; i < records.GetUsed(); ++i)
                {
                    sumTemperature += records[i].GetSensorTemperature().GetMeasurement();
                }
                float averageTemperature = sumTemperature / records.GetUsed();

                // Calculate sample standard deviation
                float standardDeviation = GetSampleStandardDeviation(records);

                cout << setprecision(3) << averageTemperature << " degrees C, stdev: " <<  setprecision(3) <<standardDeviation << endl;
            }
            else
            {
                cout << "No Data" << endl;
            }
        }
    }
    else
    {
        cout << "No Data" << endl;
    }
    cout << endl;
}

void MapAov::DisplaySumMonthOfYear(const unsigned& userInputYear) const
{
    SensorRecType sensorRecType;
    auto it = m_data.find(userInputYear);
    if (it != m_data.end())
    {
        const auto& sensorRecordsByMonth = it->second;

        for (unsigned month = 1; month <= NUM_MTH; ++month)
        {
            cout << sensorRecType.GetSensorDate().GetMonthInStr( month ) << ": ";

            const auto& records = sensorRecordsByMonth[month - 1];
            if (!records.IsEmpty())
            {
                // Calculate sum Solar Radiation
                float sumSolarRadiation = 0;
                for (unsigned i = 0; i < records.GetUsed(); ++i)
                {
                    sumSolarRadiation += records[i].GetSensorSolarRadiation().GetMeasurement();
                }
                cout << setprecision(3) << sumSolarRadiation / 60000 << " kWh/m2 " << endl;
            }
            else
            {
                cout << "No Data" << endl;
            }
        }
    }
    else
    {
        cout << "No Data" << endl;
    }
    cout << endl;
}

// Calculations of different types of measurements
float MapAov::SumOfMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const
{
    float sum = 0.0;

    switch( sensorMeasurementType )
    {
    case SensorMeasurementType::WIND_SPEED:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            sum += sensorRecords[i].GetSensorWindSpeed().GetMeasurement();
        }
        break;
    case SensorMeasurementType::AMBIENT_TEMPERATURE:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            sum += sensorRecords[i].GetSensorTemperature().GetMeasurement();
        }
        break;
    case SensorMeasurementType::SOLAR_RADIATION:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            sum += sensorRecords[i].GetSensorSolarRadiation().GetMeasurement();
        }
        break;
    }
    return sum;
}

float MapAov::MeanOfMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const
{
    float sum = SumOfMeasurementSwitch( sensorRecords, sensorMeasurementType );
    unsigned count = sensorRecords.GetUsed();
    if( count > 0 )
    {
        return ( sum / count );
    }
    else
    {
        return 0.0;
    }
}

float MapAov::SampleStandardDeviationMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const
{
    float SquaredSumDiff = 0.0;
    unsigned count = sensorRecords.GetUsed();

    switch( sensorMeasurementType )
    {
    case SensorMeasurementType::WIND_SPEED:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            float diff = sensorRecords[i].GetSensorWindSpeed().GetMeasurement();
            SquaredSumDiff += pow( diff, 2 );
        }
        break;
    case SensorMeasurementType::AMBIENT_TEMPERATURE:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            float diff = sensorRecords[i].GetSensorTemperature().GetMeasurement();
            SquaredSumDiff += pow( diff, 2 );
        }
        break;
    case SensorMeasurementType::SOLAR_RADIATION:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            float diff = sensorRecords[i].GetSensorSolarRadiation().GetMeasurement();
            SquaredSumDiff += pow( diff, 2 );
        }
        break;
    }
    return sqrt( SquaredSumDiff / count );
}
