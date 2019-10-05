//Daniel Kobold
//CSCI363 PA3
//Divide_Command.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_DIVIDE_COMMAND_H_
#define _CS363_DIVIDE_COMMAND_H_

#include <exception>
#include <string>
#include "Binary_Op_Command.h"

class Divide_Command : public Binary_Op_Command
{
public:
	//Constructor
	Divide_Command (Stack<int> & s);
	
	//Execute
	int evaluate (int n1, int n2);	
	
	//Get precedence level
	int getPrecedence (void);
};

#include "Divide_Command.cpp"

#endif	// !defined _CS363_DIVIDE_COMMAND_H_