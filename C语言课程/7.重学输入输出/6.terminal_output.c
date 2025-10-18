/*************************************************************************
	> File Name: 6.terminal_output.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 17 Dec 2023 07:30:29 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	freopen("/dev/pts/1", "w", stdout);
	char s[1000];
	while (scanf("%s", s) != EOF) {
		printf("from pts/0 : %s\n", s);
	}
	return 0;
}
