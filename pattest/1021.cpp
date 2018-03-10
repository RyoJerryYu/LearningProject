#include <iostream>
#include <string>
using namespace std;
int pro1011() {
	int d[10] = { 0 };
	string N;
	cin >> N;
	for (const auto& n : N) {
		d[(n - '0') % 10]++;
	}
	for (int i = 0; i < 10; i++) {
		if (d[i] != 0) cout << i << ":" << d[i] << endl;
	}
	return 0;
}