//Daniel Kobold
//CSCI363 PA3
//Parentheses_Command.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_PARENTHESES_COMMAND_H_
#define _CS363_PARENTHESES_COMMAND_H_

#include "Expr_Command.h"

class Parentheses_Command: public Expr_Command
{
public:
	//Constructor - doesn't do anything
	Parentheses_Command (Stack<int> & s, int n);
	
	//Doesn't do anything, just returns true
	bool execute (void);
	
	//Get precedence level
	int getPrecedence (void);
};

#include "Parentheses_Command.cpp"

#endif	// !defined _CS363_PARENTHESES_COMMAND_H_

