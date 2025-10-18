/*************************************************************************
	> File Name: 12.HZOJ-145.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 Nov 2023 05:27:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[]) {
	char s[105], t[105];
	int s_len, t_len = -1;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		s_len = strlen(s);
		if (s_len > t_len) {
			strcpy(t, s);
            t_len = s_len;
		}
	}
	printf("%s\n", t);
	return 0;
}
