#include <iostream>
#include "MyList.h"
using namespace std;

int ListFunctions() {
	cout << "Testing ListFunctions" << endl;
	MyListNode<int> Node1;
	MyListNode<int> Node2(1);
	MyList<int> List1;
	MyList<int> List2(4, 4);
	int str2[] = { 1,2,3,4,5 };
	MyList<int> List3(str2, 0, 5);
	return 2;
}