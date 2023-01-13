//#include "Iterator.h"
//
//template<typename T>
//Iterator<T>::Iterator()
//{
//	position = nullptr;
//	last = nullptr;
//}
//
//template<typename T>
//T Iterator<T>::get() const
//{
//	assert(position != nullptr);
//	return position->data;
//}
//
//template<typename T>
//void Iterator<T>::next()
//{
//	assert(position != nullptr);
//	position = position->next;
//}
//
//template<typename T>
//void Iterator<T>::prev()
//{
//	if (position == nullptr) position = last;
//	else   position = position->previous;
//	assert(position != nullptr);
//}
//
//template<typename T>
//bool Iterator<T>::equals(Iterator b) const
//{
//	return position == b.position;
//}