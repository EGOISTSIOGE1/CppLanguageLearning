/*************************************************************************
	> File Name: 11.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:19:30 PM CST
 ************************************************************************/

/*
* 编写一个算法来判断一个数n是不是快乐数。
* 【快乐数】定义为：
* 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
* 然后重复这个过程直到这个数变为1，也可能是无限循环但始终变不到1。
* 如果这个过程结果为1，那么这个数就是快乐数。
* 如果n是快乐数就返回true，不是则返回false。
* 
* n = 19, true
* 1^2 + 9^2 = 82
* 8^2 + 2^2 = 68
* 6^2 + 8^2 = 100
* 1^2 + 0^2 + 0^2 = 1
*/

#include<iostream>

class Solution {
public:
	int getNext(int x) {
		int d, y = 0;
		while (x) {
			d = x % 10;
			y += d * d;
			x /= 10;
		}
		return y;
	}

	bool isHappy(int n) {
		int p = n, q = n;
		while (q != 1) {
			p = getNext(p);
			q = getNext(getNext(q));
			if (p == q && p != 1) return false;
		}
		return true;
	}
};

int main() {
	return 0;
}
