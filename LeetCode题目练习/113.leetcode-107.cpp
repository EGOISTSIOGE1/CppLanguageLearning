/*************************************************************************
	> File Name: 113.leetcode-107.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 15 Feb 2024 02:21:00 PM CST
 ************************************************************************/

/**
 * 107. 二叉树的层序遍历 II

给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

示例 1：

输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]
 

提示：

树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000
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
	void dfs(TreeNode *root, int k, vector<vector<int>> &ans) {
		if (root == nullptr) return ;
		if (k == ans.size()) ans.push_back(vector<int>());
		ans[k].push_back(root->val);
		dfs(root->left, k + 1, ans);
		dfs(root->right, k + 1, ans);
		return ;
	}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		dfs(root, 0, ans); // root传入参数，0为层数，ans传出参数（返回值）
		for (int i = 0, j = ans.size() - 1; i < j; i++, j--) {
			swap(ans[i], ans[j]);
		}
		return ans;
    }
};

int main(int argc, const char** argv) {
	return 0;
}