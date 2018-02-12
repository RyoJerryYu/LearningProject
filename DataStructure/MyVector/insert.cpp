#ifndef INSERT_CPP
#define INSERT_CPP

#include "..\MyVector.h"

template <typename T>
T MyVector<T>::insert(Rank r,const T & t) {
	if (r < 0 || _size < r) { cout << "非法秩插入" << endl; exit(0); }
	insert(r, 1, t);
	return _elem[r];
}

template <typename T>
T MyVector<T>::insert(Rank lo, int length, const T & t) {
	if (lo < 0 || _size < lo) { cout << "非法秩插入" << endl; exit(0); }
	_size += length;
	expand();
	for (int i = _size - 1; lo + length <= i; i--) {
		_elem[i] = _elem[i - length];
	}
	for (int i = lo; i < lo + length; i++) {
		_elem[i] = t;
	}
	return t;
}

#endif INSERT_CPP