//Daniel Kobold
//CSCI363 PA3
//Num_Command.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Num_Command::Num_Command (Stack<int> & s, int n)
	:Expr_Command(s,n)
{
	//Does nothing else
}
		
bool Num_Command::execute (void) 
{
	//Push the number onto number stack
	s_.push (this->n_);		
	
	//Return true
	return true;			
}

int Num_Command::getPrecedence(void)
{
	return 1;
}
