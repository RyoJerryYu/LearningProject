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
	/*�ڲ�����*/;
	void expand();

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
	//Rank find(T);
	//Rank search(T);

	/*��д�ӿ�*/;
	T put(Rank, T);
	T insert(Rank, T);
	T insert(Rank, int, T);
	//T remove(Rank);
	//int disordered();
	//void sort();
	//void deduplicate();
	//void uniquify();

	/*�����ӿ�*/;
	//T traverse();

	/*���ز�����*/
	T& operator[](Rank r) const {
		if (r < 0 || r >= _size) {
			cout << "�����±곬����Χ" << endl;
			exit(0);
		}
		return _elem[r];
	}


	/*��������ʾ����*/
	void display() const {
		int i;
		for (i = 0; i < _size; i++) {
			cout << "this[" << i << "] =" << _elem[i] << ",";
		}
		cout << endl;
	}
};

int VectorFunctions();
#include "MyVector\MyVector.cpp" //ģ���಻֧��ֱ�Ӷ��ļ��ṹ��
#include "MyVector\expland.cpp"
#include "MyVector\SizeGetPut.cpp"
#include "MyVector\insert.cpp"

#endif //MY_VECTOR
