/*************************************************************************
	> File Name: test.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 07 Dec 2023 05:27:47 PM CST
 ************************************************************************/

/**
 * #include做的事情就是粘贴
 * gcc -I./ test.c 将文件添加到默认路径，就可以使用<>导入通过编译
*/

#include <stdio.h>
#include <def_a_b.c>

int main(int argc, char const *argv[]) {
	printf("a + b = %d\n", a + b);
	return 0;
}
