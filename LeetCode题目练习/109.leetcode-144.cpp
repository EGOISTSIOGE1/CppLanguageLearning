/*************************************************************************
	> File Name: 109.leetcode-144.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 11 Feb 2024 03:39:00 PM CST
 ************************************************************************/

/**
 * 144. 二叉树的前序遍历

给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：

输入：root = [1,null,2,3]
输出：[1,2,3]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：

输入：root = [1,2]
输出：[1,2]
示例 5：

输入：root = [1,null,2]
输出：[1,2]
 
提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
*/
#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void preorder(TreeNode *root, vector<int> &res) {
		if (root == nullptr) return ;
		res.push_back(root->val);
		preorder(root->left, res);
		preorder(root->right, res);
	}

    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorder(root, res);
		return res;
    }
};

int main(int argc, char const *argv[]) {

	return 0;
}
