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
		case 11:
			pro1011();
			break;
		case 12:
			pro1012();
			break;
		case 13:
			pro1013();
			break;
		case 14:
			pro1014();
			break;
		case 15:
			pro1015();
			break;
		case 16:
			pro1016();
			break;
		case 17:
			pro1017();
			break;
		case 18:
			pro1018();
			break;
		case 19:
			pro1019();
			break;
		case 20:
			pro1020();
			break;
		case 21:
			pro1021();
			break;
		case 25:
			pro1025();
			break;
		case 30:
			pro1030();
			break;
		default:
			n = 0;
		}
	}
	
	return 0;
}