/*************************************************************************
	> File Name: 13.math.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 Nov 2023 03:56:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    printf("pow(2, 3) = %lf\n", pow(2.0, 3.0));
    printf("sqrt(2) = %lf\n", sqrt(2));
    printf("ceil(4.01) = %lf\n", ceil(4.01));
    printf("floor(4.99) = %lf\n", floor(4.99));
    printf("abs(-65) = %d\n", abs(-65));
    printf("fabs(-65.6) = %lf\n", fabs(-65.6));
    printf("log(9) = %lf\n", log(9));
    printf("acos(-1) = %lf\n", acos(-1));
        
    return 0;
}
