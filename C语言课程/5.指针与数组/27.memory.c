/*************************************************************************
	> File Name: 27.memory.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 29 Nov 2023 11:40:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[]) {
	int *arr1 = (int *)malloc(sizeof(int) * 10); // malloc返回值是void*的地址（可以被任意类型地址转换）,但是不保证初始化
	for (int i = 0; i < 10; i++) {
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }
	int *arr2 = (int *)calloc(10, sizeof(int)); // calloc返回值是void*的地址（可以被任意类型地址转换）,会进行初始化操作（10个元素，每一个都是整型的空间）
	for (int i = 0; i < 10; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }
	free(arr1);
	free(arr2);

    char s1[100] = "hello world";
	char s2[100];
	char s3[100];
	memcpy(s2, s1, 12);
	memmove(s3, s1, 12);
	printf("s2 = %s\n", s2);
	printf("s3 = %s\n", s3);

	memcpy(s2 + 4, s2, 12); // 无法处理内存空间有重叠的情况
	memmove(s3 + 4, s3, 12); // 可以完美处理内存空间有重叠的情况，首选
	printf("s2 = %s\n", s2);
	printf("s3 = %s\n", s3);
	return 0;
}
