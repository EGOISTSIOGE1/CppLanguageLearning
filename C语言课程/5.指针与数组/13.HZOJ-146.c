/*************************************************************************
	> File Name: 13.HZOJ-146.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 Nov 2023 05:32:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char const *argv[]) {
	char s[55];
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		if (islower(s[i])) {
			if (s[i] == 'z') s[i] = 'a';
			else s[i] += 1;
		}
		if (isupper(s[i])) {
			if (s[i] == 'Z') s[i] = 'A';
			else s[i] += 1;
		}
	}
	printf("%s\n", s);

	return 0;
}
