//Daniel Kobold
//CSCI363 PA3
//Expr_Command_Iterator.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Expr_Command_Iterator::Expr_Command_Iterator(Array<Expr_Command*> & iter)
	:iter_(iter), current(0)
{
	//Does nothing else
}

bool Expr_Command_Iterator::is_done(void)
{
	//Check if done by checking the sizes of the command array
	return (this->current >= this->iter_.size());		
}

bool Expr_Command_Iterator::advance(void)
{
	//Pointer to object that needs to be deleted
	Expr_Command * old = iter_.data_[this->current]; 
	
	//Increment location
	++this->current;	

	//Delete previous command object
	delete old;		

	return true;
}

Expr_Command & Expr_Command_Iterator::operator * (void)
{
	//Return pointer
	return *this->iter_.data_[this->current];			
}

Expr_Command * Expr_Command_Iterator::operator -> (void)
{
	//Return object
	return this->iter_.data_[this->current];			
}

bool Expr_Command_Iterator::execute(void)
{
	//Holds command to be executed
	Expr_Command * exCommand_;					

	//Finds the correct command object
	exCommand_ = iter_.data_[this->current];		

	//Executes that command
	exCommand_->execute();								
	return true;
}

//Delete the remaining commands through the iterator
bool Expr_Command_Iterator::deleteRest (void)
{
	//while(!this->is_done())
	{
		//Pointer to object that needs to be deleted
		Expr_Command * old = iter_.data_[this->current]; 
	
		//Increment location
		++this->current;	

		//Delete previous command object
		delete old;	
	}
	
	return true;
}

