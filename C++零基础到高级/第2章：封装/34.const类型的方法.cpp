/*************************************************************************
	> File Name: 34.const类型的方法.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 18 Aug 2024 05:10:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A(int x, int y) : x(x), y(y), z(0) {}
	void output() const {
		z += 1;
		cout << x << ", " << y << ", " << z << endl;
		
		return ;
	}
	int x, y;
	mutable int z;	// 可变的，可以在const类型中被修改
};

int main() {
	const A a(3, 4);
	a.output();
	a.output();
	a.output();
	a.output();
	return 0;
}