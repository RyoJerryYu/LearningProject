#include <iostream>
using namespace std;
struct money {
	long knut = 0;
	friend istream& operator>>(istream&, money&);
	friend ostream& operator<<(ostream&, money);
	money operator-(money& other) {
		money res;
		res.knut = knut - other.knut;
		return res;
	}
};
int pro1037() {
	money p, a;
	cin >> p >> a;
	cout << (a - p) << endl;
	return 0;
}
istream& operator>>(istream& ins, money& it) {
	long galleon;
	int sickle, knut;
	char a, b;
	ins >> galleon >> a >> sickle >> b >> knut;
	it.knut = (galleon * 17 + sickle) * 29 + knut;
	return ins;
}
ostream& operator<<(ostream& outs, money it) {
	long sickle, galleon, knut;
	knut = it.knut;
	bool plus = true;
	if (knut < 0) {
		plus = false;
		knut = -knut;
	}
	sickle = knut / 29;
	knut = knut % 29;
	galleon = sickle / 17;
	sickle = sickle % 17;
	if (plus == false)galleon = -galleon;
	outs << galleon << '.' << sickle << '.' << knut;
	return outs;
}