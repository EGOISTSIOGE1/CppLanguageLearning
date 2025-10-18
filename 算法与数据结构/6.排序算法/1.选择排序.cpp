/*************************************************************************
	> File Name: 1.选择排序.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 May 2024 04:41:33 PM CST
 ************************************************************************/

/**
 * 口诀：
 * 1、将数组分成【已排序区】和【待排序区】
 * 2、每一轮从【待排序区】中选择一个最小的元素放到【已排序区】
 * 3、直到【待排序区】没有元素为止
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"0.sort_test.h"

void selection_sort(int *arr, int l, int r) {
	for (int i = l, I = r - 1; i < I; i++) {
		int ind = i;
		for (int j = i + 1; j < r; j++) {
			if (arr[j] < arr[ind]) ind = j;
		}
		swap(arr[i], arr[ind]);
	}
	return ;
}

int main() {
	int *arr = getRandData(SMALL_DATA_N);
	TEST(selection_sort, arr, SMALL_DATA_N);
	free(arr);

	return 0;
}
