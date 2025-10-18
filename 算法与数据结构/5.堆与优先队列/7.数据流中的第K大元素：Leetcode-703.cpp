/*************************************************************************
	> File Name: 7.数据流中的第K大元素：Leetcode-703.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 16 Apr 2024 05:38:17 PM CST
 ************************************************************************/

/**
 * 703.数据流中的第K大元素
 * 
 * 设计一个找到数据流中第k大元素的类（class）。注意是排序后的第k大元素，不是第k个不同的元素。
 * 请实现KthLargest类：
 * KthLargest(int k, int[] nums)使用整数k和整数流nums初始化对象。
 * int add(int val)将val插入数据流nums后，返回当前数据流中第k大的元素。
 * 
 * 维护第k大值，就用小顶堆
 * 维护第k小值，就用大顶堆
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class KthLargest {
public:
	typedef pair<int, int> PII;
	int tot, k;
	set<PII> s;
	KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for (auto x : nums) {
			add(x);
		}
		return ;
	}

	int add(int val) {
		if (s.size() < k) {
			s.insert(PII(val, tot++));
		} else {
			if (s.begin()->first < val) {
				s.insert(PII(val, tot++));
			}
		}
		if (s.size() > k) s.erase(s.begin());
		return s.begin()->first;
	}
};