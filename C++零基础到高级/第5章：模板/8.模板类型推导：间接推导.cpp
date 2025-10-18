/*************************************************************************
	> File Name: 8.模板类型推导：间接推导.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 22 May 2025 12:27:45 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

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

template<typename T, typename U>
T test_template_param(U a) {
	cout << "in template : a = " << a << endl;
	return 2 * a;
}

void func1(int (*func)(double)) {
	int val = func(12.3);
	cout << "in func1 : func(12.3) = " << val << endl;
	return ;
}

int main() {
	func1(test_template_param);
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