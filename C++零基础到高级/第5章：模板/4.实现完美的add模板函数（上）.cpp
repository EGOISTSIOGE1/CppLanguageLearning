/*************************************************************************
	> File Name: 4.实现完美的add模板函数（上）.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 21 Mar 2025 12:45:22 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define P(func) { \
	cout << #func << "=" << func << endl; \
}

// 使用()调用匿名对象
template<typename T, typename U>
decltype(T() + U()) add(T a, U b) {
	return a + b;
}

void is_type(int a) {
	cout << "a is int" << endl;
	return ;
}

void is_type(double a) {
	cout << "a is double" << endl;
	return ;
}

int main() {
	// cout << add(3.4, 6) << endl;
	P(add<double>(3.4, 6));
	// T -> 3.4 = double, U -> 6 = int, return -> decltype(double() + int())
	P(add(3.4, 6));
	// T -> 6 = int, U -> 3.4 = double, return -> decltype(int() + double())
	P(add(6, 3.4));
	// 当作类型使用
	decltype(3.4 + 6) a;
	is_type(a);
	return 0;
}