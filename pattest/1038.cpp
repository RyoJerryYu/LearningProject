#include <iostream>
#include <vector>
using namespace std;
int pro1038() {
	int numofgrad[101] = { 0 };
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int grad;
		cin >> grad;
		numofgrad[grad]++;
	}
	cin >> k;
	vector<int> searchgrad(k, 0);
	for (int&x : searchgrad) {
		cin >> x;
	}
	for (int i = 0; i < k - 1; i++) {
		cout << numofgrad[searchgrad[i]] << ' ';
	}
	cout << numofgrad[searchgrad[k - 1]] << endl;
	return 0;
}