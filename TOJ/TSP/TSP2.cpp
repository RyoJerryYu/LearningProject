#include <iostream>
using namespace std;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } vstatus;
struct vertex {
	long length = 1;
	vstatus status = UNDISCOVERED;
	long parent = -1;
};
class Graph {
	vertex* V;
	bool** E;
	long n;
public:
	Graph() :n(1) {
		V = new vertex[1];
		E = new bool*[1];
		for (int i = 0; i < 1; i++) {
			E[i] = new bool[1];
		}
	}
	Graph(long num): n(num) {
		V = new vertex[n];
		E = new bool*[n];
		for (long i = 0; i < n; i++) {
			E[i] = new bool[n] {false};
		}
	}
	~Graph() {
		for (long i = 0; i < n; i++) {
			delete[] E[i];
		}
		delete[] E;
		delete[] V;
	}
	bool& edge(long i, long j) {
		return E[i - 1][j - 1];
	}
	long nexChild(long v, long p) {
		p--;
		while (-1 < p && !E[v][p]) p--;
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
	long DFS(long v,long* const& S,long& top) {
		diveAlongLB(-1, v, S, top);
		while (0 < top) {
			v = S[--top];
			for (long c = fstChild(v); -1 < c; c = nexChild(v, c)) {
				if (V[c].status == VISITED && V[v].length < V[c].length+1) {
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
		G.edge(j, k) = true;
	}
	cout << G.dfs() << endl;
	return 0;
}