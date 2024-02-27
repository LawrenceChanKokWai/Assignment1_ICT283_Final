/**
* @file DateTest.cpp
* @brief Date Test execution file
*
* This file contains the execution unit test for Date Class.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#include "Date.h"
#include <iostream>
#include <sstream>
#include <iomanip>

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput );
void TestDefaultConstructor( const Date &date );
void TestParameterizedConstructor( const Date &date );
void TestSetters( Date &date );
void TestGetters( const Date &date );
void TestDateEqualsOperator( const Date &thisDate, const Date &otherDate );
void TestGetNameOfMonthValid( const Date &date );
void TestGetNameOfMonthInvalid( const Date &date );
void TestOperatingOutputStream( const Date &date, ostringstream &outputStream );
void TestOperatingInputStream( Date &date, istringstream &inputStream );

int main()
{
    ostringstream outputStream;
    istringstream inputStream;
    Date testDate;
    Date dateValid(25,12,2023);
    Date otherDate(25,12,2023);

    TestDefaultConstructor( testDate );
    TestParameterizedConstructor( dateValid );
    TestSetters( testDate );
    TestGetters( testDate );
    TestGetNameOfMonthValid( testDate );
    TestGetNameOfMonthInvalid( testDate );
    TestDateEqualsOperator( dateValid, otherDate );
    TestOperatingOutputStream( dateValid, outputStream );
    TestOperatingInputStream( dateValid, inputStream );

    return 0;
}

void Assert( bool condition, const string &title, const string &description, const string &expectedOutput )
{
    cout << title;
    cout << setw(2) << " " << description;
    cout << setw(2) << " " << expectedOutput;
    cout << setw(2) << " " << ( condition ? "[ PASS ]" : "[ FAIL ]") << "\n\n";
}

void TestDefaultConstructor( const Date &date )
{
    Assert( date.GetDay() == 0 &&
            date.GetMonth() == 0 &&
            date.GetYear() == 0,
            "Test 1: Default Constructor\n",
            "Test Data/Values: None\n",
            "Expected Output: Day, month, and year initialized to INITIAL_VALUE\n" );
}

void TestParameterizedConstructor( const Date &date )
{
    Assert( date.GetDay() == 25 &&
            date.GetMonth() == 12 &&
            date.GetYear() == 2023,
            "Test 2: Constructor with Valid Input Parameters\n",
            "Test Data/Values: Day = 25, Month = 12, Year = 2023\n",
            "Expected Output: Day = 25, Month = 12, Year = 2023\n" );
}

void TestSetters( Date &date )
{
    date.SetDay( 10 );
    date.SetMonth( 3 );
    date.SetYear( 2024 );
    Assert( date.GetDay() == 10 &&
            date.GetMonth() == 3 &&
            date.GetYear() == 2024,
            "Test 3: Setters\n",
            "Test Data/Values: Day = 10, Month = 3, Year = 2024\n",
            "Expected Output: Day = 10, Month = 3, Year = 2024\n");
}

void TestGetters( const Date &date )
{
    Assert( date.GetDay() == 10 &&
            date.GetMonth() == 3 &&
            date.GetYear() == 2024,
            "Test 4: Getters\n",
            "Test Data/Values: Day = 10, Month = 3, Year = 2024\n",
            "Expected Output: Day = 10, Month = 3, Year = 2024\n");
}

void TestGetNameOfMonthValid( const Date &date )
{
    Assert( date.GetMonthInStr(4) == "April",
            "Test 5: GetMonthInStr - Valid month\n",
            "Test Data/Values: Month = 4\n",
            " Expected Output: 'April'\n");
}

void TestGetNameOfMonthInvalid( const Date &date )
{
    Assert( date.GetMonthInStr(15) == "Error",
            "Test 6: GetMonthInStr - Invalid month\n",
            "Test Data/Values: Month = 15\n",
            "Expected Output: 'Error'\n");
}

void TestDateEqualsOperator( const Date &thisDate, const Date &otherDate )
{
    Assert( thisDate == otherDate,
            "Test 7: operator == Overloading - Equals Date\n",
            "Test Data/Values: thisDate(25/12/2023), otherDate(25/12/2023) \n",
            "Expected Output: 'Equals");
}

void TestOperatingOutputStream( const Date &date, ostringstream &outputStream )
{
    outputStream << date;
    Assert( outputStream.str() == "25 December 2023",
            "Test 8: Operator << Overloading\n",
            "Test Data/Values: Date object with Day = 25, Month = 12, Year = 2023\n",
            "Expected Output: '25 December 2023'\n");
}

void TestOperatingInputStream( Date &date, istringstream &inputStream )
{
    inputStream.str( "10/11/2022" );
    inputStream >> date;
    Assert( date.GetDay() == 10 &&
                    date.GetMonth() == 11 &&
                    date.GetYear() == 2022,
            "Test 9: Operator >> Overloading - Valid input\n",
            "Test Data/Values: Input = '10/11/2022'\n",
            "Expected Output: Date object with Day = 10, Month = 11, Year = 2022\n");
}



