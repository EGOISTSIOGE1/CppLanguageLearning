/*************************************************************************
	> File Name: 22.HZOJ-97.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 05 Nov 2023 04:32:45 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", 1LL * n * (1 + n) / 2);

    return 0;
}
