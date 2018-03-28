#include <iostream>
using namespace std;

struct binnode {
	long data;
	binnode* parent;
	binnode* lchild;
	binnode* rchild;
	binnode(long t = 0, binnode* p = NULL, binnode* l = NULL, binnode* r = NULL) :data(t), parent(p), lchild(l), rchild(r) {};
};
class bintree {
	long size = 0;
public:
	binnode * root = NULL;
	bintree() {};
	bintree(long t) :root(new binnode(t)),size(1) {};
	void maketree(binnode* const& p,
		long* const& preseq, long prelo, long prehi,
		long* const& posseq, long poslo, long poshi) {
		if (prehi - prelo < 2) return;
		p->lchild = new binnode(preseq[prelo], p);
		p->rchild = new binnode(posseq[poshi - 1], p);
		long posp = poshi - 1;
		while (preseq[prelo] != posseq[posp])posp--;
		posp++;
		size += 2;
		maketree(p->lchild, preseq, prelo + 1, prelo + posp - poslo, posseq, poslo, posp - 1);
		maketree(p->rchild, preseq, prelo + posp - poslo + 1, prehi, posseq, posp, poshi - 1);
	}
	void midv(binnode* p) {
		binnode** stack = new binnode*[size];
		long top = 0;
		while (p) {
			stack[top++] = p;
			p = p->lchild;
		}
		while (top != 0) {
			p = stack[--top];
			cout << p->data << ' ';
			p = p->rchild;
			while (p) {
				stack[top++] = p;
				p = p->lchild;
			}
		}
	}
};

int main() {
	long n;
	cin >> n;
	long* preseq = new long[n];
	long* posseq = new long[n];
	for (int i = 0; i < n; i++) {
		cin >> preseq[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> posseq[i];
	}
	bintree tree(preseq[0]);
	tree.maketree(tree.root, preseq, 1, n, posseq, 0, n - 1);
	tree.midv(tree.root);
}