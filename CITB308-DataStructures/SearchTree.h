#pragma once

template<typename E>
class SearchTree {
public:
	typedef typename E::Key K;
	typedef typename E::Value V;
	class Iterator;
protected:
	typedef LinkedBinaryTree<E> BinaryTree;
	typedef typename BinaryTree::Position TPos; 
public:
	SearchTree() : T(), sz(0) { T.expandExternal(T.getRoot()); }

	int size() const { return sz; };
	bool empty() const { return sz == 0; };
	Iterator find(const K&);
	Iterator insert(const K&, const V&);
	void erase(const K&);
	void erase(const Iterator&);

	//left internal node
	Iterator begin();
	Iterator end();

	void print() const {
		print(root(),0);
	}

	void print(const TPos& t, int space) const {
		if (t.isInternal()) {
			print(t.right(), space += 6);
			std::cout << std::setw(space) << '(' << t.getValue().key() << ", " << t.getValue().value() << ')' << std::endl;
			print(t.left(), space);
		}

	}
	//void BSTreeLevelOrder();
protected:
	TPos root() const { return T.getRoot().left(); }
	TPos finder(const K&, const TPos&);
	TPos inserter(const K&, const V&);
	TPos eraser(TPos&);
	TPos restructure(const TPos&);
private:
	BinaryTree T;
	int sz;
public:
	class Iterator {
	private:
		TPos v; //which entry
	public:
		Iterator(const TPos& vv) : v(vv) { }
		const E& operator*() const { return *v; } // get entry (read only)
		E& operator*() { return *v; } // get entry (read/write)
		bool operator==(const Iterator& it) const { return v = it.v; }
		Iterator& operator++();

		friend class SearchTree;
	};
};

template<typename E>
typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++() {
	TPos w = v.getRight();

	if (w.isInternal()) { // have right subtree?
		do { v = w; w = w.getLeft(); } // move down left chain
		while (w.isInternal());
	}
	else {
		w = v.parent();
		while (v == w.getRight()) // move up right chain
		{ v = w; w = w.parent(); }
		v = w; // and first link to left
	}
	return *this;
}

template<typename E>
typename SearchTree<E>::Iterator SearchTree<E>::begin() {
	TPos v = root(); // start at virtual root
	while (v.isInternal()) {
		v = v.left();
	} // find leftmost node
	return Iterator(v.parent());
}

template<typename E>
typename SearchTree<E>::Iterator SearchTree<E>::end() {
	return T.getRoot();
}

/*
* При ключ за търсене k и възел v в T,
алгоритъма за търсене, наречен
TreeSearch, връща възел (позиция) w в
поддърво T(v) на T, за който е в сила
едно то следните твърдения:
- w е вътрешен възел и има ключ, равен
на k;
- w е външен възел, представящ място за
вмъкване на k при inorder обхождане
на T(v), но k не е ключ, съдържащ се в
T(v).
*/
template<typename E>
typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v) {
	E ent = v.getValue();
	if (v.isExternal()) return v;
	if (k < ent.key()) return finder(k, v.left());
	if (k > ent.key()) return finder(k, v.right());
	return v;
}

template<typename E>
typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k) {
	TPos v = finder(k, root());
	if (v.isInternal()) return Iterator(v);
	else return end();
}

template<typename E>
typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x) {
	TPos v = finder(k, root());
	while (v.isInternal())
		v = finder(k, v.right());
	T.expandExternal(v);
	(*v).setKey(k);
	(*v).setValue(x);
	sz++;
	return v;
}

template <typename E>
typename SearchTree<E>::Iterator SearchTree<E>::insert(const K& k, const V& x) {
	TPos v = inserter(k, x); return Iterator(v);
}

template<typename E>
typename SearchTree<E>::TPos SearchTree<E>::eraser(TPos& v) {
	TPos w;
	if (v.left().isExternal())
		w = v.left();
	else if (v.right().isExternal())
		w = v.right();
	else { //both internal
		w = v.right();
		do {
			w = w.left();
		} while (w.isInternal());
		TPos u = w.parent();
		(*v).setKey((*u).key());
		(*v).setValue((*u).value());
	}

	sz--;
	return T.removeAboveExternal(w);
}

template <typename E>
void SearchTree<E>::erase(const K& k) {
	TPos v = finder(k, root()); // search from virtual root
	if (v.isExternal()) { // not found?
		std::cout << "Erase of nonexistent\n";
		return;
	}
	eraser(v); // remove it
}

template <typename E>
void SearchTree<E>::erase(const Iterator& p) {
	eraser(p.v);
}

template <typename E>
typename SearchTree<E>::TPos SearchTree<E>::restructure(const TPos& v) {

}