/*
������һЩӢ�ﵥ����Ҫ��ƴд��飬��Ĺ�����һ���ʵ䡣��Ҫ���ĵ��ʣ��е��Ǵʵ��еĵ��ʣ��е���ʵ��еĵ������ƣ���������Ƿ������������������A�뵥��B���Ƶ���������֣�
1��ɾ������A��һ����ĸ��õ�����B��
2��������һ����ĸ�滻����A��һ����ĸ��õ�����B��
3���ڵ���A������λ������һ����ĸ��õ�����B��
��������Ƿ��ִʵ��������������ͬ�����Ƶĵ��ʡ�


����
��һ�����Ǵʵ��еĵ��ʣ��ӵ�һ�п�ʼÿ��һ�����ʣ���"#"�������ʵ��еĵ��ʱ�֤���ظ��������10000����
�ڶ���������Ҫ��ѯ�ĵ��ʣ�ÿ��һ������"#"�����������50����Ҫ��ѯ�ĵ��ʡ�
�ʵ��еĵ��ʺ���Ҫ��ѯ�ĵ��ʾ���Сд��ĸ��ɣ�������15���ַ���
���
���������˳��Ϊÿ����Ҫ���ĵ������һ�С������Ҫ���ĵ��ʳ����ڴʵ��У������?x is correct"��?x������Ҫ���ĵ��ʡ������Ҫ���ĵ���û�г����ڴʵ��У������"?x: ?x1 ?x2 ...?xn"������?x������Ҫ���ĵ��ʣ�?x1...?xn����ʵ�������Ҫ���ĵ������Ƶĵ��ʣ���Щ�����м��Կո���������û�����Ƶĵ��ʣ����"?x:"���ɡ�
��������
i
is
has
have
be
my
more
contest
me
too
if
award
#
me
aware
m
contest
hav
oo
or
i
fi
mre
#
�������
me is correct
aware: award
m: i my me
contest is correct
hav: has have
oo: too
or:
i is correct
fi: i
mre: more me
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int _1035()
{
	vector<string> dictionary;
	while (true)
	{
	    string s;
		cin >> s;
		if (s == "#") break;
		dictionary.push_back(s);
	}
	while (true)
	{
		string s1;
		cin >> s1;
		bool isright = false;
		if (s1 == "#") break;
		for (int i = 0; i < dictionary.size(); i++)
		{
			if (dictionary[i] == s1)
			{
				cout <<s1<<" is correct\n";
				isright = true;
				break;
			}
		}
		if (!isright)
		{
			cout <<s1<<":";
			for (int i = 0; i < dictionary.size(); i++)
			{
				if (dictionary[i].length() == s1.length()-1)
				{
					bool ismatch=true;
					int count1=0;
					for (int j = 0; j<dictionary[i].length(); j++)
					{
						if (count1 == 0)
						{
							if (!(s1[j] == dictionary[i][j]))
							{
								count1++;
								j--;
								continue;
							}
						}
						else
						{
							if (!(s1[j+1] == dictionary[i][j]))
							{
								ismatch = false;
								break;
							}
						}
					}
					if (ismatch) cout <<" "<< dictionary[i];
				}
				else if (dictionary[i].length()==s1.length()+1)
				{
					bool ismatch = true;
					int count2 = 0;
					for (int j = 0; j < s1.length(); j++)
					{
						if (count2 == 0)
						{
							if (!(s1[j] == dictionary[i][j]))
							{
								count2++;
								j--;
								continue;
							}
						}
						else
						{
							if (!(s1[j] == dictionary[i][j+1]))
							{
								ismatch = false;
								break;
							}
						}
					}
					if (ismatch) cout << " " << dictionary[i];
				}
				else if (dictionary[i].length() == s1.length())
				{
					int count3 = 0;
					for (int j = 0; j < s1.length(); j++)
					{
						if (!(s1[j] == dictionary[i][j]))
						{
							count3++;
							if (count3 > 1) break;
						}
					}
					if (count3==1) cout << " " << dictionary[i];
				}
			}
			cout << endl;
		}
	}
	return 0;
}