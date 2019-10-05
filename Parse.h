//Daniel Kobold
//CSCI363 PA3
//Parse.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_PARSE_H_
#define _CS363_PARSE_H_

#include <sstream>
#include "Stack.h"
#include "Array.h"
#include "Expr_Command_Iterator.h"
#include "Expr_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Num_Command.h"
#include "Stack_Expr_Factory.h"

// COMMENT A better name for this class is Calculator.
class Parse
{
public:
	//Convert infix expression string to postfix expression of command objects
	bool infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix);
	
	//Evaluate the postfix expression of commands
	bool evaluate_postfix (Expr_Command_Iterator & iter);
	
	//Find precedence of top element on operator stack
	int top_prec (Stack<char> & topPrecS);
	
	//Find the number of elements to be made in the postfix expression based on the infix string
	size_t findSize (const std::string & infix);
	
private:

};

#include "Parse.cpp"

#endif	// !defined _CS363_PARSE_H_
