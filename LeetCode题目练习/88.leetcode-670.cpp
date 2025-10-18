/*************************************************************************
	> File Name: 88.leetcode-670.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 22 Jan 2024 11:03:01 AM CST
 ************************************************************************/

/**
 * 670. 最大交换

给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :

输入: 9973
输出: 9973
解释: 不需要交换。
注意:

给定数字的范围是 [0, 108]
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
		string charArray = to_string(num);
		int n = charArray.size();
		int maxNum = num;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(charArray[i], charArray[j]);
				maxNum = max(maxNum, stoi(charArray));
				swap(charArray[i], charArray[j]);
			}
		}
		return maxNum;
    }
};

int main(int argc, const char** argv) {

	return 0;
}