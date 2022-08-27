/*!
	\mainpage
	
	This project uses extensive mathematic knowledge and advanced programming 
	techniques to solve the world's biggest problem of all time: helping seven's grade students to solve
	linear and quadratic equations.
	
	This project may look extremely complex, but it actually is.
	So, to help our fellow 7 graders understand all depths of
	programming, linear algebra and quantum mechanics this 
	documentation was created.
	
*/


/*!
	\file
	\brief A main file
	
	A main.cpp file that contains body of a main function and variables 
	needed for solving the equation
*/

#include "prototypes.h"

/*!
    \brief A main function of program
    \var a - first coef of a quadratic equation
    \var b - second coef of a quadratic equation
    \var c - third coef of a quadratic equation
    \var x1 - first root
    \var x2 - second root
	\var argc - integer, that shows the amount of command line arguments
	\var argv[] - vector of strings that contains the arguments
*/
int main (int argc, char* argv[]) {

    if (argc > 1 and strcmp ("-t", argv[1]) == 0) {
        unit_test ();
        return 0;
    }

	printf("To terminate the program type in 'q' or 'Q' instead of the first coeffitient of the equation \n"); 

    for(;;){
    	double a  = 0,
			   b  = 0,
               c  = 0,
               x1 = 0,
               x2 = 0;
		
		if(input (&a, &b, &c) == STOP_COMMAND) return 0;

	    output (solve_equation (a, b, c, &x1, &x2), &x1, &x2);
	}
}





