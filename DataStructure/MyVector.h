#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
using namespace std;

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
	void swap(Rank, Rank);
	bool shrink();

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
	int disordered();
	Rank find(const T &);
	Rank find(const T &, Rank, Rank hi);
	//Rank search(T);

	/*可写接口*/;
	T put(Rank, T);
	T insert(Rank, const T &);
	T insert(Rank, int, const T &);
	T remove(Rank);
	int remove(Rank, Rank);
	void sort();
	void bubblesort();
	void deduplicate();
	//void uniquify();

	/*遍历接口*/;
	//T traverse();

	/*重载操作符*/
	T& operator[](Rank)const;
	MyVector<T>& operator=(MyVector<T>);
	template <typename T> friend ostream & operator<<(ostream &, const MyVector<T>&);//使用ostream类前先用std命名空间,友元函数模板声明时先说明模板
};

int VectorFunctions();
#include "MyVector\MyVector.cpp" //模板类不支持直接多文件结构！
#include "MyVector\protectedfunc.cpp"
#include "MyVector\size_get_put.cpp"
#include "MyVector\insert.cpp"
#include "MyVector\operator.cpp"
#include "MyVector\disordered.cpp"
#include "MyVector\sorts.cpp"
#include "MyVector\remove.cpp"
#include "MyVector\find_deduplicate.cpp"

#endif //MY_VECTOR_H
