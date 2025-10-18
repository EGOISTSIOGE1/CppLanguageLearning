/*************************************************************************
	> File Name: 5.冒泡排序及优化.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 28 May 2024 10:07:27 AM CST
 ************************************************************************/

/**
 * 口诀：
 * 1、将数组分成【已排序区】和【待排序区】（与前两种不同，前面的叫待排序区，后面的叫已排序区）
 * 2、从头到尾扫描【待排序区】，若前面元素比后面元素大，则交换
 * 3、每一轮都会将【待排序区】中最大的放到跑【已排序区】
 * 4、直到【待排序区】没有元素为止
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"0.sort_test.h"

void bubble_sort(int *arr, int l, int r) {
	for (int i = r - 1, I = l + 1, cnt; i >= I; i--) {
		cnt = 0;
		for (int j = l; j < i; j++) {
			if (arr[j] <= arr[j + 1]) continue;
			swap(arr[j], arr[j + 1]);
			cnt += 1;
		}
		if (cnt == 0) break;
	}
	return ;
}

int main() {
	int *arr = getRandData(SMALL_DATA_N);
	TEST(bubble_sort, arr, SMALL_DATA_N);
	free(arr);
	return 0;
}