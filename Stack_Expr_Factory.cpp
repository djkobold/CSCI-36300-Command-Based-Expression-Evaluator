//Daniel Kobold
//CSCI363 PA3
//Stack_Expr_Factory.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Stack_Expr_Factory::Stack_Expr_Factory(Stack<int> & stack)
	:stack_(stack)
{
	//Does nothing else
}

//Create a new command and return the instance of that command
Num_Command * Stack_Expr_Factory::create_number_command (int num)
{
	Num_Command * numCom = new Num_Command(stack_, num);
	return numCom;
}

//Create a new command and return the instance of that command
Add_Command * Stack_Expr_Factory::create_add_command (void)
{
	Add_Command * add = new Add_Command(stack_);
	return add;
}

//Create a new command and return the instance of that command
Subtract_Command * Stack_Expr_Factory::create_subtract_command (void)
{
	Subtract_Command * subtract = new Subtract_Command(stack_);
	return subtract;
}

//Create a new command and return the instance of that command
Multiply_Command * Stack_Expr_Factory::create_multiply_command (void)
{
	Multiply_Command * mult = new Multiply_Command(stack_);
	return mult;
}

//Create a new command and return the instance of that command
Divide_Command * Stack_Expr_Factory::create_divide_command (void)
{
	Divide_Command * div = new Divide_Command(stack_);
	return div;
}

//Create a new command and return the instance of that command
Modulo_Command * Stack_Expr_Factory::create_modulo_command (void)
{
	Modulo_Command * mod = new Modulo_Command(stack_);
	return mod;
}

//Create a new command and return the instance of that command
Parentheses_Command * Stack_Expr_Factory::create_parentheses_command (int num)
{
	Parentheses_Command * par = new Parentheses_Command(stack_, num);
	return par;
}

