//Daniel Kobold
//CSCI363 PA3
//Binary_Op_Command.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_BINARY_COMMAND_H_
#define _CS363_BINARY_COMMAND_H_

#include "Expr_Command.h"

class Binary_Op_Command : public Expr_Command 
{
public:
	//Constructor
	Binary_Op_Command(Stack<int> & s);

	//Execute - pops numbers off stack, calls evaluate, stores result
	//			on stack
	bool execute (void);
	
	//Evaluate - implemented in command classes
	virtual int evaluate (int,int) = 0;
	
	//Get precedence level
	virtual int getPrecedence (void) = 0;
	
private:
	//Stack<int> &  s_;
};

#include "Binary_Op_Command.cpp"

#endif	// !defined _CS363_BINARY_COMMAND_H_