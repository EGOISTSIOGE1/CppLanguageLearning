/*************************************************************************
	> File Name: 57.leetcode-1671.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 22 Dec 2023 09:02:39 AM CST
 ************************************************************************/

/**
 * 1671. 得到山形数组的最少删除次数

我们定义 arr 是 山形数组 当且仅当它满足：

arr.length >= 3
存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且：
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
给你整数数组 nums​ ，请你返回将 nums 变成 山形状数组 的​ 最少 删除次数。

示例 1：

输入：nums = [1,3,1]
输出：0
解释：数组本身就是山形数组，所以我们不需要删除任何元素。
示例 2：

输入：nums = [2,1,1,5,6,2,3,1]
输出：3
解释：一种方法是将下标为 0，1 和 5 的元素删除，剩余元素为 [1,5,6,3,1] ，是山形数组。
 
提示：

3 <= nums.length <= 1000
1 <= nums[i] <= 109
题目保证 nums 删除一些元素后一定能得到山形数组。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
		int n = nums.size();
		vector<int> pre = getLISArray(nums);
		vector<int> suf = getLISArray({nums.rbegin(), nums.rend()});
		reverse(suf.begin(), suf.end());

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (pre[i] > 1 && suf[i] > 1) {
				ans = max(ans, pre[i] + suf[i] - 1);
			}
		}
		return n - ans;
    }

	vector<int> getLISArray(const vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n), seq;
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
			if (it == seq.end()) {
				seq.push_back(nums[i]);
				dp[i] = seq.size();
			}
			else {
				*it = nums[i];
				dp[i] = it - seq.begin() + 1;
			}
		}
		return dp;
	}
};

int main(int argc, char const *argv[]) {
	vector<int> nums1 = {1,3,1}, nums2 = {2,1,1,5,6,2,3,1};
	Solution solution;
	cout << "nums1_result: " << solution.minimumMountainRemovals(nums1) << endl;
	cout << "nums2_result: " << solution.minimumMountainRemovals(nums2) << endl;
	return 0;
}
