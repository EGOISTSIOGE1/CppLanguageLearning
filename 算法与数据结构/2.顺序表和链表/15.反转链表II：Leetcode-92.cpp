/*************************************************************************
	> File Name: 15.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:19:48 PM CST
 ************************************************************************/

/*
* 反转链表II
* 给你单链表的头指针head和两个整数left和right，其中left <= right。请你反转从位置left到位置right的链表节点，返回反转后的链表。
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
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (left == 1 && right == 1) return head;
		if (left != 1) {
			head->next = reverseBetween(head->next, left - 1, right - 1);
		}
		else {
			ListNode* tail = head->next, *new_head;
			new_head = reverseBetween(head->next, left, right - 1);
			head->next = tail->next;
			tail->next = head;
			head = new_head;
		}
		return head;
	}
};


int main() {
	return 0;
}
