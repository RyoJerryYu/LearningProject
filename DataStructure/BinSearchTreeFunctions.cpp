#include <iostream>
#include "MyBST.h"
using namespace std;

int BinSearchTreeFunctions() {
	MyBST<int> BST1;
	BST1.insert(1, 1);
	BST1.insert(7, 7);
	cout << BST1.size() << endl;
	BST1.insert(4, 4);
	BST1.insert(2, 2);
	BST1.insert(9, 9);
	BST1.insert(5, 5);
	BST1.insert(6, 6);
	cout << BST1.size() << endl;
	BST1.insert(3, 3);
}