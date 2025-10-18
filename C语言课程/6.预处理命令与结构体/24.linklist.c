/*************************************************************************
	> File Name: 24.linklist.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 16 Dec 2023 09:45:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *getNewNode(int val) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	return p;
}

Node *insert(Node *head, int pos, int val) {
	if (pos == 0) {
		Node *p = getNewNode(val);
		p->next = head;
		return p;
	}
	Node *p = head;
	for (int i = 1; i < pos; i++) p = p->next;
	Node *node = getNewNode(val);
	node->next = p->next;
	p->next = node;
	return head;
}

void clear(Node *head) {
	if (head == NULL) return ;
	for (Node *p = head, *q; p; p = q) {
		q = p->next;
		free(p);
	}
	return ;
}

void output_linklist(Node *head) {
	int n = 0;
	for (Node *p = head; p; p = p->next) n += 1;
	for (int i = 0; i < n; i++) {
		printf("%3d", i);
		printf("  ");
	}
	printf("\n");
	for (Node *p = head; p; p = p->next) {
		printf("%3d", p->data);
		printf("->");
	}
	printf("\n\n\n");
	return ;
}

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	#define MAX_OP 7
	Node *head = NULL;
	for (int i = 0; i < MAX_OP; i++) {
		int pos = rand() % (i + 1), val = rand() % 100;
		printf("insert %d at %d to linklist\n", val, pos);
		head = insert(head, pos, val);
		output_linklist(head);
	}
	clear(head);
	return 0;
}
