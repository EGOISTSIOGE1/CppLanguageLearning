/*************************************************************************
	> File Name: 13.log.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 10 Dec 2023 04:58:09 PM CST
 ************************************************************************/

#include<stdio.h>

#define DEBUG 1
#define ERROR 2
#define FATAL 3
#define NO_LOG 4
#define LOG(level) \
if (level >= LOG_LEVEL) \
printf("[%s : %d] ", __FILE__, __LINE__), \
printf 

int main(int argc, char const *argv[]) {
	int a = 123;
	printf("hello world\n");
	printf("a = %d\n", a);
	LOG(DEBUG)("hello world, DEBUG\n");
	LOG(ERROR)("hello world, ERROR\n");
	LOG(FATAL)("hello world, FATAL\n");
	LOG(DEBUG)("a = %d, DEBUG\n", a);
	LOG(ERROR)("a = %d, ERROR\n", a);
	LOG(FATAL)("a = %d, FATAL\n", a);
	return 0;
}
