#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int pro1023() {
	int a[10];
	vector<int> d;
	for (int i = 0; i < 10; i++) cin >> a[i];
	for (int i = 0; i < 10; i++) {
		while (a[i] != 0) {
			d.push_back(i);
			a[i]--;
		}
	}
	if (d[0] == 0) {
		auto b = upper_bound(d.begin(), d.end(), 0);
		d[0] = *b;
		*b = 0;
	}
	for (const int& n : d)cout << n;
	cout << endl;
	return 0;
}