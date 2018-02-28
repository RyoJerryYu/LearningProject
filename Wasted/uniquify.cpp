#ifndef UNIQUIFY_CPP
#define UNIQUIFY_CPP

#include "..\MyVector.h"

template <typename T>
void MyVector<T>::uniquify() {
	int i = 0, j = 1;
	while (j < _size) {
		if (_elem[i] != _elem[j])_elem[++i] = _elem[j];
		j++;
	}
	_size = i + 1;
	shrink();
}

#endif //UNIQUIFY_CPP