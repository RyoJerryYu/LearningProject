#include <iostream>
#include "MyBinTree.h"
using namespace std;

int BinTreeFunctions() {
	MyBinTree<int> BinTree1(&(BinNode<int>(0, NULL)));
	BinPosi(int) x = BinTree1.root();
	BinTree1.insertAsLC(x, 1);
	BinTree1.insertAsRC(x, 2);
	x = x->lChild;
	BinTree1.insertAsLC(x, 3);
	BinTree1.insertAsRC(x, 4);
	x = x->lChild;
	BinTree1.insertAsRC(x, 5);
	x = x->parent->rChild;
	BinTree1.insertAsLC(x, 6);
	BinTree1.insertAsRC(x, 7);
	x = x->parent->parent->rChild;
	BinTree1.insertAsLC(x, 8);
	x = x->lChild;
	BinTree1.insertAsRC(x, 9);
	x = x->rChild;
	BinTree1.insertAsLC(x, 10);
	x = BinTree1.root();
	cout << BinTree1.size() << endl;
	cout << "showPre_I1" << endl;
	showPre_I1(BinTree1);
	cout << "showPre_I2" << endl;
	showPre_I2(BinTree1);
	cout << "showIn_I2" << endl;
	showIn_I2(BinTree1);
	return 0;
}