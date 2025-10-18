/*************************************************************************
	> File Name: 12.assign.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 Nov 2023 03:49:21 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    a = b = c = d;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    return 0;
}
