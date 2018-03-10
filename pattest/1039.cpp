#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int pro1039() {
	string input, want;
	cin >> input >> want;
	sort(input.begin(), input.end());
	sort(want.begin(), want.end());
	auto inp = input.begin();
	auto wanp = want.begin();
	string minus = "";
	while (inp != input.end()) {
		if (*inp == *wanp)inp++, wanp++;
		else if (*inp < *wanp)inp++;
		else {
			minus += *wanp;
			wanp++;
		}
		if (wanp == want.end())break;
	}
	while (wanp != want.end()) {

		minus += *wanp;
		wanp++;
	}
	if (minus.size() != 0)cout << "No " << minus.size() << endl;
	else cout << "Yes " << input.size() - want.size() << endl;
	return 0;
}