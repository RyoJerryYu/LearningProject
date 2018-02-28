#ifndef TRAVERSE_CPP
#define TRAVERSE_CPP

#include "..\MyVector.h"
#include <iostream>

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

#endif //TRAVERSE_CPP