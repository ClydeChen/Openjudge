/*
现在有一些英语单词需要做拼写检查，你的工具是一本词典。需要检查的单词，有的是词典中的单词，有的与词典中的单词相似，你的任务是发现这两种情况。单词A与单词B相似的情况有三种：
1、删除单词A的一个字母后得到单词B；
2、用任意一个字母替换单词A的一个字母后得到单词B；
3、在单词A的任意位置增加一个字母后得到单词B。
你的任务是发现词典中与给定单词相同或相似的单词。


输入
第一部分是词典中的单词，从第一行开始每行一个单词，以"#"结束。词典中的单词保证不重复，最多有10000个。
第二部分是需要查询的单词，每行一个，以"#"结束。最多有50个需要查询的单词。
词典中的单词和需要查询的单词均由小写字母组成，最多包含15个字符。
输出
按照输入的顺序，为每个需要检查的单词输出一行。如果需要检查的单词出现在词典中，输出“?x is correct"，?x代表需要检查的单词。如果需要检查的单词没有出现在词典中，则输出"?x: ?x1 ?x2 ...?xn"，其中?x代表需要检查的单词，?x1...?xn代表词典中与需要检查的单词相似的单词，这些单词中间以空格隔开。如果没有相似的单词，输出"?x:"即可。
样例输入
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
样例输出
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