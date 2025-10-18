/*************************************************************************
	> File Name: 21.初探：移动构造函数.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 17 Jul 2024 12:44:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Array {
public:
	Array() : n(10), data(new int[n]) {
		cout << this << " default constructor" << endl;
		for (int i = 0; i < n; i++) data[i] = 0;
	}
	Array(const Array &a) : n(a.n), data(new int[n]) {
		cout << this << " copy constructor" << endl;
		for (int i = 0; i < a.n; i++) {
			data[i] = a.data[i];
		}
	} // 深拷贝
	Array(Array &&a) : n(a.n), data(a.data) {
		cout << this << " move constructor" << endl;
		a.n = 0;
		a.data = nullptr;
	} // 移动构造是对拷贝构造的一种升级，拷贝构造本质上是对于左值的一个拷贝处理，移动构造是针对于右值（临时值）的拷贝处理
	void set(int ind, int val) {
		data[ind] = val;
		return ;
	}
	int size() {
		return n;
	}
	void output() {
		for (int i = 0; i < n; i++) {
			cout << data[i] << " ";
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
		delete[] data;
		return ;
	}
private:
	int n, *data;
};

int main() {
	Array a, b = a.duplicate();	// b对象的拷贝构造函数，第三次调用
	Array c;
	cout << "a : " << &a << endl;
	cout << "b : " << &b << endl;
	Array d = std::move(c);
	return 0;
}