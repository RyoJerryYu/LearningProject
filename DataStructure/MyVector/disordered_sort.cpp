#ifndef DISORDERED_SORT_CPP
#define DISORDERED_SORT_CPP

#include "..\MyVector.h"

template<typename T>
int MyVector<T>::disordered() {
	int disordered = 0;
	for (int i = 1; i < _size; i++) {
		if (_elem[i - 1] > _elem[i])disordered++;
	}
	return disordered;
}

#endif //DISORDERED_SORT_CPP