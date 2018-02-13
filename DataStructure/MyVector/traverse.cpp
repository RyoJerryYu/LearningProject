#ifndef TRAVERSE_CPP
#define TRAVERSE_CPP

#include "..\MyVector.h"
#include <iostream>

template <typename T>
template <typename VST>//前一个是类模板，后一个是函数模板，不能合并！！
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