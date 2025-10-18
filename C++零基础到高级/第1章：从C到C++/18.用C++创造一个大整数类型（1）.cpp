/*************************************************************************
	> File Name: 18.用C++创造一个大整数类型（1）.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 05 Jul 2024 12:39:34 AM CST
 ************************************************************************/

/**
 * #40. 爬楼梯 
题目描述
小海是一个顽皮的少年，对于爬楼梯这种事情，他从来都不愿意一步一步走，每次上楼梯的时候，要么往上跨两级，要么往上跨三级。对于有 n 级台阶的楼梯，小海想知道他从最下面走到最上面的方法总数。

输入
输入一个数字 n（1≤n≤500），代表台阶总数。

输出
输出一个整数，代表小海从最下面走到最上面的方法总数。

样例输入1
5
样例输出1
2

总数：f(n) = f(n-2) + f(n-3)
 */

#include<iostream>
#include<vector>
using namespace std;

#define MAX_N 500

class BigInt : public vector<int> {
public:
	BigInt(int x = 0) {
		push_back(0);
		process_digit();
	}
	BigInt &operator=(int x) {
		clear();
		push_back(x);
		process_digit();
		return *this;
	}
	BigInt &operator+=(const BigInt& obj) {
		for (int i = 0; i < obj.size(); i++) {
			if (i == size()) push_back(obj[i]);
			else at(i) += obj[i];
		}
		process_digit();
		return *this;
	}
	BigInt operator+(const BigInt& obj) {
		BigInt ret(*this);
		ret += obj;
		return ret;
	}

private:
	void process_digit() {
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10) continue;
			if (i + 1 == size()) push_back(0);
			at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		return ;
	}
};

BigInt f[MAX_N + 5];

ostream &operator<<(ostream &out, const BigInt &a) {
	for (int i = a.size() - 1; i >= 0; i--) {
		out << a[i];
	}
	return out;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	f[0] = 1; f[1] = 0; f[2] = 1;;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 2] + f[i - 3];
	}
	cout << f[n] << endl;
	return 0;
}
