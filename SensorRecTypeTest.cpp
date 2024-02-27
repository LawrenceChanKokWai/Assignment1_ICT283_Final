#include "SensorRecType.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void Assert(bool condition, const string &title, const string &description, const string &expectedOutput);

void TestDefaultConstructor(const SensorRecType &sensorRecType);
void TestParameterizedConstructor(const SensorRecType &sensorRecType, const Date &date, const Time &time, const WindSpeed &windSpeed, const SolarRadiation &solarRadiation, const Temperature &temperature);
void TestGetters(const SensorRecType &sensorRecType, const Date &date, const Time &time, const WindSpeed &windSpeed, const SolarRadiation &solarRadiation, const Temperature &temperature);
void TestSetters(SensorRecType &sensorRecType, const Date &date, const Time &time, const WindSpeed &windSpeed, const SolarRadiation &solarRadiation, const Temperature &temperature);

int main()
{
    ostringstream outputStream;
    istringstream inputStream;
    Date date(24, 2, 2024);
    Time time(12, 30);
    float windSpeedReading = 15.5;
    WindSpeed windSpeed(windSpeedReading);
    SolarRadiation solarRadiation(500);
    Temperature temperature(25.5);

    SensorRecType testSensorRecType;
    SensorRecType parameterizedSensorRecType(date, time, windSpeed, solarRadiation, temperature);

    TestDefaultConstructor(testSensorRecType);
    TestParameterizedConstructor(parameterizedSensorRecType, date, time, windSpeed, solarRadiation, temperature);
    TestGetters(parameterizedSensorRecType, date, time, windSpeed, solarRadiation, temperature);
    TestSetters(testSensorRecType, date, time, windSpeed, solarRadiation, temperature);

    return 0;
}

void Assert(bool condition, const string &title, const string &description, const string &expectedOutput)
{
    cout << title;
    cout << setw(2) << " " << description;
    cout << setw(2) << " " << expectedOutput;
    cout << setw(2) << " " << (condition ? "[ PASS ]" : "[ FAIL ]") << "\n\n";
}

void TestDefaultConstructor(const SensorRecType &sensorRecType)
{
    Assert(
           sensorRecType.GetSensorDate().GetDay() == 0 &&
           sensorRecType.GetSensorDate().GetMonth() == 0 &&
           sensorRecType.GetSensorDate().GetYear() == 0 &&
           sensorRecType.GetSensorTime().GetHour() == 0 &&
           sensorRecType.GetSensorTime().GetMinute() == 0 &&
           sensorRecType.GetSensorWindSpeed().GetMeasurement() == 0.0 &&
           sensorRecType.GetSensorSolarRadiation().GetMeasurement() == 0 &&
           sensorRecType.GetSensorTemperature().GetMeasurement() == 0,
           "Test 1: Default Constructor\n",
           "Test Data/Values: None\n",
           "Expected Output: All sensor data initialized to default values\n");
}

void TestParameterizedConstructor(
                                  const SensorRecType &sensorRecType,
                                  const Date &date,
                                  const Time &time,
                                  const WindSpeed &windSpeed,
                                  const SolarRadiation &solarRadiation,
                                  const Temperature &temperature)
{
    Assert(sensorRecType.GetSensorDate() == date &&
               sensorRecType.GetSensorTime() == time &&
               sensorRecType.GetSensorWindSpeed().GetMeasurement() == windSpeed.GetMeasurement() &&
               sensorRecType.GetSensorSolarRadiation().GetMeasurement() == solarRadiation.GetMeasurement() &&
               sensorRecType.GetSensorTemperature().GetMeasurement() == temperature.GetMeasurement(),
           "Test 2: Parameterized Constructor\n",
           "Test Data/Values: Provided sensor data\n",
           "Expected Output: Sensor data initialized to provided values\n");
}

void TestGetters(const SensorRecType &sensorRecType, const Date &date, const Time &time, const WindSpeed &windSpeed, const SolarRadiation &solarRadiation, const Temperature &temperature)
{
    Assert(sensorRecType.GetSensorDate() == date &&
               sensorRecType.GetSensorTime() == time &&
               sensorRecType.GetSensorWindSpeed().GetMeasurement() == windSpeed.GetMeasurement() &&
               sensorRecType.GetSensorSolarRadiation().GetMeasurement() == solarRadiation.GetMeasurement() &&
               sensorRecType.GetSensorTemperature().GetMeasurement() == temperature.GetMeasurement(),
           "Test 3: Getters\n",
           "Test Data/Values: Provided sensor data\n",
           "Expected Output: Getters return correct sensor data\n");
}

void TestSetters(SensorRecType &sensorRecType, const Date &date, const Time &time, const WindSpeed &windSpeed, const SolarRadiation &solarRadiation, const Temperature &temperature)
{
    sensorRecType.SetSensorDate(date);
    sensorRecType.SetSensorTime(time);
    sensorRecType.SetSensorWindSpeed(windSpeed);
    sensorRecType.SetSensorSolarRadiation(solarRadiation);
    sensorRecType.SetSensorTemperature(temperature);

    Assert(sensorRecType.GetSensorDate() == date &&
               sensorRecType.GetSensorTime() == time &&
               sensorRecType.GetSensorWindSpeed().GetMeasurement() == windSpeed.GetMeasurement() &&
               sensorRecType.GetSensorSolarRadiation().GetMeasurement() == solarRadiation.GetMeasurement() &&
               sensorRecType.GetSensorTemperature().GetMeasurement() == temperature.GetMeasurement(),
           "Test 4: Setters\n",
           "Test Data/Values: Provided sensor data\n",
           "Expected Output: Setters correctly update sensor data\n");
}


