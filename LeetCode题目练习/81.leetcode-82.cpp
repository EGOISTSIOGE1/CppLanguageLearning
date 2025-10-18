/*************************************************************************
	> File Name: 81.leetcode-82.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 15 Jan 2024 08:49:54 AM CST
 ************************************************************************/

/**
 * 82. 删除排序链表中的重复元素 II

给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

示例 1：

输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：

输入：head = [1,1,1,2,3]
输出：[2,3]
 
提示：

链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序 排列
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
    ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return head;
		ListNode *dummyhead = new ListNode(0, head);
		ListNode *p = dummyhead;
		ListNode *q = head->next;
		ListNode *temp = nullptr;
		bool flag = false;
		while (q) {
			while (q && p->next->val == q->val) {
				temp = q;
				q = q->next;
				delete temp;
				flag = true;
			}
			if (flag) {
				delete p->next;
				p->next = q;
				flag = false;
			}
			else p = p->next;
			if (q) q = q->next;
		}
		temp = dummyhead->next;
		delete dummyhead;
		return temp;
    }
};

int main(int argc, char const *argv[]) {

	return 0;
}
