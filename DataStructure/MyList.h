#ifndef MY_LIST_H
#define MY_LIST_H

#include "MyListNode.h"

template <typename T>
class MyList {
private:
	int _size;
	Posi(T) header;
	Posi(T) trailer;
protected:
	/*内部函数*/

public:
	/*构造函数*/
	MyList();
	MyList(int, const T&);
	MyList(const T*, int, int);
	MyList(const MyList<T> &);

	/*析构函数*/
	~MyList();

	/*只读接口*/
	/*可写接口*/
	/*遍历接口*/
	/*重载操作符*/
	MyList<T>& operator=(MyList<T>&);
};

/*********************Protected*********************/
/*********************MyList*********************/
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
MyList<T>::MyList(int size, const T& t) {
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

template <typename T>
MyList<T>::MyList(const MyList<T>& A) {
	_size = A._size;
	header = new MyListNode<T>;
	trailer = new MyListNode<T>;
	Posi(T) pointer = header;
	Posi(T) pointerA = A.header;
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

template <typename T>
MyList<T>::~MyList() {
	Posi(T) pointer = header;
	while (pointer != trailer) {
		pointer = pointer->succ;
		delete pointer->pred;
	}
	delete pointer->pred;
	delete pointer;
}


/*********************OnlyRead*********************/
/*********************Writable*********************/
/*********************Traverse*********************/
/*********************Operator*********************/
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


/*TestFunction*/
int ListFunctions();

#endif //MY_LIST_H