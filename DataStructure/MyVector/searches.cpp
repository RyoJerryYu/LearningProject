#ifndef SEARCHES_CPP
#define SEARCHES_CPP

#include "..\MyVector.h"

template <typename T>
Rank MyVector<T>::search(const T & t) {
	return search(t, 0, _size);
}

template <typename T>
Rank MyVector<T>::search(const T & t, Rank lo, Rank hi) {
	int n = rand() % 2;
	switch (1) {
	case 1:
		cout << "using binary search" << endl;
		return binsearch(t, lo, hi);
	default:
		cout << "sorry,search faild" << endl;
	}
	return 1;
}

template <typename T>
Rank MyVector<T>::binsearch(const T & t, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) / 2;
		if (t < _elem[mi]) { hi = mi; }
		else { lo = mi + 1; }
	}
	return lo - 1;
}

#endif //SEARCHES_CPP