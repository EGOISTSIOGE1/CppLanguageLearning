/*************************************************************************
	> File Name: 9.初探：有参构造.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 12 Jul 2024 01:00:24 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	// 有了有参构造后，默认构造需要显示定义
	// A() {
	// 	x = 100, y = 1000;
	// };		
	A() : A(100, 1000) {}	// 委托构造
	A(int x, int y) {
		this->x = x, this->y = y;		// this指针，指向当前对象中的指针
	}
	void output() {
		cout << "(" << this->x << ", " << this->y << ")" << endl;
	}
private:
	int x, y;
};

int main(int argc, const char** argv) {
	A a{10, 100}, b{20, 23};	// 使用{}，不会引起语法歧义，当然有参数传入时也能使用小括号
	a.output();
	b.output();
	A c;
	c.output();
	return 0;
}