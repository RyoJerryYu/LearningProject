#ifndef OPERATOR_CPP
#define OPERATOR_CPP

#include "..\MyVector.h"

template<typename T>
T& MyVector<T>::operator[](Rank r) const {
	if (r < 0 || r >= _size) {
		cout << "向量下标超出范围" << endl;
		exit(0);
	}
	return _elem[r];
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> vector) {
	delete[] _elem;
	_capacity = vector._capacity;
	_size = vector._size;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = vector._elem[i];
	}
	return *this;
}

template<typename T>
ostream & operator<<(ostream & output, const MyVector<T>& vector) {
	output << "MyVector:{";
	for (int i = 0; i < vector._size; i++) {
		output << vector[i] << ",";
	}
	output << "} ";
	return output;
}

#endif //OPERATOR_CPP