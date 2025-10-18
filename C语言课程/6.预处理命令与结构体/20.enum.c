/*************************************************************************
	> File Name: 20.enum.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 14 Dec 2023 11:56:42 PM CST
 ************************************************************************/

#include<stdio.h>

#define P(a, format) { \
	printf("%s = " format "\n", #a, a); \
}

// 枚举类型第一项默认等于0，之后项累加1
enum Number {
	zero,
	one,
	two = 10,
	three,
	four,
};

// 使用最后一位FUNC_MAX作为判断函数的大小
enum FUNC_DATA {
#ifdef TEST1
	FUNC_test1,
#endif
#ifdef TEST2
	FUNC_test2,
#endif
#ifdef TEST3
	FUNC_test3,
#endif
#ifdef TEST4
	FUNC_test4,
#endif
	FUNC_MAX
};

#define DEFINE_FUNC(name) \
void name() { \
	printf("this is function : %s\n", #name); \
}

DEFINE_FUNC(test1)
DEFINE_FUNC(test2)
DEFINE_FUNC(test3)
DEFINE_FUNC(test4)

// 枚举类型可以自动扩容数组
// 函数指针数组（使用枚举类型确认其数组大小）
void (*func_arr[FUNC_MAX])() = {
#ifdef TEST1
	test1,
#endif
#ifdef TEST2
	test2,
#endif
#ifdef TEST3
	test3,
#endif
#ifdef TEST4
	test4,
#endif
};


int main(int argc, char const *argv[]) {
	for (int i = 0; i < FUNC_MAX; i++) {
		func_arr[i]();
	}
	enum Number a;
	a = zero;
	P(a, "%d");
	a = one;
	P(a, "%d");
	a = two;
	P(a, "%d");
	a = three;
	P(a, "%d");

	return 0;
}
