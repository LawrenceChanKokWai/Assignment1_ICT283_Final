
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
    float sum = 0.0;
    float sumSquare = 0.0;
    unsigned count = sensorRecords.GetUsed();

    switch( sensorMeasurementType )
    {
    case SensorMeasurementType::WIND_SPEED:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            float measurement = sensorRecords[i].GetSensorWindSpeed().GetMeasurement();
            sum += measurement;
            sumSquare += pow( measurement, 2 );
        }
        break;
    case SensorMeasurementType::AMBIENT_TEMPERATURE:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            float measurement = sensorRecords[i].GetSensorTemperature().GetMeasurement();
            sum += measurement;
            sumSquare += pow( measurement, 2 );
        }
        break;
    case SensorMeasurementType::SOLAR_RADIATION:
        for( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
        {
            float measurement = sensorRecords[i].GetSensorSolarRadiation().GetMeasurement();
            sum += measurement;
            sumSquare += pow( measurement, 2 );
        }
        break;
    }
    float variance = (sumSquare - pow(sum, 2) / count) / (count - 1);
    return sqrt( variance );
}
