//Daniel Kobold
//CSCI363 PA3
//Calculator.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_CALC_H_
#define _CS363_CALC_H_

#include <sstream>
#include <string>
#include <iostream>
#include <exception>
#include "Stack.h"
#include "Array.h"
#include "Expr_Command_Iterator.h"
#include "Expr_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Num_Command.h"
#include "Parentheses_Command.h"
#include "Stack_Expr_Factory.h"

// COMMENT A better name for this class is Calculator.
// RESPONSE Parse has now been renamed Calculator in all files.
// This includes the .mpc, the driver, and in all include statements.
class Calculator
{
public:
	//Constructor - needs the infix expression string
	Calculator (void);

	//Convert infix expression string to postfix expression of command objects
	bool infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix);
	
	//Evaluate the postfix expression of commands
	bool evaluate_postfix (Expr_Command_Iterator & iter);
	
	//Find the number of elements to be made in the postfix expression based on the infix string
	size_t findSize (const std::string & infix);
	
	//Calculate calls the above functions to "run" the calculator until QUIT is read
	void calculate (void);

};

#include "Calculator.cpp"

#endif	// !defined _CS363_CALC_H_
