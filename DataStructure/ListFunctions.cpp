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
	List2.insertAft(List2.insertAsFirst(6), 9);
	cout << List2 << endl;
	List3.insertBfr(List3.insertAsLast(9), 10);
	cout << List3 << endl;
	Posi(int)p = List2.firstPosi();
	cout << List2.remove(p->succ->succ) << endl;
	cout << List2 << endl;
	cout << List2.removeAft(p->succ->succ, 10) << endl;
	cout << List2 << endl;
	p = List3.firstPosi();
	p = List3.find(10, p, 7);
	cout << p << endl;
	return 0;
}