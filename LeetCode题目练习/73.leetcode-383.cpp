/*************************************************************************
	> File Name: 73.leetcode-383.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 07 Jan 2024 03:04:46 PM CST
 ************************************************************************/

/**
 * 383. 赎金信

给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true
 
提示：

1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote.size() > magazine.size()) return false;
		vector<int> cnt(26);
		for (auto &c : magazine) {
			cnt[c - 'a']++;
		}
		for (auto &c : ransomNote) {
			cnt[c - 'a']--;
			if (cnt[c - 'a'] < 0) {
				return false;
			}
		}
		return true;
    }
};

int main(int argc, char const *argv[]) {

	return 0;
}
