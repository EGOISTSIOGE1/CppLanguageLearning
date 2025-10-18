/*************************************************************************
	> File Name: 42.特殊对象-2：数组对象.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 01 Sep 2024 05:28:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Array {
public:
	Array() : data(new int[10]) {}
	int &operator[](int ind) {
		return data[ind];
	}	
	int *data;
};

int main() {
	Array a;
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}