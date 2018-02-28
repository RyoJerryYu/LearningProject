#ifndef MYVECTOR_CPP
#define MYVECTOR_CPP

#include "..\MyVector.h"

template <typename T>
MyVector<T>::MyVector() :_size(0), _capacity(DEFAULT_CAPACITY) {
	_elem = new T[_capacity];
}

template <typename T>
MyVector<T>::MyVector(int size) :_size(size) {
	_capacity = 2 * _size;
	_elem = new T[_capacity];
}

template <typename T>
MyVector<T>::MyVector(int size, const T & t) :_size(size) {
	_capacity = 2 * _size;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = t;
	}
}

template <typename T>
MyVector<T>::MyVector(const T* str, Rank lo, Rank hi) {
	_size = hi - lo;
	_capacity = 2 * _size;
	_elem = new T[_capacity];
	int i;
	for (i = 0; i < hi; i++) {
		_elem[i] = str[i + lo];
	}
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& A) {
	//作用域原因，不能调用MyVector(A,0,A._size)
	_size = A._size;
	_capacity = A._capacity;
	_elem = new T[_capacity];
	int i;
	for (i = 0; i < _size; i++) {
		_elem[i] = A._elem[i];
	}
}

template <typename T>
MyVector<T>::~MyVector() {
	delete[] _elem;
}

#endif //MYVECTOR_CPP