/*************************************************************************
	> File Name: 33.成员方法与类方法.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 18 Aug 2024 05:04:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class People {
public:
	void say() {
		cout << "say something : " << this << endl;
	}
	static void say2() {
		// cout << this << endl;	// 类方法不能访问this指针
		cout << "class method : say something" << endl;
		return ;
	}
};

int main() {
	People a;
	a.say();
	a.say2();	// 1
	People::say2(); 
	return 0;
}