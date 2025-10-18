/*************************************************************************
	> File Name: 4.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:36:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NODE 10

typedef struct Node {
	int key;
	struct Node* lchild, * rchild;
} Node;

//初始化二叉树节点
Node* getNewNode(int key) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->key = key;
	p->lchild = p->rchild = NULL;
	return p;
}


//插入节点的操作（随即插入），返回插入新的二叉树节点之后的根节点地址
Node* insert(Node* root, int key) {
	if (root == NULL)return getNewNode(key);
	if (rand() % 2) root->lchild = insert(root->lchild, key);
	else root->rchild = insert(root->rchild, key);
	return root;
}


//销毁二叉树节点，采用递归的方式进行销毁
//先清空左子树，再清空右子树
void clear(Node* root) {
	if (root == NULL)return;
	clear(root->lchild);
	clear(root->rchild);
	free(root); 
	return;
}


//广度优先遍历
Node* queue[MAX_NODE + 5];
int head, tail;

void bfs(Node* root) {
	head = tail = 0;
	queue[tail++] = root;
	while (head < tail) {
		Node* node = queue[head];
		printf("\nnode : %d\n", node->key);
		if (node->lchild) {
			queue[tail++] = node->lchild;
			printf("\t%d->%d (left)\n", node->key, node->lchild->key);
		}
		if (node->rchild) {
			queue[tail++] = node->rchild;
			printf("\t%d->%d (right)\n", node->key, node->rchild->key);
		}
		head++;
	}
	return;
}

int tot = 0;
//深度优先遍历,给每个节点打上区间范围
void dfs(Node* root) {
	if (root == NULL) return;
	int start, end;
	tot += 1;
	start = tot;
	if (root->lchild)dfs(root->lchild);
	if (root->rchild)dfs(root->rchild);
	tot += 1;
	end = tot;
	printf("%d : [%d, %d]\n", root->key, start, end);
	return;
}


int main() {
	srand((unsigned)time(0));
	Node* root = NULL;
	for (int i = 0; i < MAX_NODE; i++) {
		root = insert(root, rand() % 100);
	}
	bfs(root); //广度优先遍历 
	dfs(root); //深度优先遍历
	clear(root);
	return 0;
}
