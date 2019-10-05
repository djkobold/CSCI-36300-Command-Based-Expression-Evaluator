   // -*- C++ -*-
// $Id: Queue.h 2018-09-26 dkobold $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include "Array.h"
#include <exception>

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the Queue is empty.
   */
  class empty_exception : public std::logic_error
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::logic_error () 
	  {
		//Constructor doesn't explicitly do anything
		//Because this is a logic_error, it inherits what()
		//Allowing the exception message to be specified
		//at the place the exception occurs/is thrown
	  }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::logic_error (msg) 
	  {
		//Constructor doesn't explicitly do anything
		//Because this is a logic_error, it inherits what()
		//Allowing the exception message to be specified
		//at the place the exception occurs/is thrown
	  }
	  
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * "Adds the element to the end of the list"
   * 
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * "Removes the element at the front of the list"
   * @return 		 Element at the front of the list.
   * @exception      empty_exception    The queue is empty.
   */
  T dequeue (void);
  
  //Return front element of queue
  T front (void) const;
  
  //Return index of front element of queue (for testing)
  size_t frontInd (void) const;
  
  //Return index of rear element of queue (for testing)
  size_t rearInd (void) const;

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;
  
  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t max_size (void) const;

  /// Remove all elements from the queue.
  void clear (void);
  
  // Return element of queue (for testing)
  T get(size_t index) const;

private:
  // COMMENT There is no need to allocate the array on the heap. Always try to
  // allocate on the stack to reduce the complexity of your code.
  // RESPONSE The array is now allocated on the stack instead of the heap
  Array<T> queueArray_;
  
  // These are for keeping track of which parts of the circular queue are
  // the front and back of the actual queue
  size_t qFront_;
  size_t qRear_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
