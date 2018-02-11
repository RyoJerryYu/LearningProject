#include<iostream>
#include"MyVector.h"
#include"main.h"
using namespace std;

int VectorFunctions() {
	cout << "Testing VectorFunctions" << endl;
	MyVector<int> Vector1;
	MyVector<int> Vector2(4);
	int str1[] = { 1,2,3,4,5 };
	MyVector<int> Vector3(str1, 0, 5);
	cout << Vector3[0] << Vector3[1] << Vector3[2] << endl;
	return 1;
}