/*************************************************************************
	> File Name: 4.希尔排序.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 27 May 2024 02:35:53 PM CST
 ************************************************************************/

/**
 * 口诀：
 * 1、设计一个【步长】序列（分为几组，每一个步长分为一组）
 * 2、按照步长，对序列进行分组，每组采用插入排序
 * 3、直到执行到步长为1为止
*/

/**
 * 希尔排序的效率和【步长序列】紧密相关
 * 参考时间复杂度：O(nlogn) ~ O(n^2)
 * 
 * O(n^2)    希尔增量序列：n/2、n/4、n/8、n/16 ...
 * O(n^1.5)  Hibbard增量序列：1、3、7...2^k-1
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"0.sort_test.h"

void unguarded_insert_sort(int *arr, int l, int r, int step) {
	int ind = l;
	for (int i = l + step; i < r; i += step) {
		if (arr[i] < arr[ind]) ind = i;
	}
	// 不能直接swap[arr[ind], arr[l]];
	// 这关系到插入算法的稳定性问题
	while (ind > l) {
		swap(arr[ind], arr[ind - step]);
		ind -= step;
	}
	for (int i = l + 2 * step; i < r; i += step) {
		int j = i;
		while (arr[j] < arr[j - step]) {
			swap(arr[j], arr[j - step]);
			j -= step;
		}
	}
	return ;
}

void shell_sort(int *arr, int l, int r) {
	int k = 2, n = (r- l), step;
	do {
		step = n / k == 0 ? 1 : n / k;
		for (int i = l, I = l + step; i < I; i++) {
			unguarded_insert_sort(arr, i, r, step);
		}
		k *= 2;
	} while (step != 1);
	return ;
}

void shell_sort_hibbard(int *arr, int l, int r) {
	int step = 1, n = (r - l);
	while (step <= n / 2) step = step * 2 + 1;
	do {
		step /= 2;
		for (int i = l, I = l + step; i < I; i++) {
			unguarded_insert_sort(arr, i, r, step);
		}
	} while (step > 1);
	return ;
}

int main() {
	int *arr = getRandData(BIG_DATA_N);
	TEST(shell_sort, arr, BIG_DATA_N);
	TEST(shell_sort_hibbard, arr, BIG_DATA_N);
	free(arr);
	return 0;
}