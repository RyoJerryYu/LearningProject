#ifndef MY_GRAPH_H
#define MY_GRAPH_H

#include <iostream>
#include "MyVector.h"
using namespace std;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
template <typename Tv> struct MyVertex {
	Tv data;
	int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	int parent;
	int priority;
	MyVertex(Tv const& t) :
		data(t), inDegree(0), outDegree(0), 
		status(UNDISCOVERD), 
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

	int nexNbr(int i, int j);
	int firstNbr(int i) { return nextNbr(i, n); };

	void insert(Tv const& vertex);
	Tv remove(int i);


	/*边操作*/
	bool exists(int i, int j);
	Te& edge(int i, int j) { return E[i][j]->data; };
	int& weight(int i, int j) { return E[i][j]->weight; };
	EStatus& status(int i, int j) { return E[i][j]->status; };

	void insert(Te const& edge, int weight, int i, int j);
	Te remove(int i, int j);
};


/*********Functions of Vertex*********/
template<typename Tv,typename Te>
int MyGraphMatrix<Tv, Te>::nexNbr(int i, int j) {
	while ((-1 < j) && !exist(i, --j));
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
	for (int j = 0; j < n; j++) {
		if(exists(i, j)) {
			delete E[i][j];
			inDegree(j)--;
		}
	}
	E.remove(i); n--;
	for (int j = 0; j < n; j++) {
		if (exists(j, i)) {
			delete E[j][i];
			outDegree(j)--;
		}
		E[j].remove(i);
	}
	Tv tv = vertex(i);
	V.remove(i);
	return tv;
}


/*********Functions of Edge*********/
template <typename Tv,typename Te>
bool MyGraphMatrix<Tv, Te>::exists(int i, int j) {
	return (0 <= i && i < n && 0 <= j && j < n && E[i][j] != NULL);
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


/*testFunction*/
int GraphFunctions();

#endif //MY_GRAPH_H