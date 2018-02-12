#include<iostream>
#include"MyVector.h"
using namespace std;

int VectorFunctions() {
	cout << "Testing VectorFunctions" << endl;
	MyVector<int> Vector1;
	MyVector<int> Vector2(4);
	int str1[] = { 1,2,3,4,5 };
	MyVector<int> Vector3(str1, 0, 5);
	cout << Vector3 << endl;
	MyVector<int> Vector4(Vector3);
	cout << Vector4 << endl;
	cout << Vector4.size() << "," << Vector4.get(3) << endl;
	Vector4.get(3) = 11;
	cout << Vector4 << endl;
	cout << Vector3.put(5, 12) << endl;
	cout << Vector3 << endl;
	cout << Vector4.insert(2, 13) << endl;
	cout << Vector4 << endl;
	cout << Vector4.insert(2, 7, 14) << endl;
	cout << Vector4 << endl;
	cout << Vector1.insert(0, 6, 15) << endl;
	cout << Vector1 << endl;
	MyVector<int> Vector5(5, 16);
	cout << Vector5 << endl;
	Vector2 = Vector4;//不会调用模板构造函数,先定义operator=();
	cout << Vector2 << endl;
	MyVector<int> Vector6(Vector4);
	cout << Vector1 << Vector2 << Vector3 << Vector4 << Vector5 << Vector6 << endl;
	cout << Vector3.disordered() << endl;
	Vector2.sort();
	cout << Vector2 << endl;

	return 1;
}