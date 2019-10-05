//Daniel Kobold
//CSCI363 PA3
//Parse.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


bool Parse::infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix)
{
	std::istringstream input(infix);	//Create a input stream parser
	std::string token;					//The current token in string/stream
	Expr_Command * cmd = 0;				//The created command object
	Expr_Command * trans = 0;			//Variable for transferring into postfix array (when popping elements off stack)
	char transChar;						//Used for moving part of a string to a char to the char stack tempStr
	Stack <Expr_Command *> temp;		//Temporary command stack for order of operations
	Stack<char> tempStr;				//string stack for making string postfix expression
	std::string postfixStr;				//Postfix string
	int topPrec = 0;					//Precedence of top element on stack
	int prec = 0;						//Precedence of element on stack
	int index = 0;						//Index into postfix array
	
	int early = 0;						//Keeps track of how many elements have been accessed (used to keep left to right order)
	int precIndent = 0;					//Will equal "length - early"
	int length = 0;						//Number of elements in infix expression (not including parentheses)
	length = findSize(infix);			//Determines number of elements in infix expression (not including parentheses)
	
	//Precedence Levels:
	//500: Parentheses
	//400: Powers, Roots (Add later)
	//300: "*", "/"
	//200: "+", "-"
	//100: Numbers
	//000: " "
	
	while(!input.eof() && index < length)					//While not at the end of input
	{
    // COMMENT: You should implement the precedence function on
    // the command object since it is better place there.

		prec = 0;						//Reset prec (precendence) to 0

		input >> token;					//Move input to token
		
		if(token == "+")								//ADD
		{
			cmd = factory.create_add_command();			//Create add command
			prec = 2;									//Set precedence

		}
		else if(token == "-")							//SUBTRACT
		{
			cmd = factory.create_subtract_command();	//Create subtract command
			prec = 2;									//Set precedence

		}
		else if(token == "*")							//MULTIPLY
		{
			cmd = factory.create_multiply_command();	//Create multiply command
			prec = 3;									//Set precedence

		}
		else if(token == "/")							//DIVISION
		{
			cmd = factory.create_divide_command();		//Create divide command
			prec = 3;									//Set precedence

		}
		else if(token == "%")							//MODULO
		{
			cmd = factory.create_modulo_command();		//Create modulo command
			prec = 3;									//Set precedence

		}
		else if(token == "(" || token == ")")			//PARENTHESES
		{
			prec = 5;									//Set precedence
	
		}
		else if(token.find_first_not_of("+-0123456789") == std::string::npos) //NUMBER
		{
			cmd = factory.create_number_command(std::stoi(token));		//Use stoi to change string to integer
			prec = 1;									//Set precedence
			
		}
		else
		{
			prec = 0;
		}
	
		if(prec == 1) 	//Number
		{
			postfix.set(index, cmd);					//Store number command in postfix array	
			index++;
		}
		else							//Non-Number
		{
			if(token == "(")							//Check for parentheses
			{
				tempStr.push('(');
			}
			else if(token == ")")						//Check for parentheses
			{
				//Pop elements off of stack until top is an empty stack or the other parentheses
				while(!tempStr.is_empty() && tempStr.top() != '(')
				{
					trans = temp.top();					//Load element for "transfer"
					temp.pop();							//Remove that element from the stack
					postfix.set(index, trans);			//Add object to array since it was in parentheses
					tempStr.pop();						//Remove element from character expression stack
					index++;
				}
				if(tempStr.top() == '(')
					tempStr.pop();
				
			}
			else										//Operator
			{
				if(!tempStr.is_empty())
				{
					topPrec = top_prec(tempStr);
				}
				while(!tempStr.is_empty() && prec <= topPrec && tempStr.top() != '(')
				{
					trans = temp.top();					//Load element for "transfer"
					temp.pop();							//Remove that element from the stack
					postfix.set(index, trans);			//Add object to array
					index++;
					tempStr.pop();						//Remove element from character expression stack
					
					if(!tempStr.is_empty())				//If operator stack is not empty
					{
						topPrec = top_prec(tempStr);	//Find top element precedence
					}
					else
					{
						topPrec = 0;					//Reset top element precedence
					}
				}
				tempStr.push(token[0]);					//Push the operator string
				temp.push(cmd);							//Push the corresponding command
			}
		}
	}
	
	while(!tempStr.is_empty() && !temp.is_empty())		//Pop elements while elements remain on one of the stacks
	{
		trans = temp.top();								//Prepare command for transfer
		temp.pop();										//Pop command off stack
		postfix.set(index, trans);						//Set postfix array element
		index++;										//Increment index
	}
	return true;										
}

bool Parse::evaluate_postfix (Expr_Command_Iterator & iter)	//Evaluate postfix expression through commands
{
	for(; !iter.is_done(); iter.advance())				//Loop through each command element
	{
		iter->execute();								//Execute command indicated by iterator
	}
	return true;
}

int Parse::top_prec (Stack<char> & topPrecS)			//Find precedence of operator at top of operator stack
														//NOTE: These precedence values end in 99 to ensure that
														//they will be operated before equal precedence operators
														//to the right of this one
{
  // COMMENT You should find a better way to compare precedence instead
  // of using a string comparision, which is expensive.
  
	if(topPrecS.top() == '+')							//ADD
	{
		return 2;
	}
	else if(topPrecS.top() == '-')						//SUBTRACT
	{
		return 2;
	}
	else if(topPrecS.top() == '*')						//MULTIPLY
	{
		return 3;
	}
	else if(topPrecS.top() == '/')						//DIVISION
	{
		return 3;
	}
	else if(topPrecS.top() == '%')						//MODULO
	{
		return 3;
	}
	else if(topPrecS.top() == '(' || topPrecS.top() == ')')	//PARENTHESES
	{
		return 5;
	}
	return 0;											//Otherwise, return low precedence
}

size_t Parse::findSize(const std::string & infix)		//Find number of elements to be made
{
	int size = 0;										//Start size at 0
	std::stringstream inSize(infix);					//Make stringstream
	std::string tok;									//Make a token
	
	while(!inSize.eof())								//While not at end of input
	{
		inSize >> tok;									//Move input to token
		if(tok != "(" && tok != ")")					//If NOT a parentheses
		{
			size++;										//Increment size
		}
	}
	return size;
}

