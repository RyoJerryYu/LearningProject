#ifndef MY_STACK_H
#define MY_STACK_H

#include "MyList.h"
#include <iostream>
using namespace std;

template <typename T>
class MyStack :public MyList<T> {
public:
	MyStack<T>& push(T&& t);
	T pop();
	T& top();
};

template <typename T>
MyStack<T>& MyStack<T>::push(T&& t) {
	this->insertAsLast(t);
	return *this;
}

template <typename T>
T MyStack<T>::pop() {
	T t = this->lastPosi()->data;
	this->remove(this->lastPosi());
	return t;
}

template <typename T>
T& MyStack<T>::top() {
	return this->lastPosi()->data;
}


/*TestFunction*/
int StackFunctions();


#endif //MY_STACK_H