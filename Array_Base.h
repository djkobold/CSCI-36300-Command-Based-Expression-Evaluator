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

#ifndef _ARRAYBASE_H_
#define _ARRAYBASE_H_

#include <cstring>			//for size_t definition

/**
 * @class Array_Base
 *
 * New base class for array to follow LSP and eliminate code smells
 */

template <typename T>
class Array_Base
{
public:
	//Allows iterator to access data_ and sizes
	friend class Expr_Command_Iterator;

	/// Type definition of element type.
	typedef T type;
	
	// Default Constructor
	Array_Base(void);
	
	// Initializing Constructor
	Array_Base(size_t length);
	
	// Initializing Constructor w/ Fill
	Array_Base(size_t length, T fillVal);
	
	// Copy Constructor
	Array_Base(const Array_Base & arrayBase);
	
	// Destructor
	~Array_Base(void);
	
	
   /**
	* Get the character at the specified index. If the \a index is not within
	* the range of the array, then std::out_of_range exception is thrown.
	*
	* @param[in]       index                 Zero-based location
	* @return          Character at \index
	* @exception       std::out_of_range     Invalid index value
	*/  
	T get (size_t index) const;

	/** 
	* Set the character at the specified \a index. If the \a index is not
	* within range of the array, then std::out_of_range exception is 
	* thrown.
	*
	* @param[in]       index                 Zero-based location
	* @param[in]       value                 New value for character
	* @exception       std::out_of_range     Invalid \a index value
	*/
	void set (size_t index, T value);
   
	  /**
   * Locate the specified character in the array. The index of the first
   * occurrence of the character is returned. If the character is not
   * found in the array, then -1 is returned.
   *
   * @param[in]        ch        Character to search for
   * @return           Index value of the character
   * @retval           -1        Character not found
   */
  int find (T element) const;

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
  int find (T element, size_t start) const;
   
   
   /**
   * Fill the contents of the array.
   *
   * @param[in]       ch                   Fill character
   */
	void fill (T element);
   
   /**
	* Retrieve the current size of the array.
	*
	* @return          The current size
	*/
	size_t size (void) const;

   /**
	* Retrieve the maximum size of the array.
	*
	* @return          The maximum size
	*/
	size_t max_size (void) const;
	
	//Set the size variables
	void setSizes(size_t cur, size_t max);
	
	//Reverse contents of the array
	void reverse (void);
	
	
private:
	// Pointer to the actual data
	T * data_;
	
	// Current size of the array
	size_t cur_size_;
	
	// Maximum size of the array
	size_t max_size_;
	
};

#include "Array_Base.inl"

#include "Array_Base.cpp"

#endif // !defined _ARRAYBASE_H_