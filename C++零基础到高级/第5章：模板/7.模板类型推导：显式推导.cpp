/*************************************************************************
	> File Name: 7.模板类型推导：显式推导.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 22 May 2025 12:22:21 AM CST
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
	int a = 122;
	double b = 12.3;
	Type(a);	// T -> int
	Type(b);	// T -> double
	int *p1 = &a;
	double *p2 = &b;
	Type(p1);
	Type(p2);

	Type<char>(a);		// void Type(char a);	'z'
	Type<int>(b);		// void Type(int a);	12
	Type<int>(p1);		// void Type(int *a);	122
	Type<double>(p2);	// void Type(double *a);12.3
	return 0;
}
