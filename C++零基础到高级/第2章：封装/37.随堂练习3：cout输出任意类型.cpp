/*************************************************************************
	> File Name: 37.随堂练习3：cout输出任意类型.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 25 Aug 2024 08:35:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A(int x, int y) : x(x), y(y) {}
	void output() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	int x, y;
};

A operator+(A a, A b) {
	return A(a.x + b.x, a.y + b.y);
}

ostream &operator<<(ostream &out, const A &a) {
	out << "operator<< : (" << a.x << ", " << a.y << ")";
	return out;
}

int main() {
	A a(3, 4), b(7, 10);
	A c = a + b;
	cout << c << " : end"<< endl;
	return 0;
}