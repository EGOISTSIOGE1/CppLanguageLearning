/*************************************************************************
	> File Name: 12.序列M小和：HZOJ-285.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 20 May 2024 10:59:01 AM CST
 ************************************************************************/

/**
 * #285.序列M小和
 * 
 * 题目描述
 * 给出一个n*m的矩阵，每行取一个元素，组成一个包含n个元素的序列，一共有m^n种序列，求出序列和最小的前m个序列的序列和。
 * 
 * 输入
 * 输入两个整数n，m，接下来输入矩阵。
 * 
 * 输出
 * 输出最小的前m个序列的序列和，每两个数之间用空格隔开。
 * 
 * 样例输入
 * 2 3
 * 1 2 3
 * 2 2 3
 * 
 * 样例输出
 * 3 3 4
 * 
 * 证明：前N行的M小和一定在A和S组成的m*m个和中
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;

int main() {
	int n, m, t = 0;
	cin >> n >> m;
	set<PII> s;
	s.insert(PII(0, t++));
	for (int i = 0; i < n; i++) {
		int i1 = i % 2, i2 = 1 - i1;
		vector<int> temp;
		for (auto x : s) {
			temp.push_back(x.first);
		}
		s.clear();
		for (int j = 0, a; j < m; j++) {
			cin >> a;
			for (auto x : temp) {
				if (s.size() < m || s.begin()->first < x - a) {
					s.insert(PII(x - a, t++));
				}
				if (s.size() > m)
					s.erase(s.begin());
			}
		}
	}
	int flag = 0;
	for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
		if (flag) cout << " ";
		cout << -iter->first;
		flag = 1;
	}
	cout << '\n';

	return 0;
}