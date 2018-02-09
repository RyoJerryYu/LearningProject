#ifndef MY_VECTOR
#define MY_VECTOR

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class MyVector {
private:
	Rank _size;
	int _capacity;
	T* _elem;

protected:
	/*�ڲ�����*/;
	//void expand();

public:
	/*���캯��*/;
	MyVector() :_size(0), _capacity(DEFAULT_CAPACITY) {
		_elem = new T*[_capacity];
	}
	MyVector(int size):_size(size) {
		_capacity 2 * _size;
		_elem = new T*[_capacity];
	}
	//MyVector(MyVector);
	
	/*��������*/;
	~MyVector() {
		delete[] _elem;
	}
	
	/*ֻ���ӿ�*/;
	//int size();
	//T get(Rank);
	//Rank find(T);
	//Rank search(T);

	/*��д�ӿ�*/;
	//T put(Rank, T);
	//T insert(Rank, T);
	//T remove(Rank);
	//int disordered();
	//void sort();
	//void deduplicate();
	//void uniquify();

	/*�����ӿ�*/;
	//T traverse();

	/*���ز�����*/
	
	T& operator[](Rank r=_size) const {
		return _elem[r];
	}
}

#endif //MY_VECTOR
