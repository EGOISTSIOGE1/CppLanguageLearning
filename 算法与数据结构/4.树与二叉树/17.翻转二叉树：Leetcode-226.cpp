/*************************************************************************
	> File Name: 17.翻转二叉树：Leetcode-226.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 04 Jan 2024 05:17:47 PM CST
 ************************************************************************/

/**
226. 翻转二叉树

给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 
示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
示例 2：

输入：root = [2,1,3]
输出：[2,3,1]
示例 3：

输入：root = []
输出：[]
*/

#include<iostream>
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

// 先交换根节点左右子树，再翻转左节点，右节点
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
    }
};

int main(int argc, char const *argv[]) {

	return 0;
}
