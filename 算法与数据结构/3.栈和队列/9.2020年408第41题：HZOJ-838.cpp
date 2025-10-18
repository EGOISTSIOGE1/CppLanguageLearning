/*************************************************************************
	> File Name: 9.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:27:44 PM CST
 ************************************************************************/

/*
* 题目描述：
*	  定义三元组（a，b，c）（a，b，c均为正数）的距离D=|a-b|+|b-c|+|c-a|。给定3个非空整数集合S1，S2，S3，按升序分别存储在3个数组中。请设计一个尽可能高效的算法，计算并输出所有可能的三元组（a，b，c）（a∈S1，b∈S2，c∈S3）中的最小距离，
* 例如S1={-1，0，9}，S2={-25，-10，10，11}，S3={2，9，17，30，41}，则最小距离为2，相应的三元组为{9，10，9}。
*     程序中的主要部分已经帮你写好了，你只需要将如下代码拷贝到你的环境中，并且补充func函数功能即可。函数功能描述如下：
* 
* 输入参数：
*	  输入三个参数，分别为存储三个非空集合的队列
* 
* 返回值说明：
*	  返回一个整型值，表示所有可能的三元组（a，b，c）（a∈S1，b∈S2，c∈S3）中的最小距离
*/

#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

int min_num(int a, int b, int c) {
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	return a;
}

int func(queue<int> que1, queue<int> que2, queue<int> que3) {
	int ans = 0x3f3f3f3f;
	while (!que1.empty() && !que2.empty() && !que3.empty()) {
		int a = que1.front(), b = que2.front(), c = que3.front();
		int temp_ans = abs(a - b) + abs(b - c) + abs(a - c);
		if (temp_ans < ans) ans = temp_ans;
		int d = min_num(a, b, c);
		if (a == d) que1.pop();
		if (b == d) que2.pop();
		if (c == d) que3.pop();
	}
	return ans;
}


int main() {
	int m, n, k, x;
	queue<int> que1, que2, que3;
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++) {
		cin >> x;
		que1.push(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		que2.push(x);
	}
	for (int i = 0; i < k; i++) {
		cin >> x;
		que3.push(x);
	}
	cout << func(que1, que2, que3) << endl;
	return 0;
}
