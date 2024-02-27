#include "Time.h"
#include <iostream>
#include <sstream>
#include <iomanip>

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput );
void TestDefaultConstructor( const Time &time );
void TestParameterizedConstructor( const Time &time );
void TestSetters( Time &time );
void TestGetters( const Time &time );
void TestTimeEqualsOperator( Time &thisTime, Time &otherTime );
void TestOperatingOutputStream( const Time &time, ostringstream &outputStream );
void TestOperatingInputStream( Time &time, istringstream &inputStream );

int main()
{
    ostringstream outputStream;
    istringstream inputStream;
    Time testTime;
    Time timeValid(12,20);
    Time otherValid(12,20);

    TestDefaultConstructor( testTime );
    TestParameterizedConstructor( timeValid );
    TestSetters( testTime );
    TestGetters( testTime );
    TestTimeEqualsOperator( timeValid, otherValid );
    TestOperatingOutputStream( timeValid, outputStream );
    TestOperatingInputStream( timeValid, inputStream );

    return 0;
}

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput )
{
    cout << title;
    cout << setw(2) << " " << description;
    cout << setw(2) << " " << expectedOutput;
    cout << setw(2) << " " << ( condition ? "[ PASS ]" : "[ FAIL ]") << "\n\n";
}

void TestDefaultConstructor( const Time &time )
{
    Assert( time.GetHour() == 0 &&
            time.GetMinute() == 0,
            "Test 1: Default Constructor\n",
            "Test Data/Values: None\n",
            "Expected Output: Hour, Minute initialized to INITIAL_VALUE\n" );
}

void TestParameterizedConstructor( const Time &time )
{
    Assert( time.GetHour() == 12 &&
            time.GetMinute() == 20,
            "Test 2: Constructor with Valid Input Parameters\n",
            "Test Data/Values: Hour = 12, Minute = 20\n",
            "Expected Output: Hour = 12, Minute = 20\n" );
}

void TestSetters( Time &time )
{
    time.SetHour( 10 );
    time.SetMinute( 20 );
    Assert( time.GetHour() == 10 &&
            time.GetMinute() == 20,
            "Test 3: Setters\n",
            "Test Data/Values: Hour = 10, Minute = 20\n",
            "Expected Output: Hour = 10, Minute = 20\n");
}

void TestGetters( const Time &time )
{
    Assert( time.GetHour() == 10 &&
            time.GetMinute() == 20,
            "Test 4: Getters\n",
            "Test Data/Values: Hour = 10, Minute = 10\n",
            "Expected Output: Hour = 10, Minute = 20\n");
}

void TestTimeEqualsOperator( Time &thisTime, Time &otherTime )
{
    Assert( thisTime == otherTime,
            "Test 5: operator == Overloading - Equals Time\n",
            "Test Data/Values: thisTime(12:20), otherTime(12:20) \n",
            "Expected Output: 'Equals");
}

void TestOperatingOutputStream( const Time &time, ostringstream &outputStream )
{
    outputStream << time;
    Assert( outputStream.str() == "12:20",
            "Test 6: Operator << Overloading\n",
            "Test Data/Values: Time object with hour = 12, minute = 20\n",
            "Expected Output: '12:20'\n");
}

void TestOperatingInputStream( Time &time, istringstream &inputStream )
{
    inputStream.str( "10:20" );
    inputStream >> time;
    Assert( time.GetHour() == 10 &&
            time.GetMinute() == 20,
            "Test 7: Operator >> Overloading - Valid input\n",
            "Test Data/Values: Input = '10:20'\n",
            "Expected Output: Time object with Hour = 10, Minute = 20\n");
}



