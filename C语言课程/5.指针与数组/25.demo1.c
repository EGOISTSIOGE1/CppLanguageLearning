/*************************************************************************
	> File Name: 25.demo1.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 29 Nov 2023 12:01:52 AM CST
 ************************************************************************/
/**
 * 指针等价形式转换
 * 1.p <=> &a
 * 2.p + 1 <=> 1 + p
 * 3.p + 1 <=> &p[1] --> p + n <=> &p[n] 数组为p[n]的地址
 * 4.*p <=> p[0] <=> a <=> *(p + 0)
 * 5.p[n] <=> *(p + n)
*/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int arr[] = {0, 1, 2, 3, 4, 5, 6};
	int *p = arr;
	for (int i = 0; i < 3; i++) {
		printf("%d\n", (i + 5)[&p[1] - 2]); // (i + 5)[p - 1] => *(i + 5 + p - 1) => *(p + i + 4) => p[i + 4]
	}

	return 0;
}
