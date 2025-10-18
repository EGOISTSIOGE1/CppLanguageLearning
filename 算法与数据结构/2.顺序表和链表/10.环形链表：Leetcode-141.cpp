/*************************************************************************
	> File Name: 10.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:19:26 PM CST
 ************************************************************************/

/*
* 给你一个链表的头节点head，判断链表中是否有环。
* 
* 如果链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环。为了表示给定链表中的环，评测系统内部使用整数
* pos来表示链表尾连接到链表中的位置（索引从0开始）。注意：
* pos不作为参数进行传递。仅仅是为了标识链表的实际情况。
* 
* 如果链表中存在环，则返回true。否则，返回false。
*/

#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		ListNode* p = head, * q = head;
		while (q && q->next) {
			p = p->next;
			q = q->next->next;
			if (p == q) return true;
		}
		return false;
	}
};

int main() {
	return 0;
}
