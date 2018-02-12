#ifndef SORTS_CPP
#define SORTS_CPP

#include "..\MyVector.h"
#include <stdlib.h>
#include <iostream>

template <typename T>
void MyVector<T>::sort() {
	int n = rand() % 2;
	switch (1) {
	case 1:
		cout << "using bubblesort." << endl;
		bubblesort();
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
	;
}

#endif //SORTS_CPP