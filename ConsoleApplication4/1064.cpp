/*���ַ�
�ɾ��ľ����Ǿ����ٰ�һ���������������������ίԱ����ȫ����Ը��ɣ����ǳ�ŵҪ��֯һ��ʷ������ı��������Ǿ�����ѡ�ֵĵ������������˽ṹ������һ�𣬼�������ȫ������һ����һ�����ķ�������Ϊ����֯�����ȫ�����ı���������ίԱ����ϯ���Ҫ������ѡ�ֵĵ��ԵȾ����Χ���ڷ�������Χ���á�

Ϊ�������ߣ�����ίԱ����ϵ�˵��ص�һ�������������ṩ�̣�Ҫ���ܹ��ṩһ�������ĵȳ����ߡ�����ίԱ��ϣ������Խ��Խ�ã�����ѡ����֮��ľ�����Ծ�����ԶһЩ��

�ù�˾���������ܳн������������֪�������ÿ�����ߵĳ��ȣ���ȷ�����ף�������ֻҪ��������������߳��ȣ���ȷ�����ף��������ܹ���ɶ����ߵ��и�������ǣ���Σ���������߳��Ȳ���֪���������������ܲ�֪���롣

����Ҫ��дһ�����򣬰�����������ȷ��һ��������߳��ȣ����Ұ��˳��ȶԿ���е����߽����и�ܹ��õ�ָ�����������ߡ�

����
��һ�а�����������N��K���Ե����ո������N��1 <= N <= 10000���ǿ���е���������K��1 <= K <= 10000������Ҫ������������
������N�У�ÿ��һ������Ϊ�����ÿ�����ߵĳ��ȣ���λ���ף����������ߵĳ�������1m������100km�������е����г��ȶ���ȷ�����ף���������С�������λ��
���
���������ܹ��ӿ����������г�ָ�����������ߵ�����ȣ���λ���ף������뾫ȷ�����ף���������С�������λ��
���޷��õ���������Ϊ1cm��ָ�����������ߣ�����������0.00�������������ţ���
��������
4 11
8.02
7.43
4.57
5.39
�������
2.00
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int _1064()
{
	int lengthdata[100000];
	int count, needcount, mid;
	int rangea=0, rangeb;
	cin >> count >> needcount;
	double max = 0;
	for (int i = 0; i < count; i++)
	{
		double l;
		cin >> l;
		max = (max > l ? max : l);
		lengthdata[i]=(l*100);
	}
	rangeb = max*100+1;
	
	while (rangea+1<rangeb)      
	{
		mid = (rangea + rangeb) / 2;
		int totalcount = 0;
		for(int i=0;i<count;i++)
		{
			totalcount += lengthdata[i] / mid;
		}
		if (totalcount >= needcount) rangea = mid;
		else
		{
			rangeb = mid;
		}
	}
	printf("%.2lf\n", rangea / 100.00);
	return 0; 
}
//int main()
//{
//	int max = 0, length[100000];
//	double temp;
//	int n, k;
//	int l = 0, r, mid, ans;
//	int i;
//	cin >> n >> k;
//	for (i = 0; i<n; i++)
//	{
//		cin >> temp;
//		length[i] = temp * 100;
//		if (length[i]>max) max = length[i];
//	}
//
//	r = max + 1;
//	while (l + 1<r)
//	{
//		ans = 0;
//		mid = (l + r) / 2;
//		for (i = 0; i<n; i++)
//			ans += length[i] / mid;
//		if (ans >= k) l = mid;
//		else r = mid;
//	}
//	printf("%.2lf\n", l / 100.00);
//	return 0;
//}