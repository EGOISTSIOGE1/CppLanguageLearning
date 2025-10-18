/*************************************************************************
	> File Name: 2.初次相识：类与对象.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 09 Jul 2024 11:59:57 PM CST
 ************************************************************************/

/**
 * 类型 = 类型数据 + 类型操作
 * 类 = 类型
 * 对象 = 变量
 * 成员属性与方法
 */

#include<iostream>
#include<string>
using namespace std;

class Cat {};
class Dog {};
class People {
public:
	string name;
	int age;

	void say() {
		cout << "My name is " << name << ", " << age << " years old." << endl;
		return ;
	}
};

int main(int argc, char const *argv[]) {
	Cat garfiled;
	Dog odie1, odie2;
	People hug, song;

	hug.name = "Captain Hu";
	hug.age = 50;
	hug.say(); // 直接引用

	song.name = "Captain Song";
	song.age = 32;
	song.say(); // 直接引用
	return 0;
}
