//Daniel Kobold
//CSCI363 PA3
//Modulo_Command.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_MODULO_COMMAND_H_
#define _CS363_MODULO_COMMAND_H_

#include <string>
#include "Binary_Op_Command.h"

class Modulo_Command : public Binary_Op_Command
{
public:
	//Constructor - doesn't do anything
	Modulo_Command (Stack<int> & s);
	
	//Evaluate - returns (n1 - n2)
	int evaluate (int n1, int n2);	
	
	//Get precedence level
	int getPrecedence (void);
};

#include "Modulo_Command.cpp"

#endif	// !defined _CS363_MODULO_COMMAND_H_