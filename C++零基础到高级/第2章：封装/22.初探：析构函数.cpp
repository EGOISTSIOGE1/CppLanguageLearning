/*************************************************************************
	> File Name: 22.初探：析构函数.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 21 Jul 2024 10:16:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A() : data(new int[10]) {
		cout << this << " default constructor" << endl;
	}
	~A() {
		cout << this << " destructor" << endl;
		delete[] data;
	}
private:
	int *data;
};

int main() {
	A a, *pa = new A();
	cout << "a : " << &a << endl;
	cout << "pa : " << pa << endl;
	delete pa;
	return 0;
}