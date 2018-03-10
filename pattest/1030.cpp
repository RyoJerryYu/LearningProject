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
int pro1020() {
	int N;
	long p;
	cin >> N >> p;
	vector<long> num(N);
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num.begin(), num.end());
	int q = 1;//p����������������һ��
	for (int i = 0; i < N; i++) {
		long long max = (long long)num[i] * p;
		//int maxi = search(num, max) + 1;//ָ���һ������max��λ��
		int maxi = upper_bound(num.begin() + i, num.end(), max) - num.begin();//��i��ʼ���Ҷ����Ǵ�0��ʼ
		if (maxi - i > q)q = maxi - i;//ʹ��maxi-iΪ�������������ĸ���
	}
	cout << q;
	return 0;
}