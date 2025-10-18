/*************************************************************************
	> File Name: 150.leetcode-2549.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 23 Mar 2024 08:50:53 PM CST
 ************************************************************************/

/**
 * 2549. 统计桌面上的不同数字

给你一个正整数 n ，开始时，它放在桌面上。在 109 天内，每天都要执行下述步骤：

对于出现在桌面上的每个数字 x ，找出符合 1 <= i <= n 且满足 x % i == 1 的所有数字 i 。
然后，将这些数字放在桌面上。
返回在 109 天之后，出现在桌面上的 不同 整数的数目。

注意：

一旦数字放在桌面上，则会一直保留直到结束。
% 表示取余运算。例如，14 % 3 等于 2 。
 
示例 1：

输入：n = 5
输出：4
解释：最开始，5 在桌面上。 
第二天，2 和 4 也出现在桌面上，因为 5 % 2 == 1 且 5 % 4 == 1 。 
再过一天 3 也出现在桌面上，因为 4 % 3 == 1 。 
在十亿天结束时，桌面上的不同数字有 2 、3 、4 、5 。
示例 2：

输入：n = 3 
输出：2
解释： 
因为 3 % 2 == 1 ，2 也出现在桌面上。 
在十亿天结束时，桌面上的不同数字只有两个：2 和 3 。 

提示：

1 <= n <= 100
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int distinctIntegers(int n) {
        vector<int> nums(n + 1);
        nums[n] = 1;
        for (int k = 0; k < n; k++) {
            for (int x = 1; x <= n; x++) {
                if (nums[x] == 0) {
                    continue;
                }
                for (int i = 1; i <= n; i++) {
                    if (x % i == 1) {
                        nums[i] = 1;
                    }
                }
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main(int argc, const char** argv) {
	return 0;
}