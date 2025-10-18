/*************************************************************************
	> File Name: 6.快速排序.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 29 May 2024 11:22:30 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"0.sort_test.h"

void quick_sort(int *arr, int l, int r) {
	if (r - l <= 2) {
		if (r - l <= 1) return ;
		if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
		return ;
	}
	// partition 分区操作
	int x = l, y = r - 1, z = arr[l];
	while (x < y) {
		while (x < y && z <= arr[y]) --y;
		if (x < y) arr[x++] = arr[y];
		while (x < y && arr[x] <= z) ++x;
		if (x < y) arr[y--] = arr[x];
	}
	arr[x] = z;
	quick_sort(arr, l, x);
	quick_sort(arr, x + 1, r);
	return ;
}

int main(int argc, const char** argv) {
	int *arr_s = getRandData(SMALL_DATA_N);
	int *arr_b = getRandData(BIG_DATA_N);
	TEST(quick_sort, arr_s, SMALL_DATA_N);
	TEST(quick_sort, arr_b, BIG_DATA_N);
	free(arr_s);
	free(arr_b);
	return 0;
}