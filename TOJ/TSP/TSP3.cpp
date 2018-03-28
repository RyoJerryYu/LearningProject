#include <iostream>
using namespace std;

class boolpool {
	unsigned* pool;
	long size;
	long num;
public:
	boolpool() :num(0) {
		size = 0 / sizeof(unsigned) + 1;
		pool = new unsigned[size] {0};
	}
	boolpool(long n) :num(n) {
		size = n / sizeof(unsigned) + 1;
		pool = new unsigned[size] {0};
	}
	~boolpool() {
		delete[] pool;
	}
	void operator=(boolpool&& other) {
		size = other.size;
		num = other.num;
		pool = new unsigned[size];
		for (long i = 0; i < size; i++) {
			pool[i] = other.pool[i];
		}
	}
	bool get(long n) {
		long a = n / sizeof(unsigned);
		unsigned b =1<<(n % sizeof(unsigned));
		return pool[a] & b;
	}
	void put(long n, unsigned value) {
		long a = n / sizeof(unsigned);
		value = (value % 2) << (n % sizeof(unsigned));
		pool[a] ^= value;
	}
};

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } vstatus;
struct vertex {
	long length = 1;
	vstatus status = UNDISCOVERED;
	long parent = -1;
};
class Graph {
	vertex* V;
	boolpool* E;
	long n;
public:
	Graph() :n(1) {
		V = new vertex[1];
		E = new boolpool[1];
		E[1] = boolpool(1);
	}
	Graph(long num) : n(num) {
		V = new vertex[n];
		E = new boolpool[n];
		for (long i = 0; i < n; i++) {
			E[i] = boolpool(n);
		}
	}
	~Graph() {
		delete[] E;
		delete[] V;
	}
	bool getedge(long i, long j) {
		return E[i].get(j);
	}
	void putedge(long i, long j, unsigned v) {
		E[i].put(j, v);
	}
	long nexChild(long v, long p) {
		p--;
		while (-1 < p && !getedge(v,p)) p--;
		return p;
	}
	long fstChild(long v) {
		return nexChild(v, n);
	}
	void diveAlongLB(long p, long v, long* const& S, long& top) {
		while (-1 < v) {
			V[v].status = DISCOVERED;
			V[v].parent = p;
			S[top++] = v;
			p = v;
			v = fstChild(p);
			while (-1 < v && V[v].status != UNDISCOVERED) {
				v = nexChild(p, v);
			}
		}
	}
	long DFS(long v, long* const& S, long& top) {
		diveAlongLB(-1, v, S, top);
		while (0 < top) {
			v = S[--top];
			for (long c = fstChild(v); -1 < c; c = nexChild(v, c)) {
				if (V[c].status == VISITED && V[v].length < V[c].length + 1) {
					V[v].length = V[c].length + 1;
				}
			}
			V[v].status = VISITED;
			if (V[v].parent != -1) {
				long p = V[v].parent;
				v = nexChild(p, v);
				while (-1 < v && V[v].status != UNDISCOVERED) {
					v = nexChild(p, v);
				}
				diveAlongLB(p, v, S, top);
			}
		}
		return V[v].length;
	}
	long dfs() {
		long maxl = 0;
		long length;
		long* S = new long[n];
		long top = 0;
		for (long v = 0; v < n; v++) {
			if (V[v].status == UNDISCOVERED) {
				length = DFS(v, S, top);
				if (length > maxl)maxl = length;
			}
		}
		return maxl;
	}
};

int main() {
	long n, m;
	cin >> n >> m;
	Graph G(n);
	long j, k;
	for (long i = 0; i < m; i++) {
		cin >> j >> k;
		G.putedge(j - 1, k - 1, 1);
	}
	cout << G.dfs() << endl;
	return 0;
}