
#include "Menu.h"

Menu::Menu()
{
    m_userYear = 0;
    m_userMonth = 0;
}

void Menu::Clear( unsigned &month, unsigned &year )
{
    month = 0;
    year = 0;
}

unsigned Menu::MonthValidation( string &month )
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

unsigned Menu::YearValidation( string &year )
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

bool Menu::IsMonthInputValid() const
{
    return ( m_userMonth <= 0 || m_userMonth > 12 );
}

bool Menu::IsYearInputValid() const
{
    return ( m_userYear <= 2010 || m_userYear > 2030 );
}
