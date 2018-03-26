#include <iostream>
using namespace std;
struct Range {
	long a, b;
};
template<typename T>
class Vector {
private:
	unsigned capacity, size;
	T* elem;
public:
	Vector() {
		capacity = 3;
		size = 0;
		elem = new T[capacity];
	}
	Vector(unsigned n) {
		capacity = n;
		size = n;
		elem = new T[capacity];
	}
	~Vector() {
		delete[] elem;
		elem = NULL;
	}
	T& operator[](unsigned i) {
		return elem[i];
	}
	unsigned upper_bound(unsigned lo, unsigned hi, T const& value) {
		while (lo < hi) {
			unsigned mi = (lo + hi) >> 1;
			if (value < elem[mi]) {
				hi = mi;
			}
			else {
				lo = mi + 1;
			}
		}
		return lo;
	}
	unsigned lower_bound(unsigned lo, unsigned hi, T const& value) {
		while (lo < hi) {
			unsigned mi = (lo + hi) >> 1;
			if (value <= elem[mi]) {
				hi = mi;
			}
			else {
				lo = mi + 1;
			}
		}
		return lo;
	}
	void sort(unsigned lo, unsigned hi) {
		if ((hi - lo) < 2)return;
		T e = elem[lo];
		unsigned i = lo + 1;
		unsigned j = hi - 1;
		while (i < j) {
			while (elem[i] < e && i < j)i++;
			while (e <= elem[j] && i < j)j--;
			elem[lo] = elem[j];
			elem[j] = elem[i];
			elem[i] = elem[lo];
		}
		if (e < elem[i])i--;

		elem[lo] = elem[i];
		elem[i] = e;
		sort(lo, i);
		sort(i + 1, hi);
	}
};

int main() {
	unsigned n, m;
	cin >> n >> m;
	Vector<long> points(n);
	Vector<Range> ranges(m);
	for (unsigned i = 0; i < n; i++) {
		cin >> points[i];
	}
	for (unsigned i = 0; i < m; i++) {
		cin >> ranges[i].a >> ranges[i].b;
	}
	points.sort(0, n);
	for (unsigned i = 0; i < m; i++) {
		unsigned j, k;
		j = points.lower_bound(0, n, ranges[i].a);
		k = points.upper_bound(j, n, ranges[i].b);
		cout << k - j << endl;
	}
}