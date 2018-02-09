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
	/*内部函数*/;
	//void expand();

public:
	/*构造函数*/;
	MyVector() :_size(0), _capacity(DEFAULT_CAPACITY) {
		_elem = new T*[_capacity];
	}
	MyVector(int size):_size(size) {
		_capacity 2 * _size;
		_elem = new T*[_capacity];
	}
	//MyVector(MyVector);
	
	/*析构函数*/;
	~MyVector() {
		delete[] _elem;
	}
	
	/*只读接口*/;
	//int size();
	//T get(Rank);
	//Rank find(T);
	//Rank search(T);

	/*可写接口*/;
	//T put(Rank, T);
	//T insert(Rank, T);
	//T remove(Rank);
	//int disordered();
	//void sort();
	//void deduplicate();
	//void uniquify();

	/*遍历接口*/;
	//T traverse();

	/*重载操作符*/
	
	T& operator[](Rank r=_size) const {
		return _elem[r];
	}
}

#endif //MY_VECTOR
