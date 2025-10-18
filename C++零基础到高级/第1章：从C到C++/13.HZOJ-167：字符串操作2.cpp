/*************************************************************************
	> File Name: 13.HZOJ-167：字符串操作2.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 29 Jun 2024 12:48:26 AM CST
 ************************************************************************/

/**
 * 题目描述
从键盘输入任意的一个字符串A ，其长度L 不小于6 ，同时再输入一个整数N （其中：N<L）作为插入点，以及任意的一个字符串B ，其长度为L1 （其中：L1<L ），现要求完成下列功能：

计算字符串A 的长度L ；
查找字符串A 中，从左到右第一个出现字母a 的位置；
在N 点处，插入字符串B 后，将得到一个新字符串C ，请计算并输出最后的字符串；
输入
输入包括三行：

第一行：长度为L​ 的字符串A(5≤L≤10000)​ ；
第二行：一个整数N ，作为字串的插入点（N<L )；
第三行：长度为L1​ 的字符串B​ （其中：L1<L​ ）。
输出
第一行：字符串A 的长度L ；
第二行：A 中第一个出现字母 a 的位置；
第三行：在N 点处，插入字符串B 后得到的新字符串。

样例输入1
ABCDabcdaxy
4
hello
样例输出1
11
5
ABChelloDabcdaxy
 */

#include<iostream>
#include<string>
using namespace std;

int main(int argc, const char** argv) {
	string a, b;
	int x;
	cin >> a >> x >> b;
	cout << a.size() << endl;
	cout << a.find('a') + 1 << endl;
	a.insert(x - 1, b);
	cout << a << endl;

	return 0;
}