/*************************************************************************
	> File Name: 19.HZOJ-90.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 05 Nov 2023 04:17:04 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int bai, shi, ge;
    bai = a / 100;
    shi = a % 100 / 10;
    ge = a % 10;
    printf("%d\n", bai);
    printf("%d\n", shi);
    printf("%d\n", ge);

    return 0;
}
