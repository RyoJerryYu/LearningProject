#ifndef MY_ENTRY_H
#define MY_ENTRY_H

#include <iostream>
using namespace std;

template <typename T>
struct MyEntry {
	int key;
	T value;
	MyEntry() {};
	MyEntry(int k) :key(k), value(NULL) {};
	MyEntry(int k, T v) :key(k), value(v) {};
	template <typename T> friend bool operator<(const MyEntry<T>&, const MyEntry<T>&);
	template <typename T> friend bool operator>(const MyEntry<T>&, const MyEntry<T>&);
	template <typename T> friend bool operator<=(const MyEntry<T>&, const MyEntry<T>&);
	template <typename T> friend bool operator>=(const MyEntry<T>&, const MyEntry<T>&);
	template <typename T> friend bool operator==(const MyEntry<T>&, const MyEntry<T>&);
	template <typename T> friend bool operator!=(const MyEntry<T>&, const MyEntry<T>&);
	template <typename T> friend ostream& operator<<(ostream&, const MyEntry<T>&);
};

template <typename T>
bool operator<(const MyEntry<T>& it, const MyEntry<T>& other) {
	return it.key < other.key;
}

template <typename T>
bool operator>(const MyEntry<T>& it, const MyEntry<T>& other) {
	return it.key > other.key;
}

template <typename T>
bool operator<=(const MyEntry<T>& it, const MyEntry<T>& other) {
	return it.key <= other.key;
}

template <typename T>
bool operator>=(const MyEntry<T>& it, const MyEntry<T>& other) {
	return it.key >= other.key;
}

template <typename T>
bool operator==(const MyEntry<T>& it, const MyEntry<T>& other) {
	return it.key == other.key;
}

template <typename T>
bool operator!=(const MyEntry<T>& it, const MyEntry<T>& other) {
	return it.key != other.key;
}

template <typename T>
ostream& operator<<(ostream& output, const MyEntry<T>& it) {
	output << "key: " << it.key << " . value: " << it.value;
	return output;
}


#endif //MY_ENTRY_H