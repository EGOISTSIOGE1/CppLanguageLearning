/*************************************************************************
	> File Name: 19.更方便的函数指针：function.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 05 Jul 2024 01:14:53 AM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

void test() {
	cout << "hello test" << endl;
	return ;
}

int add(int a, int b) {
	cout << "normal function : ";
	return a + b;
}

// 函数对象
class ADD {
public:
	int operator()(int a, int b) const {
		cout << "function object : ";
		return a + b;
	}
} add2;

// lambda表达式


int main(int argc, char const *argv[]) {
	function<void()> p1 = test;
	p1();
	function<int(int, int)> p2 = add;
	cout << p2(3, 4) << endl;
	cout << add2(3, 4) << endl;
	p2 = add2;
	cout << p2(3, 4) << endl;
	auto add3 = [](int a, int b) -> int {
		cout << "lambda : ";
		return a + b;
	};
	p2 = add3;
	cout << p2(3, 4) << endl;
	return 0;
}
