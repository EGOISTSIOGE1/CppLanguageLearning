/*************************************************************************
	> File Name: 9.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:19:20 PM CST
 ************************************************************************/

/*
* 给你单链表的头节点head，请你反转链表，并返回反转后的链表。（头节点地址）
* 
* 1->2->3->4->5
*		↓
* 5->4->3->2->1
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


//链表头插法
class Solution_1 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode new_head, * p = head, * q;
		new_head.next = NULL;
		while (p) {
			q = p->next;
			p->next = new_head.next;
			new_head.next = p;
			p = q;
		}
		return new_head.next;
	}
};


//递归法
class Solution_2 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* tail = head->next;
		ListNode* new_head = reverseList(head->next);
		head->next = tail->next;
		tail->next = head;
		return new_head;
	}	
};

int main() {

	return 0;
}
