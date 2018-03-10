#include <iostream>
#include <string>
#include <stdio.h>
#include "head.h"
using namespace std;
int pro1014() {
	string a1, a2, b1, b2;
	int i = 0, j = 0, count = 0;
	int d = 0, h = 0, m = 0;
	const string DAY[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	cin >> a1 >> a2 >> b1 >> b2;
	for (; i<(int)a1.length() && i<(int)a2.length(); i++) {
		if (a1[i] == a2[i] && 'A' <= a1[i] && a1[i] <= 'Z'&&count == 0) {
			d = a1[i] - 'A';
			count++; continue;
		}
		if (a1[i] == a2[i] && 'A' <= a1[i] && a1[i] <= 'Z'&&count == 1) {
			h = a1[i] - 'A' + 10;
			count++; break;
		}
		if (a1[i] == a2[i] && '0' <= a1[i] && a1[i] <= '9'&&count == 1) {
			h = a1[i] - '0';
			count++; break;
		}
	}
	count = 0;
	for (i = 0; i<(int)b1.length() && i<(int)b2.length(); i++) {
		if (b1[i] != '&') { count++; }
		if (b1[i] == b2[i] && b1[i] != '&') {
			m = count; break;
		}
	}
	cout << DAY[d] << " ";
	printf("%02d:%02d", h, m);
	return 0;
}