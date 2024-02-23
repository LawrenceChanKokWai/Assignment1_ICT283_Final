#include <iostream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>

#include "MapAov.h"
#include "Menu.h"
#include "Processor.h"

using namespace std;

int main()
{
    const string filename = "data/data_source.txt";
    const string outFilePath = "data/WindTempSolar.csv";
    Vector<string> csvFilePath;
    MapAov mapAov;
    ifstream inFile( filename );

    Processor::GetInstance();
    Processor::GetInstance().LoadCSVFilePathToVector( csvFilePath, inFile, filename );
    Processor::GetInstance().LoadCSVData( csvFilePath, mapAov );

    Menu menu;
    SensorRecType sensorRecType;
    Vector<SensorRecType> sensorRecords;

    string year;
    string month;
    char user_choice;
    do
    {
        unsigned validatedMonth = 0;
        unsigned validatedYear = 0;

        cout       << Constant::MENU_OPTIONS_MSG
                   << Constant::MENU_OPTION_ONE_MSG
                   << Constant::MENU_OPTION_TWO_MSG
                   << Constant::MENU_OPTION_THREE_MSG
                   << Constant::MENU_OPTION_FOUR_MSG
                   << Constant::MENU_OPTION_FIVE_MSG << endl;

        cout << Constant::SELECTION_INPUT;
        user_choice = getch();
        switch( user_choice )
        {
        case '1':
            cout << Constant::SELECTED_OPTION_ONE_MSG << endl;
            validatedMonth = menu.MonthValidation( month );
            validatedYear = menu.YearValidation( year );

            sensorRecords = mapAov.DisplayMeanSsdFromMonthAndYear(validatedYear, validatedMonth);

            if (!sensorRecords.IsEmpty())
            {
                float sumWindSpeed = 0.0;
                unsigned count = 0;
                for ( unsigned i(0); i<sensorRecords.GetUsed(); i++ )
                {
                    sumWindSpeed += sensorRecords[i].GetSensorWindSpeed().GetMeasurement();
                    count ++;
                }

                if( count > 0 )
                {
                    float standardDeviation = mapAov.GetSampleStandardDeviation(sensorRecords);
                    cout    << Constant::OUTPUT << endl;
                    cout    << sensorRecType.GetSensorDate().GetMonthInStr( validatedMonth ) << " " << validatedYear << ":" << endl;
                    cout    << Constant::AVERAGE_WINDSPEED << setprecision(3) << sensorRecType.GetSensorWindSpeed().GetMean( sumWindSpeed, count ) << endl;
                    cout    << Constant::WINDSPEED_STANDARD_DEVIATION << setprecision(3) << standardDeviation << '\n' << endl;
                }
                else
                {
                    cout    << Constant::OUTPUT << endl;
                    cout    << setw(5) << " " << sensorRecType.GetSensorDate().GetMonthInStr(validatedMonth) << " " << validatedYear << ": No Data" << '\n' << endl;
                }
            }
            else
            {
                cout    << Constant::OUTPUT << endl;
                cout    << setw(5) << " " << sensorRecType.GetSensorDate().GetMonthInStr(validatedMonth) << " " << validatedYear << ": No Data" << '\n' << endl;
            }
            break;

        case '2':
            cout << Constant::SELECTED_OPTION_TWO_MSG << endl;

            validatedYear = menu.YearValidation(year);
            cout << '\n'  << Constant::OUTPUT << '\n' << validatedYear << ":" << endl;
            mapAov.DisplayMeanSsdEachMonthOfYear( validatedYear );

            break;
        case '3':
            cout << Constant::SELECTED_OPTION_THREE_MSG << endl;

            validatedYear = menu.YearValidation(year);
            cout << '\n'  << Constant::OUTPUT << '\n' << validatedYear << ":" << endl;
            mapAov.DisplaySumMonthOfYear( validatedYear );

            break;
        case '4':
            cout << Constant::SELECTED_OPTION_FOUR_MSG << endl;

            validatedYear = menu.YearValidation(year);
            cout << '\n' << Constant::OUTPUT << endl;
            cout << '\n' <<  validatedYear << ":" << endl;

            for (unsigned month = 1; month <= 12; ++month)
            {
                sensorRecords = mapAov.GetSensorData()[validatedYear][month - 1];
                if (!sensorRecords.IsEmpty())
                {
                    // Calculate the sum for solar radiation
                    float solarRadiationSum = mapAov.SumOfMeasurementSwitch(sensorRecords, SensorMeasurementType::SOLAR_RADIATION);
                    float convertedSrSum = solarRadiationSum / 60000;

                    //Calculate the mean
                    float windSpeedMean = mapAov.MeanOfMeasurementSwitch(sensorRecords, SensorMeasurementType::WIND_SPEED);
                    float temperatureMean = mapAov.MeanOfMeasurementSwitch(sensorRecords, SensorMeasurementType::AMBIENT_TEMPERATURE);

                    // Calculate Sample Standard Deviation
                    float windSpeedSsd = mapAov.SampleStandardDeviationMeasurementSwitch(sensorRecords, SensorMeasurementType::WIND_SPEED);
                    float temperatureSsd = mapAov.SampleStandardDeviationMeasurementSwitch(sensorRecords, SensorMeasurementType::AMBIENT_TEMPERATURE);

                    cout << sensorRecType.GetSensorDate().GetMonthInStr(month) << ","
                         << setprecision(3) << windSpeedMean << "(" << setprecision(3) << windSpeedSsd << "),"
                         << setprecision(3) << temperatureMean << "(" << setprecision(3) << temperatureSsd << "),"
                         << setprecision(3) << convertedSrSum << endl;

                    Processor::GetInstance().OutputStreamMeasurement(
                        sensorRecType,
                        outFilePath,
                        month,
                        windSpeedMean,
                        windSpeedSsd,
                        temperatureMean,
                        temperatureSsd,
                        convertedSrSum );
                }
                else
                {
                    cout << sensorRecType.GetSensorDate().GetMonthInStr(month) << ",No Data" << endl;
                }
            }
            cout << endl;
            break;
        case '5':
            cout << Constant::SELECTED_OPTION_FIVE_MSG << endl;
            exit(0);
            break;
        default:
            break;
        }
        cout << Constant::INFO( Constant::PRESS_ENTER_TO_CONTINUE_MSG ) << endl;
        while( getch() != 13 );
        system("cls");
    }
    while( user_choice !=27 );

    return 0;
}



