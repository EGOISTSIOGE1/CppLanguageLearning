/*************************************************************************
	> File Name: 9.leetcode-765.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 11 Nov 2023 01:39:16 PM CST
 ************************************************************************/

/*
765. 情侣牵手

n 对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手。

人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的 ID。情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)。

返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起。 每次交换可选择任意两人，让他们站起来交换座位。

 

示例 1:

输入: row = [0,2,1,3]
输出: 1
解释: 只需要交换row[1]和row[2]的位置即可。
示例 2:

输入: row = [3,2,0,1]
输出: 0
解释: 无需交换座位，所有的情侣都已经可以手牵手了。
 

提示:

2n == row.length
2 <= n <= 30
n 是偶数
0 <= row[i] < 2n
row 中所有元素均无重复
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
private:
	int getf(vector<int>& f, int x) {
		if (f[x] == x) return x;
		int newf = getf(f, f[x]);
		f[x] = newf;
		return newf;
	}

	void add(vector<int>& f, int l, int r) {
		int fl = getf(f, l);
		int fr = getf(f, r);
		f[fl] = fr;
	}

public:
	int minSwapsCouples(vector<int>& row) {
		int n = row.size();
		int tot = n / 2;
		vector<int> f(tot, 0);
		for (int i = 0; i < tot; ++i) {
			f[i] = i;
		}
		for (int i = 0; i < n; i += 2) {
			int l = row[i] / 2;
			int r = row[i + 1] / 2;
			add(f, l, r);
		}
		unordered_map<int, int> m;
		for (int i = 0; i < tot; ++i) {
			int fx = getf(f, i);
			m[fx]++;
		}
		int ret = 0;
		for (const auto& [f, sz] : m) {
			ret += sz - 1; 
		}
		return ret;
	}
};

int main() {
	vector<int> row1 = {0,2,1,3};
	vector<int> row2 = {3,2,0,1};

	Solution solu;
	cout << "row1_result = " << solu.minSwapsCouples(row1) << endl;
	cout << "row2_result = " << solu.minSwapsCouples(row2) << endl;

	return 0;
}