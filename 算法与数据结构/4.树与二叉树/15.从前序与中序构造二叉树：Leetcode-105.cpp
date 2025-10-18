/*************************************************************************
	> File Name: 15.从前序与中序构造二叉树：Leetcode-105.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 02 Jan 2024 11:33:15 AM CST
 ************************************************************************/

/**
 * 105. 从前序与中序遍历序列构造二叉树

给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1:

输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
 
提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列
*/

// 前序遍历 根 左 右
// 中序遍历 左 根 右

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return nullptr;
		int pos = 0, n = preorder.size();
		while (inorder[pos] != preorder[0]) pos += 1;
		TreeNode *root = new TreeNode(preorder[0]);
		vector<int> preArr, inArr;
		// 左子树部分
		for (int i = 1; i <= pos; i++) {
			preArr.push_back(preorder[i]);
		}
		for (int i = 0; i <= pos - 1; i++) {
			inArr.push_back(inorder[i]);
		}
		root->left = buildTree(preArr, inArr);
		preArr.clear();
		inArr.clear();
		// 右子树部分
		for (int i = pos + 1; i < n; i++) {
			preArr.push_back(preorder[i]);
		}
		for (int i = pos + 1; i < n; i++) {
			inArr.push_back(inorder[i]);
		}
		root->right = buildTree(preArr, inArr);
		return root;
    }

	void deleteTree(TreeNode *root) {
		if (root == nullptr) return ;
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
};

int main(int argc, char const *argv[]) {
	vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
	Solution solution;
	solution.buildTree(preorder, inorder);
	return 0;
}
