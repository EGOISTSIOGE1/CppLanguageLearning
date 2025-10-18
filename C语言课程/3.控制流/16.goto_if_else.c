/*************************************************************************
	> File Name: 16.goto_if_else.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 17 Nov 2023 11:16:43 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	n % 2 == 0 && ({goto if_stmt; 1;}); //小括号的作用是把大括号变成了有返回值的表达式，返回值为大括号中最后一个表达式的值（返回值无所谓，不影响当前功能）
	!(n % 2 == 0) && ({goto else_stmt; 1;});

if_stmt:
	printf("n is even\n");
	goto if_end;
else_stmt:
	printf("n is odd\n");
if_end:
	return 0;
}