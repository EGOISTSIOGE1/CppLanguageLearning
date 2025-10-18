/*************************************************************************
	> File Name: 30.随堂练习1：不能被自动创建的对象.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 25 Jul 2024 11:38:58 AM CST
 ************************************************************************/

/**
 * 指不能定义在局部和全局的对象，只能通过new去创建
 * 可以删去类的构造函数或者析构函数，推荐删除析构函数
*/

#include<iostream>
using namespace std;

class A {
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

int main() {
	A *pa = new A();
	pa->destory();
	return 0;
}