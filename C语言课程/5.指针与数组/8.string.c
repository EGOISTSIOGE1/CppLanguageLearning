/*************************************************************************
	> File Name: 8.string.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 Nov 2023 03:42:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	char str1[10] = "abc";
	printf("str1 = %s\n", str1);
	strcpy(str1, "def");
	printf("str1 = %s\n", str1);
	char str2[] = "hello\0 world"; 
	printf("strlen(str2) = %lu\n", strlen(str2)); // 5, strlen不计算\0空字符
	printf("sizeof(str2) = %lu\n", sizeof(str2)); // 13, sizeof计算的是存储大小
	printf("str2 = %s\n", str2);
	str2[5] = 'A';
	printf("str2 = %s\n", str2);
	char str3[] = "abcdef", str4[] = "abc";
	printf("strcmp(str3, str4) = %d\n", strcmp(str3, str4));
	str3[3] = '\0'; // abc\0ef
	printf("strcmp(str3, str4) = %d\n", strcmp(str3, str4));

	int arr[10];
	for (int i = 0; i < 10; i++) arr[i] = rand() % 100;
	for (int i = 0; i < 10; i++) printf("arr[%d] = %d\n", i, arr[i]);
	memset(arr, 0, sizeof(arr)); // 40, sizeof(int) * 10 把一个范围内的值都设置为0值
	for (int i = 0; i < 10; i++) printf("arr[%d] = %d\n", i, arr[i]);
	return 0;
}
