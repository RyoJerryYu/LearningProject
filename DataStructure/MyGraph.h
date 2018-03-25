#ifndef MY_GRAPH_H
#define MY_GRAPH_H

#include <iostream>
#include "MyVector.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "functor.h"
using namespace std;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
template <typename Tv> struct MyVertex {
	Tv data;
	int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	int parent;
	int priority;
	MyVertex() :data(NULL) {};
	MyVertex(Tv const& t) :
		data(t), inDegree(0), outDegree(0), 
		status(UNDISCOVERED), 
		dTime(-1), fTime(-1), 
		parent(-1), priority(INT_MAX) {};
};

typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EStatus;
template <typename Te> struct MyEdge {
	Te data;
	int weight;
	EStatus status;
	MyEdge(Te const& t, int w) :
		data(t), weight(w), 
		status(UNDETERMINED) {};
};

template <typename Tv, typename Te> class MyGraph {
protected:
	virtual void reset() {
		for (int i = 0; i < n; i++) {
			status(i) = UNDISCOVERED;
			dTime(i) = -1, fTime(i) = -1;
			parent(i) = -1, priority(i) = INT_MAX;
			for (int j = 0; j < n; j++) {
				if (exists(i, j))status(i, j) = UNDETERMINED;
			}
		}
	}
	int n, e;
public:
	virtual ~MyGraph() {};
	/*顶点操作*/
	virtual Tv& vertex(int i) = 0;
	virtual int inDegree(int i) = 0;
	virtual int outDegree(int i) = 0;
	virtual VStatus& status(int i) = 0;
	virtual int& dTime(int i) = 0;
	virtual int& fTime(int i) = 0;
	virtual int& parent(int i) = 0;
	virtual int& priority(int i) = 0;
	
	/*边操作*/
	virtual bool exists(int i, int j) = 0;
	virtual Te& edge(int i, int j) = 0;
	virtual int& weight(int i, int j) = 0;
	virtual EStatus& status(int i, int j) = 0;
};

template <typename Tv, typename Te>class MyGraphMatrix :public MyGraph<Tv,Te> {
private:
	MyVector<MyVertex<Tv> > V;
	MyVector<MyVector<MyEdge<Te>* > > E;
public:
	MyGraphMatrix() { this->n = this->e = 0; };
	~MyGraphMatrix() {
		for (int j = 0; j < this->n; j++) 
			for (int k = 0; k < this->n; k++) {
				delete E[j][k];
			}
	}
	

	/*顶点操作*/
	Tv& vertex(int i) { return V[i].data; };
	int inDegree(int i) { return V[i].inDegree; };
	int outDegree(int i) { return V[i].outDegree; };
	VStatus & status(int i) { return V[i].status; };
	int& dTime(int i) { return V[i].dTime; };
	int& fTime(int i) { return V[i].fTime; };
	int& parent(int i) { return V[i].parent; };
	int& priority(int i) { return V[i].priority; };

	int nextNbr(int i, int j);
	int firstNbr(int i) { return nextNbr(i, this->n); };

	void insert(Tv const& vertex);
	Tv remove(int i);


	/*边操作*/
	bool exists(int i, int j);
	Te& edge(int i, int j) { return E[i][j]->data; };
	int& weight(int i, int j) { return E[i][j]->weight; };
	EStatus& status(int i, int j) { return E[i][j]->status; };

	void insert(Te const& edge, int weight, int i, int j);
	Te remove(int i, int j);


	/*遍历*/
	template <typename VST>
	void BFS(int v, int& clock, VST&visit);
	template <typename VST>
	void bfs(VST&& visit);
	template <typename VST>
	void DFS(int v, int& clock, VST&visit);
	template <typename VST>
	void dfs(VST&& visit);
};


/*********Functions of Vertex*********/
template<typename Tv,typename Te>
int MyGraphMatrix<Tv, Te>::nextNbr(int i, int j) {
	while ((-1 < j) && !exists(i, --j));
	return j;
}

template <typename Tv,typename Te>
void MyGraphMatrix<Tv, Te>::insert(Tv const& vertex) {
	V.insert(this->n, vertex);
	for (int i = 0; i < this->n; i++)E[i].insert(this->n, NULL);
	E.insert(this->n, MyVector<MyEdge<Te>*>(this->n + 1, NULL));
	this->n++;
}

template <typename Tv,typename Te>
Tv MyGraphMatrix<Tv, Te>::remove(int i) {
	for (int j = 0; j < this->n; j++) {
		if(exists(i, j)) {
			delete E[i][j];
			inDegree(j)--;
		}
	}
	E.remove(i);
	for (int j = 0; j < this->n; j++) {
		if (exists(j, i)) {
			delete E[j][i];
			outDegree(j)--;
		}
		E[j].remove(i);
	}
	this->n--;
	Tv tv = vertex(i);
	V.remove(i);
	return tv;
}


/*********Functions of Edge*********/
template <typename Tv,typename Te>
bool MyGraphMatrix<Tv, Te>::exists(int i, int j) {
	return (0 <= i && i < this->n && 0 <= j && j < this->n && E[i][j] != NULL);
}

template <typename Tv,typename Te>
void MyGraphMatrix<Tv, Te>::insert(Te const& edge, int weight, int i, int j) {
	if (exists(i, j))return;
	E[i][j] = new MyEdge<Te>(edge, weight);
	this->e++;
	V[i].outDegree++;
	V[j].inDegree++;
}

template <typename Tv,typename Te>
Te MyGraphMatrix<Tv, Te>::remove(int i, int j) {
	if (!exists(i, j))return NULL;
	Te te = edge(i, j);
	delete E[i][j];
	E[i][j] = NULL;
	e--;
	V[i].outDegree--;
	V[j].inDegree--;
	return te;
}


/*********traverse********/
template <typename Tv,typename Te>
template <typename VST>
void MyGraphMatrix<Tv, Te>::BFS(int v, int& clock, VST& visit) {
	MyQueue<int> Q;
	Q.enqueue(v);
	status(v) = DISCOVERED;
	while (!Q.empty()) {
		v = Q.dequeue();
		dTime(v) = clock++;
		visit(V[v].data);
		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
			if (status(u) == UNDISCOVERED) {
				Q.enqueue(u);
				status(u) = DISCOVERED;
				parent(u) = v;
				status(v, u) = TREE;
			}
			else {
				status(v, u) = CROSS;
			}
		}
		status(v) = VISITED;
	}
}

template <typename Tv,typename Te>
template <typename VST>
void MyGraphMatrix<Tv, Te>::bfs(VST&& visit) {
	this->reset();
	int clock = 0;
	for (int v = 0; v < this->n; v++) {
		if (status(v) == UNDISCOVERED) {
			BFS(v, clock, visit);
		}
	}
}

template <typename Tv,typename Te>
void travBFS(MyGraphMatrix<Tv, Te>& graph) {
	graph.bfs(Show<Tv>());
}

template <typename Tv,typename Te>
template <typename VST>
void MyGraphMatrix<Tv, Te>::DFS(int v, int& clock, VST& visit) {
	dTime(v) = clock++;
	status(v) = DISCOVERED;
	visit(V(v).data);
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
		switch (status(u)) {
		case UNDISCOVERED:
			status(v, u) = TREE;
			parent(u) = v;
			DFS(u, clock, visit);
			break;
		case DISCOVERED:
			status(v, u) = BACKWARD;
			break;
		default:
			status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
			break;
		}
	}
	status(v) = VISITED;
	fTime(v) = clock++;
}

template <typename Tv,typename Te>
template <typename VST>
void MyGraphMatrix<Tv, Te>::dfs(VST&& visit) {
	this->reset();
	int clock = 0;
	for (int v = 0; v < this->n; v++) {
		if (status(v) == UNDISCOVERED) {
			BFS(v, clock, visit);
		}
	}
}

template <typename Tv,typename Te>
void travDFS(MyGraphMatrix<Tv, Te>& graph) {
	graph.dfs(Show<Tv>());
}


/*testFunction*/
int GraphFunctions();

#endif //MY_GRAPH_H