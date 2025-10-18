/*************************************************************************
	> File Name: 2.优先队列：代码演示.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 27 Jan 2024 09:40:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROOT 1
#define cmp >
#define FATHER(i) ((i) / 2) 
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)
#define swap(a, b) { \
	printf("swap(%d, %d)\n", a, b); \
	__typeof(a) __c = (a); \
	(a) = (b); \
	(b) = __c; \
}

typedef struct PriorityQueue {
	int *__data, *data;
	int size, n; // size表示最多能存储多少，n表示当前存储了多少
} PriorityQueue;

PriorityQueue *initPQ(int size) {
	PriorityQueue *p = (PriorityQueue *)malloc(sizeof(PriorityQueue));
	p->__data = (int *)malloc(sizeof(int) * size);
	p->data = p->__data - ROOT;
	p->size = size;
	p->n = 0;
	return p;
}

int empty(PriorityQueue *p) {
	return p->n == 0;
}

int full(PriorityQueue *p) {
	return p->n == p->size;
}

int top(PriorityQueue *p) {
	return p->data[ROOT];
}

void up_update(int *data, int i) {
	/* 递归实现
	if (i == ROOT) return ;
	if (data[i] cmp data[FATHER(i)]) {
		swap(data[i], data[FATHER(i)]);
		up_update(data, FATHER(i)); 
	}
	*/

	// 循环实现
	printf("\nup update : %d\n", data[i]);
	while (i != ROOT && data[i] cmp data[FATHER(i)]) {
		swap(data[i], data[FATHER(i)]);
		i = FATHER(i);
	}
	printf("\n");
	return ;
}

void down_update(int *data, int i, int n) {
	printf("\ndown update : %d\n", data[i]);
	while (LEFT(i) <= n) {
		int ind = i, l = LEFT(i), r = RIGHT(i);	 // 指向三元组中的最大值
		if (data[l] cmp data[ind]) ind = l;
		if (r <= n && data[r] cmp data[ind]) ind = r;
		if (ind == i) break;
		swap(data[i], data[ind]);
		i = ind;
	}
	printf("\n");
	return ;
}

int push(PriorityQueue *p, int x) {
	if (full(p)) return 0;
	p->n += 1;
	p->data[p->n] = x;
	up_update(p->data, p->n);
	return 1;
}

int pop(PriorityQueue *p) {
	if (empty(p)) return 0;
	p->data[ROOT] = p->data[p->n];
	p->n -= 1;
	down_update(p->data, ROOT, p->n);
	return 1;
}

void clearPQ(PriorityQueue *p) {
	if (p == NULL) return ;
	free(p->__data);
	free(p);
	return ;
}

void output(PriorityQueue *p) {
	printf("PQ(%d) : ", p->n);
	for (int i = 1; i <= p->n; i++) {
		printf("%d ", p->data[i]);
	}
	printf("\n");
	return ;
}

int main() {
	int op, x;
	#define MAX_OP 100
	PriorityQueue *p = initPQ(MAX_OP);
	while (~scanf("%d", &op)) {
		if (op == 1) {
			scanf("%d", &x);
			printf("insert %d to priority_queue : \n", x);
			push(p, x);
			output(p);
		} else {
			printf("top : %d\n", top(p));
			pop(p);
			output(p);
		}
	}
	clearPQ(p);
	return 0;
}