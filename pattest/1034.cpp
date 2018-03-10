#include <iostream>
#include <string>
using namespace std;
struct num1024 {
	int up, down;
	void shrink() {
		if (up == 0)return;
		if (down < 0) {
			up = -up;
			down = -down;
		}
		bool plus = true;
		if (up < 0) {
			plus = false;
			up = -up;
		}
		int bigg = up > down ? up : down;
		int small = up > down ? down : up;
		int r = 0;
		while (r = bigg % small) {
			bigg = small;
			small = r;
		}
		up /= small;
		down /= small;
		if (plus == false)up = -up;
	}
	friend istream& operator>>(istream&, num1024&);
	friend ostream& operator<<(ostream&, num1024);
	num1024 operator+(const num1024& other) {
		num1024 out;
		out.down = down * other.down;
		out.up = up * other.down + other.up*down;
		out.shrink();
		return out;
	}
	num1024 operator-(const num1024& other) {
		num1024 out;
		out.down = down * other.down;
		out.up = up * other.down - other.up*down;
		out.shrink();
		return out;
	}
	num1024 operator*(const num1024& other) {
		num1024 out;
		out.down = down * other.down;
		out.up = up * other.up;
		out.shrink();
		return out;
	}
	num1024 operator/(const num1024& other) {
		num1024 out;
		out.up = up * other.down;
		out.down = down * other.up;
		out.shrink();
		return out;
	}
};
int pro1034() {
	num1024 a, b;
	cin >> a >> b;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	if (b.up == 0) {
		cout << a << " / " << b << " = Inf" << endl;
	}
	else {
		cout << a << " / " << b << " = " << a / b << endl;
	}
	return 0;
}
istream& operator>>(istream& inst, num1024& it) {
	char n;
	inst >> it.up >> n >> it.down;
	return inst;
}
ostream& operator<<(ostream&oust, num1024 it) {
	if (it.up == 0) {
		oust << 0; return oust;
	}
	it.shrink();
	int inter = 0, outup, outdown;
	bool plus = true;
	if (it.up < 0) {
		plus = false;
		it.up = -it.up;
	}
	outdown = it.down;
	inter = it.up / it.down;
	outup = it.up % it.down;
	if (plus == false)oust << "(-";
	if (inter == 0)oust << outup << "/" << outdown;
	else if (outup == 0)oust << inter;
	else oust << inter << ' ' << outup << "/" << outdown;
	if (plus == false)oust << ")";
	return oust;
}