#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int search(const vector<long> & num, const long & value) {
int lo = 0, hi = num.size();
while (hi != lo) {
int mi = (lo + hi) >> 1;
if (value < num[mi]) hi = mi;
else lo = mi + 1;
}
return lo - 1;
}*/
int pro1030() {
	int N;
	long p;
	cin >> N >> p;
	vector<long> num(N);
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num.begin(), num.end());
	int q = 1;//p是正整数，至少有一个
	for (int i = 0; i < N; i++) {
		long long max = (long long)num[i] * p;
		//int maxi = search(num, max) + 1;//指向第一个大于max的位置
		int maxi = int(upper_bound(num.begin() + i, num.end(), max) - num.begin());//从i开始查找而不是从0开始
		if (maxi - i > q)q = maxi - i;//使得maxi-i为完美序列中数的个数
	}
	cout << q;
	return 0;
}