/*************************************************************************
	> File Name: 1.leetcode-187.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 05 Nov 2023 05:11:05 PM CST
 ************************************************************************/

 /*
  *187. 重复的DNA序列

DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。

例如，"ACGAATTCCG" 是一个 DNA序列 。
在研究 DNA 时，识别 DNA 中的重复序列非常有用。

给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。

 

示例 1：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：

输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
 

提示：

0 <= s.length <= 105
s[i]=='A'、'C'、'G' or 'T'
 * */

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
    const int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s){
        vector<string> ans;
        unordered_map<string, int> cnt;
        int n = s.length();
        for (int i = 0; i <= n - L; ++i) {
            string sub = s.substr(i, L);
            if (++cnt[sub] == 2) {
                ans.push_back(sub);
            }
        }
        return ans;
    }    
};


int main() {
    Solution test;
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = test.findRepeatedDnaSequences(s1);
    cout << res[0] << ", " << res[1] << endl;

    string s2 = "AAAAAAAAAAAAA";
    res = test.findRepeatedDnaSequences(s2);
    cout << res[0] << endl;
    
    return 0;
}
