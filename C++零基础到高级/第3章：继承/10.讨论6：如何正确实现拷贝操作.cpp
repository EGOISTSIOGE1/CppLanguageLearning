/*************************************************************************
	> File Name: 10.讨论6：如何正确实现拷贝操作.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 14 Oct 2024 12:33:20 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
	Base() : x(3){
		cout << "Base default constructor" << endl;
	}
	Base(int x) : x(x) {
		cout << "Base(int x) constructor" << endl;
	}
	Base(const Base &obj) {
		this->x = obj.x;
		cout << "Base copy constructor" << endl;
	}
	int x;
};

class A : public Base {
public:
	A() : y(4) {	// 在子类中调用父类的有参构造
		cout << "A default constructor" << endl;
	}
	A(const A &obj) : Base(obj) {	// 默认情况下调用的是父类的默认构造
		this->y = obj.y;
		cout << "A copy constructor" << endl;
	}
	A &operator=(const A &obj) {
		this->y = obj.y;
		this->Base::operator=(obj);	// 完成属于父类的属性更改
		return *this;
	}

	int y;
};

ostream &operator<<(ostream &out, const A &a) {
	out << "class A (" << a.x << ", " << a.y << ")";
	return out;
}


int main() {
	A a, c;
	cout << "a : " << a << endl;
	cout << "c : " << c << endl;
	a.x = 1000, a.y = 999;
	c = a;
	cout << "after(c = a) c : " << c << endl;
	A b = a;
	cout << b << endl;
	return 0;
}