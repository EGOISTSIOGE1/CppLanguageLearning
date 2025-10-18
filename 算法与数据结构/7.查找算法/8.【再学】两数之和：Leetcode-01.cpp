/*************************************************************************
	> File Name: 8.【再学】两数之和：Leetcode-01.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 22 Dec 2024 04:04:32 PM CST
 ************************************************************************/

/**
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
 

进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> h;
		vector<int> ret(2);
		for (int i = 0, I = nums.size(); i < I; i++) {
			if (h.find(target - nums[i]) != h.end()) {
				ret[0] = h[target - nums[i]];
				ret[1] = i;
				break;
			}
			h[nums[i]] = i;
		}
		return ret;
    }
};

class Solution1 {
public:
	int binary_search(vector<int> &nums, vector<int> &ind, int b, int x) {
		int head = b, tail = nums.size() - 1, mid;
		while (head <= tail) {
			mid = (head + tail) / 2;
			if (nums[ind[mid]] == x) return mid;
			if (nums[ind[mid]] < x) head = mid + 1;
			else tail = mid - 1;
		}
		return -1;
	}

    vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> ind(n, 0);
		for (int i = 0; i < n; i++) ind[i] = i;
		sort(ind.begin(), ind.end(), [&](int i, int j) -> bool {
			return nums[i] < nums[j];
		});
		vector<int> ret(2);
		for (int i = 0; i < n; i++) {
			int j = binary_search(nums, ind, i + 1, target - nums[ind[i]]);
			if (j == -1) continue;
			ret[0] = ind[j];
			ret[1] = ind[i];
		}
		if (ret[0] > ret[1]) swap(ret[0], ret[1]);
		return ret;
    }
};