
#include "Time.h"

Time::Time()
{
    m_hour = INITIAL_VALUE;
    m_minute = INITIAL_VALUE;
}

Time::Time( const unsigned &hour,  const unsigned &minute )
{
    m_hour = hour;
    m_minute = minute;
}

unsigned Time::GetHour() const
{
    return m_hour;
}

unsigned Time::GetMinute() const
{
    return m_minute;
}

void Time::SetHour( const unsigned &hour )
{
    m_hour = hour;
}

void Time::SetMinute( const unsigned &minute )
{
    m_minute = minute;
}

bool Time::operator == ( const Time &otherTime )
{
    return m_hour == otherTime.m_hour && m_minute == otherTime.m_minute;
}

ostream &operator << ( ostream &outputStream, const Time &T )
{
    outputStream << T.GetHour() << ":" << setw(2) << setfill( '0' ) << T.GetMinute();

    return outputStream;
}

istream &operator >> ( istream &inputStream, Time &T )
{
    string tempField;
    const unsigned INITIAL_VALUE = 0;

    getline( inputStream, tempField, ':');
    try
    {
        T.SetHour( stoi(tempField) );
    }
    catch(...)
    {
        T.SetHour( INITIAL_VALUE );
    }

    getline( inputStream, tempField, ',');
    try
    {
        T.SetMinute( stoi(tempField) );

    }
    catch(...)
    {
        T.SetMinute( INITIAL_VALUE );
    }

    return inputStream;
}
