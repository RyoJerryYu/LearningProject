#include <iostream>
#include <iomanip>
using namespace std;
void printsand(int, char);
int pro1027() {
	int n, sum = 1, flr = 0;
	char a;
	cin >> n >> a;
	if (n == 0) { cout << n << endl; return 0; }
	while (sum <= n) {
		flr++;
		sum += 4 * flr + 2;
	}
	sum -= 4 * flr + 2;
	printsand(flr, a);
	cout << n - sum << endl;
	return 0;
}
void printsand(int flr, char a) {
	for (int i = 0; i < flr; i++) {
		if (i != 0)cout << setfill(' ') << setw(i) << " ";//setw参数不能为0（为0时至少输出一个空格
		cout << setfill(a) << setw(flr + flr - i - i - 1) << a << endl;//setfill参数不能为长度1的字符串只能为char
	}
	for (int i = 1; i < flr; i++) {
		if (i != flr - 1)cout << setfill(' ') << setw(flr - i - 1) << " ";
		cout << setfill(a) << setw(i + i + 1) << a << endl;
	}
}