/*************************************************************************
	> File Name: random_data.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 01 Jan 2024 07:01:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	srand((unsigned)time(NULL));
	printf("26\n");
	for (int i = 0; i < 26; i++) {
		printf("%c %d\n", 'a' + i, rand() % 100000);
	}

	return 0;
}
