#include <iostream>
#include "head.h"
using namespace std;
int main() {
	int n=1;
	while (n) {
		cout << "input a number below:" << endl;
		cout << "1:1016" << endl;
		cout << "input others to exit." << endl;
		cin >> n;
		switch (n) {
		case 1:
			pro1016();
			break;
		default:
			n = 0;
		}
	}
	
	return 0;
}