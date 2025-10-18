/*************************************************************************
	> File Name: 23.HZOJ-239.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 03:19:59 PM CST
 ************************************************************************/

/*
* 城市扩建的规划是一个令人头疼的大问题。规划师设计了一个极其复杂的方案：当城市规模扩大之后，把与原来城市结构一样的区域复制或旋转90度之后建设在原来的城市周围（详细的说，将原来的城市复制一边放在原城市上方，
* 将顺时针旋转90度后的城市放在原城市的左上方，将逆时针旋转90度后的城市放在原城市的左方），再用道路将四部分首尾连接起来。
* 
* 容易看出，扩建后的城市的各个房屋仍然由一条道路连接。定义N级城市为拥有2^2N座房屋的城市。对于任意等级的城市，从左上角开始沿着唯一的道路走，依次为房屋标号，就能够得到每间房及的编号了。住在其中两间房屋里的人们想知道，
* 如果城市发展得到了一定等级，他俩各自所出的房屋之间的直线距离事多少。你可以认为图中的每个格子都是边长为10米的正方形，房屋均位于每个格子上的中心点上（T次询问，每次输入等级N，两个编号S、D，求S与D之间的直线距离。）
*/
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define S(a) ((a) * (a))

void f(long long n, long long s, long long& x, long long& y)
{
	if (n == 1)
	{
		if (s == 1)
		{
			x = 0, y = 0;
		}
		else if (s == 2)
		{
			x = 0, y = 1;
		}
		else if (s == 3)
		{
			x = 1, y = 1;
		}
		else
		{
			x = 1, y = 0;
		}
		return;
	}
	long long L = 1LL << (n - 1); //2^(N-1)
	long long block = L * L;
	long long xx, yy;

	if (s <= block) //(x, y) -> (y, x) 一号区域
	{
		f(n - 1, s, xx, yy);
		x = yy, y = xx;
	}
	else if (s <= 2 * block) //(x, y) -> (x, y + L) 二号区域
	{
		f(n - 1, s - block, xx, yy);
		x = xx, y = yy + L;
	}
	else if (s <= 3 * block) //(x, y) -> (x + L, y + L) 三号区域
	{
		f(n - 1, s - 2 * block, xx, yy);
		x = xx + L, y = yy + L;
	}
	else //(x, y) -> (2 * L - y - 1, L - x - 1) 四号区域
	{
		f(n - 1, s - 3 * block, xx, yy);
		x = 2 * L - yy - 1, y = L - xx - 1;
	}
	return;

}

int main()
{
	long long t, n, s, d;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld%lld%lld", &n, &s, &d);
		long long sx, sy, dx, dy;
		f(n, s, sx, sy);
		f(n, d, dx, dy);
		printf("%.0lf\n", 10 * sqrt(S(sx - dx) + S(sy - dy)));
	}

	return 0;
}