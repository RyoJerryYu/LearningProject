#include <iostream>
#include <stdio.h>
using namespace std;
int pro1002() {
	int n = 0, x = 0, y = 0;
	int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
	float a4 = 0;
	int k = 1;
	int a2count = 0, a4sum = 0, a4count = 0;
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> x;
		y = x % 5;
		if (y == 0) {
			if (x % 2 == 0) { a1 += x; }
			continue;
		}
		if (y == 1) {
			a2 += k * x; k = -k; a2count++;
			continue;
		}
		if (y == 2) {
			a3++;
			continue;
		}
		if (y == 3) {
			a4sum += x; a4count++;
			continue;
		}
		if (y == 4) {
			if (a5<x) { a5 = x; }
			continue;
		}
	}
	if (a4count != 0) { a4 = ((float)a4sum) / a4count; }
	a1 == 0 ? (cout << 'N' << " ") : (cout << a1 << " ");
	a2count == 0 ? (cout << 'N' << " ") : (cout << a2 << " ");
	a3 == 0 ? (cout << 'N' << " ") : (cout << a3 << " ");
	if (a4count == 0) { cout << 'N' << " "; }
	else { printf("%.1f ", a4); }
	a5 == 0 ? (cout << 'N' << endl) : (cout << a5 << endl);
	return 0;
}