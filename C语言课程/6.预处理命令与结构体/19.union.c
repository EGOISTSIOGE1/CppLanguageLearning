/*************************************************************************
	> File Name: 19.union.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 13 Dec 2023 11:33:43 PM CST
 ************************************************************************/

#include<stdio.h>

union A { 		// 占用大小为成员最大占用大小，其共用数据存储空间，如果其中有值将其改掉，其他字段读出的值也会变化
	struct {
		unsigned char byte1;
		unsigned char byte2;
		unsigned char byte3;
		unsigned char byte4;
	} bytes;
	unsigned int number;
};

#define P(a, format) { \
	printf("%s = " format "\n", #a, a); \
}

int main(int argc, char const *argv[]) {
	union A a;
	a.number = 0x61626364;
	P(a.number, "%x");
	P(a.bytes.byte1, "%x");
	P(a.bytes.byte2, "%x");
	P(a.bytes.byte3, "%x");
	P(a.bytes.byte4, "%x");
	P(sizeof(union A), "%lu");
	P(&a.number, "%p");
	P(&a.bytes.byte1, "%p");
	P(&a.bytes.byte2, "%p");
	P(&a.bytes.byte3, "%p");
	P(&a.bytes.byte4, "%p");
	return 0;
}
