/*
һ����������Ĳ�Ʒ��״���ǳ����壬���ǵĸ߶ȶ���h�����Ϳ���ȣ�һ���������ͺţ����ǵĳ���ֱ�Ϊ1*1, 2*2, 3*3, 4*4, 5*5, 6*6����Щ��Ʒͨ��ʹ��һ�� 6*6*h �ĳ����������װȻ���ʼĸ��ͻ�����Ϊ�ʷѺܹ����Թ���Ҫ�뷽�跨�ļ�Сÿ����������ʱ�İ������������Ǻ���Ҫ��һ���õĳ�������ǽ���������Ӷ���ʡ���á��������������������ơ�
����
�����ļ��������У�ÿһ�д���һ��������ÿ���������һ�а��������������м��ÿո�������ֱ�Ϊ1*1��6*6�����ֲ�Ʒ�������������ļ�����6��0��ɵ�һ�н�β��
���
������������һ��6��0���⣬�����ļ���ÿһ�ж�Ӧ������ļ���һ�У�ÿһ�����һ�����������Ӧ�Ķ����������С��������
��������
0 0 4 0 0 1
7 5 1 0 0 0
0 0 0 0 0 0
�������
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