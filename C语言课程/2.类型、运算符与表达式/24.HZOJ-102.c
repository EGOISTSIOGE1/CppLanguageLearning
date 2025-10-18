/*************************************************************************
	> File Name: 24.HZOJ-102.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 05 Nov 2023 04:55:38 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    double a, b, c, t;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &t);
    double rest = 1.0 - (1.0 / a + 1.0 / b) * t;
    double t1 = rest / (1.0 / a + 1.0 / b - 1.0 / c);
    printf("%.2lf\n", t + t1);

    return 0;
}
