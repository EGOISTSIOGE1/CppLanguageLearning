/*************************************************************************
	> File Name: 14.HZOJ-147.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 Nov 2023 05:41:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

char s[10005];

int main(int argc, char const *argv[]) {
	scanf("%s", s);
	if (s[strlen(s) - 1] % 2) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}
