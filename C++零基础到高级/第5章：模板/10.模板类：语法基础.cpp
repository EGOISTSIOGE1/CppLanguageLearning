/*************************************************************************
	> File Name: 10.模板类：语法基础.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 22 May 2025 11:52:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
class Point {
public:
	Point() = default;
	Point(T x, T y) : x(x), y(y) {}
	template<typename U>
	void output(U msg) {
		cout << "(" << x << ", " << y << ") : " << msg << endl;
		return ;
	}
	T x, y;
};

template<typename T>
ostream &operator<<(ostream &out, Point<T> &a) {
	out << "(" << a.x << ", " << a.y << ")";
	return out;
}

int main() {
	Point<int> int_point;
	Point<double> double_point;
	cout << sizeof(int_point) << endl;
	cout << sizeof(double_point) << endl;
	int_point = {3, 4};
	double_point = {3.4, 4.5};
	cout << int_point << endl;
	cout << double_point << endl;
	int_point.output(123);
	double_point.output("hello world");
	return 0;
}