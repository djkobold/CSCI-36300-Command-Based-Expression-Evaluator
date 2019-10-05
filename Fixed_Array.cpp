// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

//
// Fixed_Array
//
/// Default constructor.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
	:Array_Base<T>(N)
{
	//Doesn't do anything else since the appropriate constructor
	//has already been called
}

//
// Fixed_Array
//
/**
 * Copy constructor.
 *
 * @param[in]      arr        Source array
 */
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
	:Array_Base<T>(arr)
{
	//Used for loop
	size_t dLoop_ = 0;

	//Make sure dLoop_ does not surpass current size of array
	while (dLoop_ < N)
	{
		//Copy contents and increment dLoop_
		this->set(dLoop_,arr.get(dLoop_));
		dLoop_++;
	}
}

//
// Fixed_Array
//
/**
 * Initializing constructor. Fills the contents of the
 * array with the specified \a fill value.
 *
 * @param[in]      fill       The file value.
 */
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	:Array_Base<T>(N,fill)
{
	//Doesn't do anything else since the appropriate constructor
	//has already been called
}

//
// ~Fixed_Array
//
/// Destructor.
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	//Nothing needed here because the corresponding heap variable
	//has been removed
}

//
// operator =
//
/**
 * Assignment operator
 *
 * @param[in]      rhs        Right-hand side of operator.
 */
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	// Used if and else for whether or not self assignment occurred
	if (this == &rhs)
	{
		//Immediately return this array since the arrays are equal
		return *this;
	}
	else
	{
		//Go through and copy the contents from one to the other
		for (size_t asgn1Loop_ = 0; asgn1Loop_ < rhs.size(); asgn1Loop_++)
		{
			//Set the contents of this array to the rhs array contents
			this->set(asgn1Loop_, rhs.myFixArray(asgn1Loop_));
		}
		//Return pointer to this array
		return *this;

	}
}


