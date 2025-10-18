/*************************************************************************
	> File Name: 10.operator.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 Nov 2023 02:41:51 PM CST
 ************************************************************************/

#include<stdio.h>

#define PRINT(stmt, func) { \
    printf("%s\n", #stmt); \
    stmt; \                       
    func; \
}

int main(){
    int a = 5, b = 2, c = 7, d;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    PRINT(a = c, printf("a = %d, b = %d, c = %d\n", a, b, c));
    PRINT(d = a + c, printf("d = %d\n", d));
    PRINT(d = a - b, printf("d = %d\n", d));
    PRINT(d = a * b, printf("d = %d\n", d));
    PRINT(d = a / b, printf("d = %d\n", d));
    PRINT(d = (-a) / b, printf("d = %d\n", d));
    PRINT(d = a % b, printf("d = %d\n", d));

    return 0;
}
