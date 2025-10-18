/*************************************************************************
	> File Name: 4.leetcode-2485.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 06 Nov 2023 10:59:44 AM CST
 ************************************************************************/
/*
* 2485. 找出中枢整数
给你一个正整数 n ，找出满足下述条件的 中枢整数 x ：

1 和 x 之间的所有元素之和等于 x 和 n 之间所有元素之和。
返回中枢整数 x 。如果不存在中枢整数，则返回 -1 。题目保证对于给定的输入，至多存在一个中枢整数。

 

示例 1：

输入：n = 8
输出：6
解释：6 是中枢整数，因为 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21 。
示例 2：

输入：n = 1
输出：1
解释：1 是中枢整数，因为 1 = 1 。
示例 3：

输入：n = 4
输出：-1
解释：可以证明不存在满足题目要求的整数。
 

提示：

1 <= n <= 1000
* */

#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) return 1;
        int temp_num = (n * n + n) / 2;
        int x = sqrt(temp_num);
        if (x * x == temp_num) {
            return x;
        }
        return -1;
    }
};


int main() {
    int test_num1 = 8, test_num2 = 1, test_num3 = 4;
    Solution solu;
    cout << "test_num1_result: " << solu.pivotInteger(test_num1) << endl;
    cout << "test_num2_result: " << solu.pivotInteger(test_num2) << endl;
    cout << "test_num3_result: " << solu.pivotInteger(test_num3) << endl;

    return 0;
}
