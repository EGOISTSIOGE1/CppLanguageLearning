/*************************************************************************
	> File Name: printf.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 29 Oct 2023 02:44:20 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n1, n2;
    n1 = printf("hello world\n");
    printf("%d\n", '\n');
    int a = 123;
    n2 = printf("hello world : %d\n", a);
    printf("n1 = %d, n2 = %d\n", n1, n2);
    return 0;
}
