#include<iostream>
using namespace std;
int main() {
	int n;//����������n���������ܷ���ѭ����
	do {
		n = 0;
		cout << "Input a number to run program(s):" << endl;
		cout << "1:Programs of vector" << endl;
		cout << "If you input 0 or others, this program will be ended." << endl;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Program1 is running." << endl;
			break;
		default:
			cout << "Program end." << endl;
			n = 0;
		}
	} while (n);
}