#pragma once

template<typename T>
class Deque{
public:
	Deque(int cap = 100) : arr(new T[]), sz(0), capacity(cap) {};
	Deque(const Deque& deque) { copy(deque); }
	Deque& operator=(const Deque&);
	~Deque() { delete[] arr; }

	int size() const { return sz; }
	bool empty() const { return sz == 0; }

	T& front();
	T& back();

	void insert_front(const T& el);
	void insert_back(const T& el);

	void erase_front();
	void erase_back();
private:
	T[] arr;
	int sz;
	int capacity;
	void copy(const Deque&);
};

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque& deque) {
	if (this != deque) {
		delete[] arr;
		copy(deque);
	}
	return *this;
}


template<typename T>
void Deque<T>::copy(const Deque& deque) {

}