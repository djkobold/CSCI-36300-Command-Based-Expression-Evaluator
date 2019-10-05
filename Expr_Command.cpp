//Daniel Kobold
//CSCI363 PA3
//Expr_Command.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Expr_Command::Expr_Command(Stack<int> & s, int n)
	:s_(s), n_(n)
{
	//Does nothing else
}

Expr_Command::Expr_Command(Stack<int> & s)
	:s_(s), n_(-1)
{
	//Does nothing else
}

Expr_Command::~Expr_Command(void)
{
	//Does nothing
}

//Returns true if this command is a left parentheses command
//based on n_
bool Expr_Command::isLeftPar(void)
{
	return (not n_);
}

