#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class MyVector {
private:
	Rank _size;
	int _capacity;
	T* _elem;

protected:
	/*�ڲ�����*/;
	bool expand();
	void swap(Rank, Rank);
	bool shrink();
	void merge(Rank, int);

public:
	/*���캯��*/;
	MyVector();
	MyVector(int);
	MyVector(int, const T &);
	MyVector(const T*, Rank, Rank);
	MyVector(const MyVector<T> &);
	
	/*��������*/;
	~MyVector();
	
	/*ֻ���ӿ�*/;
	int size() const;
	T & get(Rank);
	int disordered();
	Rank find(const T &);//����ʵ��find(T,Rank=0,Rank=_size)��ֻ���þ�̬��Ա��Ĭ�ϲ�����ģ�����Ա���������ⲿ����Ĭ�ϲ���
	Rank find(const T &, Rank, Rank);

	Rank search(const T &);
	Rank search(const T &, Rank, Rank);
	Rank binsearch(const T &, Rank, Rank);

	/*��д�ӿ�*/;
	T & put(Rank, const T &);
	void deduplicate();
	void uniquify();
	T & insert(Rank, const T &);
	T insert(Rank, int, const T &);
	T remove(Rank);
	int remove(Rank, Rank);

	/*������*/
	void sort();
	void bubblesort();
	void mergesort();

	/*�����ӿ�*/;
	template <typename VST>
	void traverse(VST &);

	/*���ز�����*/
	T& operator[](Rank)const;
	MyVector<T>& operator=(MyVector<T>);
	bool operator<(const MyVector<T> &);
	bool operator>(const MyVector<T> &);
	bool operator<=(const MyVector<T> &);
	bool operator>=(const MyVector<T> &);
	bool operator==(const MyVector<T> &);
	bool operator!=(const MyVector<T> &);
	operator T*();
	template <typename T> friend ostream & operator<<(ostream &, const MyVector<T>&);//ʹ��ostream��ǰ����std�����ռ�,��Ԫ����ģ������ʱ��˵��ģ��
};


/*********************Protected*********************/
template <typename T>
bool MyVector<T>::expand() {//���ݣ����ޱ�Ҫ����false
	if (_size < _capacity)return false;//����ǰ������size��
	T* oldelem = _elem;
	_capacity = _size * 2;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldelem[i];
	}
	delete[] oldelem; return true;
}

template <typename T>
void MyVector<T>::swap(Rank i, Rank j) {//�����±�Ϊi��j��Ԫ��
	if (i < 0 || j < 0 || _size <= i || _size <= j)return;
	T t = _elem[i];
	_elem[i] = _elem[j];
	_elem[j] = t;
}

template <typename T>
bool MyVector<T>::shrink() {//���ݣ����ޱ�Ҫ����false
	if (_capacity < 2 * _size)return false;
	T* oldelem = _elem;
	_capacity = _size;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldelem[i];
	}
	delete[] oldelem; return true;
}

template <typename T>
void MyVector<T>::merge(Rank lo, int length) {//�ϲ���lo��lo+length��ʼ������Ϊlength����������������
	if (_size <= lo + length)return;
	int i = lo, j = 0, k = lo + length;//Ŀ�������±�i��ǰ�������±�j�����������±�k
	T* sub = new T[length];//����ǰ������
	for (; j < length; j++) { sub[j] = _elem[j + lo]; }
	j = 0;
	while ((j < length) && (k < lo + length + length) && (k < _size)) {
		if (sub[j] > _elem[k]) { _elem[i++] = _elem[k++]; }
		else { _elem[i++] = sub[j++]; }
	}
	while (j < length) { _elem[i++] = sub[j++]; }//����������ǰ����ѭ��ʱ
	delete[]sub;
}


/*********************MyVector*********************/
template <typename T>
MyVector<T>::MyVector() :_size(0), _capacity(DEFAULT_CAPACITY) {
	_elem = new T[_capacity];
}

template <typename T>
MyVector<T>::MyVector(int size) : _size(size) {
	_capacity = 2 * _size;
	_elem = new T[_capacity];
}

template <typename T>
MyVector<T>::MyVector(int size, const T & t) :_size(size) {
	_capacity = 2 * _size;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = t;
	}
}

template <typename T>
MyVector<T>::MyVector(const T* str, Rank lo, Rank hi) {
	_size = hi - lo;
	_capacity = 2 * _size;
	_elem = new T[_capacity];
	int i;
	for (i = 0; i < hi; i++) {
		_elem[i] = str[i + lo];
	}
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& A) {
	//������ԭ�򣬲��ܵ���MyVector(A,0,A._size)
	_size = A._size;
	_capacity = A._capacity;
	_elem = new T[_capacity];
	int i;
	for (i = 0; i < _size; i++) {
		_elem[i] = A._elem[i];
	}
}

template <typename T>
MyVector<T>::~MyVector() {
	delete[] _elem;
}


/*********************OnlyRead*********************/
template<typename T>
int MyVector<T>::size() const {
	return _size;
}

template<typename T>
T & MyVector<T>::get(Rank r) {
	if (r < 0 || _size <= r) { cout << "�Ƿ��ȷ���" << endl; exit(0); }
	return _elem[r];
}

template<typename T>
int MyVector<T>::disordered() {
	int disordered = 0;
	for (int i = 1; i < _size; i++) {
		if (_elem[i - 1] > _elem[i])disordered++;
	}
	return disordered;
}

/**********Find**********/
template <typename T>
Rank MyVector<T>::find(const T & t) {
	return find(t, 0, _size);
}

template <typename T>
Rank MyVector<T>::find(const T & t, Rank lo, Rank hi) {
	if (lo < 0 || hi < lo || _size < hi) { cout << "�Ƿ�����" << endl; return lo - 1; }
	Rank i = hi - 1;
	for (; lo <= i; i--) {
		if (_elem[i] == t)return i;
	}
	return i;
}

/**********Search**********/
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


/*********************Writable*********************/
template<typename T>
T & MyVector<T>::put(Rank r, const T & t) {
	if (r < 0 || _size < r) { cout << "�Ƿ��ȷ���" << endl; exit(0); }
	if (r == _size) { _size++; expand(); }
	return _elem[r] = t;
}

template <typename T>
void MyVector<T>::deduplicate() {
	Rank i = 1;
	while (i < _size) {
		(find(_elem[i], 0, i) == -1) ? i++ : remove(i);
	}
	shrink();
}

template <typename T>
void MyVector<T>::uniquify() {
	int i = 0, j = 1;
	while (j < _size) {
		if (_elem[i] != _elem[j])_elem[++i] = _elem[j];
		j++;
	}
	_size = i + 1;
	shrink();
}

/**********Insert**********/
template <typename T>
T & MyVector<T>::insert(Rank r, const T & t) {
	if (r < 0 || _size < r) { cout << "�Ƿ��Ȳ���" << endl; exit(0); }
	insert(r, 1, t);
	return _elem[r];
}

template <typename T>
T MyVector<T>::insert(Rank lo, int length, const T & t) {
	if (lo < 0 || _size < lo) { cout << "�Ƿ��Ȳ���" << endl; exit(0); }
	_size += length;
	expand();
	for (int i = _size - 1; lo + length <= i; i--) {
		_elem[i] = _elem[i - length];
	}
	for (int i = lo; i < lo + length; i++) {
		_elem[i] = t;
	}
	return t;
}

/**********Remove**********/
template<typename T>
T MyVector<T>::remove(Rank r) {
	if (r < 0 || _size <= r) { cout << "û�и����ݿ�ɾ��" << endl; exit(0); }
	T t = _elem[r];
	remove(r, r + 1);
	return t;
}

template<typename T>
int MyVector<T>::remove(Rank lo, Rank hi) {
	if (lo < 0 || hi < 0 || _size <= lo || _size <= hi) { cout << "ɾ���������ݷ�Χ" << endl; exit(0); }
	if (hi <= lo) { cout << "û�����ݿ�ɾ��" << endl; return 0; }
	int length = hi - lo;
	_size -= length;
	for (int i = lo; i < _size; i++) {
		_elem[i] = _elem[i + length];
	}
	shrink();
	return length;
}


/*********************Sort*********************/
template <typename T>
void MyVector<T>::sort() {
	int n = rand() % 3;
	switch (n) {
	case 1:
		cout << "using bubblesort." << endl;
		bubblesort();
		break;
	case 2:
		cout << "using mergesort." << endl;
		mergesort();
		break;
	default:
		cout << "sorry,sort faild." << endl;
	}
}

template <typename T>
void MyVector<T>::bubblesort() {
	if (_size < 2)return;
	int i = 0, j = _size - 1, unsorted = _size;
	while (unsorted) {
		unsorted = 0;
		for (i = 0; i < j; i++) {
			if (_elem[i] > _elem[i + 1]) { swap(i, i + 1); unsorted = i; }
		}
		j = unsorted;
	}
}

template <typename T>
void MyVector<T>::mergesort() {
	int length = 1;
	while (length < _size) {
		for (Rank lo = 0; lo < _size; lo += (length * 2)) {
			merge(lo, length);//�ϲ���lo��lo+length��ʼ�ģ�����Ϊlength�����������У�protected_func.cpp
		}
		length *= 2;
	}
}


/*********************Traverse*********************/
template <typename T>
template <typename VST>//ǰһ������ģ�壬��һ���Ǻ���ģ�壬���ܺϲ�����
void MyVector<T>::traverse(VST & visit) {
	for (int i = 0; i < _size; i++)visit(_elem[i]);
}

template <typename T>
struct Show {
	virtual void operator()(T & t) { cout << t << endl; }
};

template <typename T>
void show(MyVector<T> & vector) {
	Show<T> show;
	vector.traverse(show);
}


/*********************Operator*********************/
template <typename T>
T& MyVector<T>::operator[](Rank r) const {
	if (r < 0 || r >= _size) {
		cout << "�����±곬����Χ" << endl;
		exit(0);
	}
	return _elem[r];
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> vector) {
	delete[] _elem;
	_capacity = vector._capacity;
	_size = vector._size;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = vector._elem[i];
	}
	return *this;
}

template <typename T>
bool MyVector<T>::operator<(const MyVector<T> & vector) {
	return _size < vector._size;
}

template <typename T>
bool MyVector<T>::operator>(const MyVector<T> & vector) {
	return _size > vector._size;
}

template <typename T>
bool MyVector<T>::operator<=(const MyVector<T> & vector) {
	return _size <= vector._size;
}

template <typename T>
bool MyVector<T>::operator>=(const MyVector<T> & vector) {
	return _size >= vector._size;
}

template <typename T>
bool MyVector<T>::operator==(const MyVector<T> & vector) {
	if (_size != vector._size) return false;
	for (int i = 0; i < _size; i++) {
		if (_elem[i] != vector._elem[i])return false;
	}
	return true;
}

template <typename T>
bool MyVector<T>::operator!=(const MyVector<T> & vector) {
	return !(*this == vector);
}

template <typename T>
MyVector<T>::operator T*() {
	T* t = new T[_size];
	for (int i = 0; i < _size; i++) {
		t[i] = _elem[i];
	}
	return t;
}

template <typename T>
ostream & operator<<(ostream & output, const MyVector<T>& vector) {
	output << "MyVector:{";
	for (int i = 0; i < vector._size; i++) {
		output << vector[i] << ",";
	}
	output << "} ";
	return output;
}


/*TestFunction*/
int VectorFunctions();
/*
#include "MyVector\MyVector.cpp" //ģ���಻֧��ֱ�Ӷ��ļ��ṹ��
#include "MyVector\protected_func.cpp"//�����ļ���ͻ�������г�Ա�����ŵ�ͷ�ļ�
#include "MyVector\size_get_put.cpp"
#include "MyVector\insert.cpp"
#include "MyVector\operator.cpp"
#include "MyVector\disordered.cpp"
#include "MyVector\sorts.cpp"
#include "MyVector\remove.cpp"
#include "MyVector\find_deduplicate.cpp"
#include "MyVector\uniquify.cpp"
#include "MyVector\searches.cpp"
#include "MyVector\traverse.cpp"
*/
#endif //MY_VECTOR_H
