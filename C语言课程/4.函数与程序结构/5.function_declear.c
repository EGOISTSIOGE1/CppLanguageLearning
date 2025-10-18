/*************************************************************************
	> File Name: 5.function_declear.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 20 Nov 2023 05:45:15 PM CST
 ************************************************************************/

#include<stdio.h>

int a_func(int x);
int b_func(int x);

int main(int argc, char const *argv[]) {
	a_func(1);
	b_func(2);
	return 0;
}

int a_func(int x) {
	switch (x) {
		case 1: return b_func(x);
		case 2: printf("2 * x = %d\n", 2 * x); break;
	}
	return 0;
}

int b_func(int x) {
	switch (x) {
		case 1: printf("3 * x = %d\n", 3 * x); break;
		case 2: return a_func(x);
	}
	return 0;
}