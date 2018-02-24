#include <iostream>
#include <string>
using namespace std;
int pro1016() {
	string a, b;
	int da, db;
	long pa = 0, pb = 0;
	cin >> a >> da >> b >> db;
	for (unsigned i = 0; i<a.size(); i++) {
		if (a[i] - '0' == da) { pa = pa * 10 + da; }
	}
	for (unsigned i = 0; i<b.size(); i++) {
		if (b[i] - '0' == db) { pb = pb * 10 + db; }
	}
	cout << pa + pb << endl;

	return 0;
}