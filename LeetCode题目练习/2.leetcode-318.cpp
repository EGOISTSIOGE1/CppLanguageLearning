/*************************************************************************
	> File Name: 2.leetcode-318.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 06 Nov 2023 08:29:50 AM CST
 ************************************************************************/
/*
*318. 最大单词长度乘积

给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。

 

示例 1：

输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
输出：16 
解释：这两个单词为 "abcw", "xtfn"。
示例 2：

输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
输出：4 
解释：这两个单词为 "ab", "cd"。
示例 3：

输入：words = ["a","aa","aaa","aaaa"]
输出：0 
解释：不存在这样的两个单词。
 

提示：

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] 仅包含小写字母
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxProduct(vector<string>& words){
        int length = words.size();
        vector<int> masks(length);
        for (int i = 0; i < length; ++i) {
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; ++j) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};


int main() {
    vector<string> words1{"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> words2{"a","ab","abc","d","cd","bcd","abcd"};
    vector<string> words3{"a","aa","aaa","aaaa"}; 

    Solution solution;
    int res1 = solution.maxProduct(words1);
    int res2 = solution.maxProduct(words2);
    int res3 = solution.maxProduct(words3);

    cout << "words1.res1 = " << res1 << endl;
    cout << "words2.res2 = " << res2 << endl;
    cout << "words3.res3 = " << res3 << endl;

    return 0;
}
