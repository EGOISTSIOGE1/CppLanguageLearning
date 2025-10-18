/*************************************************************************
	> File Name: 10.丑数II：Leetcode-264.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 May 2024 04:50:04 PM CST
 ************************************************************************/

/**
 * 264. 丑数 II

给你一个整数 n ，请你找出并返回第 n 个 丑数 。

丑数 就是质因子只包含 2、3 和 5 的正整数。

示例 1：

输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
示例 2：

输入：n = 1
输出：1
解释：1 通常被视为丑数。
 

提示：

1 <= n <= 1690
*/

#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		set<long long> s;
		s.insert(1);
		long long ans = 0, flag = 0;
		while (n--) {
			ans = *s.begin();
			s.erase(s.begin());
			if (ans % 5 == 0) flag = 2;
			else if (ans % 3 == 0) flag = 1;
			else flag = 0;
			switch (flag) {
				case 0: s.insert(ans * 2);
				case 1: s.insert(ans * 3);
				case 2: s.insert(ans * 5);
			}
			// if (ans % 5 == 0) {
			// 	s.insert(ans * 5);
			// } else if (ans % 3 == 0) {
			// 	s.insert(ans * 3);
			// 	s.insert(ans * 5);
			// } else {
			// 	s.insert(ans * 2);
			// 	s.insert(ans * 3);
			// 	s.insert(ans * 5);
			// }
		}
		return ans;
	}
};