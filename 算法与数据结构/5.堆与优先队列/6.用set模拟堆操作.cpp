/*************************************************************************
	> File Name: 6.用set模拟堆操作.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 11 Feb 2024 04:40:00 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

void test1() {
	cout << "set base usage" << endl;
	set<int> s;
	cout << s.size() << endl;
	s.insert(3);
	cout << s.size() << endl;
	s.insert(4);
	cout << s.size() << endl;
	s.insert(2);
	cout << s.size() << endl;
	return ;
}

void test2() {
	cout << "set item unique feature: " << endl;
	set<int> s;
	cout << s.size() << endl;
	s.insert(3);
	cout << s.size() << endl;
	s.insert(4);
	cout << "insert 4 : " << s.size() << endl;
	s.insert(4);
	cout << "insert 4 : " << s.size() << endl;
	return ;
}

void test3() {
	cout << "set item unique feature 2: " << endl;
	typedef pair<int, int> PII;
	set<PII> s;
	int tot = 0;
	cout << s.size() << endl;
	s.insert(PII(3, tot++));
	cout << s.size() << endl;
	s.insert(PII(4, tot++));
	cout << "insert 4 : " << s.size() << endl;
	s.insert(PII(4, tot++));
	cout << "insert 4 : " << s.size() << endl;
	return ;
}

void test4() {
	cout << "foreach set item : " << endl;
	typedef pair<int, int> PII;
	set<PII> s;
	int tot = 0;
	s.insert(PII(4, tot++));
	s.insert(PII(3, tot++));
	s.insert(PII(4, tot++));
	for (auto x : s) {
		cout << "(" << x.first << ", " << x.second << ")" << endl;
	}
	return ;
}

void test5() {
	cout << "set replace heap : " << endl;
	typedef pair<int, int> PII;
	int tot = 0;
	set<PII> s;
	for (int i = 0; i < 10; i++) {
		s.insert(PII(rand() % 20, tot++)); // push
	}
	for (int i = 0; i < 4; i++) {
		cout << "s.begin() = " << s.begin()->first << endl; // top
		s.erase(s.begin()); // pop
		cout << "pop heap" << endl;
	}
	return ;
}

// 大顶堆，将元素取反再插入set集合
// 例如1 3 6 6变为-1 -3 -6 -6再插入set集合，就能模拟大顶堆

int main(int argc, char const *argv[]) {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
