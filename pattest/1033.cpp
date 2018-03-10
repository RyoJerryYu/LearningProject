#include <iostream>
#include <string>
using namespace std;
bool brokey[128] = { false };
int pro1033() {
	string brostr, instr, outstr = "";
	cin >> brostr >> instr;
	for (char x : brostr) {
		if (x == '+') {
			for (int i = 'A'; i <= 'Z'; i++)brokey[i] = true;
		}
		else {
			brokey[x] = true;
			brokey[tolower(x)] = true;
		}
	}
	for (char x : instr) {
		if (!brokey[x])outstr += x;
	}
	cout << outstr << endl;
	return 0;
}