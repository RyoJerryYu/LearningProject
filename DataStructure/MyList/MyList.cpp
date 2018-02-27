#ifndef MY_LIST_CPP
#define MY_LIST_CPP

#include "..\MyList.h"

template <typename T>
MyList<T>::MyList() {
	header = new MyListNode<T>;
	trailer = new MyListNode<T>;
	header->succ = trailer;
	trailer->pred = header;
	header->pred = NULL;
	trailer->succ = NULL;
	_size = 0;
}

template <typename T>
MyList<T>::MyList(int size,const T& t) {
	_size = size;
	header = new MyListNode<T>;
	trailer = new MyListNode<T>;
	Posi(T) pointer = header;
	for (int i = 0; i < size; i++) {
		pointer->succ = new MyListNode<T>;
		pointer->succ->pred = pointer;
		pointer = pointer->succ;
		pointer->data = t;
	}
	pointer->succ = trailer;
	trailer->pred = pointer;
}

template <typename T>
MyList<T>::MyList(const T* str, int lo, int hi) {
	_size = hi - lo;
	header = new MyListNode<T>;
	trailer = new MyListNode<T>;
	Posi(T) pointer = header;
	for (int i = 0; i < _size; i++) {
		pointer->succ = new MyListNode<T>;
		pointer->succ->pred = pointer;
		pointer = pointer->succ;
		pointer->data = str[i];
	}
	pointer->succ = trailer;
	trailer->pred = pointer;
}

#endif //MY_LIST_CPP