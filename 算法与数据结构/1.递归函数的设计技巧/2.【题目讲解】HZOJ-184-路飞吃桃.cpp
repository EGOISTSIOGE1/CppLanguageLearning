/*************************************************************************
	> File Name: 2.HZOJ-184.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 15 Nov 2023 11:09:48 PM CST
 ************************************************************************/

/*
* #184.路飞吃桃
* 路飞买了一堆桃子不知道个数，第一天吃了一半的桃子，还不过瘾，又多吃了一个。以后他每天吃剩下的桃子的一半还多一个，到n天只剩下一个桃子了。
* 路飞想知道一开始买了多少桃子。
* 
* 1.f(n)能吃n天的桃子数量
* 2.n = 1 => 1
* 3.(f(n - 1) + 1) * 2 = f(n)
*/

#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<string>

using namespace std;

int f(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return (f(n - 1) + 1) * 2;
}


int main()
{
	int n;
	cin >> n;
	cout << f(n) << endl;
	
	return 0;
}
