//Daniel Kobold
//CSCI363 PA3
//Multiply_Command.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_MULTIPLY_COMMAND_H_
#define _CS363_MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

class Multiply_Command : public Binary_Op_Command
{
public:
	//Constructor - doesn't do anything
	Multiply_Command (Stack<int> & s);
	
	//Evaluate - returns (n1 * n2)
	int evaluate (int n1, int n2);
	
	//Get precedence level
	int getPrecedence (void);
};

#include "Multiply_Command.cpp"

#endif	// !defined _CS363_MULTIPLY_COMMAND_H_