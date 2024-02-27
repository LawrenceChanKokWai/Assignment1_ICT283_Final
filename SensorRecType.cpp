
#include "SensorRecType.h"

SensorRecType::SensorRecType()
{
    m_date              = Date();
    m_time              = Time();
    m_windSpeed         = WindSpeed();
    m_solarRadiation    = SolarRadiation();
    m_temperature       = Temperature();
}

SensorRecType::SensorRecType( const Date &date,
                              const Time &time,
                              const WindSpeed &windSpeed,
                              const SolarRadiation &solarRadiation,
                              const Temperature &temperature )
{
    m_date              = date;
    m_time              = time;
    m_windSpeed         = windSpeed;
    m_solarRadiation    = solarRadiation;
    m_temperature       = temperature;
}

Date SensorRecType::GetSensorDate() const
{
    return m_date;
}

Time SensorRecType::GetSensorTime() const
{
    return m_time;
}

WindSpeed SensorRecType::GetSensorWindSpeed() const
{
    return m_windSpeed;
}

SolarRadiation SensorRecType::GetSensorSolarRadiation() const
{
    return m_solarRadiation;
}

Temperature SensorRecType::GetSensorTemperature() const
{
    return m_temperature;
}

void SensorRecType::SetSensorDate(const Date &date)
{
    m_date = date;
}

void SensorRecType::SetSensorTime(const Time &time)
{
    m_time = time;
}

void SensorRecType::SetSensorWindSpeed(const WindSpeed &windSpeed)
{
    m_windSpeed = windSpeed;
}

void SensorRecType::SetSensorSolarRadiation(const SolarRadiation &solarRadiation)
{
    m_solarRadiation = solarRadiation;
}

void SensorRecType::SetSensorTemperature(const Temperature &temperature)
{
    m_temperature = temperature;
}

ostream &operator << ( ostream &output, const SensorRecType &SRT )
{
    output  << SRT.GetSensorDate()              << " "
            << SRT.GetSensorTime()              << " "
            << SRT.GetSensorWindSpeed()         << " "
            << SRT.GetSensorSolarRadiation()    << " "
            << SRT.GetSensorTemperature();

    return output;
}

istream &operator >> ( istream &input, SensorRecType &SRT )
{
    Date            tempDate;
    Time            tempTime;
    WindSpeed       tempWindSpeed;
    SolarRadiation  tempSolarRadiation;
    Temperature     tempTemperature;

    input >> tempDate >> tempTime >> tempWindSpeed >> tempSolarRadiation >> tempTemperature;

    SRT.SetSensorDate( tempDate );
    SRT.SetSensorTime( tempTime );
    SRT.SetSensorWindSpeed( tempWindSpeed );
    SRT.SetSensorSolarRadiation( tempSolarRadiation );
    SRT.SetSensorTemperature( tempTemperature );

    return input;
}
