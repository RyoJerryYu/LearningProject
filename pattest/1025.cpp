#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
struct listnode {
	int data, next;
};
int pro1025() {
	int first, n, k;
	listnode thelist[100002];
	cin >> first >> n >> k;
	int addri;
	for (int i = 0; i<n; i++) {
		cin >> addri;
		cin >> thelist[addri].data >> thelist[addri].next;
	}
	int count = 0;
	vector<int> addr(n + 1, -1);
	addr[0] = first;
	while (addr[count] != -1) {
		count++;
		addr[count] = thelist[addr[count - 1]].next;
	}
	for (int i = 0; i + k <= count; i += k) {
		reverse(addr.begin() + i, addr.begin() + i + k);
	}
	for (int i = 0; i<count - 1; i++) {
		thelist[addr[i]].next = addr[i + 1];
		printf("%05d %d %05d\n", addr[i], thelist[addr[i]].data, thelist[addr[i]].next);
	}
	thelist[addr[count - 1]].next = -1;
	printf("%05d %d -1", addr[count - 1], thelist[addr[count - 1]].data);
	return 0;
}