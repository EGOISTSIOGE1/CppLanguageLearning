/*************************************************************************
	> File Name: 8.数据流的中位数：Leetcode-295.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 17 Apr 2024 11:40:06 AM CST
 ************************************************************************/

/**
 * 295.数据流的中位数
 * 
 * 中位数是有序整数列表的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
 * 实现MedianFinder类：
 * MedianFinder()初始化MedianFinder对象。
 * void addNum(int num)将数据流中的整数num添加到数据结构中。
 * double findMedian()返回到目前为止所有元素的中位数。与实际答案相差10^-5以内的答案江北接收。
 * 
 * 前半段是大顶堆，后半段是小顶堆
 * 对顶堆
*/

#include<iostream>
#include<set>
using namespace std;

class MedianFinder {
public:
	typedef pair<int, int> PII;
	int tot;
	set<PII> s1, s2;
	
	MedianFinder() {
		tot = 0;
	}

	void addNum(int num) {
		if (s1.size() == 0 || num < -s1.begin()->first) {
			s1.insert(PII(-num, tot++));
		} else {
			s2.insert(PII(num, tot++));
		}
		int n1 = (s1.size() + s2.size() + 1) / 2;
		if (n1 == s1.size()) return ;
		if (s1.size() < n1) {
			s1.insert(PII(-s2.begin()->first, tot++));
			s2.erase(s2.begin());
		} else {
			s2.insert(PII(-s1.begin()->first, tot++));
			s1.erase(s1.begin());
		}
		return ;
	}

	double findMedian() {
		if ((s1.size() + s2.size()) % 2) {
			return -s1.begin()->first;
		}
		double a = -s1.begin()->first;
		double b = s2.begin()->first;
		return (a + b) / 2.0;
	}
};