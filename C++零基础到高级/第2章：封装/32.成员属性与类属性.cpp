/*************************************************************************
	> File Name: 32.成员属性与类属性.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 18 Aug 2024 04:07:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class People {
public:
	People() { cnt += 1; }
	string name;		// 成员属性
	static int cnt; 	// 类属性，所有对象共享一个类属性，类属性的声明，相当于一个更加高级的全局变量
	~People() { cnt -= 1; }
};

int People::cnt = 0;	// 类属性的定义

void f() {
	People a, b;
	cout << "cnt : " << People::cnt << endl;	// 5
}

int main() {
	People a, b;
	cout << "cnt : " << People::cnt << endl;	// 2
	People c;
	cout << "cnt : " << People::cnt << endl;	// 3
	f();
	cout << "cnt : " << People::cnt << endl;	// 3
	return 0;
}