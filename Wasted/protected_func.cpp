#ifndef PROTECTED_FUNC_CPP
#define PROTECTED_FUNC_CPP

#include "..\MyVector.h"

template <typename T>
bool MyVector<T>::expand() {//���ݣ����ޱ�Ҫ����false
	if (_size < _capacity)return false;//����ǰ������size��
	T* oldelem = _elem;
	_capacity = _size * 2;
	_elem = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldelem[i];
	}
	delete[] oldelem; return true;
}

template <typename T>
void MyVector<T>::swap(Rank i, Rank j) {//�����±�Ϊi��j��Ԫ��
	if (i < 0 || j < 0 || _size <= i || _size <= j)return;
	T t = _elem[i];
	_elem[i] = _elem[j];
	_elem[j] = t;
}

template <typename T>
bool MyVector<T>::shrink() {//���ݣ����ޱ�Ҫ����false
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
void MyVector<T>::merge(Rank lo, int length) {//�ϲ���lo��lo+length��ʼ������Ϊlength����������������
	if (_size <= lo + length)return;
	int i = lo, j = 0, k = lo + length;//Ŀ�������±�i��ǰ�������±�j�����������±�k
	T* sub = new T[length];//����ǰ������
	for (; j < length; j++) { sub[j] = _elem[j + lo]; }
	j = 0;
	while ((j < length) && (k < lo + length + length) && (k < _size)) {
		if (sub[j] > _elem[k]) { _elem[i++] = _elem[k++]; }
		else { _elem[i++] = sub[j++]; }
	}
	while (j < length) { _elem[i++] = sub[j++]; }//����������ǰ����ѭ��ʱ
	delete[]sub;
}

#endif // PROTECTED_FUNC_CPP