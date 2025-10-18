/*************************************************************************
	> File Name: 14.排序链表：Leetcode-148（快速排序法）.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 13 Jun 2024 11:30:46 AM CST
 ************************************************************************/

/**
 * 148. 排序链表
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 示例 1：
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 示例 2：
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 * 
 * 示例 3：
 * 输入：head = []
 * 输出：[]
 * 
 * 提示：
 * 链表中节点的数目在范围 [0, 5 * 104] 内
 * -105 <= Node.val <= 105
*/

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		int l = head->val, r = head->val, z;
		ListNode *p = head, *h1 = nullptr, *h2 = nullptr, *q;
		while (p) l = min(p->val, l), r = max(p->val, r), p = p->next;
		if (l == r) return head;
		z = (l + r) >> 1; // 向下取整，/号是向0取整
		p = head;
		while (p) {
			q = p->next;
			if (p->val <= z) {
				p->next = h1;
				h1 = p;
			} else {
				p->next = h2;
				h2 = p;
			}
			p = q;
		}
		h1 = sortList(h1);
		h2 = sortList(h2);
		p = h1;
		while (p->next) p = p->next;
		p->next = h2;
		return h1;
    }
};

int main() {

	return 0;
}