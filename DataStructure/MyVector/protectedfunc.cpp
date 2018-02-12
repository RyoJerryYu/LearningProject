#ifndef PROTECTEDFUNC_CPP
#define PROTECTEDFUNC_CPP

#include "..\MyVector.h"

template <typename T>
void MyVector<T>::expand() {
	if (_size < _capacity)return;//扩张前先增加size！
	T* oldelem = _elem;
	_capacity = _size * 2;
	_elem = new T[_capacity];
	int i;
	for (i = 0; i < _size; i++) {
		_elem[i] = oldelem[i];
	}
	delete[] oldelem;
}

template <typename T>
void MyVector<T>::swap(Rank i, Rank j) {
	if (i < 0 || j < 0 || _size <= i || _size <= j)return;
	T t = _elem[i];
	_elem[i] = _elem[j];
	_elem[j] = t;
}

#endif // PROTECTEDFUNC_CPP