#include<iostream>
#include"MyVector.h"

using namespace std;
int main() {
	int n;//由于作用域，n的声明不能放在循环内
	do {
		n = 0;
		cout << "Input a number to run program(s):" << endl;
		cout << "1:Programs of vector" << endl;
		cout << "If you input 0 or others, this program will be ended." << endl;
		cin >> n;
		cout << endl;
		switch (n) {
		case 1:
			VectorFunctions();
			break;
		default:
			cout << "Program end." << endl;
			n = 0;
		}
		cout << "\n" << endl;
	} while (n);
}