#pragma once
#include <iostream>
#include "GenericException.h"

template<typename T>
class Stack
{
public:
	Stack(int cap = 1000);
	Stack(const Stack& st);
	Stack& operator=(const Stack& st);
	~Stack(){ delete[] arr;	}

	int size() const { return top_index + 1; }
	bool isEmpty() const { return top_index < 0; }

	const T& top() throw(GenericException) ;
	void push(const T& obj);
	T pop() throw(GenericException);

	void clear();
	Stack<T> reverse();
private:
	int capacity;
	T* arr;
	int top_index;
	void copyStack(const Stack&);
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& st) {
	Stack<T> newSt(st);

	out << "Stack's size: " << newSt.size() << "; continue with pop() LIFO" << std::endl;
	while (!newSt.isEmpty()) {
		out << newSt.pop() << " ";
	}
	out << std::endl << std::endl;

	return out;
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& st) {
	capacity = st.capacity;
	top_index = st.top_index;
	arr = new T[capacity];
	for (int i = 0; i <= top_index; i++) {
		arr[i] = st.arr[i];
	}
}

template<typename T>
Stack<T>::Stack(int cap) {
	capacity = cap;
	top_index = -1;
	arr = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& st) {
	copyStack(st);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& st) {
	if (this != &st)
	{
		delete[] arr;
		copyStack(st);
	}

	return *this;
}

template<typename T>
const T& Stack<T>::top() throw(GenericException) {
	if (isEmpty())
		throw GenericException("Stack is empty");
	return arr[top_index];
}

template<typename T>
void Stack<T>::push(const T& obj) {
	if (size() == capacity)
		throw GenericException("Stack is full");
	arr[++top_index] = obj;
}

template<typename T>
T Stack<T>::pop() throw(GenericException) {
	if (isEmpty())
		throw GenericException("Stack is empty");
	return arr[top_index--];
}

template<typename T>
void Stack<T>::clear() {
	if (!isEmpty()) {
		pop();
		clear();
	}
}

template<typename T>
Stack<T> Stack<T>::reverse() {
	Stack<T> temp(*this);
	Stack<T> revSt;

	while (!temp.isEmpty()) {
		revSt.push(temp.top());
		temp.pop();
	}

	return revSt;
}