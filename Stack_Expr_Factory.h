//Daniel Kobold
//CSCI363 PA3
//Stack_Expr_Factory.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_STACK_EXPR_FACT_H_
#define _CS363_STACK_EXPR_FACT_H_

#include "Expr_Command_Factory.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"
#include "Num_Command.h"
#include "Parentheses_Command.h"

class Stack_Expr_Factory : public Expr_Command_Factory
{
public:
	//Constructor
	Stack_Expr_Factory(Stack<int> & stack);
	
	//Virtual functions for creating commands
	virtual Num_Command * create_number_command (int num);
	virtual Add_Command * create_add_command (void);
	virtual Subtract_Command * create_subtract_command (void);
	virtual Multiply_Command * create_multiply_command (void);
	virtual Divide_Command * create_divide_command (void);
	virtual Modulo_Command * create_modulo_command (void);
	virtual Parentheses_Command * create_parentheses_command (int num);
	
private:
	//Stack of integers for use in computation
	Stack<int> & stack_;
};

#include "Stack_Expr_Factory.cpp"

#endif	// !defined _CS363_STACK_EXPR_FACT_H_