/*************************************************************************
	> File Name: 34.my_qsort.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 03 Dec 2023 12:31:50 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int *getRandData(int n) {
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	return arr;
}

void output(int *arr, int n) {
	int len = 0;
	// line 1
	for (int i = 0; i < n; i++) {
		len += printf("%3d", i);
	}
	printf("\n");
	// line 2
	for (int i = 0; i < len; i++) {
		printf("-");
	}
	printf("\n");
	// line 3
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n\n");
	return ;
}

// 从小到大
int comp1(const void *p1, const void *p2) {
	const int *a = (const int *)p1;
	const int *b = (const int *)p2;
	if (*a < *b) return -1;
	if (*a == *b) return 0;
	return 1;
}

// 精简版 从小到大
int comp2(const void *p1, const void *p2) {
	return *((const int *)p1) - *((const int *)p2);
}

// 精简版 从大到小
int comp3(const void *p1, const void *p2) {
	return *((const int *)p2) - *((const int *)p1);
}

void swap1(void *x, void *y, size_t size) {
	char *a = (char *)x;
	char *b = (char *)y;
	char c;
	for (int i = 0; i < size; i++) {
		if (a[i] == b[i]) continue;
		c = a[i];
		a[i] = b[i];
		b[i] = c;
	}
	return ;
}

void swap2(void *x, void *y, size_t size, void *buff) {
	memmove(buff, x, size);
	memmove(x, y, size);
	memmove(y, buff, size);
	return ;
}

void my_qsort(void *arr, size_t count, size_t size, int(*comp)(const void *, const void *)) {
	if (count <= 1) return ;
	void *x = arr;
	void *y = arr + (count - 1) * size;
	void *z = malloc(size), *buff = malloc(size);
	memcpy(z, arr, size);
	do {
		while (comp(x, z) < 0) x += size;
		while (comp(z, y) < 0) y -= size;
		if (x <= y) {
			swap2(x, y, size, buff);
			x += size, y -= size;
		}
	} while (x <= y);
	size_t cnt1 = y < arr ? 0 : (y - arr) / size + 1;
	size_t cnt2 = count - (x - arr) / size;
	my_qsort(arr, cnt1, size, comp);
	my_qsort(x, cnt2, size, comp);
	return ;
}


int main(int argc, char const *argv[]) {
	srand(time(NULL));
	int *arr = getRandData(10);
	output(arr, 10);
	printf("use comp1 : \n");
	my_qsort(arr, 10, sizeof(int), comp1);
	output(arr, 10);
	printf("use comp2 : \n");
	my_qsort(arr, 10, sizeof(int), comp2);
	output(arr, 10);
	printf("use comp3 : \n");
	my_qsort(arr, 10, sizeof(int), comp3);
	output(arr, 10);

	return 0;
}