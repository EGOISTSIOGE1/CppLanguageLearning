/*************************************************************************
	> File Name: 11.ifdef.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 10 Dec 2023 03:54:35 PM CST
 ************************************************************************/

/**
 * gcc -DDEBUG 11.xxx.c
*/

#include<stdio.h>

#ifndef DEBUG
#define DEBUG
#endif // DEBUG

#ifdef DEBUG
int a = 1;
#else
int a = 2;
#endif // DEBUG

int main(int argc, char const *argv[]) {
	printf("a = %d\n", a);
	return 0;
}

static void SetSysClock(void) {
#ifdef SYSCLK_FREQ_HSE
	SetSysClockToHSE();
#elif difine SYSCLK_FREQ_24MHz
	SetSysClockTo24();
#elif difine SYSCLK_FREQ_36MHz
	SetSysClockTo36();
#elif difine SYSCLK_FREQ_48MHz
	SetSysClockTo48();
#elif difine SYSCLK_FREQ_56MHz
	SetSysClockTo56();
#elif difine SYSCLK_FREQ_72MHz
	SetSysClockTo72();
#endif
}