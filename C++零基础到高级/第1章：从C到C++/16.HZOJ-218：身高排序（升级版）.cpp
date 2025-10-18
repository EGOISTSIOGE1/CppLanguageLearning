/*************************************************************************
	> File Name: 16.HZOJ-218：身高排序（升级版）.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 04 Jul 2024 11:58:08 PM CST
 ************************************************************************/

/**
 * 题目描述
​ 有n个同学拍成一排，从左到右依次编号为1 ~ n
​ 现在给出了这个n位同学的身高，但是并不是按照高矮排序的。现在这些同学需要按照身高从矮到高的顺序重新排列，矮的同学在左边，高的同学在右边。如果两个同学身高相同，那么这两个同学的相对顺序不应该发生变化。
​ 请你输出排序以后从左到右同学的编号。

输入
​ 输入一个行一个整数n(1≤n≤100000)

​ 接下来一行输入n个整数，依次表示从左到右的同学的身高，每个同学身高小于等于300

输出
​ 一行输出n个整数，两个数中间用空格隔开，行末不要有多余空格。表示重新排列以后从左到右的同学的编号。

样例输入1
5
156 178 145 190 156
样例输出1
3 1 5 2 4
 */

#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
	map<int, vector<int>> arr;
	int n;
	cin >> n;
	for (int i = 1, h; i <= n; i++) {
		cin >> h;
		arr[h].push_back(i);
	}
	int flag = 0;
	for (auto x : arr) {
		for (auto y : x.second) {
			if (flag) cout << " ";
			cout << y;
			flag = 1;
		}
	}
	cout << endl;

	return 0;
}
