/*************************************************************************
	> File Name: 26.为什么一定要使用【new】和【delete】.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 24 Jul 2024 04:56:58 PM CST
 ************************************************************************/

/**
 * malloc只开辟了对象的存储空间，但没有完成里面的构造过程
 * new和delete会去调用对象的构造函数和析构函数
*/

#include<iostream>
using namespace std;

class A {
public:
	A(string msg) {
		cout << msg << " constructor" << endl;
	}
	~A() {
		cout << "destructor" << endl;
	}
};

int main() {
	A *malloc_a = (A *)malloc(sizeof(A));
	free(malloc_a);
	A *new_a = new A("new");
	delete new_a;
	return 0;
}