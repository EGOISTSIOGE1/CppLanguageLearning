/*************************************************************************
	> File Name: 21.HZOJ-95.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 05 Nov 2023 04:26:05 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);
    int shi, ge;
    shi = a / 10;
    ge = a % 10;
    b = 10 * ge + shi;
    printf("%d\n", b);

    return 0;
}
