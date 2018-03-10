#include <iostream>
#include <iomanip>
using namespace std;
int pro1026() {
	long c1, c2, deltat;
	int s, m, h;
	cin >> c1 >> c2;
	deltat = (c2 - c1 + 50) / 100;
	s = int(deltat % 60);
	deltat /= 60;
	m = int(deltat % 60);
	deltat /= 60;
	h = int(deltat);
	cout << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << endl;
	return 0;
}