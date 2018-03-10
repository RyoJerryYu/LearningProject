#include <iostream>
#include <string>
using namespace std;
int pro1029() {
	string oris, ress, difs = "";
	bool hash[256] = { false };
	cin >> oris >> ress;
	for (char x : ress)hash[toupper(x)] = true;
	for (char& x : oris) {
		x = toupper(x);
		if (hash[x] == false) { difs += x; hash[x] = true; }
	}
	cout << difs << endl;
	return 0;
}