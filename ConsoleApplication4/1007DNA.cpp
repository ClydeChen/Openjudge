/*
现在有一些长度相等的DNA串（只由ACGT四个字母组成），请将它们按照逆序对的数量多少排序。
逆序对指的是字符串A中的两个字符A[i]、A[j]，具有i < j 且 A[i] > A[j] 的性质。如字符串”ATCG“中，T和C是一个逆序对，T和G是另一个逆序对，这个字符串的逆序对数为2。


输入
第1行：两个整数n1和m，n1(0<n1<=50)表示字符串长度，m(0<m<=100)表示字符串数量

第2至m+1行：每行是一个长度为n1的字符串
输出
按逆序对数从少到多输出字符串，逆序对数一样多的字符串按照输入的顺序输出。
样例输入
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
样例输出
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