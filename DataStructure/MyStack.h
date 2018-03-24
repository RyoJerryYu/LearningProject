#ifndef MY_STACK_H
#define MY_STACK_H

#include "MyList.h"

template <typename T>
class MyStack :public MyList<T> {
public:
	MyStack<T>& push(T& t);
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
MyStack<T>& MyStack<T>::push(T& t) {
	this->insertAsLast(t);
	return *this;
}

template <typename T>
T MyStack<T>::pop() {
	return this->remove(this->lastPosi());
}

template <typename T>
T& MyStack<T>::top() {
	return this->lastPosi()->data;
}


/*TestFunction*/
int StackFunctions();


#endif //MY_STACK_H