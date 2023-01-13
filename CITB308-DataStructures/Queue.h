#pragma once
#include <iostream>
#include "GenericException.h"

template<typename T>
class Queue
{
public:
	Queue(int cap = 1000);
	Queue(const Queue&);
	Queue& operator=(const Queue&);
	~Queue() { delete[] arr; }

	int size() const { return count; }
	bool isEmpty() const { return count == 0; }
	
	T& front() throw(GenericException);
	void enqueue(T& const);
	T dequeue() throw(GenericException);
private:
	T* arr;
	int capacity;
	int frontIndex;		// It stores the index of an element which is present at the top of a queue.
	int rearIndex;		// It tells us the next position in the array where the element is to inserted.
	int count;
	void copyQueue(const Queue&);
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& q) {
	Queue<T> newQ(q);

	out << "Queue's size: " << newQ.size() << "; continue with dequeue() FIFO" <<std::endl;
	while (!newQ.isEmpty()) {
		out << newQ.dequeue() << " ";
	}
	out << std::endl << std::endl;

	return out;
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& q) {
	capacity = q.capacity;
	frontIndex = q.frontIndex;
	rearIndex = q.rearIndex;
	count = q.count;

	arr = new T[capacity];

	for (int i = 0; i < count; i++)
		arr[i] = q.arr[i];
}

template<typename T>
Queue<T>::Queue(int cap) {
	arr = new T[cap];
	capacity = cap;
	frontIndex = 0;
	rearIndex = 0;
	count = 0;
}

template<typename T>
Queue<T>::Queue(const Queue& q) {
	copyQueue(q);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& q) {
	if (this != &q)
	{
		delete[] arr;
		copyQueue(q);
	}

	return *this;
}


template<typename T>
T& Queue<T>::front() throw(GenericException) {
	if (isEmpty())
		throw GenericException("Queue is empty");

	return arr[frontIndex];
}

template<typename T>
void Queue<T>::enqueue(T& const obj) {
	//at the end
	if (count == capacity)
		return;

	//arr[++rearIndex %= capacity] = obj;
	arr[rearIndex] = obj;
	rearIndex++;
	rearIndex %= capacity;
	count++;
}

template<typename T>
T Queue<T>::dequeue() throw(GenericException) {
	//from the front
	if (isEmpty())
		throw GenericException("Queue is empty");

	T obj = arr[frontIndex];
	//++frontIndex %= capacity;
	frontIndex++;
	frontIndex %= capacity;
	count--;

	return obj;
}