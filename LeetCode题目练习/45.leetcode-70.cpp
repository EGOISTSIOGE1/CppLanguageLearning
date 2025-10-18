/*************************************************************************
	> File Name: 45.leetcode-70.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 10 Dec 2023 03:25:10 PM CST
 ************************************************************************/

/**
 * 70. 爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

示例 1：

输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
示例 2：

输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
 
提示：

1 <= n <= 45
*/

#include<iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int p = 0, q = 0, r = 1;
		for (int i = 1; i <= n; i++) {
			p = q;
			q = r;
			r = p + q;
		}
		return r;
	}
};

int main(int argc, char const *argv[]) {
	int n1 = 2, n2 = 3;
	Solution s;
	cout << "result n1 : " << s.climbStairs(n1) << endl;
	cout << "result n2 : " << s.climbStairs(n2) << endl;
	return 0;
}
