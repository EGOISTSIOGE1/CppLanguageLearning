/*************************************************************************
	> File Name: 82.leetcode-2719.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 16 Jan 2024 08:42:40 AM CST
 ************************************************************************/

/**
 * 2719. 统计整数数目

给你两个数字字符串 num1 和 num2 ，以及两个整数 max_sum 和 min_sum 。如果一个整数 x 满足以下条件，我们称它是一个好整数：

num1 <= x <= num2
min_sum <= digit_sum(x) <= max_sum.
请你返回好整数的数目。答案可能很大，请返回答案对 109 + 7 取余后的结果。

注意，digit_sum(x) 表示 x 各位数字之和。

示例 1：

输入：num1 = "1", num2 = "12", min_num = 1, max_num = 8
输出：11
解释：总共有 11 个整数的数位和在 1 到 8 之间，分别是 1,2,3,4,5,6,7,8,10,11 和 12 。所以我们返回 11 。
示例 2：

输入：num1 = "1", num2 = "5", min_num = 1, max_num = 5
输出：5
解释：数位和在 1 到 5 之间的 5 个整数分别为 1,2,3,4 和 5 。所以我们返回 5 。

提示：

1 <= num1 <= num2 <= 1022
1 <= min_sum <= max_sum <= 400
*/

#include<iostream>
#include<cstring>

using namespace std;

class Solution {
    static constexpr int N = 23;
    static constexpr int M = 401;
    static constexpr int MOD = 1e9 + 7;
    int d[N][M];
    string num;
    int min_sum;
    int max_sum;

    int dfs(int i, int j, bool limit) {
        if (j > max_sum) {
            return 0;
        }
        if (i == -1) {
            return j >= min_sum;
        }
        if (!limit && d[i][j] != -1) {
            return d[i][j];
        }
        int res = 0;
        int up = limit ? num[i] - '0' : 9;
        for (int x = 0; x <= up; x++) {
            res = (res + dfs(i - 1, j + x, limit && x == up)) % MOD;
        }
        if (!limit) {
            d[i][j] = res;
        }
        return res;
    }

    int get(string num) {
        reverse(num.begin(), num.end());
        this->num = num;
        return dfs(num.size() - 1, 0, true);
    }

    // 求解 num - 1，先把最后一个非 0 字符减去 1，再把后面的 0 字符变为 9
    string sub(string num) {
        int i = num.size() - 1;
        while (num[i] == '0') {
            i--;
        }
        num[i]--;
        i++;
        while (i < num.size()) {
            num[i] = '9';
            i++;
        }
        return num;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(d, -1, sizeof d);
        this->min_sum = min_sum;
        this->max_sum = max_sum;
        return (get(num2) - get(sub(num1)) + MOD) % MOD;
    }
};

int main(int argc, char const *argv[]) {

	return 0;
}
