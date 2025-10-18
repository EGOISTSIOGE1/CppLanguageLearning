/*************************************************************************
	> File Name: 23.国王游戏：HZOJ-256（大整数实现）.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 17 Sep 2024 06:39:14 PM CST
 ************************************************************************/

/**
 *#256. 国王游戏

题解视频
题目描述
​ 恰逢 H
 国国庆,国王邀请n位大臣来玩一个有奖游戏。首先,他让每个大臣在左、右手上面分别写下一个整数，国王自己也在左、右手上各写一个整数。然后，让这
n位大臣排成一排，国王站在队伍的最前面。排好队后，所有的大臣都会获得国王奖赏的若干金币，每位大臣获得的金币数分别是：排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数,然后向下取整得到的结果。
国王不希望某一个大臣获得特别多的奖赏，所以他想请你帮他重新安排一下队伍的顺序，使得获得奖赏最多的大臣，所获奖赏尽可能的少。注意，国王的位置始终在队伍的最前面。

输入
​ 第一行包含一个整数n，表示大臣的人数。
​ 第二行包含两个整数a和b，之间用一个空格隔开,分别表示国王左手和右手上的整数。（均小于 10000）

​ 接下来n行，每行包含两个整数a和b，之间用一个空格隔开，分别表示每个大臣左手和右手上的整数。（均小于 10000）

输出
​ 输出一个整数，表示重新排列后的队伍中获奖赏最多的大臣所获得的金币数。

样例输入
3
1 1
2 3
7 4
4 6
样例输出
2
数据规模与约定
​ 时间限制：1 s

​ 内存限制：256 M

​ 100% 的数据保证 1≤n≤1000 
 */

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];

class BigInt : public vector<int> { // 1234 ->[4,3,2,1]
public:
	BigInt(int x) {
		this->push_back(x);
		process_digit();
	}

	BigInt operator/(int x) {
		BigInt ret(*this);
		int y = 0;
		for (int i = size() - 1; i >= 0; i--) {
			y = y * 10 + at(i);
			ret[i] = y / x;
			y %= x;
		}
		ret.process_digit();
		return ret;
	}

	void operator*=(int x) {
		for (int i = 0; i < size(); i++) at(i) *= x;
		process_digit();
		return ;
	}

	bool operator>(const BigInt &a) const {
		if (size() != a.size()) return size() > a.size();
		for (int i = size() - 1; i >= 0; i--) {
			if (at(i) != a[i]) return at(i) > a[i];
		}
		return false;
	}

	void process_digit() {
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10) continue;
			if (i + 1 == size()) this->push_back(0);
			at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		while (size() > 1 && at(size() - 1) == 0) this->pop_back();
		return ;
	}
};

ostream &operator<<(ostream &out, const BigInt &a) {
	for (int i = a.size() - 1; i >= 0; i--) {
		out << a[i];
	}
	return out;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a[i] >> b[i];
		ind[i] = i;
	}
	sort(ind + 1, ind + n + 1, [&](int i, int j) -> bool {
		return a[i] * b[i] < a[j] * b[j];
	});
	BigInt p = a[0], ans = 0, temp = 0;
	for (int i = 1; i <= n; i++) {
		temp = p / b[ind[i]];
		if (temp > ans) ans = temp;
		p *= a[ind[i]];
	}
	cout << ans << endl;
	return 0;
}