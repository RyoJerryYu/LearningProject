#include <iostream>
#include <stack>
using namespace std;
int pro1022() {
	long A, B, C;
	int D;
	stack<int> res;
	cin >> A >> B >> D;
	C = A + B;
	if (C == 0) res.push(0);//处理为0情况
	while (C != 0) {
		res.push(C%D);
		C /= D;
	}
	while (!res.empty()) {
		cout << res.top();
		res.pop();
	}
	cout << endl;
	return 0;
}