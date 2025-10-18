/*************************************************************************
	> File Name: 13.彻底搞懂：继承权限.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 14 Oct 2024 01:18:08 AM CST
 ************************************************************************/

/**
 * 继承权限：是否影响子类对于父类中方法和属性的访问？不影响
 * 			不管继承权限是什么，子类都可以访问父类中的public和protected属性，private属性无法访问
 * 			实际上影响子类继承父类的方法对外的权限
 * 
 * 总结：影响子类继承自父类的属性和方法的对外访问权限
 */

#include<iostream>
using namespace std;

class Base {
public :
	int public_x;
protected:
	int protected_x;
private:
	int private_x;
};

class A : public Base {
public:
	void set() {
		this->public_x = 3;
		this->protected_x = 3;
		// this->private_x = 3;
		return ;
	}
};

class B : protected A {
public:
	void set() {
		this->public_x = 3;
		this->protected_x = 3;
		// this->private_x = 3;
		return ;
	}
};

int main() {
	A a;
	
	a.public_x = 3;
	// a.protected_x = 3;
	// a.private_x = 3;

	B b;
	// b.public_x = 3;
	// b.protected_x = 3;
	// b.private_x = 3;

	return 0;
}