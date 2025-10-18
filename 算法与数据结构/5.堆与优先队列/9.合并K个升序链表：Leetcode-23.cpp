/*************************************************************************
	> File Name: 9.合并K个升序链表：Leetcode-23.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 22 Apr 2024 05:39:52 PM CST
 ************************************************************************/

/**
 * 23.合并K个升序链表
 * 
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode*>& lists) {
		typedef pair<int, int> PII;	//	可重复
		int n = lists.size(); // 插入顺序
		set<PII> s;
		for (int i = 0; i < n; i++) {
			if (lists[i] == nullptr) continue;
			s.insert(PII(lists[i]->val, i)); // 第一个位置是具体的值，第二个位置是第几个链表
		}
		ListNode new_head, *p = &new_head, *q; // p指针就是指向结果链表的最后一位那个节点，虚拟头节点
		new_head.next = nullptr;
		while (s.size()) {
			PII a = *s.begin();
			s.erase(s.begin());
			q = lists[a.second];
			lists[a.second] = lists[a.second]->next;
			p->next = q;
			q->next = nullptr;
			p = q;
			if (lists[a.second]) {
				s.insert(PII(lists[a.second]->val, a.second));
			}
		}
		return new_head.next;
	}
};