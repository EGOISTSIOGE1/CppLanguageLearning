/*************************************************************************
	> File Name: 13.面试重点：模板函数没有偏特化.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 23 May 2025 01:49:20 AM CST
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

// 愿模板的偏特化版本
template<typename T>
class Point<T *> {
public:
	Point() = default;
	Point(T *x, T *y) : x(x), y(y) {}
	template<typename U>
	void output(U msg) {
		cout << "(" << *x << ", " << *y << ") : " << msg << endl;
		return ;
	}
	T *x, *y;
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

// 模板函数没有偏特化，这是函数重载
template<typename T>
ostream &operator<<(ostream &out, Point<T *> &a) {
	out << "(" << *a.x << ", " << *a.y << ")";
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
	Point<int *> int_pointer_point;
	cout << sizeof(int_point) << endl;
	cout << sizeof(double_point) << endl;
	cout << sizeof(string_point) << endl;
	int_point = {3, 4};
	double_point = {3.4, 4.5};
	string_point = {"abc", "def"};
	int a = 999, b = 888;
	int_pointer_point = {&a, &b};
	cout << int_point << endl;
	cout << double_point << endl;
	cout << string_point << endl;	// string : (abc, def)
	cout << int_pointer_point << endl;
	int_point.output(123);
	double_point.output("hello world");
	string_point.output("this is string point");
	int_pointer_point.output("int *");
	return 0;
}