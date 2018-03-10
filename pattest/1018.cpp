#include <iostream>
using namespace std;
const char give[3] = { 'B','C','J' }; const int compair[3][3] = { { 0,1,-1 },{ -1,0,1 },{ 1,-1,0 } };
class player {
	int nwin = 0, npeace = 0, nlose = 0, win[3] = { 0 };
public:
	int use;
	void compairwith(player & other) {
		if (compair[use][other.use] == 0) { npeace++; other.npeace++; return; }
		if (compair[use][other.use] == 1) { nwin++; other.nlose++; win[use]++; return; }
		if (compair[use][other.use] == -1) { nlose++; other.nwin++; other.win[other.use]++; return; }
	}
	void output()const { cout << nwin << " " << npeace << " " << nlose << endl; }
	char winmax()const {
		int n = 0, max = 0;
		for (int i = 0; i<3; i++) { if (win[i]>max) { n = i; max = win[i]; } }
		return give[n];
	}
};
int pro1018() {
	player A, B; int N = 0; char Ause, Buse;
	cin >> N;
	for (int i = 0; i<N; i++) {
		cin >> Ause >> Buse;
		for (int j = 0; j<3; j++) {
			if (Ause == give[j]) { A.use = j; }
			if (Buse == give[j]) { B.use = j; }
		}
		A.compairwith(B);
	}
	A.output();
	B.output();
	cout << A.winmax() << " " << B.winmax() << endl;
	return 0;
}