/*************************************************************************
	> File Name: 2.file_access.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 24 Dec 2023 03:44:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// "r"-读-以读方式打开文件-从头开始读-打开失败 
void r_access() {
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("r : failed to open file\n");
		exit(1);
	}
	char s[100];
	fscanf(fp, "%[^\n]", s); // 读入一行字符串
	printf("s = %s\n", s);
	fclose(fp);
	fp = fopen("temp.txt", "r");
	if (fp == NULL) {
		printf("r : failed to open file\n");
	}
	return ;
}

void rand_file_name(char *file_name, int n) {
	for (int i = 0; i < n; i++) {
		file_name[i] = rand() % 26 + 'a';
	}
	file_name[n] = 0;
	strcat(file_name, ".txt");
	return ;
}

// "w"-写-以写方式创建文件-清空内容-创建新文件
void w_access() {
	FILE *fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("w : failed to open file\n");
		exit(1);
	}
	fprintf(fp, "hahahah , world\n");
	fprintf(fp, "hello hangzhou\n");
	fclose(fp);
	char file_name[100] = {0};
	rand_file_name(file_name, 10);
	printf("w : open file %s\n", file_name);
	fp = fopen(file_name, "w");
	fclose(fp);
	return ;
}

// "a"-追加-向文件中追加内容-写入到末尾-创建新文件
// "r+"-读扩展-以读写的方式打开一个文件-从头开始读-出错
void r_plus_access() {
	FILE *fp = fopen("data.txt", "r+");
	if (fp == NULL) {
		printf("r+ : failed to open file\n");
		exit(1);
	}
	char s[100];
	fscanf(fp, "%s", s);
	printf("r+ : s = %s\n", s);
	fprintf(fp, "000000");
	fclose(fp);
	fp = fopen("temp.txt", "r+");
	if (fp == NULL) {
		printf("r+ : failed to open file\n");
	}
	return ;
}

// "w+"-写扩展-以读写的方式创建一个文件-清空内容-创建新文件
void w_plus_access() {
	FILE *fp = fopen("data.txt", "w+");
	if (fp == NULL) {
		printf("w : failed to open file\n");
		exit(1);
	}
	fprintf(fp, "w+hahahah , world\n");
	char s[100] = {0};
	fscanf(fp, "%s", s);
	printf("w+ : s = %s\n", s);
	fclose(fp);
	char file_name[100] = {0};
	rand_file_name(file_name, 10);
	printf("w+ : open file %s\n", file_name);
	fp = fopen(file_name, "w+");
	fclose(fp);
	return ;
}

// "a+"-追加扩展-以读写方式打开一个文件-写入到末尾-创建新文件

int main(int argc, char const *argv[]) {
	srand((unsigned)time(NULL));
	r_access();
	w_access();
	r_plus_access();
	w_plus_access();
	return 0;
}
