#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include "MyList.h"

template <typename T>
class MyQueue :public MyList<T> {
public:
	MyQueue<T>& enqueue(T&& t);
	T dequeue();
	T& rear();
	T& front();
};

template <typename T>
MyQueue<T>& MyQueue<T>::enqueue(T&& t) {
	this->insertAsLast(t);
	return *this;
}

template <typename T>
T MyQueue<T>::dequeue() {
	return this->remove(this->firstPosi());
}

template <typename T>
T& MyQueue<T>::rear() {
	return this->lastPosi()->data;
}

template <typename T>
T& MyQueue<T>::front() {
	return this->firstPosi()->data;
}


/*TestFunction*/
int QueueFunctions();

#endif //MY_QUEUE_H
