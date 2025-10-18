/*************************************************************************
	> File Name: 15.HZOJ-148.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 Nov 2023 05:44:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[]) {
	char s[55];
	scanf("%s", s);
	for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		/*char ch;
		ch = s[i];
		s[i] = s[j];
		s[j] = ch;*/
		// 使用异或运算 a ^ b = c, a ^ c = b, b ^ c = a
		s[i] ^= s[j]; // c = a ^ b
        s[j] ^= s[i]; // a = c ^ b
        s[i] ^= s[j]; // b = c ^ a
	}
	printf("%s\n", s);
	return 0;
}
