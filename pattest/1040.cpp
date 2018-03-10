#include <iostream>
#include <string>
using namespace std;
const int MOD = 1000000007;
int pro1040() {
	string a;
	long np = 0, na = 0, nt = 0;
	cin >> a;
	for (char x : a) {
		if (x == 'P')np++;
		if (x == 'A') {
			na += np; na %= MOD;
		}
		if (x == 'T') {
			nt += na; nt %= MOD;
		}
	}
	cout << nt << endl;
	return 0;
}