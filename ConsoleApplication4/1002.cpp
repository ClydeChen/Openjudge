/*
英文字母（除Q和Z外）和电话号码存在着对应关系，如下所示：
A,B,C -> 2
D,E,F -> 3
G,H,I -> 4
J,K,L -> 5
M,N,O -> 6
P,R,S -> 7
T,U,V -> 8
W,X,Y -> 9
标准的电话号码格式是xxx-xxxx，其中x表示0-9中的一个数字。有时为了方便记忆电话号码，我们会将电话号码的数字转变为英文字母，如把263-7422记成America。有时，我们还加上“-”作为分隔符，如把449-6753记成Hi-World。当然，我们未必要将所有的数字都转变为字母，比如474-6635可以记成iPhone-5。
总之，一个方便记忆的电话号码由数字和除Q、Z外的英文字母组成，并且可以在任意位置插入任意多的“-”符号。
现在 ，我们有一个列表，记录着许多方便记忆的电话号码。不同的方便记忆的电话号码可能对应相同的标准号码，你的任务就是找出它们。


输入
第一行是一个正整数n1（n1 <= 100000），表示列表中的电话号码数。
其后n1行，每行是一个方便记忆的电话号码，它由数字和除Q、Z外的英文字母、“-”符号组成，其中数字和字母的总数一定为7，字符串总长度不超过200。
输出
输出包括若干行，每行包括一个标准电话号码（xxx-xxxx）以及它重复出现的次数k（k >= 2），中间用空格分隔。输出的标准电话号码需按照升序排序。

如果没有重复出现的标准电话号码，则输出一行“No duplicates.”。
样例输入
12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279
样例输出
310-1010 2
487-3279 4
888-4567 3
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
//struct datasave
//{
//	string str;
//	int count;
//  //定义结构体的<操作符
//	bool operator < (const datasave &m)const {
//		return str < m.str;
//	}
//};

int _1002()
{

	map<string, int> datasave;
	//vector<datasave> datasavevec;
	vector<int> indexsave;
	char s[200];
	int n1;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> s;
		string str = string(s);
		int begin = 0;
		while (true)
		{
			begin = str.find("-", begin);
			if (begin == -1) break;
			str.erase(begin, 1);
		}
		for (int j = 0; j < 7; j++)
		{
			if (str[j] > 0x39 && str[j] < 0x51)
			{
				int result = floor((str[j] - 65) / 3.0);
				str[j] = 0x32 + result;
			}
			else if (str[j] > 0x39 && str[j] > 0x51)
			{
				int result = ceil((str[j] - 65) / 3.0);
				str[j] = 0x32 + result - 1;
			}
		}
		str.insert(3, "-", 0, 1);
		if (datasave.find(str) == datasave.end()) {
			datasave.insert(pair<string, int>(str, 1));
		}
		else {
			datasave[str] = datasave[str] + 1;

		}
	}

	//while (tempvector.size() > 0)
	//{
	//	int count = 0;
	//	string s = tempvector[0];
	//	vector<string> ::iterator pIter = tempvector.begin();
	//	for (; pIter != tempvector.end(); )
	//	{
	//		if (*pIter == s)
	//		{
	//			pIter = tempvector.erase(pIter);
	//			count++;
	//		}
	//		else
	//		{
	//			pIter++;
	//		}
	//	}
	//	if (count > 1)
	//	{
	//		datasave ds;
	//		ds.count = count;
	//		ds.str = s;
	//		datasavevec.push_back(ds);
	//	}
	//}
	//sort(datasavevec.begin(), datasavevec.end());
	bool isnuint64_t = true;
	map<string, int>::iterator data_iterator;
	for (data_iterator = datasave.begin(); data_iterator != datasave.end(); data_iterator++)
	{
		string temps = data_iterator->first;
		int count = data_iterator->second;
		if (count >= 2)
		{
			cout << temps.c_str() << " " << count << endl;
			isnuint64_t = false;
		}
	}
	if(isnuint64_t) cout << "No duplicates." << endl;
	return 0;
}
