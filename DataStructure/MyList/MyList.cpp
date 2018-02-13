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

#endif //MY_LIST_CPP