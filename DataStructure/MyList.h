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
	Posi(T) firstPosi() const;
	Posi(T) lastPosi() const;
	Posi(T) find(T t, int n, Posi(T))const;
	Posi(T) find(T t, Posi(T), int n)const;

	/*可写接口*/
	Posi(T) insertAsFirst(T const&);
	Posi(T) insertAsLast(T const&);
	Posi(T) insertAft(Posi(T), T const&);
	Posi(T) insertBfr(Posi(T), T const&);
	T remove(Posi(T));
	int removeAft(Posi(T), int);
	int removeBfr(Posi(T), int);

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
		pointer = pointer->insertAsSucc(t);
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
		pointer = pointer->insertAsSucc(str[i]);
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
		pointerA = pointerA->succ;
		pointer = pointer->insertAsSucc(pointerA->data);
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

template <typename T>
Posi(T) MyList<T>::firstPosi() const {
	if (header->succ == trailer)return NULL;
	return header->succ;
}

template <typename T>
Posi(T) MyList<T>::lastPosi() const {
	if (trailer->pred == header)return NULL;
	return trailer->pred;
}

template <typename T>
Posi(T) MyList<T>::find(T t, int n, Posi(T) p) const {
	while (n > 0) {
		if (p == header)return NULL;
		p = p->pred;
		if (t == p->data)return p;
		n--;
	}
	return NULL;
}

template <typename T>
Posi(T) MyList<T>::find(T t, Posi(T) p, int n) const {
	while (n > 0) {
		if (p == trailer)return NULL;
		p = p->succ;
		if (t == p->data)return p;
		n--;
	}
	return NULL;
}


/*********************Writable*********************/
template <typename T>
Posi(T) MyList<T>::insertAsFirst(T const& t) {
	Posi(T) p = insertAft(header, t);
	return p;
}

template <typename T>
Posi(T) MyList<T>::insertAsLast(T const& t) {
	Posi(T) p = insertBfr(trailer, t);
	return p;
}

template <typename T>
Posi(T) MyList<T>::insertAft(Posi(T) p, T const& t) {
	Posi(T) pi = new MyListNode<T>(t, p, p->succ);
	p->succ->pred = pi;
	p->succ = pi;
	_size++;
	return pi;
}

template <typename T>
Posi(T) MyList<T>::insertBfr(Posi(T) p, T const& t) {
	Posi(T) pi = new MyListNode<T>(t, p->pred, p);
	p->pred->succ = pi;
	p->pred = pi;
	_size++;
	return pi;
}

template <typename T>
T MyList<T>::remove(Posi(T) p) {
	if (p == header || p == trailer)return p->data;
	T t = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return t;
}

template <typename T>
int MyList<T>::removeAft(Posi(T) p, int n) {
	int count = 0;
	p = p->pred;
	while (n > 0 && p->succ!=trailer) {
		remove(p->succ);
		n--;
		count++;
	}
	return count;
}

template <typename T>
int MyList<T>::removeBfr(Posi(T) p, int n) {
	int count = 0;
	while (n > 0 && p->pred != header) {
		remove(p->pred);
		n--;
		count++;
	}
	return count;
}


/*********************Traverse*********************/
/*********************Operator*********************/
template <typename T>
MyList<T>& MyList<T>::operator=(MyList<T>& A) {
	clear();
	Posi(T) pointer = header;
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