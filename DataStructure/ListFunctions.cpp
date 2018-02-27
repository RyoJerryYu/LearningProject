#include <iostream>
#include "MyList.h"
using namespace std;

int ListFunctions() {
	cout << "Testing ListFunctions" << endl;
	MyListNode<int> Node1;
	MyListNode<int> Node2(1);
	MyList<int> List1;
	MyList<int> List2(4, 4);
	return 2;
}