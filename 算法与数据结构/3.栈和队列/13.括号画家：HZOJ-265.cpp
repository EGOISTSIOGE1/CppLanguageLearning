/*************************************************************************
	> File Name: 13.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:28:11 PM CST
 ************************************************************************/

/*
* 265.括号画家
* 
* 题目描述：
*	  Candela是一名漫画家，她有一个奇特的爱好，就是在纸上画括号。这一天，刚刚起床的Candela画了一排括号序列，其中包括小括号()、中括号[]和大括号{}，总长度为N。这排随意绘制的括号序列显得杂乱无章，
* 于是Candela定义了什么样的括号序列是美观的：
*	  1、空的括号序列是美观的；
*	  2、若括号序列'A'是美观的，则括号序列'(A)、[A]、{A}'也是美观的；
*	  3、若括号序列'A、B'都是美观的，则括号序列'AB'也是美观的；
* 
*	  例如[(){}]()是美观的括号序列，而)({)[}](则不是。
*	  现在Candela想在她绘制的括号序列中，找出其中连续的一段，满足这段子序列是美观的，并且长度尽量大，你能帮帮她吗？
* 
* 输入
*	  1个长度为N的括号序列。(5≤N≤10000)
* 
* 输出
*	  一个整数。表示最长的美观的连续子序列的长度。
* 
* 样例输入
* [[[[]]{}]]
* 
* 样例输出
* 10
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>

using namespace std;

#define MAX_N 10000
char str[MAX_N + 5];
int match[MAX_N + 5] = {0}; //match[i]所存储的就是和i位置的括号所匹配的另外一个括号的位置，match[i]==0表示没有合法的匹配，match[i]!=0表示匹配括号的位置
stack<int> s;


int main() {
	cin >> (str + 1); //使字符第一位存储在字符数组的1位置，下标从1开始
	for (int i = 1; str[i]; i++) { //遍历字符串的每一位
		switch (str[i]) {
		case '(':
		case '[':
		case '{': s.push(i); break; //栈中不存储括号，存储括号位置的下标位置i
		case ')': {
			if (!s.empty() && str[s.top()] == '(') {
				match[s.top()] = i; //记录匹配位置信息
				match[i] = s.top(); //与上一行代码意思相同，可不写
				s.pop();
			}
			else {
				s.push(i); //如果没有匹配的左括号，就将右括号压入栈顶，证明当前位置之前的所有括号已经非法，作为信息隔断
			}
		} break;
		case ']': {
			if (!s.empty() && str[s.top()] == '[') {
				match[s.top()] = i; //记录匹配位置信息
				match[i] = s.top(); //与上一行代码意思相同，可不写
				s.pop();
			}
			else {
				s.push(i); //如果没有匹配的左括号，就将右括号压入栈顶，证明当前位置之前的所有括号已经非法，作为信息隔断
			}
		} break;
		case '}': {
			if (!s.empty() && str[s.top()] == '{') {
				match[s.top()] = i; //记录匹配位置信息
				match[i] = s.top(); //与上一行代码意思相同，可不写
				s.pop();
			}
			else {
				s.push(i); //如果没有匹配的左括号，就将右括号压入栈顶，证明当前位置之前的所有括号已经非法，作为信息隔断
			}
		} break;
		}
	}
	int temp_ans = 0, ans = 0, i = 1;
	while (str[i]) {
		if (match[i]) {//首先判断i的位置有没有和它匹配的位置，如果存在，直接跳到匹配位置的后一位，如果不存在，则i位置直接向后走一步
			temp_ans += (match[i] - i + 1); //有匹配位置，先记录匹配长度，再跳到匹配位置的后一位
			i = match[i] + 1;
		}
		else {
			i += 1; //如果没有匹配，就跳到下一位
			temp_ans = 0;
		}
		if (temp_ans > ans) ans = temp_ans;
	}
	cout << ans << endl;

	return 0;
}
