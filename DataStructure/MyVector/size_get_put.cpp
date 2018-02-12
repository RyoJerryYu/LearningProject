#ifndef SIZEGETPUT_CPP
#define SIZEGETPUT_CPP

#include "..\MyVector.h"
#include<iostream>

template<typename T>
int MyVector<T>::size() const {
	return _size;
}

template<typename T>
T& MyVector<T>::get(Rank r) {
	if (r < 0 || _size <= r) { cout << "非法秩访问" << endl; exit(0); }
	return _elem[r];
}

template<typename T>
T MyVector<T>::put(Rank r, T t) {
	if (r < 0 || _size < r) { cout << "非法秩访问" << endl; exit(0); }
	if (r == _size) { _size++; expand(); }
	return _elem[r] = t;
}

#endif //SIZEGETPUT_CPP