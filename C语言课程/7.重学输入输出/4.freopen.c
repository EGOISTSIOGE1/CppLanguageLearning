/*************************************************************************
	> File Name: 4.freopen.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 17 Dec 2023 05:59:05 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	freopen("output.txt", "w", stdout); // 重定向，r读文件，w写文件
	freopen("input.txt", "r", stdin); 
	printf("hello freopen, stdout\n");
	char s[1000];
	while (scanf("%[^\n]", s) != EOF) { // 一直进行读入, ^\n表示非\n
		getchar(); // 用于吞掉缓冲区中的\n字符
		printf("%s | hello world\n", s);
	} 
	return 0;
}
