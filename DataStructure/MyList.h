#ifndef MY_LIST_H
#define MY_LIST_H

#include "MyListNode.h"
#include <iostream>
using namespace std;

template <typename T>
class MyList {
private:
	int _size;
	Posi(T) header;
	Posi(T) trailer;
protected:
	/*内部函数*/
	int clear();

public:
	/*构造函数*/
	MyList();
	MyList(int, const T&);
	MyList(const T*, int, int);
	MyList(const MyList<T> &);

	/*析构函数*/
	~MyList();

	/*只读接口*/
	int size() const;
	int disordered() const;

	/*可写接口*/
	Posi(T) insertAsFirst(T const&);
	Posi(T) insertAsLast(T const&);
	Posi(T) insertAft(Posi(T), T const&);
	Posi(T) insertBfr(Posi(T), T const&);

	/*遍历接口*/
	/*重载操作符*/
	MyList<T>& operator=(MyList<T>&);
	template <typename T> friend ostream& operator<<(ostream&, MyList<T>&);
};

/*********************Protected*********************/
template <typename T>
int MyList<T>::clear() {
	int count = 0;
	Posi(T) pointer = header;
	pointer = pointer->succ;
	while (pointer != trailer) {
		pointer = pointer->succ;
		delete pointer->pred;
		count++;
	}
	header->succ = trailer;
	trailer->pred = header;
	_size = 0;
	return count;
}


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
	clear();
	delete header;
	delete trailer;
}


/*********************OnlyRead*********************/
template <typename T>
int MyList<T>::size()const {
	return _size;
}

template <typename T>
int MyList<T>::disordered()const {
	int count = 0;
	Posi(T) p = header;
	p = p->succ;
	while (p != trailer) {
		p = p->succ;
		if (p != trailer && p->data < p->pred->data)count++;
	}
	return count;
}


/*********************Writable*********************/
template <typename T>
Posi(T) MyList<T>::insertAsFirst(T const& t) {
	Posi(T) p = new MyListNode<T>(t, header, header->succ);
	header->succ->pred = p;
	header->succ = p;
	return p;
}

template <typename T>
Posi(T) MyList<T>::insertAsLast(T const& t) {
	Posi(T) p = new MyListNode<T>(t, trailer->pred, trailer);
	trailer->pred->succ = p;
	trailer->pred = p;
	return p;
}

template <typename T>
Posi(T) MyList<T>::insertAft(Posi(T) p, T const& t) {
	Posi(T) pi = new MyListNode<T>(t, p, p->succ);
	p->succ->pred = pi;
	p->succ = pi;
	return pi;
}

template <typename T>
Posi(T) MyList<T>::insertBfr(Posi(T) p, T const& t) {
	Posi(T) pi = new MyListNode<T>(t, p->pred, p);
	p->pred->succ = pi;
	p->pred = pi;
	return pi;
}


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

template <typename T>
ostream& operator<<(ostream& output, MyList<T>& it) {
	output << "MyList:{";
	Posi(T) pointer = it.header;
	pointer = pointer->succ;
	while (pointer != it.trailer) {
		output << pointer->data << ",";
		pointer = pointer->succ;
	}
	output << "} ";
	return output;
}


/*TestFunction*/
int ListFunctions();

#endif //MY_LIST_H