/*************************************************************************
	> File Name: 7.fseek_position.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 07 Jan 2024 03:26:19 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	FILE *fp = fopen("data7.txt", "w");
	fprintf(fp, "0123456789");
	fseek(fp, -4, SEEK_CUR);
	fprintf(fp, "xy");
	fseek(fp, -3, SEEK_END);
	fprintf(fp, "z");

	fseek(fp, 0, SEEK_END); // 将文件位置指针设置到结尾
	fseek(fp, 0, SEEK_SET); // 将文件位置指针设置到开头
	return 0;
}
