/*************************************************************************
	> File Name: 20.深拷贝与浅拷贝.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 15 Jul 2024 12:27:40 AM CST
 ************************************************************************/

/**
 * C++默认的拷贝行为是简单的i项赋值
 * 浅拷贝：无脑的进行每一项的分别赋值，无论是指针还是普通变量
 * 深拷贝：对于普通变量直接进行赋值行为，对于指针变量重新开辟一片存储区，并且把a存储区的内容每一项依次的拷贝进b存储区中
 */

#include<iostream>
using namespace std;

class Array {
public:
	Array() : n(10), data(new int[n]) {
		for (int i = 0; i < n; i++) data[i] = 0;
	}
	Array(const Array &a) : n(a.n), data(new int[n]) {
		for (int i = 0; i < a.n; i++) {
			data[i] = a.data[i];
		}
	} // 深拷贝
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
private:
	int n, *data;
};

int main() {
	Array a, b = a;
	for (int i = 0; i < a.size(); i++) {
		a.set(i, 1);
	}
	for (int i = 0; i < b.size(); i++) {
		b.set(i, i);
	}
	a.output();
	b.output();
	a.set(5, 1001);
	a.output();
	b.output();
	return 0;
}