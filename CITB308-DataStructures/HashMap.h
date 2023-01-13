#pragma once
#include <list>
#include <vector>
#include "Pair.h"

class HComp {
public:
	int operator()(const int& i) const { return i; }
};

template<typename K, typename V, typename H>
class HashMap {
public:
	typedef Pair<const K, V> Entry;
	class Iterator;
public:
	HashMap(int capacity = 100) : sz(0), B(capacity) {}

	int size() const { return sz; }
	bool empty() const { return sz == 0; }

	Iterator find(const K&);
	Iterator put(const K&, const V&);

	void erase(const Iterator& it) { eraser(it); }
	void erase(const K&);

	Iterator begin();
	Iterator end();
	void print();
protected:
	typedef std::list<Entry> Bucket;
	typedef std::vector<Bucket> BktArray;
	typedef typename Bucket::iterator EItor;
	typedef typename BktArray::iterator BItor;
	Iterator finder(const K&);
	Iterator inserter(const Iterator&, const Entry&);
	void eraser(const Iterator&);
	void nextEntry(Iterator& it) { ++it.ent; }
	bool endOfBkt(const Iterator& it) { return it.ent == it.bkt->end(); }
private:
	int sz;
	H hash; //the hash comparator
	BktArray B;
public:
	class Iterator {
	private:
		EItor ent;
		BItor bkt;
		const BktArray* ba;
	public:
		Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor()) : ent(q), bkt(b), ba(&a) {}
		Entry& operator*() const { return *ent; }

		bool operator==(const Iterator& it) const {
			return (ba != it.ba || bkt != it.bkt)
				? false 
				: (bkt == ba->end() 
					? true 
					: ent == it.ent);
		}

		Iterator& operator++() {
			++ent;
			if (endOfBkt(*this)) {
				++bkt;
				while (bkt != ba->end() && bkt->empty()) {
					++bkt;
				} //find non-empty bucket

				if (bkt == ba->end()) return *this;
				ent = bkt->begin(); // first non-empty entry
			}
			return *this;
		}

		friend class HashMap;
	};
};

template<typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::find(const K& k) {
	Iterator it = finder(k);
	if (endOfBkt(it)) {
		return end();
	}
	else 
		return it;
}

template<typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::finder(const K& k) {
	int idx = hash(k) % B.size();
	BItor bkt = B.begin() + idx;
	Iterator it(B, bkt, bkt->begin());

	while (!endOfBkt(it) && (*it).key() != k)
		nextEntry(it);

	return it;
}

template<typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::put(const K& k, const V& v) {
	Iterator it = finder(k);
	if (endOfBkt(it))
		return inserter(it, Entry(k,v));
	else {
		it.ent->setValue(v);
		return it;
	}
}

template<typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::inserter(const Iterator& it, const Entry& ent) {
	EItor ins = it.bkt->insert(it.ent, ent); // insert before it
	sz++;
	return Iterator(B, it.bkt, ins);
}

template<typename K, typename V, typename H>
void HashMap<K, V, H>::erase(const K& k) {
	Iterator it = finder(k);
	if (endOfBkt(it)) {
		std::cout << "Deleting non-existent";
		return;
	}
	eraser(it);
}

template<typename K, typename V, typename H>
void HashMap<K, V, H>::eraser(const Iterator& it) {
	it.bkt->erase(it.ent);
	sz--;
}

template<typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::begin() {
	if (empty())
		return end();

	BItor bkt = B.begin();
	while (bkt->empty()) //find non-empty bucket
		++bkt;
	return Iterator(B, bkt, bkt->begin());
}

//ѕри end() не се задава стойност за частта за запис на итератора.ѕричината е,
//че за проверката за равенство на итератори не е необходимо да се
//сравн€ва стойностите на итераторите за записи, ако итераторите на
//клетката са в кра€ на клетъчни€т масив
template<typename K, typename V, typename H>
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::end() {
	return Iterator(B, B.end());
}

template <typename K, typename V, typename H>
void HashMap<K, V, H>::print()
{
	std::cout << std::endl << "Hash Map's size: " << size() << std::endl;
	std::cout << std::setw(5) << "Keys" << std::setw(13) << "Values" << std::endl;
	for (int i = 1; i <= size(); i++)
	{
		BItor bkt = B.begin() + i;
		Iterator p(B, bkt, bkt->begin());
		while (!endOfBkt(p))
		{
			int out = 12;
			if (i > 9)
				out = 11;
			std::cout << "Key: " << (*p).key() << std::setw(out) << "Value: " << (*p).value() << std::endl;
			nextEntry(p);
		}
	}
}