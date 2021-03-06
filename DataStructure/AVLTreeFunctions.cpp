#include "MyAVLTree.h"
#include <iostream>
using namespace std;

int AVLTreeFunctions() {
	MyAVLTree<int> AVL1;
	AVL1.insert(1);
	AVL1.insert(7);
	cout << AVL1.size() << endl;
	AVL1.insert(4);
	AVL1.insert(2);
	AVL1.insert(9);
	AVL1.insert(5);
	AVL1.insert(6);
	AVL1.insert(3);
	AVL1.insert(8);
	AVL1.insert(0);
	cout <<"size: "<< AVL1.size() << endl;
	cout << "height: " << AVL1.height() << endl;
	showPre_I2(AVL1);
	showIn_I2(AVL1);
	showPost_I2(AVL1);
	showLevel_I1(AVL1);
	/*
	*        4
	*     /     \
	*    2       7
	*   / \     /  \
	*  1   3   5    9
	*  /        \   /
	* 0          6  8
	*/
	cout << "\nRemove" << endl;
	AVL1.remove(2);
	showPre_I2(AVL1);
	showIn_I2(AVL1);
	showPost_I2(AVL1);
	showLevel_I1(AVL1);
	/*
	*        4
	*     /     \
	*    1       7
	*   / \     /  \
	*  0   3   5    9
	*           \   /
	*            6  8
	*/

	return 0;
}