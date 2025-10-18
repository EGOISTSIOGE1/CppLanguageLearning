/*************************************************************************
	> File Name: 18.goto_for.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 17 Nov 2023 11:40:44 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int i = 1;
for_1:
	goto for_2;
for_2:
	if (i <= n) goto for_4;
	else goto for_end;
for_3:
	i++;
	goto for_2;
for_4:
	if (i % 3 == 0) goto for_3;
	printf("%d ", i);
	goto for_3;
for_end:
	printf("\n");
	return 0;
}