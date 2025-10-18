/*************************************************************************
	> File Name: 31.随堂练习2：只能在【特定函数】中自动创建.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 25 Jul 2024 02:15:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
	friend void function_test();
public:
	A() {
		cout << "constructor" << endl;
	}
	void destory() {
		delete this;
		return ;
	}
private:
	~A() {
		cout << "destructor" << endl;
	};
};

void function_test() {
	A a;
	return ;
}

int main() {
	A *pa = new A();
	pa->destory();
	function_test();
	return 0;
}