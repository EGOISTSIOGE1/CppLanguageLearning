/*************************************************************************
	> File Name: 17.goto_while.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 17 Nov 2023 11:33:49 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int n, i = 0;
	scanf("%d", &n);

judge:
	if (i <= n) goto stmt;
	else goto while_end;
stmt:
	printf("%d ", i);
	i += 1;
	goto judge;
while_end:
	printf("\n");
	return 0;
}