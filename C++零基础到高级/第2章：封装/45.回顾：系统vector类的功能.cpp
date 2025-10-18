/*************************************************************************
	> File Name: 45.回顾：系统vector类的功能.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 07 Sep 2024 05:44:36 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> a;
	for (int i = 0; i < 10; i++) {
		a.push_back(rand() % 100);
	}
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < a.size(); i++) {
		a[i] = 2 * i;
	}
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
		int x = *iter;
		cout << x << " ";
	}
	cout << endl;
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}