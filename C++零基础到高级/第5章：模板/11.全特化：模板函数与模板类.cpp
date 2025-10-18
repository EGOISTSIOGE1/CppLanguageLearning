/*************************************************************************
	> File Name: 11.全特化：模板函数与模板类.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 23 May 2025 12:09:21 AM CST
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

template<>
class Point<string> {
public:
	Point() = default;
	Point(string x, string y) : x(x), y(y) {}
	template<typename U>
	void output(U msg) {
		cout << "string : (" << x << ", " << y << ") : " << msg << endl;
		return ;
	}
	string x, y;
};

template<typename T>
ostream &operator<<(ostream &out, Point<T> &a) {
	out << "(" << a.x << ", " << a.y << ")";
	return out;
}

// 原模板函数的全特化版本，没有类型参数，相当于原模板的一个补丁和功能的扩展
template<>
ostream &operator<<(ostream &out, Point<string> &a) {
	out << "string : (" << a.x << ", " << a.y << ")";
	return out;
}

int main() {
	Point<int> int_point;
	Point<double> double_point;
	Point<string> string_point;
	cout << sizeof(int_point) << endl;
	cout << sizeof(double_point) << endl;
	cout << sizeof(string_point) << endl;
	int_point = {3, 4};
	double_point = {3.4, 4.5};
	string_point = {"abc", "def"};
	cout << int_point << endl;
	cout << double_point << endl;
	cout << string_point << endl;	// string : (abc, def)
	int_point.output(123);
	double_point.output("hello world");
	string_point.output("this is string point");
	return 0;
}