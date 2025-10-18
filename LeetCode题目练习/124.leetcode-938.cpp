/*************************************************************************
	> File Name: 124.leetcode-938.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 26 Feb 2024 08:50:15 AM CST
 ************************************************************************/

/**
 * 938. 二叉搜索树的范围和

给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。

示例 1：

输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
输出：32
示例 2：

输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
输出：23
 
提示：

树中节点数目在范围 [1, 2 * 104] 内
1 <= Node.val <= 105
1 <= low <= high <= 105
所有 Node.val 互不相同
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

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
		if(root == nullptr) return 0;
		if(root->val > high) return rangeSumBST(root->left, low, high);
		if(root->val < low) return rangeSumBST(root->right, low, high);
		return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

int main(int argc, const char** argv) {
	return 0;
}