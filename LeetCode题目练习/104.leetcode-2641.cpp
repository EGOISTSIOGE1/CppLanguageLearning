/*************************************************************************
	> File Name: 104.leetcode-2641.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 07 Feb 2024 01:45:05 PM CST
 ************************************************************************/

/**
 * 2641. 二叉树的堂兄弟节点 II

给你一棵二叉树的根 root ，请你将每个节点的值替换成该节点的所有 堂兄弟节点值的和 。

如果两个节点在树中有相同的深度且它们的父节点不同，那么它们互为 堂兄弟 。

请你返回修改值之后，树的根 root 。

注意，一个节点的深度指的是从树根节点到这个节点经过的边数。

示例 1：

输入：root = [5,4,9,1,10,null,7]
输出：[0,0,0,7,7,null,11]
解释：上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 5 的节点没有堂兄弟，所以值修改为 0 。
- 值为 4 的节点没有堂兄弟，所以值修改为 0 。
- 值为 9 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 10 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 7 的节点有两个堂兄弟，值分别为 1 和 10 ，所以值修改为 11 。
示例 2：

输入：root = [3,1,2]
输出：[0,0,0]
解释：上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 3 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点没有堂兄弟，所以值修改为 0 。
- 值为 2 的节点没有堂兄弟，所以值修改为 0 。
 
提示：

树中节点数目的范围是 [1, 105] 。
1 <= Node.val <= 104
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> q = {root};
        root->val = 0;
        while (!q.empty()) {
            vector<TreeNode*> q2;
            int sum = 0;
            for (auto fa : q) {
                if (fa->left) {
                    q2.push_back(fa->left);
                    sum += fa->left->val;
                }
                if (fa->right) {
                    q2.push_back(fa->right);
                    sum += fa->right->val;
                }
            }
            for (auto fa : q) {
                int child_sum = (fa->left ? fa->left->val : 0) + 
                                (fa->right ? fa->right->val : 0);
                if (fa->left) {
                    fa->left->val = sum - child_sum;
                }
                if (fa->right) {
                    fa->right->val = sum - child_sum;
                }
            }
            q = move(q2);
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {

	return 0;
}
