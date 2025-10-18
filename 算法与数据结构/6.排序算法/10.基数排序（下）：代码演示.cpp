/*************************************************************************
	> File Name: 10.基数排序（下）：代码演示.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 06 Jun 2024 10:56:59 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"0.sort_test.h"

void radix_sort(int *arr, int l, int r) {
	// 时间复杂度为O(nk)
	// 需要两个数组空间，第一个是存储每个位置的统计信息，第二个是存放结果的
	// 十位为 x / k，个位为 x % k
	// 对于int类型，2^32，分成两部分为2^16和2^16（65536）, 那么十位是 x / 65536，个位是 x % 65536
	#define K 65532
	int *cnt  = (int *)malloc(sizeof(int) * K);
	int *temp = (int *)malloc(sizeof(int) * (r - l));
	// round 1 个位
	memset(cnt, 0, sizeof(int) * K);
	for (int i = l; i < r; i++) cnt[arr[i] % K] += 1;
	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1]; // 前缀和
	// 从后到前扫描元素组中的每个元素，并且把相关的元素放置进temp数组中
	for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] % K]] = arr[i];
	memcpy(arr + l, temp, sizeof(int) * (r - l));
	// round 2 十位
	memset(cnt, 0, sizeof(int) * K);
	for (int i = l; i < r; i++) cnt[arr[i] / K] += 1;
	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1]; // 前缀和
	// 从后到前扫描元素组中的每个元素，并且把相关的元素放置进temp数组中
	for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] / K]] = arr[i];
	memcpy(arr + l, temp, sizeof(int) * (r - l));
	return ;
}

int main() {
	int *arr_s = getRandData(SMALL_DATA_N);
	int *arr_b = getRandData(BIG_DATA_N);
	TEST(radix_sort, arr_s, SMALL_DATA_N);
	TEST(radix_sort, arr_b, BIG_DATA_N);
	free(arr_s);
	free(arr_b);
	return 0;
}