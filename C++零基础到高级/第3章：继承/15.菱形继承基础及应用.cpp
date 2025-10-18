/*************************************************************************
	> File Name: 15.菱形继承基础及应用.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 14 Nov 2024 12:19:04 AM CST
 ************************************************************************/

/**
 * A类：int x;
 * B类：set_x;
 * C类：get_x;
 * D类：D obj;	obj.set_x(3);	obj.get_x();
 * 
 * 想象中B类和C类继承同一个A类
 * 但是实际上他们继承不同的A类
 * 所以结果不等于3
 * 
 * 解决方法为虚继承，用来合并同类项（继承同一个A类）
 */

#include<iostream>
using namespace std;

class A {
public :
	int x;
};

class B : virtual public A {
public :
	void set_x(int x) {
		this->x = x;
		return ;
	}
};

class C : virtual public A {
public :
	int get_x() {
		return this->x;
	}
};

class D : public B, public C {};

int main() {
	D obj;
	obj.set_x(3);
	cout << obj.get_x() << endl;
	return 0;
}