//Daniel Kobold
//CSCI363 PA3
//Subtract_Command.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Modulo_Command::Modulo_Command (Stack<int> & s)
	:Binary_Op_Command(s)
{
	//Does nothing else
}

int Modulo_Command::evaluate (int n1, int n2)
{
	std::string modByZero = "Dividing by zero causes undefined behavior.";
  
	//If the number is not being divided by zero, complete the division
	//Otherwise, throw the exception
	if(n2 == 0)
	{
		throw modByZero;
	}	
	else
	{
		return n1 % n2;	
	}
	
}

int Modulo_Command::getPrecedence(void)
{
	return 3;
}
