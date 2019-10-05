//Daniel Kobold
//CSCI363 PA3
//Calculator.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


Calculator::Calculator(void)
{
	//Doesn't do anything
}

bool Calculator::infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix)
{
	//Error message for invalid arguments
	std::string invalidArgs = "Invalid argument was entered.";
	
	//Error message for out-of-range argument(s)
	std::string invalidNums = "Out of Range number was entered.";
	
	//Create an input stream parser
	std::istringstream input(infix);	
	
	//The current token in string/stream
	std::string token (" ");					
	
	//The created command object
	Expr_Command * cmd = 0;				
	
	//Variable for transferring into postfix array (when popping elements off stack)
	Expr_Command * trans = 0;		

	//Temporary command stack for order of operations
	Stack <Expr_Command *> temp;;

	//Precedence of top element on stack
	int topPrec = 0;					
	
	//Precedence of element on stack
	int prec = 0;					

	//Index into postfix array
	int index = 0;				

	//Number of elements in infix expression (not including parentheses)
	int length = 0;						
	
	//Determines number of elements in infix expression (not including parentheses)
	length = findSize(infix);				
	
	//Precedence Levels:
	//5: Parentheses
	//4: Powers, Roots (Add later)
	//3: "*", "/"
	//2: "+", "-"
	//1: Numbers
	//0: " "
	
	//While not at the end of input
	while(!input.eof() && index < length)					
	{
    // COMMENT: You should implement the precedence function on
    // the command object since it is better place there.
	// RESPONSE: Precedence is now a part of the expression itself,
	// in the form of a virtual getPrecedence() function in Expr_Command.
	// Instead of using string comparison to find the level of precedence,
	// each command has its own getPrecedence() function that returns the
	// correct level of precedence.
		
		//Reset precedence value
		prec = 0;

		//Move input to token
		input >> token;					
		
		//ADD
		if(token == "+")								
		{
			//Create add command
			cmd = factory.create_add_command();			
		}
		//SUBTRACT
		else if(token == "-")							
		{
			//Create subtract command
			cmd = factory.create_subtract_command();	
		}
		//MULTIPLY
		else if(token == "*")							
		{
			//Create multiply command
			cmd = factory.create_multiply_command();	
		}
		//DIVISION
		else if(token == "/")							
		{
			//Create divide command
			cmd = factory.create_divide_command();		
		}
		//MODULO
		else if(token == "%")							
		{
			//Create modulo command
			cmd = factory.create_modulo_command();		
		}
		//PARENTHESES - LEFT
		else if(token == "(")			
		{
			//Create parentheses command and specify that it is a left parentheses
			cmd = factory.create_parentheses_command(0);
		}
		//PARENTHESES - RIGHT
		else if(token == ")")			
		{
			//Create parentheses command and specify that it is a right parentheses
			cmd = factory.create_parentheses_command(1);
		}
		//NUMBER
		else if(token.find_first_not_of("+-0123456789") == std::string::npos) 
		{
			try{
				//Use stoi to change string to integer
				cmd = factory.create_number_command(std::stoi(token));		
			}
			//Catch an out-of-range error
			catch (std::out_of_range & o)
			{				
				//Delete commands in reverse
				while(index > 0)
				{
					delete postfix.get(--index);
				}
				
				//Delete any remaining stack commands
				while(!temp.is_empty())
				{
					trans = temp.top();
					temp.pop();
					delete trans;
				}
				
				throw invalidNums;
			}
			catch (std::exception & e)
			{
				delete cmd;
				
				//Delete commands in reverse
				while(index > 0)
				{
					delete postfix.get(--index);
				}
				
				//Delete any remaining stack commands
				while(!temp.is_empty())
				{
					trans = temp.top();
					temp.pop();
					delete trans;
				}
				
				//Throw the error that occurred (probably stoi error)
				throw e;					
			}
		}
		else
		{
			
			//Delete commands in reverse
			while(index > 0)
			{
				delete postfix.get(--index);
			}
			
			//Delete any remaining stack commands
			while(!temp.is_empty())
			{
				trans = temp.top();
				temp.pop();
				delete trans;
			}
			
			//Throw invalid arguments error
			throw invalidArgs;				
		}
		
		//Get precedence
		prec = cmd->getPrecedence();	
	
		//Number
		if(prec == 1) 	
		{			
			//Store number command in postfix array	
			postfix.set(index, cmd);	
					
			index++;
		}
		//Non-Number
		else					
		{
			//Check for (left) parentheses
			if(token == "(")							
			{
				//Push parentheses command onto stack
				temp.push(cmd);
			}
			//Check for (right) parentheses
			else if(token == ")")						
			{
				trans = cmd;
				delete trans;
				
				//Pop elements off of stack until top is an empty stack or the other parentheses
				while(!temp.is_empty() && !temp.top()->isLeftPar())
				{
					//Load element for "transfer"
					trans = temp.top();				

					//Remove that element from the stack
					temp.pop();								

					//Add object to array since it was in parentheses
					postfix.set(index, trans);		

					index++;
				}
				//Pop the last parentheses if needed
				if(temp.top()->isLeftPar())
				{
					trans = temp.top();
					temp.pop();
					delete trans;
				}
			}
			//Operator
			else										
			{
				//If temp stack is not empty, find the top element's precedence
				if(!temp.is_empty())
				{
					trans = temp.top();
					topPrec = trans->getPrecedence();
				}
				else
				{
					topPrec = 0;
				}
				while(!temp.is_empty() && prec <= topPrec)
				{					
					//Load element for "transfer"
					trans = temp.top();			

					//Remove that element from the stack
					temp.pop();			
					
					//Add object to array
					postfix.set(index, trans);	
					
					index++;
					
					//If operator stack is not empty find top element precedence
					if(!temp.is_empty())				
					{
						trans = temp.top();
						topPrec = trans->getPrecedence();	
					}
					else
					{
						//Reset top element precedence
						topPrec = 0;					
					}
				}
				//Push the corresponding command
				temp.push(cmd);
			}
		}
	}
	
	//Pop elements while elements remain on the stack
	while(!temp.is_empty())		
	{
		
		//Prepare command for transfer
		trans = temp.top();					
		
		if(trans->getPrecedence() != -1)
		{
			//Pop command off stack
			temp.pop();								
			
			//Set postfix array element
			postfix.set(index, trans);	

			//Increment index
			index++;		
		}		
		//This case only happens when there are more left parentheses than right parentheses
		else
		{
			//Pop command off stack
			temp.pop();
			
			//Delete the extra parentheses
			delete trans;
		}
	}
	
	//trans->setCode(3);
	
	return true;										
}

//Evaluate postfix expression through commands
bool Calculator::evaluate_postfix (Expr_Command_Iterator & iter)	
{
	//Loop through each command element
	for(; !iter.is_done(); iter.advance())				
	{
		//Execute command indicated by iterator
		iter->execute();								
	}
	
	return true;
}

  // COMMENT You should find a better way to compare precedence instead
  // of using a string comparision, which is expensive.
  // RESPONSE The comparison of precedence now occurs by calling a (virtual)
  // function in Expr_Command, implemented in the individual command classes.
  // This function returns a precedence level which is compared to the precedence
  // level of the command on top of the command stack.
  
//Find number of elements to be made
size_t Calculator::findSize(const std::string & infix)	
{
	//Start size at 0
	size_t size_ = 0;					

	//Make stringstream
	std::stringstream inSize_(infix);	

	//Make a token
	std::string tok_;									
	
	//While not at end of input
	while(!inSize_.eof())								
	{
		//Move input to token
		inSize_ >> tok_;									
		
		//Increment postfix expression size as long as the token is not a parentheses
		if(tok_ != ")" && tok_ != "(")
			size_++;
	}
	
	return size_;
}

//Runs everything by calling other functions
void Calculator::calculate (void)
{
	//Input string for parsing
	std::string infix_;						

	//Get a line and store in string	
	std::getline(std::cin, infix_);				

	//Size of expression (by number of elements)
	size_t exprSize_ = 0;							
	
	while(infix_ != "QUIT")
	{
		//Stack of integers
		Stack<int> numStack_;					

		//Integer to help stop this iteration execution if needed
		int detected_ = 0;						

		//Stack expression factory
		Stack_Expr_Factory myFactory_(numStack_);		
		
		//Find number of elements
		exprSize_ = findSize(infix_);			

		//Array of postfix elements
		Array<Expr_Command*> postfix_(exprSize_);	
		
		try{
			//Convert infix to postfix, store in "postfix_"
			infix_to_postfix(infix_, myFactory_, postfix_);	
		}
		catch(std::exception & ex){
			std::cout << "ERROR: " << ex.what() << "\n";
			detected_ = 1;
		}
		catch(std::string errCon){
			std::cout << "ERROR: " << errCon << "\n";
			detected_ = 1;
		}
		catch(...){
			std::cout << "ERROR: Infix to Postfix conversion failed.\n";
			detected_ = 1;
		}
		
		if(detected_ == 0)
		{
			//Iterator object
			Expr_Command_Iterator iter_(postfix_);
			
			try{
				//Evaluate postfix
				evaluate_postfix(iter_);				
			}
			catch(std::string err){
				std::cout << "ERROR: " << err << "\n";
				detected_ = 1;		
			}
			catch(...){
				std::cout << "ERROR: Evaluation of Postfix Expression failed.\n";
				detected_ = 1;
			}
			
			//Output the question
			std::cout << "Q: " << infix_ << "\n";

			//If an error has not been detected thus far
			if(detected_ == 0)
			{
				try{
					//Output the calculated answer
					std::cout << "A: " << numStack_.top();	
				}
				catch(...){
					std::cout << "ERROR: Answer Display failed.\n";
					
					detected_ = 1;
				}
			}
			
			if(detected_ == 1)
				iter_.deleteRest();
			
		}
		
		//Output newlines (for formatting)
		std::cout << "\n\n";						

		//Get the next line
		std::getline(std::cin, infix_);				
	}
}


