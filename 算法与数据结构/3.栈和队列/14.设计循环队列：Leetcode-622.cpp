/*************************************************************************
	> File Name: 14.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:28:15 PM CST
 ************************************************************************/

/*
* 622.设计循环队列
* 
* 设计你的循环队列实现。循环队列是一种线性数据结构，其操作表现基于FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
* 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
* 
* 你的实现应该支持如下操作：
* 
* MyCircularQueue(k)：构造器，设置队列长度为k。
* Front：从队首获取元素。如果队列为空，返回-1。
* Rear：获取队尾元素。如果队列为空，返回-1。
* enQueue(value)：向循环队列插入一个元素。如果成功插入则返回真。
* deQueue()：从循环队列中删除一个元素。如果成功删除则返回真。
* isEmpty()：检查循环队列是否为空。
* isFull()：检查循环队列是否已满。
* 
* 采用单向循环链表作为底层数据结构
*/

#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Node {
	int data;
	Node* next;
};


class MyCircularQueue {
public:
	int size, count;
	Node* head, * tail; //构造完成之后应该让队列的头指针和尾指针指向单向循环链表相应的位置，例如head应该指向0号位，tail应该指向0号位之前的那个节点（-1）
	MyCircularQueue(int k) {
		head = new Node();
		tail = head;
		for (int i = 1; i < k; i++) {
			tail->next = new Node();
			tail = tail->next; //尾节点每次向后移动一位，一直到k个节点，就完成单向链表的构建
		}
		tail->next = head; //将tail节点的指针指向头节点，这样就完成单项循环链表的构建
		size = k;
		count = 0;
		return;
	}

	bool enQueue(int value) {
		if (isFull()) return false;
		tail = tail->next;
		tail->data = value;
		count += 1;
		return true;
	}

	bool deQueue() {
		if (isEmpty()) return false;
		head = head->next;
		count -= 1;
		return true;
	}

	int Front() {
		if (isEmpty()) return -1;
		return head->data;
	}

	int Rear() {
		if (isEmpty()) return -1;
		return tail->data;
	}

	bool isEmpty() {
		return count == 0;
	}

	bool isFull() {
		return count == size;
	}
};


int main() {

	return 0;
}
