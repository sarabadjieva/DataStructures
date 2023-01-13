#pragma once
#include <iostream>

template<typename T>
class NodeList {
private:
	struct Node {
		T data;
		Node* prev; 
		Node* next;
		//Node() : data(), prev(NULL), next(NULL) {}
	};
public:
	class Iterator {
	public:
		Iterator() : node(new Node) {}
		Iterator(Node* u) : node(u) {}
		Iterator(const Iterator& it) { copy(it); }
		Iterator& operator=(const Iterator&);

		T& operator*() { return node->data; }

		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
		
		//prefix
		Iterator& operator--();
		Iterator& operator++();
		//postfix
		Iterator operator --(int);
		Iterator operator ++(int);

		friend class NodeList;
	private:
		Node* node;
		void copy(const Iterator&);
	}; 

private:
	int sz;
	Node* header;
	Node* trailer;
	void copy(const NodeList&);
public:	
	NodeList();
	NodeList(const NodeList& list) { copy(list); }
	NodeList& operator=(const NodeList&);
	~NodeList();

	int size() const { return sz; }
	bool empty() const { return sz == 0; }

	Iterator begin() const { return Iterator(header->next); }
	Iterator end() const { return Iterator(trailer); }

	void insert(const Iterator&, const T&);
	void insert_front(const T&);
	void insert_back(const T&);
	
	void remove(const Iterator&);
	void remove_front();
	void remove_back();
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const NodeList<T>& list) {
	out << "List's size: " << list.size() << std::endl;

	typename NodeList<T>::Iterator it = list.begin();
	for (it = list.begin(); it != list.end(); it++)
		out << *it << " ";

	out << std::endl << std::endl;

	return out;
}

template<typename T>
NodeList<T>& NodeList<T>::operator=(const NodeList<T>& list) {
	if (this != &list) {
		delete header, trailer;
		copy(list);
	}

	return *this;
}

template<typename T>
void NodeList<T>::copy(const NodeList<T>& list) {
	sz = list.size();
	header = list.header;
	trailer = list.trailer;
}

template<typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator=(const NodeList<T>::Iterator& it) {
	copy(it);
	return *this;
}

template<typename T>
bool NodeList<T>::Iterator::operator==(const Iterator& it) const {
	return node == it.node;
}

template<typename T>
bool NodeList<T>::Iterator::operator!=(const Iterator& it) const {
	return node != it.node;
}

template<typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--() {
	node = node->prev;
	return *this;
}

template<typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator++() {
	node = node->next;
	return *this;
}

template<typename T>
typename NodeList<T>::Iterator NodeList<T>::Iterator::operator--(int) {
	Iterator it = *this;
	--* this;
	return it;
}

template<typename T>
typename NodeList<T>::Iterator NodeList<T>::Iterator::operator++(int) {
	Iterator it = *this;
	++* this;
	return it;
}

template<typename T>
void NodeList<T>::Iterator::copy(const Iterator& it) {
	node = it.node;
}

template<typename T>
NodeList<T>::NodeList() {
	sz = 0;
	header = new Node;
	trailer = new Node;

	header->next = trailer;
	trailer->prev = header;
}

template<typename T>
NodeList<T>::~NodeList() {
	while (!empty()) {
		remove_back();
	}
}

template<typename T>
void NodeList<T>::insert(const Iterator& it, const T& data) {
	Node* node = it.node;
	Node* prev = node->prev;

	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = prev; prev->next = newNode;
	newNode->next = node; node->prev = newNode;

	sz++;
}//insert before position it

template<typename T>
void NodeList<T>::insert_front(const T& data) {
	insert(begin(), data);
}

template<typename T>
void NodeList<T>::insert_back(const T& data) {
	insert(end(), data);
}

template<typename T>
void NodeList<T>::remove(const Iterator& it) {
	Node* v = it.node;
	Node* w = v->prev;
	Node* u = v->next;

	w->next = u;
	u->prev = w;

	delete v;
	sz--;
}

template<typename T>
void NodeList<T>::remove_front() {
	remove(begin());
}

template<typename T>
void NodeList<T>::remove_back() {
	remove(--end());
}
