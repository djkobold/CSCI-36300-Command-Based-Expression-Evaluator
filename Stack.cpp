// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
/// Default constructor.
template <typename T>
Stack <T>::Stack (void)
{
	//Make new stack (from Array) and point to new stack
	Array<T> aStack_(10);
	stackArray_ = aStack_;
}

//
// Stack
//
/// Copy constructor.
template <typename T>
Stack <T>::Stack (const Stack & stack)
{
	//Used in loop
	size_t bSLoop_ = 0;
	
	//Loop through array to be copied
	while (bSLoop_ < stack.stackArray_.size())
	{
		//Copy contents to new array
		this->stackArray_.set(bSLoop_,stack.stackArray_.get(bSLoop_));
		bSLoop_++;
	}
}

//
// ~Stack
//
/// Destructor.
template <typename T>
Stack <T>::~Stack (void)
{
	//Does nothing now that stack's array is on the stack
}

//
// push
//
/**
 * Push a new \a element onto the stack. The element is inserted
 * before all the other elements in the list.
 *
 * @param[in]      element       Element to add to the list
 */
template <typename T>
void Stack <T>::push (T element)
{	
	if(stackArray_.size()+1 >= stackArray_.max_size())
	{
		//Increment the current size (element is being added to the array)
		stackArray_.resize(stackArray_.size()+1);
		
		//With cur_size_ changed in resize, the next element is now cur_size_ - 1
		//Change the element at that location
		stackArray_.set(stackArray_.size() - 1, element);
	}
	else
	{
		//There is still space in the array, so set the element AFTER the last element
		stackArray_.set(stackArray_.size(), element);
	}
	
}

//
// pop
//
/**
 * Remove the top-most element from the stack.
 *
 * @exception      empty_exception    The stack is empty.
 */
template <typename T>
void Stack <T>::pop (void)
{
	//Check if stack is empty
	if (is_empty())
		throw std::logic_error("ERROR: Empty stack found in pop");
	else
	{
		//"Remove" by decreasing size of stack
		//(Makes the old top element inaccessible)
		stackArray_.resize(stackArray_.size() -1);
	}
}

//
// operator =
//
/**
 * Assignment operator
 *
 * @param[in]      rhs           Right-hand side of operator
 * @return         Reference to self
 */
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	//Checked self assignment with if and else
	if(this == &rhs)
		return *this;
	else
	{
		//Go through and copy the contents from one to the other
		for (size_t asgnLoop_ = 0; asgnLoop_ < rhs.size(); asgnLoop_++)
		{
			//Set the contents of this array to the rhs array contents
			this->stackArray_.set(asgnLoop_, rhs.get(asgnLoop_));
		}
		//Return pointer to this array
		return *this;
	}
}

//
// clear
//
/// Remove all elements from the stack.
template <typename T>
void Stack <T>::clear (void)
{
	//"Removed" elements by resizing to 0
	stackArray_.resize(0);
}

template <typename T>
T Stack <T>::get (size_t index) const
{
	//Empty stack exception
	if(is_empty())
	{
		throw empty_exception("ERROR: Empty stack found in get");
	}
	//If in range, return the data at index
	else if (index < size())
	{
		return stackArray_.get(index);
	}
	//Otherwise, its out of range and exception is thrown
	else
	{
		throw std::out_of_range("Get Failed");
	}
}

