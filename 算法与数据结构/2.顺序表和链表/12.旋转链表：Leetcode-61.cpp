/*************************************************************************
	> File Name: 12.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:19:33 PM CST
 ************************************************************************/

/*
* 给你一个链表的头节点head，旋转链表，将链表每个节点向右移动k个位置。
* 
*		   1->2->3->4->5
* rotate 1 5->1->2->3->4
* rotate 2 4->5->1->2->3
*/

#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	int getLength(ListNode* head) {
		int n = 0;
		while (head) {
			n += 1;
			head = head->next;
		}
		return n;
	}

	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) return head;
		int n = getLength(head);
		k %= n;
		if (k == 0) return head;
		ListNode* p = head, * q = head;
		for (int i = 0; i <= k; i++) {
			p = p->next;
		}
		while (p) {
			p = p->next;
			q = q->next;
		}
		p = q->next;
		q->next = NULL;
		q = p;
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = head;
		return p;
	}
};

int main() {
	return 0;
}
