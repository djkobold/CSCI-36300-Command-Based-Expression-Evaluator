// -*- C++ -*-
// $ID: Array_Base.h 2018-10-03 dkobold $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

	
#include <stdexcept>         // for std::out_of_bounds exception

// Default Constructor
template <typename T>
Array_Base<T>::Array_Base(void)
	:data_(nullptr),
	cur_size_(0),
	max_size_(10)
{
	//Make a new array of type T and size cur_size_
	T * aArray_ = nullptr;
	aArray_ = new T[max_size_];
	
	//Point data to new array
	data_ = aArray_;
}

//
// Array (size_t)
//
/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 */
template <typename T>
Array_Base <T>::Array_Base (size_t length)
	:data_(nullptr),
	cur_size_(length),
	max_size_(length)
{
	//Make a new array of size length
	T * bArray_ = nullptr;
	bArray_ = new T[length]; 

	//Point data_ to new array
	data_ = bArray_;
}


//
// Array (size_t, char)
//
/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 * @param[in]      fill          Initial value for each element
 */
template <typename T>
Array_Base <T>::Array_Base(size_t length, T fillVal)
	:data_(nullptr),
	cur_size_(length),
	max_size_(length)
{
	//Make a new T array of size length
	T * cArray_ = nullptr;
	cArray_ = new T[length];

	//Point data_ to new array
	data_ = cArray_;

	//Use fill() to fill the array w/ the character
	this->fill(fillVal);
}

//
// Array (const Array &)
//
/**
 * Copy constructor
 *
 * @param[in]     arr         The source array.
 */
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & arrayBase)
	:data_(nullptr),
	cur_size_(arrayBase.size()),
	max_size_(arrayBase.size())
{
	//Used for loop
	size_t dLoop_ = 0;

	T * dArray_ = nullptr;
	dArray_ = new T[arrayBase.size()];

	//Make our array the same size as copy array
	if (cur_size_ != arrayBase.size())
	{
		//Adjust size variables
		cur_size_ = arrayBase.size();
		max_size_ = arrayBase.max_size();
	}

	//Make sure dLoop_ does not surpass current size of array
	while (dLoop_ < arrayBase.size())
	{
		//Copy contents and increment dLoop_
		dArray_[dLoop_] = arrayBase.get(dLoop_);
		dLoop_++;
	}

	//Point data_ to new char array
	data_ = dArray_;
}

//Destructor
template <typename T>
Array_Base<T>::~Array_Base()
{
	//If needed, delete data_
	if (data_ != nullptr)
	{
		delete[] data_;
	}
}

/**
* Get the character at the specified index. If the \a index is not within
* the range of the array, then std::out_of_range exception is thrown.
*
* @param[in]       index                 Zero-based location
* @return          Character at \index
* @exception       std::out_of_range     Invalid index value
*/  
template <typename T>
T Array_Base<T>::get (size_t index) const
{
	//This assumes a try and catch section in the driver

	//If in range, return the data at index
	if (index < max_size())
	{
		return data_[index];
	}
	//Otherwise, its out of range and exception is thrown
	else
	{
		throw std::out_of_range("Get Failed");
	}
}

/** 
* Set the character at the specified \a index. If the \a index is not
* within range of the array, then std::out_of_range exception is 
* thrown.
*
* @param[in]       index                 Zero-based location
* @param[in]       value                 New value for character
* @exception       std::out_of_range     Invalid \a index value
*/
template <typename T>
void Array_Base<T>::set (size_t index, T value)
{
	//This assumes a try and catch section in the driver

	//If out of range, throw exception
	if (index >= max_size_)
		throw std::out_of_range("Set Failed");
	//Otherwise, set the value at index
	else
		data_[index] = value;

	//Make sure new contents are accounted for in cur_size_
	if (index >= cur_size_)
		cur_size_ = index + 1;
}


//
// find (char)
//
/**
 * Locate the specified character in the array. The index of the first
 * occurrence of the character is returned. If the character is not
 * found in the array, then -1 is returned.
 *
 * @param[in]        ch        Character to search for
 * @return           Index value of the character
 * @retval           -1        Character not found
 */
template  <typename T>
int Array_Base <T>::find (T value) const
{
	//Find the matching value by looping through data_
	//and stopping if an index is found for a match
	for (size_t findLoop_ = 0; findLoop_ < cur_size_; findLoop_++)
	{
		if (data_[findLoop_] == value)
			return findLoop_;
	}
	//Otherwise (if not found), return -1
	return -1;
}


//
// find (char, size_t) 
//
/**
 * @overload
 *
 * This version allows you to specify the start index of the search. If
 * the start index is not within the range of the array, then the
 * std::out_of_range exception is thrown.
 *
 * @param[in]       ch                   Character to search for
 * @param[in]       start                Index to begin search
 * @return          Index value of first occurrence
 * @retval          -1                   Character not found
 * @exception       std::out_of_range    Invalid index
 */
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	//Make sure start is less than cur_size_
	if (start < cur_size_)
	{
		//Search through remainder of the data_ array
		for (size_t find2Loop_ = start; find2Loop_ < cur_size_; find2Loop_++)
		{
			if (data_[find2Loop_] == val)
				//Value was found, return index
				return find2Loop_;
		}
		//Value was not found
		return -1;
	}
	//Otherwise, starting point was out of range
	else
		throw std::out_of_range("Out of Range Error");
}

//
// fill
//
/**
 * Fill the contents of the array.
 *
 * @param[in]       value                   Fill character
 */
template <typename T>
void Array_Base <T>::fill (T value)
{
	//Loop through array and fill with value
	for (size_t fillLoop_ = 0; fillLoop_ < max_size(); fillLoop_++)
	{
		set(fillLoop_,value);
	}

}

// Set array size variables
template <typename T>
void Array_Base<T>::setSizes(size_t cur, size_t max)
{
	//Set size variables
	cur_size_ = cur;
	max_size_ = max;
}


/// Reverse the contents of the array such that the first element is now
/// the last element and the last element is the first element.
template <typename T>
void Array_Base<T>::reverse (void)
{
	//Make new array to hold reversed array
	T * revArray_ = nullptr;
	revArray_ = new T[size()];

	//Set up an old array pointer for deleting old data at end
	T * oldArray_ = data_;
	
	//Index for moving backwards through array
	size_t k_ = size()-1;
	
	//Loop forward through reverse array, copying data backwards
	for (size_t m_ = 0; m_ < size(); m_++)
	{
		revArray_[m_] = data_[k_--];
	}
	
	//Set data to the reversed array
	data_ = revArray_;
	
	//Delete the old data
	delete[] oldArray_;
}


	
