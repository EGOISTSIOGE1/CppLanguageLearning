/*************************************************************************
	> File Name: 4.名称空间：基本定义.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 22 Jun 2024 11:43:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

namespace apple {
	int cnt = 0;
	void inc() {
		cnt += 1;
		return ;
	}
}

namespace banana {
	int cnt = 0;
	void inc() {
		cnt += 1;
		return ;
	}
}

int main(int argc, const char** argv) {

	return 0;
}