#ifndef FIND_DEDUPLICATE_CPP
#define FIND_DEDUPLICATE_CPP

#include "..\MyVector.h"

template <typename T>
Rank MyVector<T>::find(const T & t) {
	return find(t, 0, _size);
}

template <typename T>
Rank MyVector<T>::find(const T & t, Rank lo, Rank hi) {
	if (lo < 0 || hi < lo || _size < hi) { cout << "·Ç·¨²éÕÒ" << endl; return lo - 1; }
	Rank i = hi - 1;
	for (; lo <= i; i--) {
		if (_elem[i] == t)return i;
	}
	return i;
}

template <typename T>
void MyVector<T>::deduplicate() {
	Rank i = 1;
	while (i < _size) {
		(find(_elem[i], 0, i) == -1) ? i++ : remove(i);
	}
	shrink();
}

#endif //FIND_DEDUPLICATE_CPP