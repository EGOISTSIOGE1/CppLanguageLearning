/*************************************************************************
	> File Name: 107.leetcode-94.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 10 Feb 2024 06:59:41 PM CST
 ************************************************************************/

/**
 * 94. 二叉树的中序遍历

给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

示例 1：

输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
 
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
	void inorder(TreeNode* root, vector<int>& res) {
		if (root == nullptr) return ;
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}

    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
    }
};

int main(int argc, char const *argv[]) {
	
	return 0;
}
