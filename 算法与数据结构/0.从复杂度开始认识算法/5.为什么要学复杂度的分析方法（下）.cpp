/*************************************************************************
	> File Name: 5.为什么要学复杂度的分析方法（下）.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:05:18 PM CST
 ************************************************************************/
/*
* 三、学会这几种复杂度，解决90%的问题
* 
* 1.O(1)时间复杂度
* 程序运行时间和问题规模之间的变化关系（只执行固定次数）
* 
* 2.O(n)时间复杂度
* 程序运行时间和问题规模之间的变化关系（成线性增长关系）
* 
* 3.O(n^2)时间复杂度
* 一般是循环套循环
* 
* 4.O(logn)时间复杂度
* for (int i = 1; i <= n; i *=2)
* {
*	cout << i << endl;
* }
* 实际运行次数[log2n] + 1次
* log2n + 1 == O(log2n) -> O(logn)，以什么为底不重要
* 
* 5.O(nm)时间复杂度
* int n, m;
* cin >> n >> m;
* for (int i = 0; i < n; i++)
* {
*	for (int j = 0; j < m; j++)
*	{
*		cout << i << " " << j << endl;
*	}
* }
* 遍历矩阵里的元素
* 
* 6.O(n+m)时间复杂度
* int n, m;
* cin >> n >> m;
* for (int i = 0; i < n; i++)
* {
*	cout << i << endl;
* }
* for (int i = 0; i < m; i++)
* {
*	cout << i << endl;
* }
*/

/*
* 随堂练习1：
* int n, m;
* cin >> n >> m;
* for (int i = 1; i <= n; i *= 4)
* {
*	for (int j = 0; j < m; j++)
*	{
*		cout << i << " " << j << endl;	
*	}
* }
* O(mlogn)
*/

/*
* 随堂练习2：
* int n, m;
* cin >> n >> m;
* for (int i = 0; i * i < n; i++)
* {
*	cout << i << endl;
* }
* 
* i^2 < n -> i < 根号n
* O(sqrt(n))  根号n
*/

#include<iostream>
using namespace std;

