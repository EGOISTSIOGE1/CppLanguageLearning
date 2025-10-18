/*************************************************************************
	> File Name: 9.scanf的接班人：cin.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 25 Jun 2024 12:01:01 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	cout << "a = " << a << endl;
	double b;
	char c[100];
	cin >> a >> b >> c;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	while (cin >> a) {
		cout << "EOF read : a = " << a << endl;
	}
	return 0;
}