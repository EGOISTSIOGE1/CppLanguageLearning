/*************************************************************************
	> File Name: 13.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:19:38 PM CST
 ************************************************************************/

/*
* 给你一个链表，删除链表的倒数第n个节点，并且返回链表的头节点
*/

#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//双指针等距移动法 + 虚拟头节点
		ListNode new_head, * p = &new_head, *q = p;
		new_head.next = head;
		for (int i = 0; i <= n; i++) {
			q = q->next;
		}
		while (q) {
			p = p->next, q = q->next;
		}
		p->next = p->next->next;
		return new_head.next;
	}
};


int main() {
	return 0;
}

