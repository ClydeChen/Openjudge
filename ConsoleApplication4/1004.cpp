/*
Larry今年毕业并找到了一份工作。他赚很多钱，但似乎总是不够。Larry认为他需要控制他的投资以解决自己的财务问题。Larry拿到了自己的银行账户详单，想看看自己有多少钱。请帮助Larry写一个程序，通过过去12个月中每月的月末结余，计算平均结余。

输入
输入包含12行，每行包含一个数，为某个月的结余。每个数都是不大于1,000,000的正数，保留两位小数，省略"$"符。
输出
输出一个数，为这12个月的平均月末结余，保留到小数点后第二位，并在最前面加一个"$"符。
样例输入
100.00
489.12
12454.12
1234.10
823.05
109.20
5.27
1542.25
839.18
83.99
1295.01
1.75
样例输出
$1581.42
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int _1004()
{
	double d=0.0;
	double whole=0.0;
	for (int i = 0; i < 12;i++)
	{
		cin >> d;
		whole += d;
	}
	printf("$%.2f", whole / 12.0);
	return 0;
}