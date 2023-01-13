//#pragma once
//#include "Iterator.h"
//#include "GenericException.h"
//
////double linked list
//template<typename T>
//class List
//{
//private:
//	NodePtr<T> firstEl;
//	NodePtr<T> lastEl;
//
//public:
//	List() : firstEl(nullptr), lastEl(nullptr) { };
//
//	int size() const;
//	bool isEmpty() const { return firstEl == nullptr; };
//	
//	//void replaceElement(const Position& p, const Object& element)
//	//	throw(InvalidPositionException);
//	//void swapElements(const Position& a, const Position& b)
//	//	throw(InvalidPositionException);
//
//	void push_back(T);
//	void insert(Iterator<T>, T);
//	void insertBefore(Iterator<T>, T);
//	void insertAfter(Iterator<T>, T);
//	void insertFirst(T);
//	void insertLast(T);
//
//	//void remove(Iterator<T>) throw(GenericException);
//	Iterator<T> erase(Iterator<T>);
//	//Iterator<T> first();
//	Iterator<T> begin();
//	//Iterator<T> last();
//	Iterator<T> end();
//	
//	bool isFirst(Iterator<T>) throw (GenericException);
//	bool isLast(Iterator<T>) throw (GenericException);
//
//	//exception if first
//	T before(const Iterator<T> it) { return it.position->previous->data; };
//	T after(const Iterator<T> it) {
//		return it.position == it.last
//			? throw GenericException("Last element")
//			: it.position->next->data;
//	};
//};
//
//
//template<typename T>
//void List<T>::push_back(T obj)
//{
//    Node<T>* newnode = new Node<T>(obj);
//    if (lastEl == nullptr) /* list is empty */
//    {
//        firstEl = newnode;
//        lastEl = newnode;
//    }
//    else
//    {
//        newnode->previous = lastEl;
//        lastEl->next = newnode;
//        lastEl = newnode;
//    }
//}
//
//template<typename T>
//void List<T>::insert(Iterator<T> iter, T s)
//{
//    if (iter.position == nullptr)
//    {
//        push_back(s);
//        return;
//    }
//
//    Node<T>* after = iter.position;
//    Node<T>* before = after->previous;
//    Node<T>* newnode = new Node<T>(s);
//    newnode->previous = before;
//    newnode->next = after;
//    after->previous = newnode;
//    if (before == nullptr) /* insert at beginning */
//        firstEl = newnode;
//    else
//        before->next = newnode;
//}
//
//template<typename T>
//Iterator<T> List<T>::erase(Iterator<T> i)
//{
//    Iterator<T> iter = i;
//    assert(iter.position != nullptr);
//    Node<T>* remove = iter.position;
//    Node<T>* before = remove->previous;
//    Node<T>* after = remove->next;
//    if (remove == firstEl) firstEl = after;
//    else          before->next = after;
//    if (remove == lastEl) lastEl = before;
//    else     after->previous = before;
//    iter.position = after;
//    delete remove;
//    return iter;
//}
//
//template<typename T>
//Iterator<T> List<T>::begin()
//{
//    Iterator<T> iter;
//    iter.position = firstEl;
//    iter.last = lastEl;
//    return iter;
//}
//
//template<typename T>
//Iterator<T> List<T>::end()
//{
//    Iterator<T> iter;
//    iter.position = nullptr;
//    iter.last = lastEl;
//    return iter;
//}