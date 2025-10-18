/*************************************************************************
	> File Name: 39.编码技巧之：重载比较运算符.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 01 Sep 2024 04:29:29 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class A {
public:
	A(int x = 0) : x(x) {}
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

int main() {
	A a(3), b(4);
	h[a] = 123;
	cout << h[a] << endl;
	P(a < b);
	P(a > b);
	P(a == b);
	P(a != b);
	P(a >= b);
	P(a <= b);
	return 0;
}