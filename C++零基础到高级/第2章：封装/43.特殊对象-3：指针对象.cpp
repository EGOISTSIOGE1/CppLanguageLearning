/*************************************************************************
	> File Name: 43.特殊对象-3：指针对象.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 01 Sep 2024 05:36:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	int x, y;
};

class Pointer_A {
public:
	Pointer_A(A *p) : p(p) {}
	A *operator->() { return p; }
	A &operator*() { return *p; }
	A *p;
};

ostream &operator<<(ostream &out, const A &a) {
	cout << "(" << a.x << ", " << a.y << ")";
	return out;
}

int main() {
	A a;
	Pointer_A p = &a;
	p->x = 3;
	p->y = 4;
	cout << *p << endl;

	return 0;
}