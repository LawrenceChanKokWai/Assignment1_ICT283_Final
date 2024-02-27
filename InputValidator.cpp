/**
* @file InputValidator.cpp
* @brief InputValidator class implementation file
*
* This file contains the InputValidator class implementation.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
#include "InputValidator.h"

InputValidator::InputValidator()
{
    m_userYear = 0;
    m_userMonth = 0;
}

unsigned InputValidator::MonthValidation( string &month )
{
    do
    {
        cout << Constant::INFO(Constant::MONTH_RANGE_MSG) << '\n'
             << Constant::SELECTION_INPUT;
        cin >> month;
        try
        {
            m_userMonth = stoi( month );
        }
        catch (...)
        {
            cout << Constant::STATUS(!IsMonthInputValid(), Constant::INVALID_NUMERIC_ENTRY_MSG) << '\n';
        }
    }
    while (IsMonthInputValid());   // Continue looping until the input is valid
    return m_userMonth;
}

unsigned InputValidator::YearValidation( string &year )
{
    do
    {
        cout << Constant::INFO(Constant::YEAR_RANGE_MSG) << '\n'
             << Constant::SELECTION_INPUT;
        cin >> year;
        try
        {
            m_userYear = stoi( year );
        }
        catch (...)
        {
            cout << Constant::STATUS(!IsYearInputValid(), Constant::INVALID_NUMERIC_ENTRY_MSG) << '\n';
        }
    }
    while (IsYearInputValid());   // Continue looping until the input is valid
    return m_userYear;
}

bool InputValidator::IsMonthInputValid() const
{
    return ( m_userMonth <= 0 || m_userMonth > 12 );
}

bool InputValidator::IsYearInputValid() const
{
    return ( m_userYear <= 2010 || m_userYear > 2030 );
}
