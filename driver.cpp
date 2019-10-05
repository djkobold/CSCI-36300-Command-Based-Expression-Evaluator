#include "Stack.h"
#include "Calculator.h"
#include "Add_Command.h"
#include "Num_Command.h"
#include "Array.h"
#include "Expr_Command.h"
#include "Subtract_Command.h"
#include "Expr_Command_Iterator.h"
#include <iostream>
#include <string>
#include <sstream>

int main (int argc, char * argv[])
{	
    // COMMENT A better design would be to use a Calculator wrapper facade
    // to house the C functions instead of an object named Parse.
    // RESPONSE	Program now uses wrapper facade, and simply has to call
	// calculator's calculate function to run program in driver
	
	//Calculator wrapper-facade
	Calculator calc;
	
	//Call calculate to run calculation process
	calc.calculate();								


	return 0;
}
