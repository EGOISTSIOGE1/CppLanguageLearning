/*************************************************************************
	> File Name: 27.leetcode-771.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 21 Nov 2023 09:37:00 AM CST
 ************************************************************************/
/**
 * 771. 宝石与石头

 给你一个字符串 jewels 代表石头中宝石的类型，另有一个字符串 stones 代表你拥有的石头。 stones 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

字母区分大小写，因此 "a" 和 "A" 是不同类型的石头。

示例 1：

输入：jewels = "aA", stones = "aAAbbbb"
输出：3
示例 2：

输入：jewels = "z", stones = "ZZ"
输出：0
 
提示：

1 <= jewels.length, stones.length <= 50
jewels 和 stones 仅由英文字母组成
jewels 中的所有字符都是 唯一的
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		int jewel_num = jewels.length();
		int stone_num = stones.length();
		int ans = 0;
		for (int i = 0; i < jewel_num; i++) {
			char jewel = jewels[i];
			for (int j = 0; j < stone_num; j++) {
				char stone = stones[j];
				if (jewel == stone) {
					ans++;
				}
			}
		}
		return ans;
	}
};

int main(int argc, char const *argv[]) {
	string jewels1 = "aA", stones1 = "aAAbbbb";
	string jewels2 = "z", stones2 = "ZZ";
	Solution s;
	cout << "result1: " << s.numJewelsInStones(jewels1, stones1) << "\n";
	cout << "result2: " << s.numJewelsInStones(jewels2, stones2) << "\n";

	return 0;
}
