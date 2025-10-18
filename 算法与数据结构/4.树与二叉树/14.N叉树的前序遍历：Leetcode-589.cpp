/*************************************************************************
	> File Name: 14.N叉树的前序遍历：Leetcode-589.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 02 Jan 2024 10:45:38 AM CST
 ************************************************************************/

/**
 * 589. N 叉树的前序遍历

给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

示例 1：

输入：root = [1,null,3,2,4,null,5,6]
输出：[1,3,5,6,2,4]
示例 2：

输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 
提示：

节点总数在范围 [0, 104]内
0 <= Node.val <= 104
n 叉树的高度小于或等于 1000
*/

#include<iostream>
#include<vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution1 {
public:
    vector<int> preorder(Node* root) {
        if (root == NULL) return vector<int>();
		vector<int> ans;
		ans.push_back(root->val);
		// 依次扫描root的子节点
		for (auto x : root->children) {
			vector<int> temp = preorder(x);
			for (auto y : temp) {
				ans.push_back(y);
			}
		}
		return ans;
    }
};

// 重新封装以减少数据拷贝次数
class Solution2 {
public:
	void __preorder(Node *root, vector<int> &ans) {
		if (root == NULL) return ;
		ans.push_back(root->val);
		for (auto x : root->children) {
			__preorder(x, ans);
		}
		return ;
	}

    vector<int> preorder(Node* root) {
        vector<int> ans;
		__preorder(root, ans);
		return ans;
    }
};

int main(int argc, char const *argv[]) {

	return 0;
}
