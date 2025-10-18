/*************************************************************************
	> File Name: 17.HZOJ-172：排序名单.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 05 Jul 2024 12:26:56 AM CST
 ************************************************************************/

/**
 * 题目描述
学习了字典序和字符串比较之后，今天让我们来给学生名单进行一下排序。我们知道海贼理工学院的每个精英班有10名学生，老师会依次给出10名学生的名字（均为不含有空格的英文字符串）。你需要将这些名字按照字典序从小到大进行输出。

输入
测评机会反复运行你的程序。每次程序运行时，你的程序会被输入10行不含有空格的字符串，分别对应十个学生的姓名（字符串长度均大于0且小于等于20）。

输出
输出为10行，为排序后的10个学生姓名，每个学生姓名单独占一行。

样例输入1
Alice
Bob
Gary
Harry
Ivn
Julia
Danis
Fone
Candy
Evan
样例输出1
Alice
Bob
Candy
Danis
Evan
Fone
Gary
Harry
Ivn
Julia
 */

/**
 * set 类说明
 * 		set类：有序集合
 * 		头文件：set
 * 		命名空间：std
 * 		声明：std<data_type> s;
 * 
 * 		s.insert(data) 	将data插入到集合s中
 * 		s.find(data)	查找集合s中是否存在元素data
 * 		s.erase(iter)	删除iter指向的元素
 * 		s.begin()		有序集合的起始位置
 * 		s.end()			有序集合的结束位置
 */

#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(int argc, char const *argv[]) {
	set<string> s;
	string name;
	for (int i = 0; i < 10; i++) {
		cin >> name;
		s.insert(name);
	}
	for (auto x : s) {
		cout << x << endl;
	}
	return 0;
}
