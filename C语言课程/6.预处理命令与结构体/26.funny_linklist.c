/*************************************************************************
	> File Name: 26.funny_linklist.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 17 Dec 2023 03:51:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define offset(T, d) ((size_t)(&(((T *)(0))->d)))
#define start(addr, T, d) ((T *)(((void *)addr) - offset(T, d)))

enum DataType {
	A_type, 
	B_type,
	C_type,
	D_type,
	MAX_type
};

typedef struct Link {
	enum DataType type;
	struct Link *next;
} Link;

struct A {
	int x, y;
	Link l;
};

Link *getDataA() {
	struct A *a = (struct A *)malloc(sizeof(struct A));
	a->x = 3, a->y = 4;
	a->l.next = NULL;
	a->l.type = A_type;
	return &(a->l);
}

void output_A(Link *p) {
	struct A *a = start(p, struct A, l);
	printf("struct A : x = %d, y = %d\n", a->x, a->y);
	return ;
}

struct B {
	int a;
	Link l;
	double b;
};

Link *getDataB() {
	struct B *b = (struct B *)malloc(sizeof(struct B));
	b->a = 100, b->b = 45.3;
	b->l.next = NULL;
	b->l.type = B_type;
	return &(b->l);
}

void output_B(Link *p) {
	struct B *b = start(p, struct B, l);
	printf("struct B : a = %d, b = %lf\n", b->a, b->b);
	return ;
}

struct C {
	char c;
	Link l;
	const char *s;
	int t;
};

Link *getDataC() {
	struct C *c = (struct C *)malloc(sizeof(struct C));
	c->c = 'x', c->s = "struct C", c->t = 99;
	c->l.next = NULL;
	c->l.type = C_type;
	return &(c->l);
}

void output_C(Link *p) {
	struct C *c = start(p, struct C, l);
	printf("struct C : c = %c, s = %s, t = %d\n", c->c, c->s, c->t);
	return ;
}

struct D {
	long long a;
	Link l;
};

Link *getDataD() {
	struct D *d = (struct D *)malloc(sizeof(struct D));
	d->a = INT64_MAX;
	d->l.next = NULL;
	d->l.type = D_type;
	return &(d->l);
}

void output_D(Link *p) {
	struct D *d = start(p, struct D, l);
	printf("struct D : a = %lld\n", d->a);
	return ;
}

Link *(*getData[MAX_type])() = {
	getDataA, getDataB, getDataC, getDataD
};

void (*output[MAX_type])(Link *) = {
	output_A, output_B, output_C, output_D
};

int main(int argc, char const *argv[]) {
	#define MAX_OP 10
	Link head, *p = &head;
	for (int i = 0; i < MAX_OP; i++) {
		p->next = getData[rand() % MAX_type]();
		p = p->next;
	}
	for (p = head.next; p; p = p->next) {
		output[p->type](p);
	}

	return 0;
}
