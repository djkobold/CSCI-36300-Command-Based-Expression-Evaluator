//Daniel Kobold
//CSCI363 PA3
//Num_Command.h

#ifndef _CS363_NUM_COMMAND_H_
#define _CS363_NUM_COMMAND_H_

#include "Expr_Command.h"

class Num_Command : public Expr_Command
{
public:
	//Constructor
	Num_Command (Stack<int> & s, int n);
		
	//Execute
	bool execute (void);
	
	//Get precedence level
	int getPrecedence (void);
	
};

#include "Num_Command.cpp"

#endif	// !defined _CS363_NUM_COMMAND_H_