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
	/*�ڲ�����*/;
	void expand();
	void swap(Rank, Rank);
	bool shrink();

public:
	/*���캯��*/;
	MyVector();
	MyVector(int);
	MyVector(int, T);
	MyVector(const T*, Rank, Rank);
	MyVector(const MyVector<T>& A);
	
	/*��������*/;
	~MyVector();
	
	/*ֻ���ӿ�*/;
	int size() const;
	T& get(Rank);
	int disordered();
	Rank find(const T &);
	Rank find(const T &, Rank, Rank hi);
	//Rank search(T);

	/*��д�ӿ�*/;
	T put(Rank, T);
	T insert(Rank, const T &);
	T insert(Rank, int, const T &);
	T remove(Rank);
	int remove(Rank, Rank);
	void sort();
	void bubblesort();
	void deduplicate();
	//void uniquify();

	/*�����ӿ�*/;
	//T traverse();

	/*���ز�����*/
	T& operator[](Rank)const;
	MyVector<T>& operator=(MyVector<T>);
	template <typename T> friend ostream & operator<<(ostream &, const MyVector<T>&);//ʹ��ostream��ǰ����std�����ռ�,��Ԫ����ģ������ʱ��˵��ģ��
};

int VectorFunctions();
#include "MyVector\MyVector.cpp" //ģ���಻֧��ֱ�Ӷ��ļ��ṹ��
#include "MyVector\protectedfunc.cpp"
#include "MyVector\size_get_put.cpp"
#include "MyVector\insert.cpp"
#include "MyVector\operator.cpp"
#include "MyVector\disordered.cpp"
#include "MyVector\sorts.cpp"
#include "MyVector\remove.cpp"
#include "MyVector\find_deduplicate.cpp"

#endif //MY_VECTOR_H
