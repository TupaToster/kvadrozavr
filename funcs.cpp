/*!
	\file
	\brief Contains all functions' bodies

	A .cpp file that contains bodies of all functions declared in "prototypes.h"
*/

#include "prototypes.h"

bool comp_doubles (const double a, const double b) {

    return fabs (a-b) < EPS;
}

//---------------------------------------------------------------------------------

// bug somewhere here!!!!!!!!!!!
enum input_type input (double* const a, double* const b, double* const c) {

    for(;;) {

		assert (a != NULL);
		assert (b != NULL);
		assert (c != NULL);
		assert (a != b);
		assert (b != c);
		assert (c != a);

        printf ("Please insert coefs of quadratic equation\n"
				"a, b and c :");

		char in[MAX_LEN] = "";

		if (fgets (in, MAX_LEN, stdin) == NULL) {

			printf ("Empty input got. Reenter it u must \n");

			continue;
		}

		char terminator = '\0';
		sscanf(in, "%c", terminator);

		if (terminator == 'q' || terminator == 'Q') return STOP_COMMAND;

  	    int amount_of_chars = 0;
	    sscanf (in, "%lf %lf %lf %n", a, b, c, &amount_of_chars);

	    if (strlen (in) == (unsigned int) amount_of_chars) break;

    	printf ("One or more coefs are not numbers or there is some rng stuff in the input line \n");
    }
    return OK;
}

//---------------------------------------------------------------------------------

enum roots_amount solve_equation (const double a, const double b, const double c,
								  double* const x1, double* const x2) {

    if (comp_doubles (a, 0)) return solve_linear_case (   b, c, x1    );
    else    	             return solve_square_case (a, b, c, x1, x2);
}

enum roots_amount solve_linear_case (const double b, const double c, double* const x1) {


    if (comp_doubles (b, 0) &&  comp_doubles (c, 0)) return INF_ROOTS;

    if (comp_doubles (b, 0) && !comp_doubles (c, 0)) return ZERO_ROOTS;

	assert (x1 != NULL);

	*x1 = -c / b;

	if (comp_doubles (*x1, -0)) *x1 = 0;

    return ONE_ROOTS;
}

enum roots_amount solve_square_case(const double a, const double b, const double c,
								    double* const x1, double* const x2) {

    double D = b * b - 4 * a * c;

    if (D < 0) return ZERO_ROOTS;

    if (comp_doubles (D, 0)) {

		assert (x1 != NULL);

		*x1 = -b / (2 * a);

		if (comp_doubles (*x1, -0)) *x1 = 0;

	    return ONE_ROOTS;
    }

	assert (x1 != NULL && "X1 is NULL");
	assert (x2 != NULL);

	D = sqrt(D);
	*x1 = ( -b - D ) / (2 * a);
    *x2 = ( -b + D ) / (2 * a);

	if (comp_doubles (*x1, -0)) *x1 = 0;
	if (comp_doubles (*x2, -0)) *x2 = 0;

    return TWO_ROOTS;

}

void output (enum roots_amount root_am, double* const x1, double* const x2) {

    switch (root_am) {

        case  INF_ROOTS:

            printf ("There is an infinite number of roots");
       	    break;

    	case ZERO_ROOTS:

            printf ("There is zero roots");
       	    break;

    	case  ONE_ROOTS:

            printf ("There is one root: %lf", *x1);
            break;

        case  TWO_ROOTS:

            printf ("There are two roots: %lf and %lf", *x1, *x2);
            break;

        default:

            printf ("If u see this, there is an unexplainable error with root_am of %d", root_am);

    }
	printf ("\n");
}


void unit_test () {

    double tx1 = 0, tx2 = 0;

    ASRT (comp_doubles (1e5 + 1e-8, 1e5       ) == true );
    ASRT (comp_doubles (1e5 + 1e-7, 1e5 - 1e-7) == false);

    ASRT (solve_linear_case (0, 0, &tx1) == INF_ROOTS                   		  );
    ASRT (solve_linear_case (0, 1, &tx1) == ZERO_ROOTS                  		  );
    ASRT (solve_linear_case (1, 1, &tx1) == ONE_ROOTS and comp_doubles (tx1, -1));

    ASRT (solve_square_case ( 1,  0,  0,  &tx1, &tx2) == ONE_ROOTS and comp_doubles (tx1, 0));

    ASRT (solve_square_case ( 1, -7, 10,  &tx1, &tx2) == TWO_ROOTS and comp_doubles (tx1, 2)
															 and comp_doubles (tx2, 5));

	ASRT (solve_square_case (10,  1, 10,  &tx1, &tx2) == ZERO_ROOTS);

    ASRT (solve_equation ( 0, 0,  1, &tx1, &tx2) == solve_linear_case (    0,  1, &tx1      ));
    ASRT (solve_equation (10, 1, 10, &tx1, &tx2) == solve_square_case (10, 1, 10, &tx1, &tx2));
}