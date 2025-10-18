/*************************************************************************
	> File Name: 61.leetcode-1349.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 26 Dec 2023 09:41:19 AM CST
 ************************************************************************/

/**
 * 1349. 参加考试的最大学生数

给你一个 m * n 的矩阵 seats 表示教室中的座位分布。如果座位是坏的（不可用），就用 '#' 表示；否则，用 '.' 表示。

学生可以看到左侧、右侧、左上、右上这四个方向上紧邻他的学生的答卷，但是看不到直接坐在他前面或者后面的学生的答卷。请你计算并返回该考场可以容纳的同时参加考试且无法作弊的 最大 学生人数。

学生必须坐在状况良好的座位上。

示例 1：

输入：seats = [["#",".","#","#",".","#"],
              [".","#","#","#","#","."],
              ["#",".","#","#",".","#"]]
输出：4
解释：教师可以让 4 个学生坐在可用的座位上，这样他们就无法在考试中作弊。 
示例 2：

输入：seats = [[".","#"],
              ["#","#"],
              ["#","."],
              ["#","#"],
              [".","#"]]
输出：3
解释：让所有学生坐在可用的座位上。
示例 3：

输入：seats = [["#",".",".",".","#"],
              [".","#",".","#","."],
              [".",".","#",".","."],
              [".","#",".","#","."],
              ["#",".",".",".","#"]]
输出：10
解释：让学生坐在第 1、3 和 5 列的可用座位上。
 
提示：

seats 只包含字符 '.' 和'#'
m == seats.length
n == seats[i].length
1 <= m <= 8
1 <= n <= 8
*/

#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
		int m = seats.size();
		int n = seats[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(1 << n));

		for (int row = 1; row <= m; row++) {
			for (int s = 0; s < (1 << n); s++) {
				bitset<8> bs(s);
				bool ok = true;
				for (int j = 0; j < n; j++) {
					if ((bs[j] && seats[row - 1][j] == '#') || (j < n - 1 && bs[j] && bs [j + 1])) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					dp[row][s] = -1;
					continue;
				}
				for (int last = 0; last < (1 << n); last++) {
					if (dp[row - 1][last] == -1) continue;
					bitset<8> lbs(last);
					bool flag = true;
					for (int j = 0; j < n; j++) {
						if (lbs[j] && ((j > 0 && bs[j - 1]) || (j < n - 1 && bs[j + 1]))){
							flag = false;
							break;
						}
					}
					if (flag) {
						dp[row][s] = max(dp[row][s], dp[row - 1][last] + (int)bs.count());
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < (1 << n); i++) {
			if (dp[m][i] > res) {
				res = dp[m][i];
			}
		}
		return res;
    }
};

int main(int argc, char const *argv[]) {

	return 0;
}
