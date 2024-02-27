
#include "SolarRadiation.h"

SolarRadiation::SolarRadiation(): Measurement() {}

SolarRadiation::SolarRadiation( const float &measurement ): Measurement( measurement ) {}

float SolarRadiation::ConvertUnit( float &measurement )
{
    return ( measurement/1000 * 10/60 );
}

ostream &operator << ( ostream &output, const SolarRadiation &SR )
{
    output << SR.GetMeasurement();

    return output;
}

istream &operator >> ( istream &input, SolarRadiation &SR )
{
    string tempSolarRadiation;

    getline( input, tempSolarRadiation, ',' );

    SR.SetMeasurement( stof(tempSolarRadiation) );

    return input;
}
