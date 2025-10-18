/*************************************************************************
	> File Name: 3.scanf_printf.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 22 Oct 2023 05:28:56 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b, c, d;
    int ret_scanf = scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("ret_scanf = %d\n", ret_scanf);
    printf("%d, %d, %d, %d\n", a, b, c, d);
    return 0;
}
