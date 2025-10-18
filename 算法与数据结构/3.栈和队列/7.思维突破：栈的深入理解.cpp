/*************************************************************************
	> File Name: 7.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:27:35 PM CST
 ************************************************************************/

/*
* 栈：深入理解
* 
* 思考：
*		问题简化成只有一种括号，怎么做？
*		想到用栈的同学，在简化问题中，能不能不用栈？
* 
*		1、（（（）（））（））	TRUE
*		2、（（）））（）			FALSE
*		3、（（）（）				FALSE
* 
*		1、在任意一个位置上，左括号数量大于等于右括号数量
*		2、在最后一个位置上，左括号数量等于右括号数量
*		3、程序中只需要记录左括号数量和右括号数量即可
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

bool isValid_1(char* s) {
	int32_t lnum = 0, rnum = 0;
	int32_t len = strlen(s);
	for (int32_t i = 0; i < len; i++) {
		switch (s[i]) {
		case '(':++lnum; break;
		case ')':++rnum; break;
		default:return false;
		}
		if (lnum >= rnum)continue;
		return false;
	}
	return lnum == rnum;
}


bool isValid_2(char* s) {
	int32_t lnum = 0;
	int32_t len = strlen(s);
	for (int32_t i = 0; i < len; i++) {
		switch (s[i]) {
		case '(':++lnum; break;
		case ')':--lnum; break;
		default:return false;
		}
		if (lnum >= 0)continue;
		return false;
	}
	return lnum == 0;
}

/*
* 1、我们获得了怎样新的思维方式？
* 2、+1可以等价为“进”，-1可以等价为“出”
* 3、一对（）可以等价为一个完整的时间
* 4、（（））可以看作事件与事件之间的完全包含关系
* 5、由括号的等价变换，得到了一个新的数据结构
* 
* 栈
* 可以处理具有完全包含关系的问题
* 
* 栈：树的深度遍历、深度优先搜索（图算法基础）
* 队列（循环）：树的层序遍历，广度优先搜索（图算法基础）
* 单调栈：临近最大（小）值
* 单调队列：区间最大（小）值
*/
