#include <iostream>
using namespace std;

template <typename T>
struct Listnode {
	T data;
	Listnode* pre;
	Listnode* nex;
	Listnode() {};
	Listnode(T const& t, Listnode* p = NULL, Listnode* n = NULL) :data(t), pre(p), nex(n) {};
};

template <typename T>
class List {
	Listnode<T>* header;
	Listnode<T>* trailer;
	unsigned size;
public:
	List() {
		header = new Listnode<T>;
		trailer = new Listnode<T>;
		header->nex = trailer;
		trailer->pre = header;
		size = 0;
	}
	Listnode<T>* gethead() { return header; }
	Listnode<T>* gettrail() { return trailer; }
	unsigned getsize() { return size; }
	Listnode<T>* insertAsLast(T const& t) {
		size++;
		Listnode<T>* p = new Listnode<T>(t, trailer->pre, trailer);
		trailer->pre->nex = p;
		trailer->pre = p;
		return p;
	}
	Listnode<T>* insertAt(unsigned n, T const& t) {
		size++;
		Listnode<T>* q = header;
		while (n-- > 0) {
			q = q->nex;
		}
		Listnode<T>* p = new Listnode<T>(t, q, q->nex);
		q->nex->pre = p;
		q->nex = p;
		return p;
	}
	T remove(Listnode<T>* posi) {
		size--;
		T buff = posi->data;
		posi->pre->nex = posi->nex;
		posi->nex->pre = posi->pre;
		delete posi;
		return buff;
	}
	void show() {
		if (size == 0) {
			cout << '-';
			return;
		}
		Listnode<T>* p = header->nex;
		while (p != trailer) {
			cout << p->data;
			p = p->nex;
		}
	}
};

int main() {
	List<char> seq;
	char c;
	unsigned n;
	unsigned posi;
	char color;
	Listnode<char>* hot;
	Listnode<char>* frontp;
	Listnode<char>* backp;
	int count;
	while ((c = cin.get()) != '\n') {
		seq.insertAsLast(c);
	}
	cin >> n;
	for (unsigned i = 0; i < n; i++) {
		cin >> posi >> color;
		hot = seq.insertAt(posi, color);
		do {
			count = 0;
			frontp = hot->pre;
			while (frontp != seq.gethead() && frontp->data == hot->data) {
				frontp = frontp->pre;
			}
			backp = frontp->nex;
			while (backp != seq.gettrail() && backp->data == hot->data) {
				count++;
				backp = backp->nex;
			}
			if (count >= 3) {
				while (frontp->nex != backp) {
					seq.remove(frontp->nex);
				}
			}
			hot = frontp;
		} while (count >= 3 && hot != seq.gethead());
		seq.show();
		cout << endl;
	}
}