/*************************************************************************
	> File Name: 35.初识：函数重载.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 25 Aug 2024 07:56:16 PM CST
 ************************************************************************/

/**
 * 函数重载：
 * 如果一个作用域内几个函数名字相同但是参数列表不同，称为函数重载
 * 与返回值没有关系
 * 
 * 1、通过函数名对函数功能进行提示
 * 2、通过函数参数列表对函数的用法进行提示
 * 3、扩展已有的功能
 */

#include<iostream>
using namespace std;

int add(int a, int b) {
	cout << "add(int, int) : " << a + b << endl;
	return a + b;
}

int add(int a, int b, int c) {
	cout << "add(int, int, int) : " << a + b + c << endl;
	return a + b + c;
}

double add(double a, double b) {
	cout << "add(double, double) : " << a + b << endl;
	return a + b;
}

int main() {
	add(3, 4);
	add(1, 2, 3);
	add(3.4, 5.6);
	return 0;
}

