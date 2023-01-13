#pragma once
#include <stdexcept>
#include <iostream>

template<typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector<T>& v) { copyVector(v); }
	Vector& operator=(const Vector<T>&);
	~Vector() { free(); }

	int size() const { return sz; }
	bool isEmpty() const { return sz == 0; }

	T& at(int) const;
	T& operator[](int r) const { return at(r); };

	void replaceAtRank(int r, const T& obj) { arr[r] = obj; }
	void remove(int);
	void insert(int, const T&);
	void insert_back(const T&);
protected:
	void overflow(); //reserve
private:
	int capacity;
	int sz;
	T* arr;
	void free();
	void copyVector(const Vector<T>&);
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v) {
	int sz = v.size();
	out << "Vector's size: " << sz << std::endl;
	for (int i = 0; i < sz; i++) {
		out << v[i] << " ";
	}

	std::cout << std::endl << std::endl;
	return out;
}

template<typename T>
Vector<T>::Vector() {
	sz = 0;
	capacity = 1;
	arr = new T[capacity];
}

template<typename T>
void Vector<T>::free(){
	if (arr) {
		delete[] arr;
		arr = NULL;
	}
}

template<typename T>
void Vector<T>::copyVector(const Vector& v) {
	sz = v.sz;
	capacity = v.capacity;

	arr = new T[capacity];
	for (int i = 0; i < sz; i++) {
		arr[i] = v.arr[i];
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
	if (this != &v) {
		free();
		copyVector(v);
	}

	return *this;
}

template<typename T>
T& Vector<T>::at(int r) const {
	if (r >= 0 && r < sz)
		return arr[r];
	else
		throw std::out_of_range("Illegal index for vector.");
}

template<typename T>
void Vector<T>::overflow() {
	capacity *= 2;
	T* newArr = new T[capacity];

	for (int i = 0; i < sz; i++) {
		newArr[i] = arr[i];
	}

	free();
	arr = newArr;
}

template<typename T>
void Vector<T>::remove(int r) {
	if (r >= 0 && r < sz) {
		for (int i = r; i < sz - 1; i++) {
			arr[i] = arr[i + 1];
		}
		/*
		 for(int j = i + 1; j < n; j++) {
			elements[j - 1] = elements[j];
		}*/
		sz--;
	}
	else
		throw std::out_of_range("illegal index in function erase()");
}

template<typename T>
void Vector<T>::insert(int r, const T& obj) {
	if (sz >= capacity)
		overflow();

	/// shifts all elements after r
	/// one position to the right
	for (int i = sz - 1; i >= r; i--) {
		arr[i + 1] = arr[i];
	}

	arr[r] = obj;
	sz++;
}

template<typename T>
void Vector<T>::insert_back(const T& obj) {
	insert(sz, obj);
}