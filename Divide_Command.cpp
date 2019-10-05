//Daniel Kobold
//CSCI363 PA3
//Divide_Command.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Divide_Command::Divide_Command (Stack<int> & s)
	:Binary_Op_Command(s)
{
	//Does nothing else
}

int Divide_Command::evaluate (int n1, int n2)
{
  // COMMENT: You are not handling divide by zero.
  // RESPONSE: Added an include statement for exception
  // allowing an error to be thrown if n2 equals 0
  
	std::string divByZero = "Dividing by zero causes undefined behavior.";
  
	//If the number is not being divided by zero, complete the division
	//Otherwise, throw the exception
	if(n2 == 0)
	{
		throw divByZero;
	}	
	else
	{
		return n1 / n2;	
	}
}

int Divide_Command::getPrecedence(void)
{
	return 3;
}
