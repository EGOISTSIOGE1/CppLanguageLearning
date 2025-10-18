/*************************************************************************
	> File Name: 11.leetcode-307.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 13 Nov 2023 08:42:03 AM CST
 ************************************************************************/

/**
 * 307. 区域和检索 - 数组可修改

给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值 更新 为 val
int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
 

示例 1：

输入：
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
输出：
[null, 9, null, 8]

解释：
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1,2,5]
numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
 

提示：

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
调用 update 和 sumRange 方法次数不大于 3 * 104 
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

class NumArray {
private:
	vector<int> sum;
	int size;
	vector<int>& nums;
public:
	NumArray(vector<int>& nums) : nums(nums){
		int n = nums.size();
		size = sqrt(n);
		sum.resize((n + size - 1) / size);
		for (int i = 0; i < n; ++i) {
			sum[i / size] += nums[i];
		}
	}

	void update(int index, int val) {
		sum[index / size] += val - nums[index];
		nums[index] = val;
	}

	int sumRange(int left, int right) {
		int b1 = left / size, i1 = left % size, b2 = right / size, i2 = right % size;
		if (b1 == b2) {
			return accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + i2 + 1, 0);
		}
		int sum1 = accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + size, 0);
		int sum2 = accumulate(nums.begin() + b2 * size, nums.begin() + b2 * size + i2 + 1, 0);
		int sum3 = accumulate(sum.begin() + b1 + 1, sum.begin() + b2, 0);
		return sum1 + sum2 + sum3;
	}
};

int main() {

	return 0;
}