#pragma once

template<typename K, typename V>
class Pair {
public:
	typedef K Key;
	typedef V Value;
public:
	Pair(const K& _k = K(), const V& _v = V()) : k(_k), v(_v) {}

	const K& key() const { return k; }
	void setKey(const K& _k) { k = _k; }

	const V& value() const { return v; }
	void setValue(const V& _v) { v = _v; }
private:
	K k;
	V v;
};