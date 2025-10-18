/*************************************************************************
	> File Name: 12.HZOJ-166：字符串操作1.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 29 Jun 2024 12:33:32 AM CST
 ************************************************************************/

/**
 * 题目描述
从键盘输入任意的一个字符串A ，其长度L 不小于6 ，同时再输入一个整数N （其中：N<L）作为插入点，以及任意的一个字符串B ，其长度为L1 （其中：L1<L ），现要求完成下列功能：

如果字符串A 的长度L 大于100 输出 100 ，否则输出L ；

在N 点处，插入字符串B 后，将得到一个新字符串C ，请计算并输出最后的字符串；

查找字符串C 中，从右到左第一个出现字母 x 的位置。

输入
输入包括三行：

第一行：长度为L 的字符串A(5≤L≤10000) ；
第二行：一个整数N ，作为字串的插入点（N<L )；
第三行：长度为L1 的字符串B （其中：L1<L ）。
输出
第一行：如果字符串A 的长度L 大于100 输出 100，否则输出L ；
第二行：新字符串 C​ ；
第三行：字符串 C 中，从右到左第一个出现字母 x 的位置。

样例输入1
AAAAAA
2
xxx
样例输出1
6
AxxxAAAAA
6
 */

#include<iostream>
#include<string>
using namespace std;

int main(int argc, const char** argv) {
	string a, b;
	int x;
	cin >> a >> x >> b;
	cout << min((int)a.size(), 100) << endl;
	a.insert(x - 1, b);
	cout << a << endl;
	cout << a.size() - a.rfind('x') << endl;

	return 0;
}