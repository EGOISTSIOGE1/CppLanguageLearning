/*************************************************************************
	> File Name: 13.两数之和：Leetcode-01.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 11 Jun 2024 09:19:18 AM CST
 ************************************************************************/

/**
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案
 * 示例 1：
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * 示例 2：
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * 示例 3：
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * 提示：
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * 只会存在一个有效答案
*/

// 1、首先对元素组进行排序，最小值为第一个，最大值为最后一个
// 2、设置头尾两个指针，交替向中间移动查找目标值，如果相加小于目标值，就让头指针向后移动一位，如果相加大于目标值，就让尾指针向前移动一位，等于目标值输出答案

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> ind(n);
		for (int i = 0; i < n; i++) ind[i] = i;
		sort(ind.begin(), ind.end(), [&](int i, int j)->bool{
			return nums[i] < nums[j];
		});
		int p1 = 0, p2 = n - 1;
		while (nums[ind[p1]] + nums[ind[p2]] != target) {
			if (nums[ind[p1]] + nums[ind[p2]] < target) p1 += 1;
			else p2 -= 1;
		}
		vector<int> ret(2);
		ret[0] = ind[p1], ret[1] = ind[p2];
		if (ret[0] > ret[1]) swap(ret[0], ret[1]);
		return ret;
	}
};

int main() {

	return 0;
}