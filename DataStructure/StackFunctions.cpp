#include <iostream>
#include "MyStack.h"
using namespace std;

int StackFunctions() {
	cout << "Testing StackFunctions" << endl;
	MyStack<int> Stack1;
	Stack1.push(4).push(5).push(3);
	Stack1.push(2);
	cout << Stack1 << endl;
	cout << Stack1.top() << endl;
	cout << Stack1 << endl;
	cout << Stack1.pop() << endl;
	cout << Stack1 << endl;
	return 0;
}