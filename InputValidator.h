#ifndef INPUTVALIDATOR_H_INCLUDED
#define INPUTVALIDATOR_H_INCLUDED

#include<iostream>
#include "Constant.h"

using namespace std;

/**
 * @brief Class for user input validation related to month and year.
 *
 * This class provides methods to validate user input for month and year
 * to ensure they are within valid ranges and formats.
 */
class InputValidator
{
public:
    InputValidator();

    unsigned MonthValidation( string &month );
    unsigned YearValidation( string &year );

private:
    unsigned m_userYear;
    unsigned m_userMonth;

    bool IsMonthInputValid() const;
    bool IsYearInputValid() const;
};

#endif // INPUTVALIDATOR_H_INCLUDED
