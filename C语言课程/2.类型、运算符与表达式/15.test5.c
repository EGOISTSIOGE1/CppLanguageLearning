/*************************************************************************
	> File Name: 15.test5.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 Nov 2023 04:33:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf\n", x / 180.0 * acos(-1));

    return 0;
}
