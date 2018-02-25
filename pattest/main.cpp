#include <iostream>
#include "head.h"
using namespace std;
int main() {
	int n=1;
	while (n) {
		cout << "input a number below:" << endl;
		cout << "1:1016" << endl;
		cout << "2:1005" << endl;
		cout << "input others to exit." << endl;
		//cin >> n;
		switch (4) {
		case 1:
			pro1016();
			break;
		case 2:
			pro1005();
			break;
		case 3:
			pro1002();
			break;
		case 4:
			pro1003();
			break;
		default:
			n = 0;
		}
	}
	
	return 0;
}