// -*- C++ -*-
// $Id: Queue.inl 2018-09-26 dkobold $

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
size_t Queue <T>::size (void) const
{
	return queueArray_.size();
}

//
// max size
//
// Return maximum size
template <typename T>
inline
size_t Queue <T>::max_size (void) const
{
	return queueArray_.max_size();
}

//
// front
//
// Return the front element of the queue
// because circular queue is now used
template <typename T>
inline
T Queue <T>::front (void) const
{
	return queueArray_.get(qFront_);
}

// Front index
// Return front index
template <typename T>
inline
size_t Queue <T>::frontInd (void) const
{
	return qFront_;
}

// Rear index
// Return rear index
template <typename T>
inline
size_t Queue <T>::rearInd (void) const
{
	return qRear_;
}

//
// is_empty
//
// Return true if queue is empty, false if not empty
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
	return (queueArray_.size() == 0);
}