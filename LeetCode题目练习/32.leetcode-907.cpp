/*************************************************************************
	> File Name: 32.leetcode-907.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 27 Nov 2023 09:55:47 AM CST
 ************************************************************************/
/**
 * 907. 子数组的最小值之和

给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。

由于答案可能很大，因此 返回答案模 10^9 + 7 。

示例 1：

输入：arr = [3,1,2,4]
输出：17
解释：
子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
示例 2：

输入：arr = [11,81,94,43,3]
输出：444
 
提示：

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int sumSubarrayMins(vector<int>& arr) {
		int n = arr.size();
		vector<int> monoStack;
		vector<int> left(n), right(n);
		for (int i = 0; i < n; i++) {
			while (!monoStack.empty() && arr[i] <= arr[monoStack.back()]) {
				monoStack.pop_back();
			}
			left[i] = i - (monoStack.empty() ? -1 : monoStack.back());
			monoStack.emplace_back(i);
		}
		monoStack.clear();
		for (int i = n - 1; i >= 0; i--) {
			while (!monoStack.empty() && arr[i] < arr[monoStack.back()]) {
				monoStack.pop_back();
			}
			right[i] = (monoStack.empty() ? n : monoStack.back()) - i;
			monoStack.emplace_back(i);
		}
		long long ans = 0;
		long long mod = 1e9 + 7;
		for (int i = 0; i < n; i++) {
			ans = (ans + (long long)left[i] * right[i] * arr[i]) % mod;
		}
		return ans;
	}
};

int main(int argc, char const *argv[]) {
	vector<int> arr1 = {3,1,2,4}, arr2 = {11,81,94,43,3};
	Solution s;
	cout << "result_arr1: " << s.sumSubarrayMins(arr1) << endl;
	cout << "result_arr2: " << s.sumSubarrayMins(arr2) << endl;
	return 0;
}

