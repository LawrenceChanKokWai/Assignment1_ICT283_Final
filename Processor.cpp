
#include "Processor.h"

// +++++++++++++ PRIVATE ++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++
Processor::Processor()
{
    m_dataRead = 0;
    m_dataInserted = 0;
}

void Processor::LoadDisplayCount()
{
    std::cout   << Constant::INFO( Constant::TOTAL_READ_DATA_MSG ) << m_dataRead << '\n'
                << Constant::INFO( Constant::TOTAL_SAVED_DATA_MSG ) << m_dataInserted << '\n'
                << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                << endl;
}

// +++++++++++++ PUBLIC +++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++
Processor &Processor::GetInstance()
{
    static Processor *s_instance = new Processor();
    return *s_instance;
}

void Processor::LoadCSVFilePathToVector( Vector<string> &csvFilePath, ifstream &input, const string &filename )
{
    string file_path;
    if( !input )
    {
        cerr    << "++++++++++++++++++++++++++++++++ STATUS +++++++++++++++++++++++++++++++++++++++++\n"
                << "Error Opening File: " + filename << endl;
    }
    else
    {
        cout    << "++++++++++++++++++++++++++++++++ STATUS +++++++++++++++++++++++++++++++++++++++++\n"
                << "Opening File: " + filename << endl;
        while( input.peek() != EOF )
        {
            input >> file_path;
            csvFilePath.InsertLast( file_path );
        }
    }
    input.close();
}

void Processor::LoadCSVData( Vector<string> &csvFilePath, MapAov &mapAov )
{
    for( unsigned i(0); i<csvFilePath.GetUsed(); i++ )
    {
        string modifiedFilePath = "data/" + csvFilePath[i];
        ifstream CSVFile( modifiedFilePath );
        if( !CSVFile )
        {
            cerr << "Error Opening CSV File Path: " << modifiedFilePath << endl;
        }
        else
        {
            cout << "Opening CSV File Path: " << modifiedFilePath << endl;
        }

        string line;
        SensorRecType sensorRecType;
        getline( CSVFile, line );
        while( CSVFile.peek() != EOF )
        {
            CSVFile >> sensorRecType;
            m_dataRead ++;

            mapAov.InsertSensorData( sensorRecType );
            m_dataInserted ++;
        }
        CSVFile.close();
    }
    LoadDisplayCount();
}

void Processor::OutputStreamMeasurement(
    SensorRecType &sensorRecType,
    const string &output_filePath,
    unsigned &month,
    float &speedMean,
    float &speedSsd,
    float &tempMean,
    float &tempSsd,
    float &srSum )
{
    ofstream outputFile( output_filePath );

    if( !outputFile )
    {
        cerr << "[ ERROR ] Opening File: " << output_filePath << endl;
    }
    outputFile << "Month,Average Wind Speed(stdev),Average Ambient Temperature(stdev),Solar Radiation" << endl;

    outputFile << sensorRecType.GetSensorDate().GetMonthInStr(month) << ","
               << speedMean << "(" << speedSsd << "),"
               << tempMean << "(" << tempSsd << "),"
               << srSum / 60000 << endl;

    outputFile.close();
}

