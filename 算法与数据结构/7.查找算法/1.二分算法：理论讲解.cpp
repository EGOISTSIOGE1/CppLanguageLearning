/*************************************************************************
	> File Name: 1.二分算法：理论讲解.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 19 Sep 2024 10:03:17 AM CST
 ************************************************************************/

/**
 * 一、二分算法
 * 二、跳跃表（Skiplist）
 * 三、哈希表与布隆过滤器
 * 
 * 二分查找算法
 * min是头指针；max是尾指针；mid=（min + max）/ 2
 * 调整：
 * 		如果arr[mid] < x, min = mid + 1
 * 		如果arr[mid] > x, max = mid - 1
 * 		如果arr[mid] == x，找到结果
 * 终止条件：
 * 		min >= max
 * 时间复杂度：
 *  	O(logn)
 * 
 * 二分查找——泛型情况
 * 1、中间指针指向0的时候如何操作
 *  0：min = mid + 1
 * 2、中间指针指向1的时候如何操作
 * 	1：max = mid
 * 3、头尾指针处在交界面的时候是否出现bug
 * 	不会出现bug
*/

#include<iostream>
using namespace std;

