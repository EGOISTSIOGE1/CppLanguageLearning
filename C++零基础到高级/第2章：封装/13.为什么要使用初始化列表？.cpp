/*************************************************************************
	> File Name: 13.为什么要使用初始化列表？.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 14 Jul 2024 03:00:27 PM CST
 ************************************************************************/

/**
 * 能够使用就尽量使用，效率更高，能省略两个赋值过程
 */

#include<iostream>
using namespace std;

namespace test1 {

class A {
public:
	A() : A(1, 1) {}	// 委托构造
	A(int x, int y) : x(x), y(y) {}
	void output() {
		cout << "(" << x << ", " << y << ")" << endl;
		return ;
	}
private:
	int x, y;
};

int main() {
	A a(3, 4), b(101, 202), c;
	a.output();
	b.output();
	c.output();
	return 0;
}
} // test1 

namespace test2 {

class B {
public:
	B(int x) : x(x) {
		cout << this << " : Class B constructor" << endl;
	}
	int x;
};

class A {
public:
	A() : A(1, 1) {}	// 委托构造
	// A(int z) : y(z), x(y + 1) {}	// 初始化列表中的顺序并不是其初始的顺序，是按照这些变量所定义的顺序去执行的
	A(int z) : y(z), x(z) {		// 初始化列表先执行，再执行大括号里面的内容
		cout << "x : " << &x << endl;
		cout << "y : " << &y << endl;
	}
	A(int x, int y) : x(x), y(y) {}
	void output() {
		cout << "(" << x.x << ", " << y.x << ")" << endl;
		return ;
	}
private:
	B x, y;
};

int main() {
	A a(5); // x = 6, y = 5
	a.output();
	return 0;
}

} // test2

namespace test3 {

class B {
public:
	B() {
		cout << this << " default constructor" << endl;
	}
	B(int x) : x(x) {
		cout << this << " : Class B constructor" << endl;
	}
	int x;
};

class A {
public:
	A() : A(1, 1) {}	// 委托构造
	// A(int z) : y(z), x(y + 1) {}	// 初始化列表中的顺序并不是其初始的顺序，是按照这些变量所定义的顺序去执行的
	A(int x, int y) : x(x), y(y) {}
	void output() {
		cout << "(" << x.x << ", " << y.x << ")" << endl;
		return ;
	}
private:
	B x, y;
};

int main() {
	A a(3, 4);
	a.output();
	return 0;
}

} // test3


int main() {
	// test1::main();
	// test2::main();
	test3::main();
	return 0;
}

