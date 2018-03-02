#include <iostream>
#include "head.h"
using namespace std;
int main() {
	int n=1;
	while (n) {
		cout << "input a number below:" << endl;
		cout << "input others to exit." << endl;
		cin >> n;
		switch (n) {
		case 1:
			pro1001();
			break;
		case 2:
			pro1004();
			break;
		case 3:
			pro1002();
			break;
		case 4:
			pro1003();
			break;
		case 5:
			pro1005();
			break;
		case 6:
			pro1006();
			break;
		case 7:
			pro1007();
			break;
		case 8:
			pro1008();
			break;
		case 9:
			pro1009();
			break;
		case 10:
			pro1010();
			break;
		case 11:
			pro1011();
			break;
		case 15:
			pro1015();
			break;
		case 20:
			pro1020();
			break;
		default:
			n = 0;
		}
	}
	
	return 0;
}