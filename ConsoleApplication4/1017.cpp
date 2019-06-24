/*
一个工厂制造的产品形状都是长方体，它们的高度都是h，长和宽都相等，一共有六个型号，他们的长宽分别为1*1, 2*2, 3*3, 4*4, 5*5, 6*6。这些产品通常使用一个 6*6*h 的长方体包裹包装然后邮寄给客户。因为邮费很贵，所以工厂要想方设法的减小每个订单运送时的包裹数量。他们很需要有一个好的程序帮他们解决这个问题从而节省费用。现在这个程序由你来设计。
输入
输入文件包括几行，每一行代表一个订单。每个订单里的一行包括六个整数，中间用空格隔开，分别为1*1至6*6这六种产品的数量。输入文件将以6个0组成的一行结尾。
输出
除了输入的最后一行6个0以外，输入文件里每一行对应着输出文件的一行，每一行输出一个整数代表对应的订单所需的最小包裹数。
样例输入
0 0 4 0 0 1
7 5 1 0 0 0
0 0 0 0 0 0
样例输出
2
1
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int _1017()
{
	int a1, a2, a3, a4, a5, a6;
	vector<int> result;
	while (true)
	{
		int count = 0;
		cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
		if (a1==0 && a2==0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0) break;
		//int area = a1 + 4*a2 + 9*a3 + 16*a4 + 25*a5 + 36*a6;
		if (a6 != 0) {
			count += a6;
			a6 = 0;
		}
		if (a5 != 0) {
			count += a5;
			if (a1 != 0) {
				if ((a1 - 11*a5) < 0) a1 = 0;
				else a1 = a1 - 11*a5;
			}
			a5 = 0;
		}
		if (a4 != 0)
		{
			count += a4;
			if (a2 != 0)
			{
				if (a2 > 5 * a4)
				{
					a2 = a2 - 5 * a4;
					a4 = 0;
				}
				else
				{
					int temp4 = 20 * a4 - a2 * 4;
					if (a1 != 0) {
						if (a1 < temp4)
						{
							a1 = 0;
							a4 = 0;
						}
						else
						{
							a1 = a1 - temp4;
							a4 = 0;
						}
					}
					a2 = 0;
				}
			}
		}
		if (a3 != 0)
		{
			int tmp= floor(a3 / 4.0);
			count += tmp;
			a3 = a3 - tmp * 4;
			if (a3 != 0) {
				count++;
				if (a2 != 0)
				{
					if (a2 > 7 - 2 * a3)
					{
						a2 = a2 - 7 + 2 * a3;
						if (a1 != 0)
						{
							if (a1 > 36 - 4 * (7 - 2 * a3) - a3 * 9)
							{
								a1 = a1 - (36 - 4 * (7 - 2 * a3) - a3 * 9);
							}
							else
							{
								a1 = 0;
							}
						}
					}
					else
					{
						if (a1 != 0)
						{
							if (a1 > 36 - 9 * a3 - 4 * a2)
							{
								a1 = a1 - (36 - 9 * a3 - 4 * a2);
							}
							else
							{
								a1 = 0;
							}
						}
					}
					a2 = 0;
				}
			}
		}
		if (a2 != 0)
		{
			int temp2= floor(a2 / 9.0);
			count += temp2;
			a2 = a2%9;
			if (a2 != 0)
			{
				count++;
				if (a1 != 0)
				{
					if (a1 > (36 - a2 * 4))
					{
						a1 = a1 - (36 - a2 * 4);
					}
					else
					{
						a1 = 0;
					}
				}
				a2 = 0;
			}
		}
		if (a1 != 0)
		{
			int temp1 = ceil(a1 / 36.0);
			count += temp1;
			a1 = 0;
		}
		result.push_back(count);
	}
	for (int i = 0; i < result.size(); i++)
	{
		if (i == result.size() - 1) {
			printf("%d", result[i]);
		}
		else {
			printf("%d\n1", result[i]);
		}
	}
	return 0;
}