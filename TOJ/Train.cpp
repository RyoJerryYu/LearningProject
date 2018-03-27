#include <iostream>
using namespace std;

class chainstack {
	long capacity;
	long size;
	long* elem;
public:
	chainstack() {
		capacity = 3;
		size = 0;
		elem = new long[capacity];
	}
	chainstack(long n) {
		capacity = n;
		size = 0;
		elem = new long[capacity];
	}
	~chainstack() {
		delete[] elem;
	}
	long getsize() {
		return size;
	}
	chainstack& push(long n) {
		elem[size] = n;
		size++;
		return *this;
	}
	long& top() {
		return elem[size - 1];
	}
	long pop() {
		size--;
		return elem[size];
	}
};
bool trys(long*& seq, long n, long m, bool*& oper, long& opern) {
	chainstack buff(n);
	long seqi = 0, operi = 0;//pointer to seq, oper;
	long oritop = 1;//the top of origin sequence
	while (seqi < n) {
		if (buff.getsize() > 0) {
			if (seq[seqi] < buff.top())return false;
			if (seq[seqi] == buff.top()) {
				buff.pop();
				oper[operi++] = false;//pop operation
				seqi++;
				continue;
			}
		}
		while (oritop < seq[seqi]) {
			buff.push(oritop++);
			oper[operi++] = true;
		}
		if (buff.getsize() > m)return false;
		oritop++;//buff.push(oritop++).pop();
		oper[operi++] = true;
		oper[operi++] = false;
		seqi++;
		continue;
	}
	opern = operi;//opern is a reference. return times of operation.
	return true;
}

int main() {
	long n, m;
	cin >> n >> m;
	long* seq = new long[n];
	long opern = 2 * n + 1;
	bool* oper = new bool[opern];
	for (long i = 0; i < n; i++) {
		cin >> seq[i];
	}
	if (!trys(seq, n, m, oper, opern)) {
		cout << "No" << endl;
	}
	else {
		for (long i = 0; i < opern; i++) {
			cout << (oper[i] ? "push" : "pop") << endl;
		}
	}
	delete[] seq;
	delete[] oper;
	return 0;
}