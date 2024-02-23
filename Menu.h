#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include<iostream>
#include "Constant.h"

using namespace std;

class Menu
{
public:
    Menu();

    void Clear( unsigned &month, unsigned &year );
    unsigned MonthValidation( string &month );
    unsigned YearValidation( string &year );

private:
    unsigned m_userYear;
    unsigned m_userMonth;

    bool IsMonthInputValid() const;
    bool IsYearInputValid() const;
};

#endif // MENU_H_INCLUDED
