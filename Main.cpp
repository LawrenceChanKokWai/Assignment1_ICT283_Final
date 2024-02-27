/**
* @file Main.cpp
* @brief Entry point for the assignment. The main execution file.
*
* This file contains the entry point of execution for assignment one.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#include <iostream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>

#include "InputValidator.h"
#include "Processor.h"

using namespace std;

int main()
{
    //const string filename = "data/data_source.txt";
    //const string outFilePath = "data/WindTempSolar.csv";

    const string filename = "C:/Users/ChanKokWai/Desktop/V3_AssignmentOne/ICT283_AssignmentOne_ChanKokWai_3394804/data/data_source.txt";
    const string outFilePath = "C:/Users/ChanKokWai/Desktop/V3_AssignmentOne/ICT283_AssignmentOne_ChanKokWai_3394804/data/WindTempSolar.csv";
    Vector<string> csvFilePath;
    MapAov mapAov;
    ifstream inFile( filename );
    ofstream outputFile( outFilePath );

    Processor::GetInstance();
    Processor::GetInstance().LoadCSVFilePathToVector( csvFilePath, inFile, filename );
    Processor::GetInstance().LoadCSVData( csvFilePath, mapAov );

    InputValidator validator;
    SensorRecType sensorRecType;
    Vector<SensorRecType> sensorRecords;

    string year;
    string month;
    bool isFileExported = false;
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
            validatedMonth = validator.MonthValidation(month);
            validatedYear = validator.YearValidation(year);

            sensorRecords = mapAov.GetSensorData()[validatedYear][validatedMonth - 1];
            if (!sensorRecords.IsEmpty())
            {
                //Calculate the mean
                float windSpeedMean = mapAov.MeanOfMeasurementSwitch(sensorRecords, SensorMeasurementType::WIND_SPEED);

                // Calculate Sample Standard Deviation
                float windSpeedSsd = mapAov.SampleStandardDeviationMeasurementSwitch(sensorRecords, SensorMeasurementType::WIND_SPEED);

                float convertedWindSpeedMean = sensorRecType.GetSensorWindSpeed().ConvertUnit( windSpeedMean );
                float convertedWindSpeedSsd = sensorRecType.GetSensorWindSpeed().ConvertUnit( windSpeedSsd );

                cout    << Constant::OUTPUT << endl;
                cout    << sensorRecType.GetSensorDate().GetMonthInStr( validatedMonth ) << " " << validatedYear << ":" << endl;
                cout    << Constant::AVERAGE_WINDSPEED << setprecision(3) << convertedWindSpeedMean << endl;
                cout    << Constant::WINDSPEED_STANDARD_DEVIATION << setprecision(3) << convertedWindSpeedSsd << '\n' << endl;
            }
            else
            {
                cout    << Constant::OUTPUT << endl;
                cout    << setw(5) << " " << sensorRecType.GetSensorDate().GetMonthInStr(validatedMonth) << " " << validatedYear << ": No Data" << '\n' << endl;
            }
            cout << endl;
            break;
        case '2':
            cout << Constant::SELECTED_OPTION_TWO_MSG << endl;

            validatedYear = validator.YearValidation(year);
            cout << '\n'  << Constant::OUTPUT << '\n' << validatedYear << ":" << endl;

            for (unsigned month = 1; month <= 12; ++month)
            {
                sensorRecords = mapAov.GetSensorData()[validatedYear][month - 1];
                if (!sensorRecords.IsEmpty())
                {
                    //Calculate the mean
                    float temperatureMean = mapAov.MeanOfMeasurementSwitch(sensorRecords, SensorMeasurementType::AMBIENT_TEMPERATURE);

                    // Calculate Sample Standard Deviation
                    float temperatureSsd = mapAov.SampleStandardDeviationMeasurementSwitch(sensorRecords, SensorMeasurementType::AMBIENT_TEMPERATURE);

                    cout << sensorRecType.GetSensorDate().GetMonthInStr( month ) << ": " <<
                         setprecision(3) << temperatureMean << " degrees C, stdev: " <<  setprecision(3) <<temperatureSsd << endl;
                }
                else
                {
                    cout << sensorRecType.GetSensorDate().GetMonthInStr(month) << ": No Data" << endl;
                }
            }
            cout << endl;
            break;
        case '3':
            cout << Constant::SELECTED_OPTION_THREE_MSG << endl;

            validatedYear = validator.YearValidation(year);
            cout << '\n'  << Constant::OUTPUT << '\n' << validatedYear << ":" << endl;
            for (unsigned month = 1; month <= 12; ++month)
            {
                sensorRecords = mapAov.GetSensorData()[validatedYear][month - 1];
                if (!sensorRecords.IsEmpty())
                {
                    float solarRadiationSum = mapAov.SumOfMeasurementSwitch(sensorRecords, SensorMeasurementType::SOLAR_RADIATION);
                    float convertedSrSum = sensorRecType.GetSensorSolarRadiation().ConvertUnit( solarRadiationSum );

                    cout << sensorRecType.GetSensorDate().GetMonthInStr(month) << ": "
                         << setprecision(3) << convertedSrSum << " kWh/m2" << endl;
                }
                else
                {
                    cout << sensorRecType.GetSensorDate().GetMonthInStr(month) << ": No Data" << endl;
                }
            }
            cout << endl;
            break;
        case '4':
            cout << Constant::SELECTED_OPTION_FOUR_MSG << endl;

            validatedYear = validator.YearValidation(year);
            cout << '\n' << Constant::OUTPUT << endl;
            cout << '\n' <<  validatedYear << ":" << endl;

            if( !outputFile )
            {
                cerr << "[ ERROR ] Opening File: " << outFilePath << endl;
            }

            outputFile << "Month,Average Wind Speed(stdev),Average Ambient Temperature(stdev),Solar Radiation" << endl;

            for (unsigned month = 1; month <= 12; ++month)
            {
                sensorRecords = mapAov.GetSensorData()[validatedYear][month - 1];
                if (!sensorRecords.IsEmpty())
                {
                    // Calculate the sum for solar radiation
                    float solarRadiationSum = mapAov.SumOfMeasurementSwitch(sensorRecords, SensorMeasurementType::SOLAR_RADIATION);

                    //Calculate the mean
                    float windSpeedMean = mapAov.MeanOfMeasurementSwitch(sensorRecords, SensorMeasurementType::WIND_SPEED);
                    float temperatureMean = mapAov.MeanOfMeasurementSwitch(sensorRecords, SensorMeasurementType::AMBIENT_TEMPERATURE);

                    // Calculate Sample Standard Deviation
                    float windSpeedSsd = mapAov.SampleStandardDeviationMeasurementSwitch(sensorRecords, SensorMeasurementType::WIND_SPEED);
                    float temperatureSsd = mapAov.SampleStandardDeviationMeasurementSwitch(sensorRecords, SensorMeasurementType::AMBIENT_TEMPERATURE);

                    float convertedWindSpeedMean = sensorRecType.GetSensorWindSpeed().ConvertUnit( windSpeedMean );
                    float convertedWindSpeedSsd = sensorRecType.GetSensorWindSpeed().ConvertUnit( windSpeedSsd );
                    float convertedSrSum = sensorRecType.GetSensorSolarRadiation().ConvertUnit( solarRadiationSum );

                    cout << sensorRecType.GetSensorDate().GetMonthInStr(month) << ","
                         << setprecision(3) << convertedWindSpeedMean << "(" << setprecision(3) << convertedWindSpeedSsd << "),"
                         << setprecision(3) << temperatureMean << "(" << setprecision(3) << temperatureSsd << "),"
                         << setprecision(3) << convertedSrSum << endl;

                    if(
                        Processor::GetInstance().OutputStreamMeasurement(
                            sensorRecType,
                            outputFile,
                            month,
                            windSpeedMean,
                            convertedWindSpeedSsd,
                            temperatureMean,
                            temperatureSsd,
                            convertedSrSum ) )
                    {
                        isFileExported = true;
                    }
                }
                else
                {
                    cout << sensorRecType.GetSensorDate().GetMonthInStr(month) << ",No Data" << endl;
                }
            }
            outputFile.close();
            if( isFileExported )
            {
                cout << '\n' << "[ INFO ]: Data has being exported to: " << outFilePath << endl;
            }
            else
            {
                cout << "[ ERROR ]: Exporting data to: " << outFilePath << endl;
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



