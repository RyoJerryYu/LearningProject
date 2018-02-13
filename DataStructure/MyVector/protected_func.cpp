#ifndef PROTECTED_FUNC_CPP
#define PROTECTED_FUNC_CPP

#include "..\MyVector.h"

template <typename T>
bool MyVector<T>::expand() {//扩容，如无必要返回false
	if (_size < _capacity)return false;//扩张前先增加size！
	T* oldelem = _elem;
	_capacity = _size * 2;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldelem[i];
	}
	delete[] oldelem; return true;
}

template <typename T>
void MyVector<T>::swap(Rank i, Rank j) {//交换下标为i与j的元素
	if (i < 0 || j < 0 || _size <= i || _size <= j)return;
	T t = _elem[i];
	_elem[i] = _elem[j];
	_elem[j] = t;
}

template <typename T>
bool MyVector<T>::shrink() {//缩容，如无必要返回false
	if (_capacity < 2 * _size)return false;
	T* oldelem = _elem;
	_capacity = _size;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldelem[i];
	}
	delete[] oldelem; return true;
}

template <typename T>
void MyVector<T>::merge(Rank lo, int length) {//合并从lo及lo+length开始，长度为length的两个有序子序列
	if (_size <= lo + length)return;
	int i = lo, j = 0, k = lo + length;//目标序列下标i，前子序列下标j，后子序列下标k
	T* sub = new T[length];//备份前子序列
	for (; j < length; j++) { sub[j] = _elem[j + lo]; }
	j = 0;
	while ((j < length) && (k < lo + length + length) && (k < _size)) {
		if (sub[j] > _elem[k]) { _elem[i++] = _elem[k++]; }
		else { _elem[i++] = sub[j++]; }
	}
	while (j < length) { _elem[i++] = sub[j++]; }//后子序列提前结束循环时
	delete[]sub;
}

#endif // PROTECTED_FUNC_CPP