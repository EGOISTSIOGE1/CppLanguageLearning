/*************************************************************************
	> File Name: 5.control_reopen.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 17 Dec 2023 07:18:40 PM CST
 ************************************************************************/

// ./a.out < input.txt 重定向输入流
// ./a.out > output.txt 重定向输出流

// ./a.out 2> output_err.txt
// stdin : 0
// stdout : 1
// stderr : 2

#include<stdio.h>

int main(int argc, char const *argv[]) {
	char s[1000];
	int i = 1;
	while (scanf("%[^\n]", s) != EOF) { // 一直进行读入, ^\n表示非\n
		getchar(); // 用于吞掉缓冲区中的\n字符
		fprintf(stderr, "%d test case\n", i++);
		printf("%s | hello world\n", s);
	} 
	return 0;
}
