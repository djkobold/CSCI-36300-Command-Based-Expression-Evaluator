// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Array
//
/// Default constructor.
template <typename T>
Array <T>::Array (void)
    :Array_Base<T>(),
	myArray_(nullptr)
{
	//Make a new base array of type T
	Array_Base<T> * aDArray_ = nullptr;
	aDArray_ = new Array_Base<T>();
	
	//Point myArray_ to new array
	myArray_ = aDArray_;
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
Array <T>::Array (size_t length)
    :Array_Base<T>(length),
	myArray_(nullptr)
{
    //Make a new array of size cur_size_
    Array_Base<T> * bDArray_ = nullptr;
    bDArray_ = new Array_Base<T>(length); 

	//Point myArray_ to new array
	myArray_ = bDArray_;
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
Array <T>::Array(size_t length, T fill)
	:Array_Base<T>(length,fill),
	myArray_(nullptr)
{
	//Make a new T array of size cur_size_
	Array_Base<T> * cDArray_ = nullptr;
	cDArray_ = new Array_Base<T>(length,fill);

	//Point myArray_ to new array
	//Fill is completed in Array_Base constructor
	myArray_ = cDArray_;
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
Array <T>::Array (const Array & array)
	:Array_Base<T>(array),
	myArray_(nullptr)
{
	//Used for loop
	size_t dLoop_ = 0;
	
	//Make new base array of the same size as copied array
	Array_Base<T> * dDArray_ = nullptr;
	
	dDArray_ = new Array_Base<T>(array);
	
	//Make sure dLoop_ does not surpass current size of array
	while (dLoop_ < array.myArray_->size())
	{
		//Copy contents and increment dLoop_
		dDArray_->set(dLoop_,array.myArray_->get(dLoop_));
		dLoop_++;
	}
	
	//Point data_ to new char array
	myArray_ = dDArray_;
}

//
// ~Array
//
/// Destructor.
template <typename T>
Array <T>::~Array (void)
{
	//Delete memory that myArray_ pointed to
	delete myArray_;
}

//
// operator =
//
/**
 * Assignment operation
 *
 * @param[in]       rhs      Right-hand side of equal sign
 * @return          Reference to self
 */
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	// Used if and else for whether or not self assignment occurred
	if (*this == rhs)
	{
		//Immediately return this array since the arrays are equal
		return *this;
	}
	else
	{				
		//Go through and copy the contents from one to the other
		for (size_t asgnLoop_ = 0; asgnLoop_ < rhs.myArray_->size(); asgnLoop_++)
		{
			//Set the contents of this array to the rhs array contents
			this->myArray_->set(asgnLoop_, rhs.myArray_->get(asgnLoop_));
		}
		//Return pointer to this array
		return *this;

	}
}

//
// operator []
//
/**
 * Get the character at the specified index. If the index is not
 * within the range of the array, then std::out_of_range exception
 * is thrown.
 *
 * @param[in]       index               Zero-based location
 * @exception       std::out_of_range   Invalid \a index value
 */
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	//This assumes a try and catch section in driver

	//If index is in range, return the char at that index
	if (index < myArray_->max_size())
	{
		//Return the data at selected index
		return myArray_->get(index);
	}
	//Otherwise, index is out of range and exception is thrown
	else
		throw std::out_of_range("Index Operator Failed");
}

//
// operator [] 
//
/**
 * @overload
 *
 * The returned character is not modifiable.
 */
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	//This assumes a try and catch section in driver

	//Return data at index as long as index is in range
	if (index < myArray_->max_size())
	{
		//Return the data at selected index
		return myArray_->get(index);
	}
	//Otherwise, index is out of range and exception is thrown
	else
		throw std::out_of_range("Const Index Operator Failed");
}

//
// resize
//
/**
 * Set a new size for the array. If \a new_size is less than the current
 * size, then the array is truncated. If \a new_size if greater then the
 * current size, then the array is made larger and the new elements are
 * not initialized to anything. If \a new_size is the same as the current
 * size, then nothing happens.
 *
 * The array's original contents are preserved regardless of whether the
 * array's size is either increased or decreased.
 *
 * @param[in]       new_size              New size of the array
 */
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size > this->max_size())
	{
		//Used for copying contents to new array
		size_t resLoop_ = 0;

		//New Array
		Array_Base<T> * newArray_ = nullptr;
		Array_Base<T> * oldArray_ = nullptr;
		
		//Set up char array of new_size
		newArray_ = new Array_Base<T>(new_size);

		//Copy contents over to newArray
		while (resLoop_ < myArray_->size())
		{
			newArray_->set(resLoop_,myArray_->get(resLoop_));
			resLoop_++;
		}

		//Point oldArray_ to data_ so data_ can point to the newArray_
		//and then oldArray_ can be deleted
		oldArray_ = myArray_;

		//Point myArray_ to the newArray_
		this->myArray_ = newArray_;

		//Delete the old array
		delete oldArray_;
		
		
		this->setSizes(new_size,new_size);
	}
	else
	{
		//Adjust cur_size_ only
		this->setSizes(new_size,this->max_size());
	}
}




//
// operator ==
//
/**
 * Test the array for equality.
 *
 * @param[in]       rhs                  Right hand side of equal to sign
 * @retval          true                 Left side is equal to right side
 * @retval          false                Left side is not equal to right side
 */
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	// Used if and else for whether or not self comparison occurred
	if (this == &rhs)
	{
		//Immediately return true since the arrays are equal
		return true;
	}
	else
	{
		//Make sure sizes of arrays match
		//If they don't -> arrays don't match
		if (myArray_->size() == rhs.myArray_->size())
		{
			//Check for mismatches between the array values
			for (size_t equLoop_ = 0; equLoop_ < myArray_->size(); equLoop_++)
			{
				//Check if values at one index don't match
				if (myArray_->get(equLoop_) != rhs.myArray_->get(equLoop_))
					//Mismatch found -> arrays don't match
					return false;
			}
			//Sizes were the same and no mismatch found
			// -> arrays match
			return true;
		}
		//Sizes don't match -> arrays don't match
		else
			return false;
	}
}

//
// operator !=
//
/**
 * Test the array for inequality.
 *
 * @param[in]       rhs                  Right-hand size of not equal to sign
 * @retval          true                 Left side is not equal to right side
 * @retval          false                Left size is equal to right side
 */
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	//Return the opposite of the equality operator
	return !(*this == rhs);
}

//Return element of array (used for testing)
template <typename T>
T Array<T>::getElement(size_t index) const
{
	return myArray_->get(index);
}

/// Shrink the array to reclaim unused space.
template <typename T>
void Array<T>::shrink (void)
{
	if (myArray_->size() < myArray_->max_size())
	{
		Array_Base<T> * newArray_ = nullptr;
		newArray_ = new Array_Base<T>(myArray_->size());

		//Used for copying to new array
		size_t k_ = 0;

		while (k_ < myArray_->size())
		{
			//Copy contents
			newArray_->set(k_,myArray_->get(k_));

			k_++;
		}

		//Old array for deletion
		Array_Base<T> * oldArray_ = nullptr;
		oldArray_ = myArray_;

		//Set this to the new array
		myArray_ = newArray_;

		//Delete the old array
		delete[] oldArray_;

		//Set max_size_ to cur_size_ because unused elements are
		//being eliminated
		setSizes(myArray_->size(),myArray_->size());
	}
}





