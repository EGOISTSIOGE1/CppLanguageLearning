/*************************************************************************
	> File Name: 5.friend：友元函数与友元类.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 10 Jul 2024 11:51:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
	friend int main(int argc, char const *argv[]); // 友元函数
	friend class B; // 友元类
public:
	void output() {
		cout << "Class A : " << x << ", " << y << endl;
	}
private:
	int x, y;
};

class B {
public:
	void change(A &a) {
		a.x = 100, a.y = 200;
		return ;
	}
};

void test(A &a) {
	// a.x = 3, a.y = 4;
	return ;
}

int main(int argc, char const *argv[]) {
	A a;
	test(a);
	a.x = 3, a.y = 4;
	a.output();

	B b;
	b.change(a);
	a.output();
	return 0;
}
