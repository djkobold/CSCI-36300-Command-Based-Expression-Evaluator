//Daniel Kobold
//CSCI363 PA3
//Expr_Command_Iterator.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS363_EXPR_IT_H_
#define _CS363_EXPR_IT_H_

#include "Expr_Command.h"

class Expr_Command_Iterator
{
public:
	//Constructor
	Expr_Command_Iterator(Array<Expr_Command*> & iter);
	
	//Checks if iterator has reached end of array of commands
	bool is_done(void);
	
	//Advance the array to the next element and delete previous element
	bool advance(void);
	
	//Return address of Expr_Command object
	Expr_Command & operator * (void);
	
	//Return pointer to Expr_Command object
	Expr_Command * operator -> (void);

	//Call the command's execute method
	bool execute (void);
	
	//Delete the rest of the commands (means an error occurred)
	bool deleteRest (void);
	
private:
	//Array of commands to be iterated through	
	Array<Expr_Command *> & iter_;		
	
	//Current location
	size_t current;					
};

#include "Expr_Command_Iterator.cpp"

#endif	// !defined _CS363_EXPR_IT_H_