
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

