/*************************************************************************
	> File Name: 4.揭秘：船说中的C++学习方法.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 19 Jun 2024 11:57:44 PM CST
 ************************************************************************/

/**
 * 编程范式：
 * 1、面向过程		默认有基础
 * 2、面向对象		*学习重点*
 * 3、泛型编程		STL检验所学
 * 4、函数式编程	只做了解，用的不多
 * 5、模板元编程	只做了解，用的不多
 */

#include<iostream>
using namespace std;

int add1(int a, int b) {
	return a + b;
}

class ADD {
public:
	int operator()(int a, int b) const {
		return a + b;
	}
} add2;

template<typename T, typename U>
auto add3(T a, U b) -> decltype(a + b) {
	return a + b;
}

auto add4 = [](int a, int b) -> int {
	return a + b;
};

template<int N, int M>
struct add5 {
	static const int r = N + M;
};

int main() {
	cout << add1(3, 4) << endl;
	cout << add2(3, 4) << endl;
	cout << add3(3, 4) << endl;
	cout << add4(3, 4) << endl;
	cout << add5<3, 4>::r << endl;
	return 0;
}