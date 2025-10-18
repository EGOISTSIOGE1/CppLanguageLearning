/*************************************************************************
	> File Name: 14.指针转换：reinterpret_cast.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 01 Jan 2025 04:51:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d.%d.%d.%d", &a, &b, &c, &d);
	unsigned int n;
	char *p = reinterpret_cast<char *>(&n);
	p[3] = a;
	p[2] = b;
	p[1] = c;
	p[0] = d;
	printf("n = %u\n", n);
	return 0;
}