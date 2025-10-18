/*************************************************************************
	> File Name: 28.emplace_new：原地构造.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 25 Jul 2024 10:27:40 AM CST
 ************************************************************************/

/**
 * emplace new用于申请多个没有默认构造的类
 * 1、先申请空间
 * 2、调用构造函数
*/

#include<iostream>
using namespace std;

class A {
public:
	A() = delete;
	A(int x) : x(x) {
		data = new int[10];
		cout << "constructor" << endl;
	}
	void output() {
		cout << "x : " << x << endl;
		return ;
	}
	~A() {
		cout << "destructor" << endl;
		delete[] data;
	}
	int x, *data;
};

int main() {
	// A *arr = new A[100];	// 不可行，没有默认构造

	// 方法一：先申请空间，再一次构造
	A *arr = (A *)malloc(sizeof(A) * 5);
	for (int i = 0; i < 5; i++) {
		new(arr + i) A(i);	// 给new中传入要构造的地址
	}
	for (int i = 0; i < 5; i++) {
		arr[i].output();
	}
	for (int i = 0; i < 5; i++) {
		arr[i].~A();	// 由于不是new申请出来的，不能使用delete释放，必须手动调用析构函数
	}
	free(arr);
	return 0;
}