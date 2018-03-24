#ifndef MY_BIN_NODE_H
#define MY_BIN_NODE_H

#define BinPosi(T) BinNode<T>*

template <typename T>
struct BinNode {
	BinPosi(T) parent, lChild=NULL, rChild=NULL;
	T data;
	BinNode(T t, BinPosi(T) p) :data(t), parent(p) {};
	int height;
	int size();
	BinPosi(T) insertAsLC(T const&);
	BinPosi(T) insertAsRC(T const&);
	BinPosi(T) succ();//中序遍历后继
	//四个遍历接口
};

template <typename T>
int BinNode<T>::size() {
	int size = 1;
	if (lChild)size += lChild->size();
	if (rChild)size += rChild->size();
	return size;
}

template <typename T>
BinPosi(T) BinNode<T>::insertAsLC(T const& t) {
	return lChild = new BinNode(t, this);
}

template <typename T>
BinPosi(T) BinNode<T>::insertAsRC(T const& t) {
	return rChild = new BinNode(t, this);
}


#endif //MY_BIN_NODE_H