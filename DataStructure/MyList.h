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
	/*析构函数*/
	/*只读接口*/
	/*可写接口*/
	/*遍历接口*/
};

int ListFunctions();
#include "MyList\MyList.cpp"

#endif //MY_LIST_H