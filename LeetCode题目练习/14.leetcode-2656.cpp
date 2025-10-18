/*************************************************************************
	> File Name: 14.leetcode-2656.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 09:51:08 AM CST
 ************************************************************************/

/**
 * 2656. K 个元素的最大和

给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。你需要执行以下操作 恰好 k 次，最大化你的得分：

从 nums 中选择一个元素 m 。
将选中的元素 m 从数组中删除。
将新元素 m + 1 添加到数组中。
你的得分增加 m 。
请你返回执行以上操作恰好 k 次后的最大得分。

示例 1：

输入：nums = [1,2,3,4,5], k = 3
输出：18
解释：我们需要从 nums 中恰好选择 3 个元素并最大化得分。
第一次选择 5 。和为 5 ，nums = [1,2,3,4,6] 。
第二次选择 6 。和为 6 ，nums = [1,2,3,4,7] 。
第三次选择 7 。和为 5 + 6 + 7 = 18 ，nums = [1,2,3,4,8] 。
所以我们返回 18 。
18 是可以得到的最大答案。
示例 2：

输入：nums = [5,5,5], k = 2
输出：11
解释：我们需要从 nums 中恰好选择 2 个元素并最大化得分。
第一次选择 5 。和为 5 ，nums = [5,5,6] 。
第二次选择 6 。和为 6 ，nums = [5,5,7] 。
所以我们返回 11 。
11 是可以得到的最大答案。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maximizeSum(vector<int>& nums, int k) {
		int tmp_num = 0, sum = 0;
		sort(nums.begin(), nums.end());
		for (int i = 1; i <= k; ++i) {
			tmp_num = nums.back();
			sum += tmp_num;
			nums.pop_back();
			nums.push_back(tmp_num + 1);
		}
		return sum;
	}
};

int main() {
	vector<int> nums_1 = {1,2,3,4,5};
	vector<int> nums_2 = {5,5,5};

	int k1 = 3, k2 = 2;

	Solution solu;
	cout << "result_1: " << solu.maximizeSum(nums_1, k1) << "\n";
	cout << "result_2: " << solu.maximizeSum(nums_2, k2) << "\n";

	return 0;
}