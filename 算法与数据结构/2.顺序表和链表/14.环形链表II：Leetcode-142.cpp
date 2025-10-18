/*************************************************************************
	> File Name: 14.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:19:44 PM CST
 ************************************************************************/

/*
* 环形链表II
* 给定一个链表的头节点head，返回链表开始入环的第一个节点。如果链表无环，则返回NULL。
* 如果链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环。为了表示给定链表中的环，
* 评测系统内部使用整数pos来表示链表尾连接到链表中的位置（索引从0开始）。如果pos是-1，则在该链表中没有环。
* 注意：pos不作为参数进行传递，仅仅是为了标识链表的实际情况。
* 
* 不允许修改链表。
*/

#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* p = head, * q = head;
		while (q && q->next) {
			p = p->next;
			q = q->next->next;
			if (p == q) break;
		}
		if (q == NULL || q->next == NULL) return NULL;
		p = head;
		while (p != q) p = p->next, q = q->next;
		return p;
	}
};


int main() {
	return 0;
}
