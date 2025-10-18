/*************************************************************************
	> File Name: 11.超市卖货：HZOJ-284.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 04 May 2024 05:32:23 PM CST
 ************************************************************************/

/**
 * HZOJ-284 超市卖货
 * 
 * 超市里有N个商品，第i个商品必须在保质期（第di天）之前卖掉，若卖掉可让超市获得pi的利润。
 * 每天只能卖一个商品。
 * 现在你要让超市获得最大的利润。
 * 
 * 当前的最优方案集合
 * 1、集合中的元素数量<=最晚过期的商品日期d
 * 2、重点考虑d`和d的关系
 * 
 * d`>7 直接添加
 * d`=7 如果p`>p，替换最小利润商品，否则不变
 * d`<7 不存在
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

struct Data {
	Data(int p, int d) : p(p), d(d) {}
	int p, d;
	bool operator<(const Data &obj) const {
		if (d != obj.d) return d < obj.d;
		return  p > obj.p;
	}
};

typedef pair<int, int> PII;

int main() {
	int n;
	cin >> n;
	vector<Data> arr;
	set<PII> s;
	for (int i = 0, p, d; i < n; i++) {
		cin >> p >> d;
		arr.push_back(Data(p, d));
	}
	sort(arr.begin(), arr.end());
	// for (int i = 0; i < n; i++) {
	// 	cout << i << " : " << arr[i].d << " " << arr[i].p << endl;
	// }
	for (int i = 0; i < n; i++) {
		if (arr[i].d > s.size()) {
			s.insert(PII(arr[i].p, i));
		} else {
			if (arr[i].p > s.begin()->first) {
				s.erase(s.begin());
				s.insert(PII(arr[i].p, i));
			}
		}
	}
	int ans = 0;
	for (auto x : s) {
		ans += x.first;
	}
	cout << ans << endl;
	return 0;
}