/*************************************************************************
	> File Name: 4.public与private：代码演示.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 10 Jul 2024 12:29:59 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class People {
public:
	string name;
	int age;

	void say1() {
		cout << "say1: " << "My name is " << name << ", " << age << " years old" << endl;
	}

private:
	string name2;
	int age2;

public:
	void say2() {
		cout << "say2: " << "My name is " << name << ", " << age << " years old" << endl;
	}
};

int main(int argc, char const *argv[]) {
	People hug;
	hug.name = "Captain Hu";
	hug.age = 50;
	hug.say1();
	hug.say2();
	return 0;
}
