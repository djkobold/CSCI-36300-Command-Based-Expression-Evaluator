//Daniel Kobold
//CSCI363 PA3
//Subtract_Command.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Subtract_Command::Subtract_Command (Stack<int> & s)
	:Binary_Op_Command(s)
{
	//Does nothing else
}

int Subtract_Command::evaluate (int n1, int n2)
{
	return n1 - n2;
}

int Subtract_Command::getPrecedence(void)
{
	return 2;
}

