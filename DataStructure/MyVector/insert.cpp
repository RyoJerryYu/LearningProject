#ifndef INSERT_CPP
#define INSERT_CPP

#include "..\MyVector.h"

template <typename T>
T MyVector<T>::insert(Rank r, T t) {
	if (r < 0 || _size < r) { cout << "�Ƿ��Ȳ���" << endl; exit(0); }
	_size++;
	expand();
	int i, j;
	for (i = _size - 1, j = i - 1; r < i; i--, j--) {
		//_elem[i] = _elem[--i];����
		_elem[i] = _elem[j];
	}
	return _elem[r] = t;
}

template <typename T>
T MyVector<T>::insert(Rank lo, int length, T t) {
	if (lo < 0 || _size < lo) { cout << "�Ƿ��Ȳ���" << endl; exit(0); }
	int i, j;
	j = _size - 1;
	_size += length;
	expand();
	for (i = _size - 1; lo <= j; i--, j--) {
		_elem[i] = _elem[j];
	}
	for (i = lo; i < lo + length; i++) {
		_elem[i] = t;
	}
	return t;
}

#endif INSERT_CPP