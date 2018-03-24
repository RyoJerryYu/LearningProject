#ifndef MY_BIN_TREE_H
#define MY_BIN_TREE_H

#include "MyBinNode.h"
#include <iostream>
using namespace std;

template <typename T>
class MyBinTree {
protected:
	int _size;
	BinPosi(T) _root;
	virtual int updateHeight(BinPosi(T));
	void updateHeightAbove(BinPosi(T));
	int stature(BinPosi(T) p) { return p ? p->height : -1; };
public:
	int size() { return _size; };
	bool empty() { return !_root; };
	BinPosi(T) root() { return _root; };
	/*子树接入，删除和分离接口*/
	/*遍历接口*/
};

template <typename T>
int MyBinTree<T>::updateHeight(BinPosi(T) x) {
	return x->height = 1 + (stature(x->lChild) > stature(x->rChild) ? stature(x->lChild) : stature(x->rChild));
}

template <typename T>
void MyBinTree<T>::updateHeightAbove(BinPosi(T) x) {
	bool flag = true;
	int t;
	while (flag) {
		t = x->height;
		flag = (t != updateHeight(x));
		x = x->parent;
	}
}


#endif //MY_BIN_TREE_H