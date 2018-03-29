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
	showPre_I2(BST1);
	showIn_I2(BST1);
	showPost_I2(BST1);
	showLevel_I1(BST1);
	BST1.insert(9, 9);
	BST1.insert(5, 5);
	BST1.insert(6);
	cout << BST1.size() << endl;
	BST1.insert(3, 3);
	BST1.insert(8, 8);
	BST1.insert(0, 0);
	showPre_I2(BST1);
	showIn_I2(BST1);
	showPost_I2(BST1);
	showLevel_I1(BST1);
	/*
	*    1
	*   / \
	*  0   7
	*    /   \
	*   4     9
	*  / \    /
	* 2  5   8
	*  \  \
	*   3  6
	*/
	cout << "\nRemove" << endl;
	BST1.remove(1);
	showPre_I2(BST1);
	showIn_I2(BST1);
	showPost_I2(BST1);
	showLevel_I1(BST1);
	/*
	*    2
	*   / \
	*  0   7
	*    /   \
	*   4     9
	*  / \    /
	* 3  5   8
	*     \
	*      6
	*/
	return 0;
}