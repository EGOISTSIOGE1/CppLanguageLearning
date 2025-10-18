/*************************************************************************
	> File Name: 6.fscanf_and_fseek.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 04 Jan 2024 12:37:09 AM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	FILE *fp = fopen("data5.txt", "r");
	int n;
	fseek(fp, 5, SEEK_SET);
	fscanf(fp, "%d", &n);
	printf("fscanf n = %d\n", n);
	return 0;
}
