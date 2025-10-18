/*************************************************************************
	> File Name: 10.HZOJ-144.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 Nov 2023 05:14:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[]) {
	char str[105];
	scanf("%s", str);
	// for (int i = 0; i < strlen(str); i++) 效率低下，每次都要重新计算字符串的长度
	int cnt = 0;
	for (int i = 0, n = strlen(str); i < n; i++) {
		if (str[i] == 'A') cnt += 1;
	}
	printf("%d\n", cnt);

	return 0;
}
