#ifndef OPERATOR_CPP
#define OPERATOR_CPP

#include "..\MyList.h"

template <typename T>
MyList<T>& MyList<T>::operator=(MyList<T>& A) {
	Posi(T) pointer = header->succ;
	while (pointer != trailer) {
		pointer = pointer->succ;
		delete pointer->pred;
	}
	pointer = header;
	Posi(T) pointerA = A.header;
	_size = A._size;
	for (int i = 0; i < _size; i++) {
		pointer->succ = new MyListNode<T>;
		pointer->succ->pred = pointer;
		pointer = pointer->succ;
		pointerA = pointerA->succ;
		pointer->data = pointerA->data;
	}
	pointer->succ = trailer;
	trailer->pred = pointer;
}

#endif //OPERATOR_CPP