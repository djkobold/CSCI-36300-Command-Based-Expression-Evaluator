//Daniel Kobold
//CSCI363 PA3
//Expr_Command_Factory.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_EXPR_COMM_FACT_H_
#define _CS363_EXPR_COMM_FACT_H_

#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Parentheses_Command.h"
#include "Modulo_Command.h"
#include "Num_Command.h"

class Expr_Command_Factory
{
public:
	//Constructor - doesn't do anything
	Expr_Command_Factory(void);

	//Pure virtual destructor - implemented elsewhere
	virtual ~Expr_Command_Factory (void) = 0;
	
	//Pure virtual create commands, implemented in "Stack_Expr_Factory"
	virtual Num_Command * create_number_command (int num) = 0;
	virtual Add_Command * create_add_command (void) = 0;
	virtual Subtract_Command * create_subtract_command (void) = 0;
	virtual Multiply_Command * create_multiply_command (void) = 0;
	virtual Divide_Command * create_divide_command (void) = 0;
	virtual Modulo_Command * create_modulo_command (void) = 0;
	virtual Parentheses_Command * create_parentheses_command (int lOrR) = 0;
private:
	//prevent the following operations
	Expr_Command_Factory (const Expr_Command_Factory &);
	const Expr_Command_Factory & operator = (const Expr_Command_Factory & factory);

};

#include "Expr_Command_Factory.cpp"

#endif	// !defined _CS363_EXPR_COMM_FACT_H_