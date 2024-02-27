/**
* @file InputValidator.h
* @brief InputValidator class definition.
*
* This file contains the definition of the InputValidator class.
* The class allows validating user year and month inputs.
*
* @author Chan Kok Wai ( Student Number: 33924804 )
* @version 1.0
*/
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

    /**
     * @brief Default constructor for the InputValidator class.
     *
     * This constructor initializes the member variables m_userYear and m_userMonth to zero,
     * providing a default starting point for these variables.
     *
     * @remarks This constructor is called when an instance of the InputValidator class is created,
     * ensuring that the member variables are properly initialized.
     */
    InputValidator();

    /**
     * @brief Validates user input for month.
     *
     * This function repeatedly prompts the user to enter a month value until a valid input is provided.
     * It displays a message indicating the acceptable range of months and requests input from the user.
     * If the input is invalid (non-numeric or out of range), an error message is shown, and the user is prompted again.
     *
     * @param month A reference to a string variable where the user input for month will be stored.
     * @return The validated user input for month.
     */
    unsigned MonthValidation( string &month );

    /**
     * @brief Validates user input for year.
     *
     * This function repeatedly prompts the user to enter a year value until a valid input is provided.
     * It displays a message indicating the acceptable range of year and requests input from the user.
     * If the input is invalid (non-numeric or out of range), an error message is shown, and the user is prompted again.
     *
     * @param year A reference to a string variable where the user input for year will be stored.
     * @return The validated user input for year.
     */
    unsigned YearValidation( string &year );

private:
    unsigned m_userYear;         ///< Holds the user input for year.
    unsigned m_userMonth;       ///< Holds the user input for year.

    /**
     * @brief Checks if the user input for month is valid.
     *
     * This function verifies whether the user-provided month value is within the acceptable range (1 to 12).
     *
     * @return True if the input is invalid (outside the range of 1 to 12), false otherwise.
     */
    bool IsMonthInputValid() const;

    /**
     * @brief Checks if the user input for year is valid.
     *
     * This function verifies whether the user-provided year value is within the acceptable range (2010 to 2030).
     *
     * @return True if the input is invalid (outside the range of 2010 to 2030), false otherwise.
     */
    bool IsYearInputValid() const;
};

#endif // INPUTVALIDATOR_H_INCLUDED
