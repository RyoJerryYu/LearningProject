#include <iostream>
#include "head.h"
using namespace std;
int pro1007() {
	char A[1001] = { 0 }, Q[1001] = { 0 };
	int B = 0, R = 0;
	int i = 0, j = 0;
	cin >> A >> B;
	if ((A[0] - '0') / B == 0) {
		R = A[0] - '0'; i++;
	}
	else {
		Q[0] = (A[0] - '0') / B + '0'; R = (A[0] - '0') % B; i++; j++;
	}
	while (A[i]) {
		R = R * 10 + A[i] - '0';
		Q[j] = R / B + '0';
		R %= B;
		i++; j++;
	}
	i = 0, j = 0;
	cout << Q << " " << R << endl;
	return 0;
}