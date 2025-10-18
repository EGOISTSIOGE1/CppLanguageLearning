/*************************************************************************
	> File Name: 11.digit.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 Nov 2023 03:00:16 PM CST
 ************************************************************************/

/**
 * <<为乘，>>为除
 * >> 是向下取整，/ 是向零取整 
*/

#include<stdio.h>

void print_digit(int x){
    for (int i = 31; i >= 0; i--) {
        printf("%c", (x & (1 << i)) ? '1' : '0');
    }
    printf("\n");
    return ;
}    
    
int main(){
    int a = 5, b = 3;
    printf("a = "); print_digit(a);
    printf("b = "); print_digit(b);
    printf("a & b = "); print_digit(a & b);
    printf("a | b = "); print_digit(a | b);
    printf("a ^ b = "); print_digit(a ^ b);

    a ^= b; b ^= a; a ^= b;
    printf("a = "); print_digit(a);
    printf("b = "); print_digit(b);
    printf("~a = "); print_digit(~a);

    printf("(~b + 1) = %d\n", ~b + 1);

    int x;
    scanf("%d", &x);
    printf("x = "); print_digit(x);
    printf("(-x & x) = "); print_digit(-x & x);

    int c = 1279813123, d = -c;
    printf("c = "); print_digit(c);
    printf("d = "); print_digit(d);
    printf("c << 1 = "); print_digit(c << 1);
    printf("c >> 1 = "); print_digit(c >> 1);
    printf("d << 1 = "); print_digit(d << 1);
    printf("d >> 1 = "); print_digit(d >> 1);

    printf("a = %d, b = %d\n", a, b);
    printf("a << 1 = %d, b >> 1 = %d\n", a << 1, b >> 1);

    printf("-5 / 2 = %d, (-5) >> 1 = %d\n", -5 / 2, -5 >> 1);

    __uint8_t e = 0xBA;
    printf("e = %d\n", e);
    printf("e << 8 = %d\n", e << 8);
    printf("e >> 7 = %d\n", e >> 7);

    return 0;
}
