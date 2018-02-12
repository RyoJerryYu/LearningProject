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
	int disordered();
	//Rank find(T);
	//Rank search(T);

	/*��д�ӿ�*/;
	T put(Rank, T);
	T insert(Rank, T);
	T insert(Rank, int, T);
	//T remove(Rank);
	//void sort();
	//void deduplicate();
	//void uniquify();

	/*�����ӿ�*/;
	//T traverse();

	/*���ز�����*/
	T& operator[](Rank)const;
	MyVector<T>& operator=(MyVector<T>);
	template <typename T> friend ostream & operator<<(ostream &, const MyVector<T>&);//ʹ��ostream��ǰ����std�����ռ�,��Ԫ����ģ������ʱ��˵��ģ��


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
#include "MyVector\size_get_put.cpp"
#include "MyVector\insert.cpp"
#include "MyVector\operator.cpp"
#include "MyVector\disordered_sort.cpp"

#endif //MY_VECTOR
