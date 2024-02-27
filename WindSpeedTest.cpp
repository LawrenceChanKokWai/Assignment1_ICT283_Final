#include "WindSpeed.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput );
void TestDefaultConstructor( const WindSpeed &windspeed );
void TestParameterizedConstructor( const WindSpeed &windspeed, const float &validMeasurement  );
void TestSetters( WindSpeed &windspeed, const float &validMeasurement );
void TestGetters( const WindSpeed &windspeed, const float &validMeasurement );
void TestGetMean( WindSpeed &windspeed );
void TestGetSumSquareDifferences( WindSpeed &windspeed );
void TestGetStandardDeviation( WindSpeed &windspeed );

int main()
{
    ostringstream outputStream;
    istringstream inputStream;
    float validMeasurement = 12.12;
    float newValidMeasurement = 11.11;
    WindSpeed testWindSpeed;
    WindSpeed windSpeedValid( validMeasurement );

    TestDefaultConstructor( testWindSpeed );
    TestParameterizedConstructor( windSpeedValid, validMeasurement );
    TestSetters( testWindSpeed, newValidMeasurement );
    TestGetters( testWindSpeed, newValidMeasurement );

    return 0;
}

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput )
{
    cout << title;
    cout << setw(2) << " " << description;
    cout << setw(2) << " " << expectedOutput;
    cout << setw(2) << " " << ( condition ? "[ PASS ]" : "[ FAIL ]") << "\n\n";
}

void TestDefaultConstructor( const WindSpeed &windSpeed )
{
    Assert( windSpeed.GetMeasurement() == 0,
            "Test 1: Default Constructor\n",
            "Test Data/Values: None\n",
            "Expected Output: windspeed initialized to INITIAL_VALUE\n" );
}

void TestParameterizedConstructor( const WindSpeed &windspeed, const float &validMeasurement )
{
    Assert( windspeed.GetMeasurement() == validMeasurement,
            "Test 2: Constructor with Valid Input Parameters\n",
            "Test Data/Values: windspeed = 12.12\n",
            "Expected Output: windspeed = 12.12\n" );
}

void TestSetters( WindSpeed &windspeed, const float &validMeasurement )
{
    windspeed.SetMeasurement( validMeasurement );
    Assert( windspeed.GetMeasurement() == validMeasurement,
            "Test 3: Setters\n",
            "Test Data/Values: windspeed = 11.11\n",
            "Expected Output: windspeed = 11.11\n");
}

void TestGetters( const WindSpeed &windspeed, const float &validMeasurement )
{
    Assert( windspeed.GetMeasurement() == validMeasurement,
            "Test 4: Getters\n",
            "Test Data/Values: windspeed = 11.11\n",
            "Expected Output: windspeed = 11.11\n");
}

void TestGetMean( WindSpeed &windspeed )
{
    float sum = 30.0;
    unsigned count = 5;
    float expectedMean = 6.0;

    float computedMean = windspeed.GetMean(sum, count);

    Assert(computedMean == expectedMean,
           "Test 5: GetMean\n",
           "Test Data/Values: sum = 30.0, count = 5\n",
           "Expected Output: Mean = 6.0\n");
}

void TestGetSumSquareDifferences( WindSpeed &windspeed )
{
    float sumSquareDifferences = 0.0;
    float perSquareDifference = 3.0;
    float mean = 2.0;
    float expectedSumSquareDifferences = 1.0;

    float computedSumSquareDifferences = windspeed.GetSumSquareDifferences(sumSquareDifferences, perSquareDifference, mean);

    Assert(computedSumSquareDifferences == expectedSumSquareDifferences,
           "Test 6: GetSumSquareDifferences\n",
           "Test Data/Values: perSquareDifference = 3.0, mean = 2.0\n",
           "Expected Output: Sum of Square Differences = 1.0\n");
}

void TestGetStandardDeviation( WindSpeed &windspeed )
{
    float sumSquareDifferences = 10.0;
    unsigned count = 5;
    float expectedStandardDeviation = sqrt(10.0 / 5);

    float computedStandardDeviation = windspeed.GetStandardDeviation(sumSquareDifferences, count);

    Assert(computedStandardDeviation == expectedStandardDeviation,
           "Test 7: GetStandardDeviation\n",
           "Test Data/Values: sumSquareDifferences = 10.0, count = 5\n",
           "Expected Output: Standard Deviation = sqrt(10.0 / 5)\n");
}
