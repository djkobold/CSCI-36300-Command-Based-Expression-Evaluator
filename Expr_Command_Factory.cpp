//Daniel Kobold
//CSCI363 PA3
//Expr_Command_Factory.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


Expr_Command_Factory::Expr_Command_Factory(void)
{
	//Does nothing
}

Expr_Command_Factory::~Expr_Command_Factory (void)
{
	//Private items don't need deleted, they are on the stack
}

Expr_Command_Factory::Expr_Command_Factory (const Expr_Command_Factory &)
{
	//Does nothing, this is here to prevent use
}

const Expr_Command_Factory & Expr_Command_Factory::operator = (const Expr_Command_Factory & factory)
{
	//Does nothing, this is here to prevent use
}
