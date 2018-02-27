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
	/*内部函数*/

public:
	/*构造函数*/
	MyList();
	MyList(int, const T&);
	MyList(const T*, int, int);
	MyList(const MyList<T> &);
	/*析构函数*/
	/*只读接口*/
	/*可写接口*/
	/*遍历接口*/
	/*重载操作符*/
	MyList<T>& operator=(MyList<T>&);
};

int ListFunctions();
#include "MyList\MyList.cpp"
#include "MyList\Operator.cpp"

#endif //MY_LIST_H