/*************************************************************************
	> File Name: 22.货仓选址：HZOJ-245.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 15 Jan 2024 11:47:20 PM CST
 ************************************************************************/

/**
 * 在一条数轴上有N家商店，他们的坐标分别为A[1]-A[N]。现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
 * 为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小，输出最短距离之和。
 * 
 * 输入
 * 		第一行输入一个数N。(1 <= N <= 100000)
 * 		接下来一行，输入N个数，表示商店的坐标
 * 输出
 * 		输出最短距离之和。
 * 
 * 样例输入
 * 5
 * 1 3 5 6 10
 * 样例输出
 * 12
 * 
 * C = Σ|Ai-P| 找到P是所有Ai的中位数
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
	int n; 
	vector<int> arr;
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	int p = arr[n / 2], ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(arr[i] - p);
	}
	cout << ans << endl;
	return 0;
}
