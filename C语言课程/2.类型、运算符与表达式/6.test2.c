/*************************************************************************
	> File Name: 6.test2.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 29 Oct 2023 07:59:14 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    char s[100];
    scanf("%[^\n]", s);
    
    int n;
    n = printf("%s", s);
    printf(" : %d\n", n);

    return 0;
}
