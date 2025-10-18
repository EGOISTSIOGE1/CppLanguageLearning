/*************************************************************************
	> File Name: HZOJ-114.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 19 Nov 2023 03:13:28 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[])
{
	char s[10];
	const char *name;
	scanf("%s", s);
	switch (s[0]) {
		case 'h': name = "He\n"; goto PRINT;
		case 'l': name = "Li\n"; goto PRINT;
		case 'c': name = "Cao\n"; goto PRINT;
		case 'd': name = "Duan\n"; goto PRINT;
		case 'w': name = "Wang\n"; goto PRINT;
PRINT:
		printf("%s", name); break;
		default : printf("Not Here\n"); break;
	}

	if (s[0] == 'h') printf("He\n");
	else if (s[0] == 'l') printf("Li\n");
	else if (s[0] == 'c') printf("Cao\n");
	else if (s[0] == 'd') printf("Duan\n");
	else if (s[0] == 'w') printf("Wang\n");
	else printf("Not Here\n");

	return 0;
}
