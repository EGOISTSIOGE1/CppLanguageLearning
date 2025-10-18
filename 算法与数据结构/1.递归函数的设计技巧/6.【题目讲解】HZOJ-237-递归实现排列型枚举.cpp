/*************************************************************************
	> File Name: 6.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:11:16 PM CST
 ************************************************************************/

/*
* #237.递归实现排列型枚举
* 从1-n这n个整数排成一排并打乱次序，按字典序输出所有可能的选择方案
*
* 1.f(i, n)
* 2.i == n -> 返回
* 3.f(i, n) = v[0] + f(i+1, n)
*			  v[1] + f(i+1, n)
*/


#include<iostream>
#include<algorithm>

using namespace std;

int arr[10], vis[10] = { 0 };

void print_one_result(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i)
		{
			cout << " ";
		}
		cout << arr[i];
	}
	cout << endl;
	return;
}

void f(int i, int n)
{
	if (i == n)
	{
		print_one_result(n);
		return;
	}
	for (int k = 1; k <= n; k++)
	{
		if (vis[k])
		{
			continue;
		}
		arr[i] = k;
		vis[k] = 1;
		f(i + 1, n);
		vis[k] = 0;
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	f(0, n);

	return 0;
}
