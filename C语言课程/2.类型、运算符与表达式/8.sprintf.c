/*************************************************************************
	> File Name: 8.sprintf.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 Nov 2023 02:19:47 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    char str[100] = "192.168.1.245";
    int a, b, c, d;
    sscanf(str, "%d.%d.%d.%d", &a, &b, &c, &d);
    sprintf(str, "%d:%d:%d:%d", a, b, c, d);
    printf("str = %s\n", str);
    return 0;
}
