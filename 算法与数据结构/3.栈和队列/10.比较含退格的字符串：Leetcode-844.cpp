/*************************************************************************
	> File Name: 10.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:27:58 PM CST
 ************************************************************************/

/*
* 844.比较含退格的字符串
* 
* 给定s和t两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回true。
* #代表退格字符。
* 
* 注意：如果对空文本输入退格字符，文本继续为空。
* 
* 
* 示例1：
* 输入：s = "ab#c", t = "ad#c"
* 输出：true
* 解释：s和t都会变成"ac"
* 
* 示例2：
* 输入：s = "ab##", t = "c#d#"
* 输出：true
* 解释：s和t都会变成""
*/

#include<iostream>
#include<stack>
#include<cstdlib>
#include<string>

using namespace std;

class Solution {
public:
	void pushStack(string& s, stack<char>& s1) {
		for (int i = 0; s[i]; i++) {
			if (s[i] == '#') {
				if(!s1.empty()) s1.pop();
			} else s1.push(s[i]);
		}
		return;
	}

	bool backspaceCompare(string s, string t) {
		stack<char> s1, s2;
		pushStack(s, s1);
		pushStack(t, s2);
		if (s1.size() != s2.size()) return false;
		while (!s1.empty()) {
			if (s1.top() != s2.top())return false;
			s1.pop(), s2.pop();
		}
		return true;
	}
};


int main() {
	return 0;
}
