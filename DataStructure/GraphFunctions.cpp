#include "MyGraph.h"
using namespace std;

int GraphFunctions() {
	MyGraphMatrix<char, char> Graph1;
	Graph1.insert('a');
	Graph1.insert('b');
	Graph1.insert('c');
	Graph1.insert('A', 1, 0, 1);
	Graph1.insert('B', 1, 1, 2);
	Graph1.insert('C', 2, 0, 2);
	return 0;
}