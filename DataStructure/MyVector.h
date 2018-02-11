#ifndef MY_VECTOR
#define MY_VECTOR

#include <iostream>

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class MyVector {
private:
	Rank _size;
	int _capacity;
	T* _elem;

protected:
	/*内部函数*/;
	void expand();

public:
	/*构造函数*/;
	MyVector();
	MyVector(int);
	MyVector(int, T);
	MyVector(const T*, Rank, Rank);
	MyVector(const MyVector<T>& A);
	
	
	/*析构函数*/;
	~MyVector();
	
	
	/*只读接口*/;
	int size() const;
	T& get(Rank);
	//Rank find(T);
	//Rank search(T);

	/*可写接口*/;
	T put(Rank, T);
	T insert(Rank, T);
	T insert(Rank, int, T);
	//T remove(Rank);
	//int disordered();
	//void sort();
	//void deduplicate();
	//void uniquify();

	/*遍历接口*/;
	//T traverse();

	/*重载操作符*/
	T& operator[](Rank r) const {
		if (r < 0 || r >= _size) {
			cout << "向量下标超出范围" << endl;
			exit(0);
		}
		return _elem[r];
	}


	/*测试用显示函数*/
	void display() const {
		int i;
		for (i = 0; i < _size; i++) {
			cout << "this[" << i << "] =" << _elem[i] << ",";
		}
		cout << endl;
	}
};

int VectorFunctions();
#include "MyVector\MyVector.cpp" //模板类不支持直接多文件结构！
#include "MyVector\expland.cpp"
#include "MyVector\SizeGetPut.cpp"
#include "MyVector\insert.cpp"

#endif //MY_VECTOR
