/*************************************************************************
	> File Name: 21.士兵：HZOJ-251.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 11 Sep 2024 10:32:20 AM CST
 ************************************************************************/

/**
 * 题目描述
​ 一些士兵站在矩阵的一些方格内，现要把他们移动到一横排，并连续地排成一队，士兵一次可以选择四个方向中的一个方向移动一格，求最少需要移动多少步才能完成要求。

​ 即所有士兵的y坐标相同并且x坐标相邻。

输入
​ 第一行输入一个正整数 n，表示士兵的数量。（1≤n≤10000）
​ 接下来 n 行，每行两个数，代表第 i 个士兵所处位置的横纵坐标 Xi,Yi。（−10000≤Xi,Yi≤10000）
输出
​ 输出最少移动步数

样例输入
5
1 2
2 2
1 3
3 -2
3 3
样例输出
8
*/

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	int X, Y, costX = 0, costY = 0;
	sort(x.begin(), x.end());
	for (int i = 0; i < n; i++) x[i] = x[i] - i;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());\
	X = x[n / 2];
	Y = y[n / 2];
	for (int i = 0; i < n; i++) costX += abs(x[i] - X);
	for (int i = 0; i < n; i++) costY += abs(y[i] - Y);
	cout << costX + costY << endl;
	return 0;
}