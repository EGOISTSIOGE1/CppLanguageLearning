/*************************************************************************
	> File Name: 5.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:11:09 PM CST
 ************************************************************************/

/*
* #236.递归实现组合型枚举
* 从1-n这n个整数中随机选取m个，每种方案里的数从小到大排列，按字典序输出所有可能的选择方案
* 
* 1.f(i, j, n)
* 2.i==m->返回
* 3.f(i, j, n) = j + f(i+1, j+1, n)
*				 j+1 + f(i+1, j+2, n)
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int arr[10];

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

void f(int i, int j, int n, int m)
{
	if (i == m)
	{
		print_one_result(m);
		return;
	}
	for (int k = j; k <= n && m - i - 1 <= n - k; k++) 
	{
		arr[i] = k;
		f(i + 1, k + 1, n, m);
	}
	return;
}

int main()
{
	int n, m;
	cin >> n >> m;
	f(0, 1, n, m);
	return 0;
}
