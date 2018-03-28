#include <iostream>
using namespace std;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } vstatus;
struct vertex {
	long length = 1;
	vstatus status = UNDISCOVERED;
	long from = -1;
};
class Graph {
	vertex* V;
	int* E;
	long n;
	long m;
public:
	Graph() :n(1),m(1) {
		V = new vertex[1];
		E = new int[1];
	}
	Graph(long num,long edg) : n(num),m(edg) {
		V = new vertex[n];
		E = new int[n*m]{ 0 };
	}
	~Graph() {
		delete[] E;
		delete[] V;
	}
	void inputedg(long edg, long in, long out) {
		E[in*m + edg] = 1;
		E[out*m + edg] = -1;
	}
	bool existedg(long in, long out) {
		for (long i = 0; i < m; i++) {
			if (E[in*m + i] == 1 && E[out*m + i] == -1)return true;
		}
		return false;
	}
	long childof(long edg) {
		if (edg == -1)return -1;
		long p = n - 1;
		while (-1<p && E[p*m + edg] != -1)p--;
		return p;
	}
	long parentof(long edg) {
		if (edg == -1)return -1;
		long p = n - 1;
		while (-1 < p&&E[p*m + edg] != 1)p--;
		return p;
	}
	long nexEdg(long v, long edg) {
		edg--;
		while (-1 < edg && E[v*m + edg] != 1)edg--;
		return edg;
	}
	long fstEdg(long v) {
		return nexEdg(v, m);
	}
	void diveAlongLB(long edg, long v, long* const& S, long& top) {
		long p;
		while (-1 < v) {
			V[v].status = DISCOVERED;
			V[v].from = edg;
			S[top++] = v;
			p = v;
			edg = fstEdg(p);
			v = childof(edg);
			while (-1 < v && V[v].status != UNDISCOVERED) {
				edg = nexEdg(p, edg);
				v = childof(edg);
			}
		}
	}
	long DFS(long v, long* const& S, long& top) {
		diveAlongLB(-1, v, S, top);
		while (0 < top) {
			v = S[--top];
			for (long edg = fstEdg(v); -1 < edg; edg = nexEdg(v, edg)) {
				long c = childof(edg);
				if (V[c].status == VISITED && V[v].length < V[c].length + 1) {
					V[v].length = V[c].length + 1;
				}
			}
			V[v].status = VISITED;
			if (V[v].from != -1) {
				long edg = V[v].from;
				long p = parentof(edg);
				edg = nexEdg(p, edg);
				v = childof(edg);
				while (-1 < v && V[v].status != UNDISCOVERED) {
					edg = nexEdg(p, edg);
					v = childof(edg);
				}
				diveAlongLB(edg, v, S, top);
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
	Graph G(n, m);
	long j, k;
	for (long i = 0; i < m; i++) {
		cin >> j >> k;
		G.inputedg(i, j - 1, k - 1);
	}
	cout << G.dfs() << endl;
	return 0;
}