
/**
* @file TemperatureTest.cpp
* @brief Temperature Test execution file
*
* This file contains the execution unit test for Temperature Class.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#include "Temperature.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput );
void TestDefaultConstructor( const Temperature &temperature );
void TestParameterizedConstructor( const Temperature &temperature, const float &validMeasurement  );
void TestSetters( Temperature &temperature, const float &validMeasurement );
void TestGetters( const Temperature &temperature, const float &validMeasurement );
void TestGetMean( Temperature &temperature );
void TestGetSumSquareDifferences( Temperature &temperature );
void TestGetStandardDeviation( Temperature &temperature );



int main()
{
    ostringstream outputStream;
    istringstream inputStream;
    float validMeasurement = 12.12;
    float newValidMeasurement = 11.11;
    Temperature testTemperature;
    Temperature temperatureValid( validMeasurement );

    TestDefaultConstructor( testTemperature );
    TestParameterizedConstructor( temperatureValid, validMeasurement );
    TestSetters( testTemperature, newValidMeasurement );
    TestGetters( testTemperature, newValidMeasurement );
    TestGetMean( testTemperature );
    TestGetSumSquareDifferences( testTemperature );
    TestGetStandardDeviation( testTemperature );

    return 0;
}

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput )
{
    cout << title;
    cout << setw(2) << " " << description;
    cout << setw(2) << " " << expectedOutput;
    cout << setw(2) << " " << ( condition ? "[ PASS ]" : "[ FAIL ]") << "\n\n";
}

void TestDefaultConstructor( const Temperature &temperature )
{
    Assert( temperature.GetMeasurement() == 0,
            "Test 1: Default Constructor\n",
            "Test Data/Values: None\n",
            "Expected Output: temperature initialized to INITIAL_VALUE\n" );
}

void TestParameterizedConstructor( const Temperature &temperature, const float &validMeasurement )
{
    Assert( temperature.GetMeasurement() == validMeasurement,
            "Test 2: Constructor with Valid Input Parameters\n",
            "Test Data/Values: temperature = 12.12\n",
            "Expected Output: temperature = 12.12\n" );
}

void TestSetters( Temperature &temperature, const float &validMeasurement )
{
    temperature.SetMeasurement( validMeasurement );
    Assert( temperature.GetMeasurement() == validMeasurement,
            "Test 3: Setters\n",
            "Test Data/Values: temperature = 11.11\n",
            "Expected Output: temperature = 11.11\n");
}

void TestGetters( const Temperature &temperature, const float &validMeasurement )
{
    Assert( temperature.GetMeasurement() == validMeasurement,
            "Test 4: Getters\n",
            "Test Data/Values: temperature = 11.11\n",
            "Expected Output: temperature = 11.11\n");
}

void TestGetMean( Temperature &temperature )
{
    float sum = 30.0;
    unsigned count = 5;
    float expectedMean = 6.0;

    float computedMean = temperature.GetMean(sum, count);

    Assert(computedMean == expectedMean,
           "Test 5: GetMean\n",
           "Test Data/Values: sum = 30.0, count = 5\n",
           "Expected Output: Mean = 6.0\n");
}

void TestGetSumSquareDifferences( Temperature &temperature )
{
    float sumSquareDifferences = 0.0;
    float perSquareDifference = 3.0;
    float mean = 2.0;
    float expectedSumSquareDifferences = 1.0;

    float computedSumSquareDifferences = temperature.GetSumSquareDifferences(sumSquareDifferences, perSquareDifference, mean);

    Assert(computedSumSquareDifferences == expectedSumSquareDifferences,
           "Test 6: GetSumSquareDifferences\n",
           "Test Data/Values: perSquareDifference = 3.0, mean = 2.0\n",
           "Expected Output: Sum of Square Differences = 1.0\n");
}

void TestGetStandardDeviation( Temperature &temperature )
{
    float sumSquareDifferences = 10.0;
    unsigned count = 5;
    float expectedStandardDeviation = sqrt(10.0 / 5);

    float computedStandardDeviation = temperature.GetStandardDeviation(sumSquareDifferences, count);

    Assert(computedStandardDeviation == expectedStandardDeviation,
           "Test 7: GetStandardDeviation\n",
           "Test Data/Values: sumSquareDifferences = 10.0, count = 5\n",
           "Expected Output: Standard Deviation = sqrt(10.0 / 5)\n");
}


