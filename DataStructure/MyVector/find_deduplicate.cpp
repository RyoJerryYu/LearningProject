#ifndef FIND_DEDUPLICATE_CPP
#define FIND_DEDUPLICATE_CPP

#include "..\MyVector.h"

template <typename T>
Rank MyVector<T>::find(const T & t) {
	Rank i = _size - 1;
	for (; 0 <= i; i--) {
		if (_elem[i] == t)return i;
	}
	return i;
}

#endif //FIND_DEDUPLICATE_CPP