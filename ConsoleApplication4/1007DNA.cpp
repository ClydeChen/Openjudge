/*
������һЩ������ȵ�DNA����ֻ��ACGT�ĸ���ĸ��ɣ����뽫���ǰ�������Ե�������������
�����ָ�����ַ���A�е������ַ�A[i]��A[j]������i < j �� A[i] > A[j] �����ʡ����ַ�����ATCG���У�T��C��һ������ԣ�T��G����һ������ԣ�����ַ������������Ϊ2��


����
��1�У���������n1��m��n1(0<n1<=50)��ʾ�ַ������ȣ�m(0<m<=100)��ʾ�ַ�������

��2��m+1�У�ÿ����һ������Ϊn1���ַ���
���
������������ٵ�������ַ������������һ������ַ������������˳�������
��������
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
�������
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
struct MyStruct
{
	string str;
	int count;
	bool operator < (const MyStruct &m)const {
		return count < m.count;
	}
};
int _1007()
{
	int length, count;
	char instr[50];
	cin >> length >> count;
	vector<MyStruct> datavec;
	for (int i = 0; i < count; i++)
	{
		int n1 = 0;
		cin >> instr;
		for (int j=0; j < length; j++)
		{
			for (int k = j; k < length; k++)
			{
				if (instr[k] < instr[j])
				{
					n1++;
				}
			}
		}
		MyStruct ms;
		ms.count = n1;
		ms.str = string(instr);
		datavec.push_back(ms);
	}
	sort(datavec.begin(), datavec.end());
	for (int c = 0; c < count; c++)
	{
		printf("%s\n1", datavec[c].str.c_str());
	}
	return 0;
}