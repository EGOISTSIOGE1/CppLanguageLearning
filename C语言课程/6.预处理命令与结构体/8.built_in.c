/*************************************************************************
	> File Name: 8.built_in.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 09 Dec 2023 05:33:10 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	printf("__DATE__ = %s\n", __DATE__);
	printf("__TIME__ = %s\n", __TIME__);
	printf("__LINE__ = %d\n", __LINE__);
	printf("__FILE__ = %s\n", __FILE__);
	printf("__func__ = %s\n", __func__);
	printf("__PRETTY_FUNCTION__ = %s\n", __PRETTY_FUNCTION__);
	return 0;
}
