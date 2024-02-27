/**
* @file MeasurementTest.cpp
* @brief Measurement Test execution file
*
* This file contains the execution unit test for Measurement Class.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#include "Measurement.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput );
void TestDefaultConstructor( const Measurement &measurement );
void TestParameterizedConstructor( const Measurement &measurement, const float &validMeasurement  );
void TestSetters( Measurement &measurement, const float &validMeasurement );
void TestGetters( const Measurement &measurement, const float &validMeasurement );
void TestGetMean( Measurement &measurement );
void TestGetSumSquareDifferences( Measurement &measurement );
void TestGetStandardDeviation( Measurement &measurement );



int main()
{
    ostringstream outputStream;
    istringstream inputStream;
    float validMeasurement = 12.12;
    float newValidMeasurement = 11.11;
    Measurement testMeasurement;
    Measurement measurementValid( validMeasurement );

    TestDefaultConstructor( testMeasurement );
    TestParameterizedConstructor( measurementValid, validMeasurement );
    TestSetters( testMeasurement, newValidMeasurement );
    TestGetters( testMeasurement, newValidMeasurement );
    TestGetMean( testMeasurement );
    TestGetSumSquareDifferences( testMeasurement );
    TestGetStandardDeviation( testMeasurement );

    return 0;
}

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput )
{
    cout << title;
    cout << setw(2) << " " << description;
    cout << setw(2) << " " << expectedOutput;
    cout << setw(2) << " " << ( condition ? "[ PASS ]" : "[ FAIL ]") << "\n\n";
}

void TestDefaultConstructor( const Measurement &measurement )
{
    Assert( measurement.GetMeasurement() == 0,
            "Test 1: Default Constructor\n",
            "Test Data/Values: None\n",
            "Expected Output: Measurement initialized to INITIAL_VALUE\n" );
}

void TestParameterizedConstructor( const Measurement &measurement, const float &validMeasurement )
{
    Assert( measurement.GetMeasurement() == validMeasurement,
            "Test 2: Constructor with Valid Input Parameters\n",
            "Test Data/Values: measurement = 12.12\n",
            "Expected Output: measurement = 12.12\n" );
}

void TestSetters( Measurement &measurement, const float &validMeasurement )
{
    measurement.SetMeasurement( validMeasurement );
    Assert( measurement.GetMeasurement() == validMeasurement,
            "Test 3: Setters\n",
            "Test Data/Values: measurement = 11.11\n",
            "Expected Output: measurement = 11.11\n");
}

void TestGetters( const Measurement &measurement, const float &validMeasurement )
{
    Assert( measurement.GetMeasurement() == validMeasurement,
            "Test 4: Getters\n",
            "Test Data/Values: measurement = 11.11\n",
            "Expected Output: measurement = 11.11\n");
}

void TestGetMean( Measurement &measurement )
{
    float sum = 30.0;
    unsigned count = 5;
    float expectedMean = 6.0;

    float computedMean = measurement.GetMean(sum, count);

    Assert(computedMean == expectedMean,
           "Test 5: GetMean\n",
           "Test Data/Values: sum = 30.0, count = 5\n",
           "Expected Output: Mean = 6.0\n");
}

void TestGetSumSquareDifferences( Measurement &measurement )
{
    float sumSquareDifferences = 0.0;
    float perSquareDifference = 3.0;
    float mean = 2.0;
    float expectedSumSquareDifferences = 1.0;

    float computedSumSquareDifferences = measurement.GetSumSquareDifferences(sumSquareDifferences, perSquareDifference, mean);

    Assert(computedSumSquareDifferences == expectedSumSquareDifferences,
           "Test 6: GetSumSquareDifferences\n",
           "Test Data/Values: perSquareDifference = 3.0, mean = 2.0\n",
           "Expected Output: Sum of Square Differences = 1.0\n");
}

void TestGetStandardDeviation( Measurement &measurement )
{
    float sumSquareDifferences = 10.0;
    unsigned count = 5;
    float expectedStandardDeviation = sqrt(10.0 / 5);

    float computedStandardDeviation = measurement.GetStandardDeviation(sumSquareDifferences, count);

    Assert(computedStandardDeviation == expectedStandardDeviation,
           "Test 7: GetStandardDeviation\n",
           "Test Data/Values: sumSquareDifferences = 10.0, count = 5\n",
           "Expected Output: Standard Deviation = sqrt(10.0 / 5)\n");
}


