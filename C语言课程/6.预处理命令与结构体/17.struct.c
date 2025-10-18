/*************************************************************************
	> File Name: 17.struct.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 11 Dec 2023 11:50:59 PM CST
 ************************************************************************/

/**
 * 结构体-对齐补齐规则
 * 1、类型都有一个对齐值，内建类型的对齐值等于其自身大小（只看类型）
 * 2、结构体的对齐值，等于其成员中的最大对齐值
 * 3、成员被存储在其整数倍的对齐值位置上
 * 4、可以通过#pragma pack限制对齐值得最大值
*/

#include<stdio.h>

struct A {			// 2
	char a;			// 1
	short b;		// 2
};

struct B {			// 8 如果没有写d，就是4
	struct A a; 	// 2
	struct {		
		char b;		// 1
		double c;	// 8
	} d;			// 8 如果没有写d，就不算其对齐值
	int e;			// 4
};

#pragma pack (1)
typedef struct person { //结构体得对齐值等于其成员中的最大对齐值，是4
	char name[20]; 	//对齐值是1
	int age;		//对齐值是4
	char gender;	//对齐值是1
	float height;	//对齐值是4
} person;
#pragma pack ()

void output(struct person *p) {
	printf("use pointer p : (%s, %d, %c, %f)\n", 
		p->name, 
		p->age, 
		p->gender, 
		p->height
	); // 间接访问（通过指针访问）
	return ;
}

void set_buff(char *buff, void * head, void *begin, void *end, char ch) {
	while (begin != end) {
		buff[begin - head] = ch;
		begin += 1;
	}
	return ;
}

void output_person() {
	int n = sizeof(struct person), len = 0;
	char buff[n];
	for (int i = 0; i < n; i++) buff[i] = '.';
	for (int i = 0; i < n; i++) {
		len += printf("%3d", i);
	}
	printf("\n");
	for (int i = 0; i < len; i++) printf("-");
	printf("\n");
	struct person hug;
	set_buff(buff, hug.name, hug.name, 20 + (void *)hug.name, 'n');
	set_buff(buff, hug.name, &hug.age, 4 + (void *)&hug.age, 'a');
	set_buff(buff, hug.name, &hug.gender, 1 + (void *)&hug.gender, 'g');
	set_buff(buff, hug.name, &hug.height, 4 + (void *)&hug.height, 'h');
	for (int i = 0; i < n; i++) {
		printf("%3c", buff[i]);
	}
	printf("\n");
	return ;
}

int main(int argc, char const *argv[]) {
	struct person hug = {"Captain Hu", 18, 'M', 2.13};
	person su = {"Su", 49, 'M', 2.12};
	printf("(%s, %d, %c, %f)\n", hug.name, hug.age, hug.gender, hug.height); // 直接访问（通过结构体变量访问）
	output(&hug);
	output(&su);
	printf("sizeof(struct person) = %lu\n", sizeof(struct person));
	output_person();
	return 0;
}
