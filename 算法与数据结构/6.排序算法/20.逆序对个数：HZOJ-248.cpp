/*************************************************************************
	> File Name: 20.逆序对个数：HZOJ-248.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 18 Jun 2024 11:35:29 AM CST
 ************************************************************************/

/**
 * 248.逆序对个数
 * 
 * 题目描述：
 * 		输入N组数据，对每组数据输出逆序对个数。
 * 
 * 输入：
 * 		对于每组测试用例，第一行输入此组数据元素个数X，接下来X行，每行一个数，表示元素。（1 ≤ X ≤ 500000）
 * 		当读入的元素个数X为零时，程序结束。
 * 
 * 输出：
 * 		对于每组测试用例，输出一个数，表示逆序对个数。
 * 
 * 样例输入：
 * 	5
 * 	9
 * 	1
 * 	0
 * 	5
 * 	4
 * 	3
 * 	1
 * 	2
 * 	3
 * 	0
 * 
 * 样例输出：
 * 	6
 * 	0
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

#define MAX_N 500000
int arr[MAX_N + 5], temp[MAX_N + 5];

long long merge_sort(int *arr, int l, int r) {
	if (r - l <= 1) return 0;
	int mid = (l + r) / 2;
	long long a = merge_sort(arr, l, mid);
	long long b = merge_sort(arr, mid, r);
	long long c = 0; 
	int p1 = l, p2 = mid, k = 0;
	while (p1 < mid || p2 < r) {
		if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
			temp[k++] = arr[p1++];
		} else {
			temp[k++] = arr[p2++];
			c += (mid - p1);
		}
	} 
	for (int i = l; i < r; i++) arr[i] = temp[i - l];
	return a + b + c;
}

void solve(int n) {
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	printf("%lld\n", merge_sort(arr, 0, n));
	return ;
}

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		solve(n);
	}

	return 0;
}