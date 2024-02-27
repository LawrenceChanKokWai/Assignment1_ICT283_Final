
#include "WindSpeed.h"

WindSpeed::WindSpeed(): Measurement(){}

WindSpeed::WindSpeed( const float &measurement ): Measurement( measurement ){}

float WindSpeed::ConvertUnit( float &measurement )
{
    return ( measurement * 3.6 );
}

ostream &operator << ( ostream &output, const WindSpeed &WS )
{
    output << WS.GetMeasurement();

    return output;
}

istream &operator >> ( istream &input, WindSpeed &WS )
{
    string tempWindSpeed;
    const unsigned columnToSkip =10;

    for( unsigned i(0); i<columnToSkip; i++ )
    {
        getline( input, tempWindSpeed, ',' );
    }
    getline( input, tempWindSpeed, ',' );

    WS.SetMeasurement( stof(tempWindSpeed) );

    return input;
}
