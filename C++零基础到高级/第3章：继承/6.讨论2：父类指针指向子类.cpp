/*************************************************************************
	> File Name: 6.讨论2：父类指针指向子类.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 13 Oct 2024 11:00:22 PM CST
 ************************************************************************/

/**
 * 所有用在父类上的方法都可以用在子类上
 * 子类是父类的扩展，可以把子类对象当成是一个加强版的父类对象
 */

#include<iostream>
using namespace std;

class Base {
public:
	Base(int x, int y) : x(x), y(y) {}
	int x, y;
};

class A : public Base {
public:
	A(int x, int y, int z) : Base(x, y), z(z) {}
	int z;
};

void func1(Base *p) {
	cout << "Base : " << p->x << ", " << p->y << endl;
	return ;
}

ostream &operator<<(ostream &out, const Base &obj) {
	out << "Base (" << obj.x << ", " << obj.y << ")";
	return out;
}

int main() {
	A a(3, 4, 5);
	func1(&a);
	Base &b = a;
	b.x = 5;
	b.y = 6;
	func1(&a);
	cout << a << endl;
	return 0;
}