//Daniel Kobold
//CSCI363 PA3
//Multiply_Command.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Multiply_Command::Multiply_Command (Stack<int> & s) 
	:Binary_Op_Command(s)
{
	//Does nothing else
}

int Multiply_Command::evaluate (int n1, int n2)
{
	return n1 * n2;		//Return product
}

int Multiply_Command::getPrecedence(void)
{
	return 3;
}
