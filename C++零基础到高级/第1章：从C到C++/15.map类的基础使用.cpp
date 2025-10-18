/*************************************************************************
	> File Name: 15.map类的基础使用.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 03 Jul 2024 11:45:27 PM CST
 ************************************************************************/

/**
 * map类说明（底层为红黑树）
 * 
 * map类：映射表
 * 		头文件：map
 * 		命名空间：std
 * 		声明：map<key_type, value_type> arr;
 * 
 * 		arr.find(key) 判断某个key值是否在map中
 * 		arr[key] = value 将value存储在key位上
 * 		arr[key] 访问key值对应的value
 * 		arr.begin() 映射表的起始位置
 * 		arr.end() 映射表的结束位置
 */

#include<iostream>
#include<map>
using namespace std;

int main(int argc, char const *argv[]) {
	map<int, int> arr1;
	arr1[10000] = 1;
	arr1[-10000] = 2;

	map<double, int> arr2;
	arr2[1.5] = 3;
	arr2[2.5] = 4;
	arr2[3.5] = 5;

	cout << arr1.size() << " " << arr2.size() << endl;

	cout << arr1[10000] << endl;	// 1
	cout << arr1[100080] << endl;	// 0 返回相关类型的默认值 如果不存在会新生成该值，元素增加之后map性能会变差
	cout << arr1.size() << " " << arr2.size() << endl;	// arr1中元素增加了

	// 会依次将arr1的元素赋值给x，x=(key, value) first second
	for (auto x : arr1) {
		cout << x.first << " " << x.second << endl;
	}

	for (auto x : arr2) {
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}
