//Daniel Kobold
//CSCI363 PA3
//Binary_Op_Command.h

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Binary_Op_Command::Binary_Op_Command(Stack<int> & s)
	:Expr_Command(s)
{
	//Does nothing else
}

bool Binary_Op_Command::execute(void)
{
	//Access top element
	int n2 = s_.top();			

	//Pop element off stack
	s_.pop();					

	//Access top element
	int n1 = s_.top();		

	//Pop element off stack
	s_.pop();								
	
	//Call evaluate for this command
	int result = this->evaluate(n1,n2);	

	//Push result onto stack
	s_.push(result);		
	
	return true;
}