// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
// Return current size
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return stackArray_.size();
}

//
// top
//
// Return current top element
template <typename T>
inline
T Stack <T>::top (void) const
{
	return stackArray_.get(stackArray_.size()-1);
}

//
// is_empty
//
// Returns true if stack is empty, false if not empty
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return (stackArray_.size() == 0);
}
