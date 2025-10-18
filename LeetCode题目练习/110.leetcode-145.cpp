/*************************************************************************
	> File Name: 110.leetcode-145.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 12 Feb 2024 04:19:10 PM CST
 ************************************************************************/

/**
 * 145. 二叉树的后序遍历

给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

示例 1：

输入：root = [1,null,2,3]
输出：[3,2,1]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
 
提示：

树中节点的数目在范围 [0, 100] 内
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
	void postorder(TreeNode *root, vector<int> &res) {
		if (root == nullptr) return ;
		postorder(root->left, res);
		postorder(root->right, res);
		res.push_back(root->val);
	}

    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorder(root, res);
		return res;
    }
};

int main(int argc, const char** argv) {
	return 0;
}