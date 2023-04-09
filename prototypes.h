//da blya za chto


/*!
    \file
    \brief A header with all funcs prototypes and constants

    This thing contains all functions' prototypes and constants needed for work of a program
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

/*!
    \brief A constant that specifies what a really smol number is
*/
#define EPS 1e-7


/*!
	\brief A constant that specifies max length of an input string
*/
#define MAX_LEN 1000


/*!
    \brief Asserts the condition but does not abort whole program
	\param cnd - an expression with a bool return type

	This function is used to let user now if a bool type expression
	has a different value than expected
*/
#define ASRT(cnd) if(!(cnd)) printf("\n"					 \
									"Assertion failed: %s\n"\
									"in file %s\n"			 \
                					"function %s\n"			 \
                					"line %d\n",		     \
    				  #cnd, __FILE__, __PRETTY_FUNCTION__, __LINE__);


/*!
    \brief Constants that specify amounts of roots
	\var  case with infinite roots
	\var ZERO_ROOTS - case with zero roots
	\var ONE_ROOTS - case with one root(s)
	\var TWO _ROOTS - case with two roots

	This set of constants is used to tell the output function how many roots it has to print.
	Also used in solve_equation, solve_square_case and solve_linear_case as a return value
	with the same purposes.
*/
enum roots_amount {
	INF_ROOTS  = -1, ///< Indicates that infinite roots exist
	ZERO_ROOTS = 0,  ///< Indicates that zero roots exist
	ONE_ROOTS  = 1,  ///< Indicates that one root exists
	TWO_ROOTS  = 2   ///< Indicates that two roots exist
};


/*!
  	\brief Constants to specify type of input
*/
enum input_type {
	OK           = 1, ///< Indicates that input format is ok
	STOP_COMMAND = 0  ///< Indicates that user wishes to exit
};


/*!
    \brief Compares two double variables
    \param a, b - two numbers for comparison
    \return true - if |a - b| is less then EPS
	\return false - if |a - b| is more then EPS

    This function is used to compare two double type variables with a precision of EPS
*/
bool comp_doubles (double a, double b);


/*!
	\brief Chooses a method of solution
    \param a, b, c - coefficients of a quadratic equation of type: a * x^2 + b * x + c = 0
    \param x1, x2 - pointers to variables that will contain found roots
    \return roots_amount type constant that specifies amount of roots found

    This function is used to choose a calculation method depending on "a" parameter.
    If "a" is equal to 0 than equation is linear and solvelin function is used
    In other cases a solvesq function is used
*/
enum roots_amount solve_equation (double a, double b, double c, double* x1, double* x2);


/*!
    \brief Solves a quadratic equation
    \param a, b, c - coefficients of a quadratic equation of type: a * x^2 + b * x + c = 0
    \param x1, x2  - pointers to variables that will contain found roots
    \return roots_amount type constant that specifies amount of roots found
    \exception This function does not operate with "a" equal to zero
	\exception (this issue is solved in solve_equation function)

    This function is used to find all real roots of a quadratic equation
    and specify the amount of roots found
*/
enum roots_amount solve_square_case (double a, double b, double c, double* x1, double* x2);

/*!
    \brief Solves a linear equation
    \param b, c - coefficients of a linear function of type: b * x + c = 0
    \param x1   - pointer to a variable that will contain a found root
    \return roots_amount type constant that specifies amount of roots found

    This function is used to find all real roots of a linear equation
    and specify the amount of roots found
*/
enum roots_amount solve_linear_case (double b, double c, double* x1);

/*!
    \brief Takes input from user
    \param a, b, c - pointers to variables that will contain coefficients of an equation of type: a * x^2 + b * x + c = 0
    \return Returns an input_type enumerator to show wether the user wishes to stop the program, or continue calculations

    This function is used to take input of coefficients of an equation.
*/
enum input_type input (double* a, double* b, double* c);

/*!
    \brief Creates output
    \param root_am - a roots_amount that specifies an amount of roots
    \param x1, x2 pointers to roots that have been found


    This function is used to generate output based on amount of roots
	(specified by root_am) and to print it
*/
void output (enum roots_amount root_am, double* x1, double* x2);

/*!
    \brief Tests correctness of work of key functions

    This function is used to detect mistakes in functions solve_equation,
	solve_linear_case, solve_square_case and comp_doubles
*/
void unit_test ();















