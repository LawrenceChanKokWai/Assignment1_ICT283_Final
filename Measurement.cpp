/**
* @file Measurement.cpp
* @brief Measurement class implementation file
*
* This file contains the Measurement base class implementation.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#include "Measurement.h"

Measurement::Measurement()
{
    m_measurement = INITIAL_VALUE;
}

Measurement::Measurement( const float &measurement )
{
    m_measurement = measurement;
}

float Measurement::GetMeasurement() const
{
    return m_measurement;
}

void Measurement::SetMeasurement( const float &measurement )
{
    m_measurement = measurement;
}

