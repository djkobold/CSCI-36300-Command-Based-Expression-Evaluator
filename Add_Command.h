//Daniel Kobold
//CSCI363 PA3
//Add_Command.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_ADD_COMMAND_H_
#define _CS363_ADD_COMMAND_H_

#include "Binary_Op_Command.h"

class Add_Command : public Binary_Op_Command
{
public:
	//Constructor - calls Binary_Op_Command constructor
	Add_Command (Stack<int> & s);
	
	//Execute - completes addition
	int evaluate (int n1, int n2);
	
	//Get precedence level
	int getPrecedence (void);
};

#include "Add_Command.cpp"

#endif	// !defined _CS363_ADD_COMMAND_H_