/*************************************************************************
	> File Name: 37.leetcode-1094.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 02 Dec 2023 03:17:17 PM CST
 ************************************************************************/

/**
 * 1094. 拼车

车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）

给定整数 capacity 和一个数组 trips ,  trip[i] = [numPassengersi, fromi, toi] 表示第 i 次旅行有 numPassengersi 乘客，接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。

当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。

示例 1：

输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false
示例 2：

输入：trips = [[2,1,5],[3,3,7]], capacity = 5
输出：true
 
提示：

1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 105
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		int to_max = 0;
		for (const auto& trip : trips) {
			to_max = max(to_max, trip[2]);
		}

		vector<int> diff(to_max + 1);
		for (const auto& trip : trips) {
			diff[trip[1]] += trip[0];
			diff[trip[2]] -= trip[0];
		}

		int count = 0;
		for (int i = 0; i <= to_max; ++i) {
			count += diff[i];
            if (count > capacity) {
                return false;
            }
		}
		return true;
	}
};

int main(int argc, char const *argv[]) {
	vector<vector<int>> trips = {{2,1,5},{3,3,7}};
	int capacity1 = 4, capacity2 = 5;
	
	Solution s;
	cout << "result_1: " << s.carPooling(trips, capacity1) << endl;
	cout << "result_2: " << s.carPooling(trips, capacity2) << endl;
	return 0;
}
