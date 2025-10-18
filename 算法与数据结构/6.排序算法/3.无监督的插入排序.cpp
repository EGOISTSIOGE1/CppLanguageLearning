/*************************************************************************
	> File Name: 3.无监督的插入排序.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 27 May 2024 01:46:22 PM CST
 ************************************************************************/

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

void unguarded_insert_sort(int *arr, int l, int r) {
	int ind = l;
	for (int i = l + 1; i < r; i++) {
		if (arr[i] < arr[ind]) ind = i;
	}
	// 不能直接swap[arr[ind], arr[l]];
	// 这关系到插入算法的稳定性问题
	while (ind > l) {
		swap(arr[ind], arr[ind - 1]);
		ind -= 1;
	}
	for (int i = l + 1; i < r; i++) {
		int j = i;
		while (arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j -= 1;
		}
	}
	return ;
}

// 逆序数：当前有几对数的顺序是反的 3 4 2 1的逆序数是5 范围为0 ~ n*(n-1)/2
// 每次交换都相当于逆序数减1

int main() {
	int *arr = getRandData(SMALL_DATA_N);
	TEST(insert_sort, arr, SMALL_DATA_N);
	TEST(unguarded_insert_sort, arr, SMALL_DATA_N);
	free(arr);
	return 0;
}