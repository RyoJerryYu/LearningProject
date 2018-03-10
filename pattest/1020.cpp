#include <iostream>
#include <stdio.h>
using namespace std;
int pro1020() {
	int N = 0, need = 0, *storage = 0, *price = 0, soldnum = 0;
	float *per = 0, soldprice = 0;
	cin >> N >> need;
	storage = new int[N], price = new int[N], per = new float[N];
	for (int i = 0; i < N; i++) {
		cin >> storage[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
		per[i] = float(price[i]) / storage[i];
	}
	int k = 0;
	for (int i = N - 1; i > 0; i--) {//bubble sort
		for (int j = 0; j < i; j++) {
			if (per[j] < per[j + 1]) {
				int m = storage[j]; storage[j] = storage[j + 1]; storage[j + 1] = m;
				m = price[j]; price[j] = price[j + 1]; price[j + 1] = m;
				float l = per[j]; per[j] = per[j + 1]; per[j + 1] = l;
				k = j + 2;
			}
		}
		i = k; k = 0;
	}
	k = 0;
	while (soldnum < need) {
		soldnum += storage[k]; soldprice += price[k];
		k++;
	}
	int n = soldnum - need; k--;
	soldprice -= per[k] * n;
	printf("%.2f", soldprice);
	delete[] storage, price, per;
	return 0;
}