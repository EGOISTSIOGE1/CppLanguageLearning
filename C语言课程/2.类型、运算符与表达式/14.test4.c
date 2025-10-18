/*************************************************************************
	> File Name: 14.test4.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 Nov 2023 04:19:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf^%lf = %lf\n", x, 1.0 / 3.0, pow(x, 1.0 / 3.0));
    // printf("%lf\n", pow(27, 1.0 / 3.0));
    return 0;
}
