/*************************************************************************
	> File Name: 11.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:28:03 PM CST
 ************************************************************************/

/*
* 263.火车进站
* 
* 题目描述：
*	  有n列火车按1到n的顺序从东方左转进站，这个车站是南北方向的，它虽然无限长，只可惜是一个死胡同，而且站台只有一条轨道，火车只能倒着从西方出去，而且每列火车必须进站，先进后出。
*	  进站的火车编号顺序为1~n，现在请你按火车编号从小到大的顺序，输出前20种可能的出站方案。
* 
* 输入：
*	  输入一行一个整数n。（n≤20）
* 输出：
*	  输出前20中答案，每行一种，不要空格。
* 
* 样例输入1
*	3
* 样例输出1
*	123
*	132
*	213
*	231
*	321
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

bool isValid(int a[], int n) {
	stack<int> s;
	int x = 1;
	for (int i = 0; i < n; i++) {
		if (s.empty() || s.top() < a[i]) {
			while (x <= a[i]) {
				s.push(x);
				x += 1;
			}
		}
		if (s.empty() || s.top() != a[i])return false;
		s.pop();
	}
	return true;
}

int main() {
	int n, a[25], cnt = 20;
	cin >> n;
	for (int i = 0; i < n; i++) a[i] = i + 1;
	do {
		if (isValid(a, n)) {
			for (int i = 0; i < n; i++) {
				cout << a[i];
			}
			cout << endl;
			cnt -= 1;
		}
	} while (next_permutation(a, a + n) && cnt);

	return 0;
}
