//Daniel Kobold
//CSCI363 PA3
//Add_Command.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Add_Command::Add_Command (Stack<int> & s)
	:Binary_Op_Command(s)
{
	//Does nothing else
}

int Add_Command::evaluate (int n1, int n2)
{
	return n1 + n2;
}

int Add_Command::getPrecedence(void)
{
	return 2;
}
