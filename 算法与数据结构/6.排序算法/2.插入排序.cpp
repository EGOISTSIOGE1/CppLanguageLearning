/*************************************************************************
	> File Name: 2.插入排序.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 May 2024 05:37:47 PM CST
 ************************************************************************/

/**
 * 口诀：
 * 1、将数组分成【已排序区】和【待排序区】
 * 2、将【已排序区】后面一个元素，向前插入到【待排序区】中
 * 3、直到【待排序区】没有元素为止
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"0.sort_test.h"

void insert_sort(int *arr, int l, int r) {
	for (int i = l + 1; i < r; i++) {
		int j = i;
		while (j > l && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j -= 1;
		}
	}
	return ;
}

int main() {
	int *arr = getRandData(SMALL_DATA_N);
	TEST(insert_sort, arr, SMALL_DATA_N);
	free(arr);
	return 0;
}