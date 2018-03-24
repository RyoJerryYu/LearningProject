#include <iostream>
#include "MyQueue.h"
using namespace std;

int QueueFunctions() {
	cout << "Testing QueueFunctions" << endl;
	MyQueue<int> Queue1;
	Queue1.enqueue(2).enqueue(3).enqueue(4);
	Queue1.enqueue(5);
	cout << Queue1 << endl;
	cout << Queue1.front() << endl;
	cout << Queue1 << endl;
	cout << Queue1.rear() << endl;
	cout << Queue1 << endl;
	cout << Queue1.dequeue() << endl;
	cout << Queue1 << endl;
	return 0;
}