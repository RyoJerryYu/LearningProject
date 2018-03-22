#ifndef MY_STACK_H
#define MY_STACK_H

#include "MyList.h"
#include <iostream>
using namespace std;

template <typename T>
class MyStack :public MyList<T> {
public:
	MyStack<T>& push(T& t);
	T pop();
	T& top();
};

template <typename T>
MyStack<T>& MyStack<T>::push(T& t) {

}

#endif //MY_STACK_H