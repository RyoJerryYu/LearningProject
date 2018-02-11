#ifndef EXPLAND_CPP
#define EXPLAND_CPP

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

#endif // EXPLAND_CPP
