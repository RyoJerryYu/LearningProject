#ifndef REMOVE_CPP
#define REMOVE_CPP

#include "..\MyVector.h"

template<typename T>
T MyVector<T>::remove(Rank r) {
	if (r < 0 || _size <= r) { cout << "没有该数据可删除" << endl; exit(0); }
	T t = _elem[r];
	remove(r, r + 1);
	return t;
}

template<typename T>
int MyVector<T>::remove(Rank lo, Rank hi) {
	if (lo < 0 || hi < 0 || _size <= lo || _size <= hi) { cout << "删除超出数据范围" << endl; exit(0); }
	if (hi <= lo) { cout << "没有数据可删除" << endl; return 0; }
	int length = hi - lo;
	_size -= length;
	for (int i = lo; i < _size; i++) {
		_elem[i] = _elem[i + length];
	}
	shrink();
	return length;
}

#endif //REMOVE_CPP