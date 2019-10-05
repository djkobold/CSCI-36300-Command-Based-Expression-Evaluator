//Daniel Kobold
//CSCI363 PA3
//Expr_Command.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_EXPR_COMMAND_H_
#define _CS363_EXPR_COMMAND_H_

#include "Stack.h"

class Expr_Command 
{
public:
	//Constructor for number commands
	Expr_Command(Stack<int> & s, int n);
	
	//Constructor for all other commands
	Expr_Command(Stack<int> & s);
	
	//Destructor
	~Expr_Command(void);
	
	//Execute - virtual so it can be handled based on specific command type
	virtual bool execute (void) = 0;

	//Return precedence level
	virtual int getPrecedence (void) = 0;
	
	//Return true if this is a left parentheses
	bool isLeftPar (void);
	
protected:
	//Stack of integers for use in execution
	Stack<int> & s_;
	
	//Integer for if this instance is a number command
	//or 0 or 1 if this is a parentheses command
	int n_;	
	
};

#include "Expr_Command.cpp"

#endif	// !defined _CS363_EXPR_COMMAND_H_