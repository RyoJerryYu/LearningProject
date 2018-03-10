#include <iostream>
using namespace std;
int pro1036() {
	int N;
	char c;
	cin >> N >> c;
	int col = (N + 1) / 2;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 || j == 0 || i == col - 1 || j == N - 1)cout << c;
			else cout << ' ';
		}
		cout << endl;
	}
	return 0;
}