/*************************************************************************
	> File Name: 8.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:27:39 PM CST
 ************************************************************************/

/*
* #595.程序调用关系
* 
* 题目描述
* 
*	  众所周知，计算机程序中通常含有许多的函数调用，而调用关系往往是嵌套的，也就是说被调用的函数可能会调用另一个函数，这导致我们常常在debug的时候
* 遇到困难，并希望能弄清楚其上层的一系列调用关系。
*     在这道题目中，我们会给定一篇代码，并希望你能找到指定函数第一次被调用时的调用链，将其打印出来；当然，你有可能会发现给定的函数没有在代码中出现，
* 那么你应该打印一行“NOT REFERENCED”并结束你的程序。
*	  为了降低难度，给定的代码是经过极度简化的，它只包括函数调用和返回语句（表示退出这层调用），并且没有任何额外的语法格式。
* 
* 
* 输入：
*	  第一行是一个数字N，代表代码共有N行；
*	  接下来的N行，第i+1行是一个字符串S[i]，代表第i行代码：
*		  1、这行代码是一个函数调用，那么他的形式类似“fun()”；
*		  2、这行代码是返回语句，它的内容固定为“return”；
*/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>

using namespace std;

int main() {
	int flag = 0, n;
	cin >> n;
	vector<string> ops(n), s; //用数组模拟栈
	string target;
	for (int i = 0; i < n; i++) cin >> ops[i];
	cin >> target;
	for (int i = 0; i < n; i++) {
		if (target == ops[i]) {
			s.push_back(ops[i]);
			flag = 1;
			break;
		}
		if (ops[i] == "return") s.pop_back();
		else s.push_back(ops[i]);
	}
	if (flag) {
		for (int i = 0; i < s.size(); i++) {
			if (i)cout << "->";
			cout << s[i];
		}
		cout << endl;
	}
	else {
		cout << "NOT REFERENCED" << endl;
	}

	return 0;
}
