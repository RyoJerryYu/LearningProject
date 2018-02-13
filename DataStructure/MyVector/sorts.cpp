#ifndef SORTS_CPP
#define SORTS_CPP

#include "..\MyVector.h"
#include <stdlib.h>
#include <iostream>

template <typename T>
void MyVector<T>::sort() {
	int n = rand() % 3;
	switch (n) {
	case 1:
		cout << "using bubblesort." << endl;
		bubblesort();
		break;
	case 2:
		cout << "using mergesort." << endl;
		mergesort();
		break;
	default:
		cout << "sorry,sort faild." << endl;
	}
}

template <typename T>
void MyVector<T>::bubblesort() {
	if (_size < 2)return;
	int i = 0, j = _size - 1, unsorted = _size;
	while (unsorted) {
		unsorted = 0;
		for (i = 0; i < j; i++) {
			if (_elem[i] > _elem[i + 1]) { swap(i, i + 1); unsorted = i; }
		}
		j = unsorted;
	}
}

template <typename T>
void MyVector<T>::mergesort() {
	int length = 1;
	while (length < _size) {
		for (Rank lo = 0; lo < _size; lo += (length * 2)) {
			merge(lo, length);//合并从lo和lo+length开始的，长度为length的两个子序列，protected_func.cpp
		}
		length *= 2;
	}
}


#endif //SORTS_CPP