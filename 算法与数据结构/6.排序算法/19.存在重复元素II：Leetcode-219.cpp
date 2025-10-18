/*************************************************************************
	> File Name: 19.存在重复元素II：Leetcode-219.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 18 Jun 2024 09:58:38 AM CST
 ************************************************************************/

/**
 * 219. 存在重复元素 II

给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1
输出：true
示例 3：

输入：nums = [1,2,3,1,2,3], k = 2
输出：false

提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> ind(n);
		for (int i = 0; i < n; i++) ind[i] = i;
		sort(ind.begin(), ind.end(), [&](int i, int j) -> bool {
			if (nums[i] != nums[j]) return nums[i] < nums[j];
			return i < j;
		});
		for (int i = 0, I = n - 1; i < I; i++) {
			if (nums[ind[i]] - nums[ind[i + 1]]) continue;
			if (ind[i + 1] - ind[i] <= k) return true;
		}
		return false;
    }
};

int main() {

	return 0;
}