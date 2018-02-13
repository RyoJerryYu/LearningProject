#ifndef MY_LIST_NODE_H
#define MY_LIST_NODE_H

#define Posi(T) MyListNode<T>*

template <typename T>
struct MyListNode {
	T data;
	Posi(T) pred;
	Posi(T) succ;

	MyListNode() {}
	MyListNode(T t, Posi(T) p = NULL, Posi(T) s = NULL) :data(t), pred(p), succ(s) {}
	Posi(T) insertAsPred(const T & t) {
		pred = new MyListNode<T>(t, NULL, this);
		return pred;
	}
	Posi(T) insertAsSucc(const T & t) {
		succ = new MyListNode<T>(t, this, NULL);
		return succ;
	}
};

#endif //MY_LIST_NODE_H