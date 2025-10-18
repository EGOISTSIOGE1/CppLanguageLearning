/*************************************************************************
	> File Name: 8.getchar_fflush.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 18 Dec 2023 11:19:32 PM CST
 ************************************************************************/

/**
 * 用于处理scanf残留字符问题
 * getchar 完美，最优选择
 * fflush  不完美
*/

#include<stdio.h>

#ifdef GETCHAR

int main(int argc, char const *argv[]) {
	int a, b;
	scanf("%d%d", &a, &b);
	getchar();
	// fflush(stdin);
	char c = 'x';
	scanf("%c", &c);
	printf("a = %d, b = %d, c = %c\n", a, b, c);
	return 0;
}

#endif

#ifdef FFLUSH

int main(int argc, char const *argv[]) {
	int a, b;
	scanf("%d%d", &a, &b);
	// getchar();
	fflush(stdin);
	char c = 'x';
	scanf("%c", &c);
	printf("a = %d, b = %d, c = %c\n", a, b, c);
	while (scanf("%c", &c) != EOF) {
		printf("%c", c);
	}
	printf("\n");
	return 0;
}

#endif