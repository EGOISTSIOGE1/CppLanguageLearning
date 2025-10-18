/*************************************************************************
	> File Name: 40.运算符重载：前自增与后自增.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 01 Sep 2024 04:50:20 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class A {
public:
	A(int x = 0) : x(x) {}
	// 类内重载前++
	A &operator++() {
		x += 1;
		return *this;
	}
	// 类内重载后++，int为占位参数，没有任何意义，只用于区分前后++，有int为后++
	A operator++(int) {
		A ret(*this);
		x += 1;
		return ret;
	}
	bool operator<(const A &a) const {
		return x < a.x;
	}
	bool operator>(const A &a) const {
		return a < *this;
	}
	bool operator==(const A &a) const {
		return !(*this < a) && !(a < *this);
	}
	bool operator!=(const A &a) const {
		return !(*this == a);
	}
	bool operator>=(const A &a) const {
		return (a < *this) || (a == *this);
	}
	bool operator<=(const A &a) const {
		return (*this < a) || (a == *this);
	}
	int x;
};

map<A, int> h;

#define P(stmt) { \
	cout << #stmt << " : " << (stmt) << endl; \
}

// // 类外重载前++
// A &operator++(A &a) {
// 	a.x += 1;
// 	return a;
// }

ostream &operator<<(ostream &out, const A &a) {
	out << "class A : x = " << a.x;
	return out;
}

int main() {
	A a(3), b(4);
	cout << a << endl;
	cout << "++a : " << ++a << endl;
	cout << "a++ : " << a++ << endl;
	cout << "a : " << a << endl;
	return 0;
}