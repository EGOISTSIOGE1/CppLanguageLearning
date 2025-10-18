/*************************************************************************
	> File Name: 3.模板函数：语法基础.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 21 Mar 2025 12:33:05 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
	return a + b;
}

template<typename T, typename U>
void Print(T a, U b) {
	cout << a << " " << b << endl;
	return ;
}

int main() {
	cout << add(3, 4) << endl;
	cout << add(3.4, 5.2) << endl;
	cout << add<double>(3, 3.4) << endl;
	Print(3, 'c');

	return 0;
}