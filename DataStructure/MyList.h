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
	/*�ڲ�����*/

public:
	/*���캯��*/
	MyList();
	MyList(int, const T&);
	MyList(const T*, int, int);/*
	MyList(const MyList<T> &);*/
	/*��������*/
	/*ֻ���ӿ�*/
	/*��д�ӿ�*/
	/*�����ӿ�*/
};

int ListFunctions();
#include "MyList\MyList.cpp"

#endif //MY_LIST_H