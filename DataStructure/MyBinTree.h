#ifndef MY_BIN_TREE_H
#define MY_BIN_TREE_H

#include "MyBinNode.h"
#include "functor.h"
#include "MyStack.h"
#include "MyQueue.h"
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
	/*遍历子程序*/
	template <typename VST>
	void visitAlongLBranch(BinPosi(T), VST&, MyStack<BinPosi(T)>&);
	void goAlongLBranch(BinPosi(T), MyStack<BinPosi(T)>&);
	void deepAlongLBranch(BinPosi(T), MyStack<BinPosi(T)>&);
public:
	MyBinTree(BinPosi(T)x = NULL) :_root(x) {};
	int size() { return _size; };
	bool empty() { return !_root; };
	BinPosi(T) root() { return _root; };

	/*子树接入，删除和分离接口*/
	BinPosi(T) insertAsLC(BinPosi(T), T const&);
	BinPosi(T) insertAsRC(BinPosi(T), T const&);
	
	/*遍历接口*/
	template <typename VST>
	void travPre_I1(BinPosi(T), VST&&);
	template <typename VST>
	void travPre_I2(BinPosi(T), VST&&);
	template <typename VST>
	void travIn_I2(BinPosi(T), VST&&);
	template <typename VST>
	void travPost_I2(BinPosi(T), VST&&);
	template <typename VST>
	void travLevel_I1(BinPosi(T), VST&&);
};

/*********Protected*********/
template <typename T>
int MyBinTree<T>::updateHeight(BinPosi(T) x) {
	return x->height = 1 + (stature(x->lChild) > stature(x->rChild) ? stature(x->lChild) : stature(x->rChild));
}

template <typename T>
void MyBinTree<T>::updateHeightAbove(BinPosi(T) x) {
	bool flag = true;
	int t;
	while (flag&&x) {
		t = x->height;
		flag = (t != updateHeight(x));
		x = x->parent;
	}
}


/*********Structure Changable********/
template <typename T>
BinPosi(T) MyBinTree<T>::insertAsLC(BinPosi(T) x, T const& t) {
	if (x->lChild)delete x->lChild;
	else _size++;
	x->insertAsLC(t);
	updateHeightAbove(x);
	return x->lChild;
}

template <typename T>
BinPosi(T) MyBinTree<T>::insertAsRC(BinPosi(T) x, T const& t) {
	if (x->rChild)delete x->rChild;
	else _size++;
	x->insertAsRC(t);
	updateHeightAbove(x);
	return x->rChild;
}


/**********traverse********/
template <typename T>
template <typename VST>
void MyBinTree<T>::travPre_I1(BinPosi(T) x, VST&& visit) {
	MyStack<BinPosi(T)> posiStack;
	posiStack.push(x);
	while (!posiStack.empty()) {
		x = posiStack.pop();
		if (x->rChild)posiStack.push(x->rChild);
		if (x->lChild)posiStack.push(x->lChild);
		visit(x->data);
	}
}

template <typename T>
void showPre_I1(MyBinTree<T> & bintree) {
	cout << endl;
	cout << "show Pre" << endl;
	bintree.travPre_I1(bintree.root(),Show<T>());
}

template <typename T>
template <typename VST>
void MyBinTree<T>::visitAlongLBranch(BinPosi(T) x, VST& visit, MyStack<BinPosi(T)>& posiStack) {
	while (x) {
		posiStack.push(x->rChild);
		visit(x->data);
		x = x->lChild;
	}
}

template <typename T>
template <typename VST>
void MyBinTree<T>::travPre_I2(BinPosi(T) x,VST&& visit) {
	MyStack<BinPosi(T)> posiStack;
	posiStack.push(x);
	while (!posiStack.empty()) {
		x = posiStack.pop();
		visitAlongLBranch(x, visit, posiStack);
	}
}

template <typename T>
void showPre_I2(MyBinTree<T> & bintree) {
	cout << endl;
	cout << "show Pre" << endl;
	bintree.travPre_I2(bintree.root(),Show<T>());
}

template <typename T>
void MyBinTree<T>::goAlongLBranch(BinPosi(T) x, MyStack<BinPosi(T)>& posiStack) {
	while (x) {
		posiStack.push(x);
		x = x->lChild;
	}
}

template <typename T>
template <typename VST>
void MyBinTree<T>::travIn_I2(BinPosi(T) x, VST&& visit) {
	MyStack<BinPosi(T)> posiStack;
	goAlongLBranch(x, posiStack);
	while (!posiStack.empty()) {
		x = posiStack.pop();
		goAlongLBranch(x->rChild, posiStack);
		visit(x->data);
	}
}

template <typename T>
void showIn_I2(MyBinTree<T> & bintree) {
	cout << endl;
	cout << "show In" << endl;
	bintree.travIn_I2(bintree.root(), Show<T>());
}

template <typename T>
void MyBinTree<T>::deepAlongLBranch(BinPosi(T) x, MyStack<BinPosi(T)>& posiStack) {
	while (x) {
		posiStack.push(x);
		x = (x->lChild) ? (x->lChild) : (x->rChild);
	}
}

template <typename T>
template <typename VST>
void MyBinTree<T>::travPost_I2(BinPosi(T) x, VST&& visit) {
	MyStack<BinPosi(T)> posiStack;
	deepAlongLBranch(x, posiStack);
	while (!posiStack.empty()) {
		x = posiStack.pop();
		while (x->parent && x == x->parent->rChild) {
			visit(x->data);
			x = posiStack.pop();
		}
		if (x->parent)deepAlongLBranch(x->parent->rChild, posiStack);
		visit(x->data);
	}
}

template <typename T>
void showPost_I2(MyBinTree<T> & bintree) {
	cout << endl;
	cout << "show Post" << endl;
	bintree.travPost_I2(bintree.root(), Show<T>());
}

template <typename T>
template <typename VST>
void MyBinTree<T>::travLevel_I1(BinPosi(T) x, VST&& visit) {
	MyQueue<BinPosi(T)> posiQueue;
	posiQueue.enqueue(x);
	while (!posiQueue.empty()) {
		x = posiQueue.dequeue();
		if (x->lChild)posiQueue.enqueue(x->lChild);
		if (x->rChild)posiQueue.enqueue(x->rChild);
		visit(x->data);
	}
}

template <typename T>
void showLevel_I1(MyBinTree<T>& bintree) {
	cout << endl;
	cout << "show Level" << endl;
	bintree.travLevel_I1(bintree.root(), Show<T>());
}


/*TestFunction*/
int BinTreeFunctions();

#endif //MY_BIN_TREE_H