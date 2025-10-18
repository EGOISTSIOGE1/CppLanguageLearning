/*************************************************************************
	> File Name: 6.模板类型推导：隐式推导.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 22 May 2025 12:10:03 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
void Type(T a) {
	cout << "Type(T a) = " << a << endl;
	return ;
}

template<typename T>
void Type(T *a) {
	cout << "Type(T *a) = " << a << ", " << *a << endl;
	return ;
}

int main() {
	int a = 123;
	double b = 12.3;
	Type(a);	// T -> int
	Type(b);	// T -> double
	int *p1 = &a;
	double *p2 = &b;
	Type(p1);
	Type(p2);
	return 0;
}