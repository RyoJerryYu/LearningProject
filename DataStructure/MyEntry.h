#ifndef MY_ENTRY_H
#define MY_ENTRY_H

template <typename T>
struct MyEntry {
	int key;
	T value;
	MyEntry() {};
	MyEntry(int k, T v) :key(k), value(v) {};
	template <typename T> friend bool operator<(MyEntry<T>&, MyEntry<T>&);
	template <typename T> friend bool operator>(MyEntry<T>&, MyEntry<T>&);
	template <typename T> friend bool operator<=(MyEntry<T>&, MyEntry<T>&);
	template <typename T> friend bool operator>=(MyEntry<T>&, MyEntry<T>&);
	template <typename T> friend bool operator==(MyEntry<T>&, MyEntry<T>&);
	template <typename T> friend bool operator!=(MyEntry<T>&, MyEntry<T>&);
};

template <typename T>
bool operator<(MyEntry<T>& it, MyEntry<T>& other) {
	return it.key < other.key;
}

template <typename T>
bool operator>(MyEntry<T>& it, MyEntry<T>& other) {
	return it.key > other.key;
}

template <typename T>
bool operator<=(MyEntry<T>& it, MyEntry<T>& other) {
	return it.key <= other.key;
}

template <typename T>
bool operator>=(MyEntry<T>& it, MyEntry<T>& other) {
	return it.key >= other.key;
}

template <typename T>
bool operator==(MyEntry<T>& it, MyEntry<T>& other) {
	return it.key == other.key;
}

template <typename T>
bool operator!=(MyEntry<T>& it, MyEntry<T>& other) {
	return it.key != other.key;
}

#endif //MY_ENTRY_H