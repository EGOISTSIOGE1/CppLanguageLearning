/*************************************************************************
	> File Name: 10.讨论：scanf与printf应该被废弃么.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 28 Jun 2024 11:54:33 PM CST
 ************************************************************************/

/**
 * 1.printf与scanf是旧时代产物，我们新时代不用
 * 2.cin和cout明显更方便
 * 3.printf与scanf存在安全风险
 * 
 * 结论：各有优势，关键在【用】
 * 
 * cin和cout的可扩展性
 */

#include<iostream>
using namespace std;

struct Point {
	int x, y;
};

ostream &operator<<(ostream &out, const Point &p) {
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

int main() {
	Point p1 = {3, 4}, p2 = {5, 99};
	printf("p1 = (%d, %d)\n", p1.x, p1.y);
	printf("p2 = (%d, %d)\n", p2.x, p2.y);
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	return 0;
}