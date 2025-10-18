/*************************************************************************
	> File Name: 14.HZOJ-170：禁止吸烟.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 29 Jun 2024 12:49:51 AM CST
 ************************************************************************/

/**
 * 题目描述
小明的学校设计了很多的标语，但是中间很多地方都把 No_smoking 写成了 Ban_smoking 。请 你找到这些错误并将他们替换成正确的结果。

输入
输入第一行为N
𝑁
 表示总共的标语数量。

之后的N
𝑁
 行每行有一个或多个待处理的标语。每个标语中不带有任何的空格。

输出
输出为N
𝑁
 行，为经过处理后的所有的标语。输出顺序与输入时保持一致。

样例输入1
4
Ban_smoking_is_good
Yes,We_are_good.Ban_smoking
I_ban_smoking
I_love_you,Ban_pig
样例输出1
No_smoking_is_good
Yes,We_are_good.No_smoking
I_ban_smoking
I_love_you,Ban_pig
 */

#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	string olds = "Ban_smoking", news = "No_smoking";
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		do {
			int pos = s.find(olds);
			if (pos == -1) break;
			s.replace(pos, olds.size(), news);
		} while (1);
		cout << s << endl;
	}

	return 0;
}
