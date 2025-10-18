/*************************************************************************
	> File Name: 11.静态转换：static_cast.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 01 Jan 2025 03:52:13 PM CST
 ************************************************************************/

/**
 * 用于同类和同类const->非const之间的转换
 */

#include<iostream>
using namespace std;

namespace T1 {
	void run() {
		int x = 123;	//	long long double float
		double fx = static_cast<double>(x);
		const int cx = 456;
		int non_cx = static_cast<int>(cx);
		return ;
	}
}

namespace T2 {
	void run() {
		// int *x = new int();
		// double *fx = static_cast<double *>(x);
		// const int *cx = new int();
		// int *non_cx = static_cast<int *>(cx);
		int * const p1 = new int();
		int *p2 = static_cast<int *>(p1);
		return ;
	}
}

namespace T3 {
	class Base {};
	class A : public Base {
	public:
		operator int() {	// 类型转换重载运算符
			return 999;
		}
	};
	class B {};
	class C : public Base {};
	void run() {
		A *p1 = new A();
		// B *p2 = static_cast<B *>(p1);
		Base *p3 = static_cast<Base *>(p1);	// 存在继承关系
		// C *p4 = static_cast<C *>(p1);		// 不存在直接继承关系
		cout << (int)(*p1) << endl;
		cout << static_cast<int>(*p1) << endl;
		return ;
	}
}

int main() {
	T1::run();
	T2::run();
	T3::run();
	return 0;
}