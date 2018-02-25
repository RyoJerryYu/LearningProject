#include <iostream>
#include "head.h"
using namespace std;
int pro1001() {
	int n;
	long a[10][3];
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (int i = 0; i<n; i++) {
		cout << "Case #" << i + 1 << ": ";
		if (a[i][0] + a[i][1]>a[i][2]) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}