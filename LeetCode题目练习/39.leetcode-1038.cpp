/*************************************************************************
	> File Name: 39.leetcode-1038.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 04 Dec 2023 09:32:44 AM CST
 ************************************************************************/

/**
 * 1038. 从二叉搜索树到更大和树

给定一个二叉搜索树 root (BST)，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。

提醒一下， 二叉搜索树 满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
 
示例 1：

输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
示例 2：

输入：root = [0,null,1]
输出：[1,null,1]

提示：

树中的节点数在 [1, 100] 范围内。
0 <= Node.val <= 100
树中的所有值均 不重复 。
*/

#include<iostream>
using namespace std;

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
	TreeNode* getSuccessor(TreeNode* node) {
		TreeNode* succ = node->right;
		while (succ->left!= nullptr && succ->left != node) {
            succ = succ->left;
        }
		return succ;
	}

	TreeNode* bstToGst(TreeNode* root) {
		int sum = 0;
		TreeNode* node = root;
		while (node != nullptr) {
			if (node->right == nullptr) {
				sum += node->val;
                node->val = sum;
                node = node->left;
			} else {
				TreeNode* succ = getSuccessor(node);
                if (succ->left == nullptr) {
					succ->left = node;
					node = node->right;
				} else {
					succ->left = nullptr;
					sum += node->val;
					node->val = sum;
					node = node->left;
				}
			}
		}
		return root;
	}
};

int main(int argc, char const *argv[]) {

	return 0;
}
