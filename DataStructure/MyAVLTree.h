#ifndef MY_AVL_TREE_H
#define MY_AVL_TREE_H

#include "MyBST.h"

template <typename T>
class MyAVLTree :public MyBST<T>{
protected:
	virtual bool balanced(BSTPosi(T));
public:
	BSTPosi(T) insert(const MyEntry<T>&&);
	bool remove(const MyEntry<T>&&);
};


template <typename T>
bool MyAVLTree<T>::balanced(BSTPosi(T) x) {
	int a = (this->stature(x->lChild) - this->stature(x->rChild));
	return -2 < a&&a < 2;
}

template <typename T>
BSTPosi(T) MyAVLTree<T>::insert(const MyEntry<T>&& t) {
	BSTPosi(T)& x = this->search(t);
	if (x)return x;
	x = new BinNode<MyEntry<T> >(t, this->_hot);
	MyBinTree<MyEntry<T> >::_size++;
	BSTPosi(T) xx = x;
	for (BSTPosi(T) g = x->parent; g; g = g->parent) {
		if (!balanced(g)) {
			MyBinTree<MyEntry<T> >::fromParentTo(g) = this->rotateAt(MyBinTree<MyEntry<T> >::tallerChild(MyBinTree<MyEntry<T> >::tallerChild(g)));
			break;
		}
		else {
			MyBinTree<MyEntry<T> >::updateHeightAbove(g);
		}
	}
	return xx;
}

template <typename T>
bool MyAVLTree<T>::remove(const MyEntry<T>&& t) {
	BSTPosi(T)& x = this->search(t);
	if (!x)return false;
	this->removeAt(x);
	MyBinTree<MyEntry<T> >::_size--;
	for (BSTPosi(T) g = this->_hot; g; g = g->parent) {
		if (!balanced(g)) {
			MyBinTree<MyEntry<T> >::fromParentTo(g) = this->rotateAt(MyBinTree<MyEntry<T> >::tallerChild(MyBinTree<MyEntry<T> >::tallerChild(g)));
		}
		MyBinTree<MyEntry<T> >::updateHeightAbove(g);
	}
	return true;
}


/*TestFunctions*/
int AVLTreeFunctions();


#endif //MY_AVL_TREE_H