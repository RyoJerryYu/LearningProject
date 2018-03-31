#include <iostream>
#include "MyVector.h"
#include "MyList.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "MyBinTree.h"
#include "MyGraph.h"
#include "MyBST.h"
#include "MyAVLTree.h"

using namespace std;

int main() {
	int n;//由于作用域，n的声明不能放在循环内
	do {
		n = 0;
		cout << "Input a number to run program(s):" << endl;
		cout << "1:Programs of vector" << endl;
		cout << "2:Programs of list" << endl;
		cout << "3:Programs of stack" << endl;
		cout << "4:Programs of queue" << endl;
		cout << "5:Programs of binary tree" << endl;
		cout << "6:Programs of graph" << endl;
		cout << "7:Programs of binary search tree" << endl;
		cout << "8:Programs of AVL tree" << endl;
		cout << "If you input 0 or others, this program will be ended." << endl;
		cin >> n;
		cout << endl;
		switch (n) {
		case 1:
			VectorFunctions();
			break;
		case 2:
			ListFunctions();
			break;
		case 3:
			StackFunctions();
			break;
		case 4:
			QueueFunctions();
			break;
		case 5:
			BinTreeFunctions();
			break;
		case 6:
			GraphFunctions();
			break;
		case 7:
			BinSearchTreeFunctions();
			break;
		case 8:
			AVLTreeFunctions();
			break;
		default:
			cout << "Program end." << endl;
			n = 0;
		}
		cout << "\n" << endl;
	} while (n);
}