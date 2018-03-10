#include <iostream>
#include <string>
#include <vector>
using namespace std;
const vector<int> weight = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
const vector<char> compair = { '1','0','X','9','8','7','6','5','4','3','2' };
int pro1031() {
	int N;
	cin >> N;
	vector<string> id(N);
	int wgt = 0;
	bool pass = true, allpass = true;
	for (auto& x : id) {
		cin >> x;
		wgt = 0, pass = true;
		for (int i = 0; i < 17; i++) {
			if ('0' <= x[i] && x[i] <= '9') wgt += (x[i] - '0') * weight[i];
			else {
				cout << x << endl;
				pass = false, allpass = false;
				break;
			}
		}
		wgt %= 11;
		if (pass == true && x[17] != compair[wgt]) {
			cout << x << endl;
			pass = false, allpass = false;
		}
	}
	if (allpass)cout << "All passed" << endl;
	return 0;
}