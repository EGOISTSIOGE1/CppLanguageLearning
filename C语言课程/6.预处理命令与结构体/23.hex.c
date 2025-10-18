/*************************************************************************
	> File Name: 23.hex.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 16 Dec 2023 09:26:03 PM CST
 ************************************************************************/

#include<stdio.h>

union INT_NUMBER {
	struct {
		unsigned char b1:4;
		unsigned char b2:4;
	} bytes[4]; // 4个字节
	unsigned int number; // 4个字节
};

char code(unsigned int x) {
	if (x < 10) return '0' + x;
	return x - 10 + 'A';
}

int main(int argc, char const *argv[]) {
	union INT_NUMBER n;
	n.number =0x6a6b6c6d;
	printf("output result : ");
	for (int i = 3; i >= 0; i--) {
		printf("%c%c", code(n.bytes[i].b2), code(n.bytes[i].b1));
	}
	printf("\n");
	return 0;
}
