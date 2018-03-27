#include <iostream>
using namespace std;

struct lighthouse {
	long x, y;
};
class Vectorlh {
	long capacity;
	long size;
	lighthouse* elem;
public:
	Vectorlh() {
		capacity = 3;
		size = 0;
		elem = new lighthouse[capacity];
	}
	Vectorlh(long n) {
		capacity = n + 1;
		size = n;
		elem = new lighthouse[capacity];
	}
	~Vectorlh() {
		delete[] elem;
	}
	lighthouse& operator[](long i) {
		return elem[i];
	}
	void mergex(long lo, long mi, long hi) {
		lighthouse* buff = new lighthouse[mi - lo];
		long i, j, k;
		for (i = lo; i < mi; i++) {
			buff[i - lo] = elem[i];
		}
		i = lo, j = 0, k = mi;
		while (j < mi - lo && k < hi) {
			if (buff[j].x <= elem[k].x)elem[i++] = buff[j++];
			else elem[i++] = elem[k++];
		}
		while (j < mi - lo) {
			elem[i++] = buff[j++];
		}
		delete[] buff;
	}
	void mergesortx(long lo,long hi) {
		if (hi - lo < 2)return;
		long mi = (lo + hi) >> 1;
		mergesortx(lo, mi);
		mergesortx(mi, hi);
		mergex(lo, mi, hi);
	}
	long invBetween(long lo, long mi, long hi) {
		lighthouse* buff = new lighthouse[mi - lo];
		long count = 0;
		long i, j, k;
		for (i = lo; i < mi; i++) {
			buff[i - lo] = elem[i];
		}
		i = lo, j = 0, k = mi;
		while (j < mi - lo && k < hi) {
			if (buff[j].y <= elem[k].y) {
				elem[i++] = buff[j++];
				count += hi - k;
			}
			else elem[i++] = elem[k++];
		}
		while (j < mi - lo) elem[i++] = buff[j++];
		delete[] buff;
		return count;
	}
	long invIn(long lo, long hi) {
		if (hi - lo < 2) return 0;
		long i, j, k;
		long mi = (lo + hi) >> 1;
		i = invIn(lo, mi);
		j = invIn(mi, hi);
		k = invBetween(lo, mi, hi);
		return i + j + k;
	}
};
int main() {
	long n;
	cin >> n;
	Vectorlh lights(n);
	for (long i = 0; i < n; i++) {
		cin >> lights[i].x >> lights[i].y;
	}
	lights.mergesortx(0, n);
	cout << lights.invIn(0, n) << endl;
	return 0;
}