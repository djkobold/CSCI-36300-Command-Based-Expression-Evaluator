//Daniel Kobold
//CSCI363 PA3
//Parentheses_Command.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Parentheses_Command::Parentheses_Command (Stack<int> & s, int n)
	:Expr_Command(s, n)	
{
	//Does nothing else
}

bool Parentheses_Command::execute (void) 
{
	return true;
}

int Parentheses_Command::getPrecedence(void)
{
	return -1;
}

