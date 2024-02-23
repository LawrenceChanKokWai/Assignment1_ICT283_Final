#ifndef MAPAOV_H_INCLUDED
#define MAPAOV_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <map>

#include "Vector.h"
#include "SensorRecType.h"
#include "SensorMeasurementType.h"

using namespace std;

class MapAov
{
public:
    static const unsigned NUM_MTH = 12;

    const map<unsigned, array<Vector<SensorRecType>, NUM_MTH>>& GetSensorData() const;
    map<unsigned, array<Vector<SensorRecType>, NUM_MTH>>& GetSensorData();


    void InsertSensorData(const SensorRecType &sensorData);

    void displayByYear() const;
    void displayByYearAndMonth() const;
    Vector<SensorRecType> displayByYearByUserInput(const unsigned& userInputYear) const;
    Vector<SensorRecType> DisplayMeanSsdFromMonthAndYear(const unsigned& userInputYear, const unsigned& userInputMonth);
    float GetSampleStandardDeviation(const Vector<SensorRecType>& sensorRecords) const;
    void DisplayMeanSsdEachMonthOfYear(const unsigned& userInputYear) const;
    void DisplaySumMonthOfYear(const unsigned& userInputYear) const;

    //void CalculateMeanAndSSd(const Vector<SensorRecType>& sensorRecords, SensorMeasurementType sensorMeasurementType, float& avg, float& stdDev) const;
    float SumOfMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const;
    float MeanOfMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const;
    float SampleStandardDeviationMeasurementSwitch( const Vector<SensorRecType> &sensorRecords, SensorMeasurementType sensorMeasurementType ) const;


private:
    map<unsigned, std::array<Vector<SensorRecType>, NUM_MTH>> m_data;

};


#endif // MAPAOV_H_INCLUDED
