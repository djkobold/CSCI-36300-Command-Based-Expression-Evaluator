// $Id: Queue.cpp 2018-09-26 dkobold $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Queue
//
/// Default constructor.
template <typename T>
Queue <T>::Queue (void)
	: qFront_(0),
	qRear_(0)
{
	//Make new queue (from Array) and point to new queue
	Array<T> aQueue_(10);
	this->queueArray_ = aQueue_;
}

//
// Queue
//
/// Copy constructor.
template <typename T>
Queue <T>::Queue (const Queue & queue)
	: qFront_(queue.qFront_),
	qRear_(queue.qRear_)
{
	//Used in loop
	size_t bQLoop_ = 0;
	
	//If needed, change size of this array before assignment operation
	if(this->queueArray_.size() != queue.queueArray_.size())
	{
		this->queueArray_.resize(queue.queueArray_.max_size());
		this->queueArray_.setSizes(queue.queueArray_.size(),queueArray_.max_size());
	}
	
	//Loop through array to be copied
	while (bQLoop_ < queue.queueArray_.size())
	{
		//Copy contents to new array
		this->queueArray_.set(bQLoop_,queue.queueArray_.get(bQLoop_));
		bQLoop_++;
	}
}

//
// ~Queue
//
/// Destructor.
template <typename T>
Queue <T>::~Queue (void)
{
	//Does nothing now that the Queue's array is on the stack
}

//
// enqueue
//
/**
 * "Adds the element to the end of the list"
 * 
 *
 * @param[in]      element       Element to add to the list
 */
template <typename T>
void Queue <T>::enqueue (T element)
{
	//This means that "wrap around" has not occurred yet, as the rear index
	//is still after the front index
	if(qRear_ > qFront_)
	{
		//This case occurs if first element is at 0 and last is at max_size()-1
		//Meaning that the array needs resized and the new element can be added
		//to the end of the array
		if(qRear_ - qFront_ + 1 >= queueArray_.max_size())
		{
			queueArray_.resize(queueArray_.max_size()+1);
			
			qRear_++;
			//With cur_size_ changed in resize, the next element is now cur_size_ - 1
			//Change the element at that location
			queueArray_.set(qRear_,element);
		}
		//This case occurs if rear is at end of array but front is not at the beginning
		//This means that the "wrap around" needs to occur
		else if(qRear_ + 1 >= queueArray_.max_size() && qFront_ != 0)
		{
			//Set rear index to 0 (Thus "wrap around")
			qRear_ = 0;
			
			//Set element at new rear location
			queueArray_.set(qRear_,element);			
		}
		//This case occurs if rear is not at the end of the array yet
		else
		{
			//Increment rear element index
			qRear_++;
			
			//Set element at new rear location
			queueArray_.set(qRear_,element);
		}
	}
	else if(qRear_ < qFront_)
	{
		//This case occurs if rear still has space to add values before getting to
		//the element before front
		if(qRear_ + 1 < qFront_)
		{
			//Increment rear element index
			qRear_++;
			
			//Set element at new rear location
			queueArray_.set(qRear_,element);
	
		}
		//This case occurs if rear is now the element before front
		//This means everything needs reordered, and the array needs resized
		else
		{
			//Make a new array that will have the reordered old array, plus extra space
			Array<T> reorder_ (queueArray_.max_size()+1);
			
			for(size_t reo_ = 0; reo_ < reorder_.max_size()-1; reo_++)
			{
				//Copy each element of old array in order to new array
				reorder_.set(reo_,queueArray_.get((qFront_ + reo_)%queueArray_.max_size()));
			}
			
			queueArray_.resize(reorder_.max_size());
			
			for(size_t reo2_ = 0; reo2_ < queueArray_.max_size()-1; reo2_++)
			{
				//Copy each element of old array in order to new array
				queueArray_.set(reo2_,reorder_.get(reo2_));
			}
						
			//Make final changes to this array
			//queueArray_ = reorder_;
			qFront_ = 0;
			qRear_ = queueArray_.max_size()-1;
			
			//Set element at new rear location
			queueArray_.set(qRear_,element);
		}
	}
	//Otherwise, this queue is currently empty or has one element
	else
	{		
		//Queue is empty, rear index stays at 0
		if(this->is_empty())
		{	
			//Set element at new rear location
			queueArray_.set(qRear_,element);
		}
		//Otherwise, queue has one element so rear index should be
		//incremented before element is set
		else
		{
			qRear_++;
			
			//Set element at new rear location
			queueArray_.set(qRear_,element);
		}
	}
}

//
// dequeue
//
/**
 * "Removes the element at the front of the list"
 * @return 		 Element at the front of the list.
 * @exception      empty_exception    The queue is empty.
 */
template <typename T>
T Queue <T>::dequeue (void)
{
	//Check if queue is empty
	if(is_empty())
		throw empty_exception("ERROR: Empty queue found in dequeue");
	else
	{
    // COMMENT This design is OK, but it is not the best design. This will be
    // a very expensive array to use if you are dequeing a lot of elements. This
    // is because you are copying N elements each time you dequeue 1 element.
    // Instead, you only want to copy element when necessary. Come up with a better
    // design that is not as expensive for the client to use.
	// RESPONSE The new design is largely implemented in the enqueue function.
	// The new design uses the concept of a "circular queue" where elements can
	// be easily dequeued, and then the later added elements can "wrap around" to
	// the front of the array where elements have been removed. When necessary to
	// resize the array, the elements are reordered to allow the queue to stay in
	// the proper order as more elements are added to the end. Please see comments
	// in enqueue for more information.
    
		//Place the front element in a placeholder variable
		T placeholder_ = queueArray_.get(qFront_);
		
		//Increment the front element index, meaning the next element is now the
		//front of the queue
		qFront_++;
		
		//Change the size variables of the array
		queueArray_.setSizes(queueArray_.size()-1,queueArray_.max_size());
		
		//If needed, set front and rear indices to 0 to "shift" the starting
		//point to 0, since the queue is currently empty
		if(this->is_empty() && qFront_!=0 && qRear_!=0)
		{
			//Since the queue is empty, start over at 0
			qFront_ = 0;
			qRear_ = 0;
		}
		
		//Return the old front element
		return placeholder_;
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
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	//Checked self-assignment with if and else
	//Return this if self-assignment occurred
	if(this == &rhs)
		return *this;
	else
	{
		//Go through and copy the contents from one to the other
		for (size_t asgnLoop_ = 0; asgnLoop_ < rhs.size(); asgnLoop_++)
		{
			//Set the contents of this array to the rhs array contents
			this->queueArray_.set(asgnLoop_, rhs.get(asngLoop_));
		}
		//Return pointer to this array
		return *this;
	}
	
}

//
// clear
//
/// Remove all elements from the queue.
template <typename T>
void Queue <T>::clear (void)
{
	//"Removed" elements by resizing to 0
	queueArray_.resize(0);
}

template <typename T>
T Queue <T>::get (size_t index) const
{
	//Empty queue exception
	if(is_empty())
	{
		throw empty_exception("ERROR: Empty queue found in get");
	}
	//If in range, return the data at index
	//This is checked against max size instead of current size because
	//the queue may not occupy positions 0 to current size, but instead
	//the front index (!=0) to rear index (!=current size)
	else if (index < max_size())
	{
		return queueArray_.get(index);
	}
	//Otherwise, its out of range and exception is thrown
	//Index out of range exception
	else
	{
		throw std::out_of_range("Get Failed");
	}
}





