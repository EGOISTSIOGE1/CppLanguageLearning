/*************************************************************************
	> File Name: 29.Array类的BUG修复.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 25 Jul 2024 10:44:51 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class INT {
public:
	INT() : px(new int(0)) {
		cout << "INT constructor" << endl;
	}
	INT(const INT &a) : px(new int(0)) {
		cout << "INT constructor" << endl;
		*px = *a.px;
	}
	void set(int x) {
		*px = x;
		return ;
	}
	int val() {
		return *px;
	}
	~INT() {
		cout << "INT destructor" << endl;
		delete px;
	}
private:
	int *px;
};

class Array {
public:
	Array() : n(10), data((INT *)malloc(sizeof(INT) * n)) {
		cout << this << " default constructor" << endl;
		for (int i = 0; i < n; i++) {
			new(data + i) INT();
		}
	}
	// 原地构造，new会调用构造函数导致多申请出内存空间，应该使用malloc申请内存空间
	Array(const Array &a) : n(a.n), data((INT *)malloc(sizeof(INT) * n)) {
		cout << this << " copy constructor" << endl;
		for (int i = 0; i < a.n; i++) {
			// data[i] = a.data[i];	
			// 在构造过程中，要使用每个属性的构造函数，而不是简单的赋值运算符
			new(data + i) INT(a.data[i]);
		}
	} // 深拷贝
	Array(Array &&a) : n(a.n), data(a.data) {
		cout << this << " move constructor" << endl;
		a.n = 0;
		a.data = nullptr;
	} // 移动构造是对拷贝构造的一种升级，拷贝构造本质上是对于左值的一个拷贝处理，移动构造是针对于右值（临时值）的拷贝处理
	void set(int ind, int val) {
		data[ind].set(val);
		return ;
	}
	int size() {
		return n;
	}
	void output() {
		cout << data << " : "; 
		for (int i = 0; i < n; i++) {
			cout << data[i].val() << " ";
		}
		cout << endl;
		return ;
	}
	Array duplicate() {
		return Array(*this);	// 相当于在调用Array类的拷贝构造函数，第一次调用（临时对象）
	}							// 返回值对象的拷贝构造函数，第二次调用（临时对象）
	~Array() {
		cout << this << " destructor" << endl;
		if (n == 0) return ;
		for (int i = 0; i < n; i++) {
			data[i].~INT();
		}
		free(data);
		return ;
	}
private:
	int n;
	INT *data;
};

int main() {
	Array a, b = a;
	a.set(0, 1001);
	b.set(0, 2002);
	a.output();
	b.output();
	return 0;
}