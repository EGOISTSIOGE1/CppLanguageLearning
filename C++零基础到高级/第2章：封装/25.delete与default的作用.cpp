/*************************************************************************
	> File Name: 25.delete与default的作用.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 24 Jul 2024 04:34:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A() = default; // 想保留默认构造
	A(const A &) = delete; // 删除A类的拷贝构造(浅拷贝)
	A(int) {}
	~A() = default;
};

int main() {
	A a;
	return 0;
}