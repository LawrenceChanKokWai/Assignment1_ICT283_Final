
/**
* @file SolarRadiationTest.cpp
* @brief SolarRadiation Test execution file
*
* This file contains the execution unit test for SolarRadiation Class.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#include "SolarRadiation.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput );
void TestDefaultConstructor( const SolarRadiation &solarRadiation );
void TestParameterizedConstructor( const SolarRadiation &solarRadiation, const float &validMeasurement  );
void TestSetters( SolarRadiation &solarRadiation, const float &validMeasurement );
void TestGetters( const SolarRadiation &solarRadiation, const float &validMeasurement );
void TestGetMean( SolarRadiation &solarRadiation );
void TestGetSumSquareDifferences( SolarRadiation &solarRadiation );
void TestGetStandardDeviation( SolarRadiation &solarRadiation );



int main()
{
    ostringstream outputStream;
    istringstream inputStream;
    float validMeasurement = 12.12;
    float newValidMeasurement = 11.11;
    SolarRadiation testSolarRadiation;
    SolarRadiation solarRadiationValid( validMeasurement );

    TestDefaultConstructor( testSolarRadiation );
    TestParameterizedConstructor( solarRadiationValid, validMeasurement );
    TestSetters( testSolarRadiation, newValidMeasurement );
    TestGetters( testSolarRadiation, newValidMeasurement );
    TestGetMean( testSolarRadiation );
    TestGetSumSquareDifferences( testSolarRadiation );
    TestGetStandardDeviation( testSolarRadiation );

    return 0;
}

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput )
{
    cout << title;
    cout << setw(2) << " " << description;
    cout << setw(2) << " " << expectedOutput;
    cout << setw(2) << " " << ( condition ? "[ PASS ]" : "[ FAIL ]") << "\n\n";
}

void TestDefaultConstructor( const SolarRadiation &solarRadiation )
{
    Assert( solarRadiation.GetMeasurement() == 0,
            "Test 1: Default Constructor\n",
            "Test Data/Values: None\n",
            "Expected Output: solar radiation initialized to INITIAL_VALUE\n" );
}

void TestParameterizedConstructor( const SolarRadiation &solarRadiation, const float &validMeasurement )
{
    Assert( solarRadiation.GetMeasurement() == validMeasurement,
            "Test 2: Constructor with Valid Input Parameters\n",
            "Test Data/Values: solar radiation = 12.12\n",
            "Expected Output: solar radiation = 12.12\n" );
}

void TestSetters( SolarRadiation &solarRadiation, const float &validMeasurement )
{
    solarRadiation.SetMeasurement( validMeasurement );
    Assert( solarRadiation.GetMeasurement() == validMeasurement,
            "Test 3: Setters\n",
            "Test Data/Values: solar radiation = 11.11\n",
            "Expected Output: solar radiation = 11.11\n");
}

void TestGetters( const SolarRadiation &solarRadiation, const float &validMeasurement )
{
    Assert( solarRadiation.GetMeasurement() == validMeasurement,
            "Test 4: Getters\n",
            "Test Data/Values: solar radiation = 11.11\n",
            "Expected Output: solar radiation = 11.11\n");
}

void TestGetMean( SolarRadiation &solarRadiation )
{
    float sum = 30.0;
    unsigned count = 5;
    float expectedMean = 6.0;

    float computedMean = solarRadiation.GetMean(sum, count);

    Assert(computedMean == expectedMean,
           "Test 5: GetMean\n",
           "Test Data/Values: sum = 30.0, count = 5\n",
           "Expected Output: Mean = 6.0\n");
}

void TestGetSumSquareDifferences( SolarRadiation &solarRadiation )
{
    float sumSquareDifferences = 0.0;
    float perSquareDifference = 3.0;
    float mean = 2.0;
    float expectedSumSquareDifferences = 1.0;

    float computedSumSquareDifferences = solarRadiation.GetSumSquareDifferences(sumSquareDifferences, perSquareDifference, mean);

    Assert(computedSumSquareDifferences == expectedSumSquareDifferences,
           "Test 6: GetSumSquareDifferences\n",
           "Test Data/Values: perSquareDifference = 3.0, mean = 2.0\n",
           "Expected Output: Sum of Square Differences = 1.0\n");
}

void TestGetStandardDeviation( SolarRadiation &solarRadiation )
{
    float sumSquareDifferences = 10.0;
    unsigned count = 5;
    float expectedStandardDeviation = sqrt(10.0 / 5);

    float computedStandardDeviation = solarRadiation.GetStandardDeviation(sumSquareDifferences, count);

    Assert(computedStandardDeviation == expectedStandardDeviation,
           "Test 7: GetStandardDeviation\n",
           "Test Data/Values: sumSquareDifferences = 10.0, count = 5\n",
           "Expected Output: Standard Deviation = sqrt(10.0 / 5)\n");
}


