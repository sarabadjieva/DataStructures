#pragma once
#include<iostream>
#include <list>
#include "Pair.h"

template<typename K, typename V>
class ListMap {
public:
	typedef typename std::list<Pair<K,V> >::iterator MIter;

public:
	int size() const { return sz; }
	bool empty() const { return sz == 0; }

	MIter begin() { return LMap.begin(); }
	MIter end() { return LMap.end(); }

	MIter find(const K&) const;
	MIter put(const K&, const V&);

	void erase(const K&);
	void erase(const MIter&);

	void print();
private:
	int sz;
	std::list<Pair<K,V>> LMap;
};

template<typename K, typename V>
typename ListMap<K, V>::MIter ListMap<K, V>::find(const K& k) const {
	for (MIter iter = LMap.begin(); iter != LMap.end(); iter++) {
		if (iter.getKey() == k) {
			return iter;
		}
	}

	return end();
}

template<typename K, typename V>
typename ListMap<K, V>::MIter ListMap<K, V>::put(const K& k, const V& v) {
	Pair<K,V> pair = Pair<K,V>(k, v);

	MIter iter = LMap.begin();
	while (iter != LMap.end()) {
		Pair<K,V> current = *iter;
		if (current.key() == k) {
			*iter = pair;
			return iter;
		}
		iter++;
	}

	LMap.insert(iter, pair);
	sz++;
	return iter;
}

template<typename K, typename V>
void ListMap<K, V>::erase(const K& k) {
	MIter iter = find(k);
	
	if (iter != LMap.end()) {
		LMap.erase(iter);
		sz--;
	}
}

template<typename K, typename V>
void ListMap<K, V>::erase(const MIter& iter) {
	LMap.erase(iter);
	sz--;
}

template<typename K, typename V>
void ListMap<K, V>::print() {
	Pair<K,V> pair;
	std::cout << std::endl << "Map's size: " << size() << std::endl;
	std::cout << std::setw(6) << "Keys" << std::setw(11) << "Values" << std::endl;
	for (MIter iter = LMap.begin(); iter !=LMap.end() ; iter++)
	{
		pair = *iter;
		std::cout << "Key: " << pair.key() << std::setw(10) << "Value: " << pair.value() << std::endl;
	}
}