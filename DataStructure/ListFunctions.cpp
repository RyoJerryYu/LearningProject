#include <iostream>
#include "MyList.h"
using namespace std;

int ListFunctions() {
	cout << "Testing ListFunctions" << endl;
	MyListNode<int> Node1;
	MyListNode<int> Node2(1);
	MyList<int> List1;
	cout << List1 << endl;
	MyList<int> List2(4, 4);
	cout << List2 << endl;
	int str2[] = { 1,2,3,6,5 };
	MyList<int> List3(str2, 0, 5);
	cout << List3 << endl;
	cout << List3.size() << endl;
	cout << List3.disordered() << endl;
	return 2;
}