/*************************************************************************
	> File Name: 51.leetcode-2276.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 16 Dec 2023 05:04:43 PM CST
 ************************************************************************/

/**
 * 2276. 统计区间中的整数数目

给你区间的 空 集，请你设计并实现满足要求的数据结构：

新增：添加一个区间到这个区间集合中。
统计：计算出现在 至少一个 区间中的整数个数。
实现 CountIntervals 类：

CountIntervals() 使用区间的空集初始化对象
void add(int left, int right) 添加区间 [left, right] 到区间集合之中。
int count() 返回出现在 至少一个 区间中的整数个数。
注意：区间 [left, right] 表示满足 left <= x <= right 的所有整数 x 。

示例 1：

输入
["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
输出
[null, null, null, 6, null, 8]

解释
CountIntervals countIntervals = new CountIntervals(); // 用一个区间空集初始化对象
countIntervals.add(2, 3);  // 将 [2, 3] 添加到区间集合中
countIntervals.add(7, 10); // 将 [7, 10] 添加到区间集合中
countIntervals.count();    // 返回 6
                           // 整数 2 和 3 出现在区间 [2, 3] 中
                           // 整数 7、8、9、10 出现在区间 [7, 10] 中
countIntervals.add(5, 8);  // 将 [5, 8] 添加到区间集合中
countIntervals.count();    // 返回 8
                           // 整数 2 和 3 出现在区间 [2, 3] 中
                           // 整数 5 和 6 出现在区间 [5, 8] 中
                           // 整数 7 和 8 出现在区间 [5, 8] 和区间 [7, 10] 中
                           // 整数 9 和 10 出现在区间 [7, 10] 中

提示：

1 <= left <= right <= 109
最多调用  add 和 count 方法 总计 105 次
调用 count 方法至少一次
*/

#include<iostream>
#include<map>
using namespace std;

class CountIntervals {
public:
    CountIntervals() {

    }
    
    void add(int left, int right) {
		auto interval = mp.upper_bound(right);
		if (interval != mp.begin()) {
			interval--;
		}
		while (interval != mp.end() && interval->first <= right && interval->second >= left) {
			int l = interval->first, r = interval->second;
			left = min(left, l);
			right = max(right, r);
			cnt -= r - l + 1;
			mp.erase(interval);
			interval = mp.upper_bound(right);
			if (interval != mp.begin()) {
				interval--;
			}
		}
		cnt += (right - left + 1);
		mp[left] = right;
    }
    
    int count() {
		return cnt;
    }

private:
	int cnt = 0;
	map<int, int> mp;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main(int argc, char const *argv[]) {

	return 0;
}
