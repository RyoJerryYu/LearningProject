#ifndef MY_VECTOR
#define MY_VECTOR

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
	//int disordered();
	//Rank find(T);
	//Rank search(T);

	/*可写接口*/;
	T put(Rank, T);
	T insert(Rank, T);
	T insert(Rank, int, T);
	//T remove(Rank);
	//void sort();
	//void deduplicate();
	//void uniquify();

	/*遍历接口*/;
	//T traverse();

	/*重载操作符*/
	T& operator[](Rank)const;
	MyVector<T>& operator=(MyVector<T>);
	template <typename T> friend ostream & operator<<(ostream &, const MyVector<T>&);//使用ostream类前先用std命名空间,友元函数模板声明时先说明模板


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
#include "MyVector\size_get_put.cpp"
#include "MyVector\insert.cpp"
#include "MyVector\operator.cpp"

#endif //MY_VECTOR
