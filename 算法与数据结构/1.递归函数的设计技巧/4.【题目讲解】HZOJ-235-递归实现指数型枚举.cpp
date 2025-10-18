/*************************************************************************
	> File Name: 4.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:11:04 PM CST
 ************************************************************************/

/*
* #235.递归实现指数型枚举
* 从1-n这n个整数中随机选取任意多个，每种方案里的数从小到大排列，按字典序输出所有可能的选择方案
* 
* 1.f(i, j, n)  第i个位置开始枚举，可以选择最小的数字是j，最大位置为n
* 2.j > n -> 返回
* 3.f(i, j, n){
* j + f(i+1, j+1, n)
* j+1 + f(i+1, j+2, n)
* j+2 + f(i+1, j+3, n)
* .
* .
* .
* n + f(i + 1, n + 1, n)
* }
*/


#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int arr[10];

void print_one_result(int n)
{
	for (int i = 0; i <= n; i++)
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

void f(int i, int j, int n)
{
	if (j > n) return;
	for (int k = j; k <= n; k++)
	{
		arr[i] = k;
		print_one_result(i);
		f(i + 1, k + 1, n);
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	f(0, 1, n);
	return 0;
}
