/*************************************************************************
	> File Name: 12.【大整数版】兔子繁殖问题：HZOJ-38.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 14 Oct 2024 01:00:12 AM CST
 ************************************************************************/

 /**
  * HZOJ-38 兔子繁殖问题
  * 
  * 如果有一对兔子，每一个月都生下一对小兔，而所生下的每一对小兔在出生后的第三个月也都生下一对小兔。那么，由一对兔子开始，n个月后有多少对小兔子呢？
  *	
  */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class BigInt : public vector<int>{
public:
	BigInt() { push_back(0); }
	BigInt(int x) {
		this->push_back(x);
		proccess_digit();
	}

	BigInt &operator+=(const BigInt &a) {
		for (int i = 0; i < a.size(); i++) {
			if (i >= size()) push_back(a[i]);
			else at(i) += a[i];
		}
		proccess_digit();
		return *this;
	}

	BigInt operator+(const BigInt &a) {
		BigInt ret(*this);
		ret += a;
		return ret;
	}

	void proccess_digit() {
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10) continue;
			if (i == size() - 1) push_back(0);
			at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		return ;
	}
};

ostream &operator<<(ostream &out, const BigInt &a) {
	for (int i = a.size() - 1; i >= 0; i--) {
		out << a[i];
	}
	return out;
}

BigInt f[105];

int main() {
	int n;
	cin >> n;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[n] << endl;
	return 0;
}