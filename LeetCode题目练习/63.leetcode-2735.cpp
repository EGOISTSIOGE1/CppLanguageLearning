/*************************************************************************
	> File Name: 63.leetcode-2735.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 28 Dec 2023 10:40:11 AM CST
 ************************************************************************/

/**
 * 2735. 收集巧克力

给你一个长度为 n 、下标从 0 开始的整数数组 nums ，表示收集不同巧克力的成本。每个巧克力都对应一个不同的类型，最初，位于下标 i 的巧克力就对应第 i 个类型。

在一步操作中，你可以用成本 x 执行下述行为：

同时修改所有巧克力的类型，将巧克力的类型 ith 修改为类型 ((i + 1) mod n)th。
假设你可以执行任意次操作，请返回收集所有类型巧克力所需的最小成本。

示例 1：

输入：nums = [20,1,15], x = 5
输出：13
解释：最开始，巧克力的类型分别是 [0,1,2] 。我们可以用成本 1 购买第 1 个类型的巧克力。
接着，我们用成本 5 执行一次操作，巧克力的类型变更为 [1,2,0] 。我们可以用成本 1 购买第 2 个类型的巧克力。
然后，我们用成本 5 执行一次操作，巧克力的类型变更为 [2,0,1] 。我们可以用成本 1 购买第 0 个类型的巧克力。
因此，收集所有类型的巧克力需要的总成本是 (1 + 5 + 1 + 5 + 1) = 13 。可以证明这是一种最优方案。
示例 2：

输入：nums = [1,2,3], x = 4
输出：6
解释：我们将会按最初的成本收集全部三个类型的巧克力，而不需执行任何操作。因此，收集所有类型的巧克力需要的总成本是 1 + 2 + 3 = 6 。
 
提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 109
1 <= x <= 109
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
		vector<int> f(nums);
		long long ans = accumulate(f.begin(), f.end(), 0LL);
		for (int k = 1; k < n; k++) {
			for (int i = 0; i < n; i++) {
				f[i] = min(f[i], nums[(i + k) % n]);
			}
			ans = min(ans, static_cast<long long>(k) * x + accumulate(f.begin(), f.end(), 0LL));
		}
		return ans;
    }
};

int main(int argc, char const *argv[]) {
	vector<int> nums1 = {20,1,15}, nums2 = {1,2,3};
	int x1 = 5, x2 = 4;
	Solution solution;
	cout << "result1: " << solution.minCost(nums1, x1) << endl;
	cout << "result2: " << solution.minCost(nums2, x2) << endl;
	return 0;
}
