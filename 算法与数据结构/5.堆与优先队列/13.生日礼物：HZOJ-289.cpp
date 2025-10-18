/*************************************************************************
	> File Name: 13.生日礼物：HZOJ-289.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 21 May 2024 03:52:00 PM CST
 ************************************************************************/

/**
 * #289.生日礼物
 * 
 * 题目描述
 * 李华18岁生日的时候，小明给她看了一个神奇的序列A1，A2，。。。，An。她被允许选择不超过M个连续的部分作为自己的生日礼物。自然地，李华想要知道选择元素之和的最大值。你能帮助他吗？
 * 
 * 输入
 * 第一行，两个整数N（1≤N≤10^5）和M（0≤M≤10^5），序列的长度和可以选择的部分。
 * 第二行，N个整数A1，A2，。。。，An（0≤|Ai|≤10^4），序列。
 * 
 * 输出
 * 输出一个整数，表示最大的和。
 * 
 * 样例输入
 * 5 2
 * 2 -3 2 -1 2
 * 
 * 样例输出
 * 5
 * 
 * 结论1：可以将原序列看成是正负交替的一个序列
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<list>
#include<vector>
#include<set>
using namespace std;

#define MAX_N 100000
long long arr[MAX_N + 5];
int l[MAX_N + 5] = {0}, r[MAX_N + 5] = {0}, st[MAX_N + 5] = {0}; // l节点前一位 r节点后一位

typedef pair<int, int> PII;
set<PII> h;

void del(int x) {
	r[l[x]] = r[x];
	l[r[x]] = l[x];
	st[x] = 1;
	return ;
}

int main() {
	int n, m, k = 1;
	scanf("%d%d", &n, &m);
	scanf("%lld", arr + 1); // 下标从1开始
	for (int i = 1, a; i < n; i++) {
		scanf("%d", &a);
		if (1LL * arr[k] * a < 0) arr[++k] = a;
		else arr[k] += a;
	}
	long long cnt = 0, S = 0;
	n = k;
	for (int i = 1; i <= n; i++) {
		if (arr[i] > 0) {
			cnt += 1;
			S += arr[i];
		}
		h.insert(PII(abs(arr[i]), i));
		l[i] = i - 1;
		r[i] = i + 1;
	}
	while (cnt > m) {
		while (st[h.begin()->second]) h.erase(h.begin());
		int ind = h.begin()->second;
		h.erase(h.begin());
		int left = l[ind], right = r[ind];
		if ((left > 0 && right <= n) || arr[ind] > 0) {
			S -= abs(arr[ind]);
			cnt -= 1;
			arr[ind] += arr[left] + arr[right];
			h.insert(PII(abs(arr[ind]), ind));
			del(left);
			del(right);
		}
	}
	printf("%lld\n", S);
	return 0;
}