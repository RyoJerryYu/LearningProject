#ifndef MY_BST_H
#define MY_BST_H

#include "MyEntry.h"
#include "MyBinTree.h"
#define BSTPosi(T) BinNode<MyEntry<T> >

template <typename T>
class MyBST :protected MyBinTree<MyEntry<T> > {
public:
	virtual BSTPosi(T)& search(const MyEntry<T>&);
	virtual BSTPosi(T) insert(const int&, const T&);
	virtual BSTPosi(T) insert(const MyEntry<T>&&);
	virtual bool remove(const MyEntry<T>&&);
protected:
	BSTPosi(T) _hot;
	BSTPosi(T) removeAt(BSTPosi(T));
};
/*********search********/
template <typename T>
BSTPosi(T)& MyBST<T>::search(const MyEntry<T>& t) {
	_hot = NULL;//_hot aim to t->parent whatever t exists or not.
	BSTPosi(T) v = this->_root;
	if (!v || v->data == t)return this->_root;
	while (v && v->data!=t) {
		_hot = v;
		v = v->data < t ? v->rChild : v->lChild;
	}
	return _hot->data < t ? _hot->rChild : _hot->lChild;
}

template <typename T>
BSTPosi(T) MyBST<T>::insert(const int& key, const T& value) {
	return insert(MyEntry<T>(key, value));
}

template <typename T>
BSTPosi(T) MyBST<T>::insert(const MyEntry<T>&& t) {
	BSTPosi(T)& x = search(t);
	if (!x) {
		x = new BinNode<MyEntry<T> >(t, _hot);
		this->_size++;
		this->updateHeightAbove(x);
	}
	return x;
}

template <typename T>
bool MyBST<T>::remove(const MyEntry<T>&& t) {
	BSTPosi(T)& x = search(t);
	if (!x)return false;
	removeAt(x);
	this->_size--;
	updateHeightAbove(_hot);//_hot aim to parent of the point it truly remove.
}

template <typename T>
BSTPosi(T) MyBST<T>::removeAt(BSTPosi(T)) {

}


#endif //MY_BST_H