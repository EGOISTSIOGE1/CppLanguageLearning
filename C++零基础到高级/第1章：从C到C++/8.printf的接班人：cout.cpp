/*************************************************************************
	> File Name: 8.printf的接班人：cout.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 24 Jun 2024 11:37:14 PM CST
 ************************************************************************/

#include <iostream> // input output stream
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {
	int a = 123;
	cout << "hello world" << endl;
	cout << a << endl;
	cout << "a = " << a << endl;

	double b = 12.345;
	cout << b << endl;
	printf("%%lf = %lf\n", b);
	printf("%%g = %g\n", b); // 输出尽可能简短的信息

	printf("%%.4lf = %.4lf\n", b);
	cout << setprecision(4) << b << endl; // 12.35 四位有效数字
	cout << fixed << setprecision(4) << b << endl; // 12.3450 设置小数点后四位数字

	return 0;
}
