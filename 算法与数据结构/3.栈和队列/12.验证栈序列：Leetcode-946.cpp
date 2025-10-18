/*************************************************************************
	> File Name: 12.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:28:07 PM CST
 ************************************************************************/

/*
* 946.验证栈序列
* 
* 给定pushed和popped两个序列，每个序列中的值都不重复，只有当它们可能是在最初空栈上进行的推入push和弹出pop操作序列的结果时，返回true；否则，返回false。
* 
* 示例1：
* 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
* 输出：true
* 解释：我们可以按以下顺序执行：
* push(1), push(2), push(3), push(4), pop() -> 4,
* push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
* 
* 示例2：
* 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
* 输出：false
* 解释：1 不能在 2 之前弹出。
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int x = 0, n = pushed.size();
		stack<int> s;
		for (int i = 0; i < n; i++) {
			if (s.empty() || s.top() != popped[i]) {
				while (x < pushed.size() && pushed[x] != popped[i]) {
					s.push(pushed[x]);
					x += 1;
				}
				if (x == pushed.size()) return false;
				s.push(pushed[x]);
				x += 1;
			}
			s.pop();
		}
		return true;
	}
};


int main() {

	return 0;
}