#ifndef MY_BST_H
#define MY_BST_H

#include "MyEntry.h"
#include "MyBinTree.h"
#define BSTPosi(T) BinNode<MyEntry<T> >*

template <typename T>
class MyBST :public MyBinTree<MyEntry<T> > {
public:
	MyBST() :MyBinTree<MyEntry<T> >(), _hot(NULL) {};
	virtual BSTPosi(T)& search(const MyEntry<T>&);
	virtual BSTPosi(T) insert(const int&, const T&);
	virtual BSTPosi(T) insert(const MyEntry<T>&&);
	virtual bool remove(const MyEntry<T>&&);
protected:
	BSTPosi(T) _hot;
	BSTPosi(T) removeAt(BSTPosi(T)&);
	BSTPosi(T) rotateAt(BSTPosi(T));
	BSTPosi(T) connet34(BSTPosi(T), BSTPosi(T), BSTPosi(T), BSTPosi(T), BSTPosi(T), BSTPosi(T), BSTPosi(T));
};

/*********protected********/
template <typename T>
BSTPosi(T) MyBST<T>::connet34(BSTPosi(T) a, BSTPosi(T) b, BSTPosi(T) c, BSTPosi(T) T0, BSTPosi(T) T1, BSTPosi(T) T2, BSTPosi(T) T3) {
	a->lChild = T0;
	if (T0)T0->parent = a;
	a->rChild = T1;
	if (T1)T1->parent = a;
	this->updateHeight(a);
	c->lChild = T2;
	if (T2)T2->parent = c;
	c->rChild = T3;
	if (T3)T3->parent = c;
	this->updateHeight(c);
	b->lChild = a;
	b->rChild = c;
	a->parent = b;
	c->parent = b;
	this->updateHeight(b);
	return b;
}

template <typename T>
BSTPosi(T) MyBST<T>::rotateAt(BSTPosi(T) v) {
	BSTPosi(T) p = v->parent;
	BSTPosi(T) g = p->parent;
	if (p == g->lChild) {
		if (v == p->lChild) {//zig-zig
			p->parent = g->parent;
			return connet34(v, p, g, v->lChild, v->rChild, p->rChild, g->rChild);
		}
		else {//zig-zag
			v->parent = g->parent;
			return connet34(p, v, g, p->lChild, v->lChild, v->rChild, g->rChild);
		}
	}
	else {
		if (v == p->lChild) {//zag-zig
			v->parent = g->parent;
			return connet34(g, v, p, g->lChild, v->lChild, v->rChild, p->rChild);
		}
		else {//zag-zag
			p->parent = g->parent;
			return connet34(g, p, v, g->lChild, p->lChild, v->lChild, v->rChild);
		}
	}
}


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
	this->updateHeightAbove(_hot);//_hot aim to parent of the point it truly remove.
	return true;
}

template <typename T>
BSTPosi(T) MyBST<T>::removeAt(BSTPosi(T)& x) {
	BSTPosi(T)w = x;
	BSTPosi(T) succ = NULL;
	if (!x->lChild)succ = x = x->rChild;
	else if (!x->rChild)succ = x = x->lChild;
	else {
		w = x->succ();//w could never be NULL because x have rChild.
		x->data = exchange(w->data, x->data);
		BSTPosi(T) u = w->parent;//w->parent could never be NULL
		(u == x ? u->rChild : u->lChild) = succ = w->rChild;//w->rChild could be NULL.
	}
	_hot = w->parent;
	if (succ)succ->parent = _hot;
	delete w;
	return succ;
}


/*TestFunctions*/
int BinSearchTreeFunctions();


#endif //MY_BST_H