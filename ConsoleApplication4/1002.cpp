/*
Ӣ����ĸ����Q��Z�⣩�͵绰��������Ŷ�Ӧ��ϵ��������ʾ��
A,B,C -> 2
D,E,F -> 3
G,H,I -> 4
J,K,L -> 5
M,N,O -> 6
P,R,S -> 7
T,U,V -> 8
W,X,Y -> 9
��׼�ĵ绰�����ʽ��xxx-xxxx������x��ʾ0-9�е�һ�����֡���ʱΪ�˷������绰���룬���ǻὫ�绰���������ת��ΪӢ����ĸ�����263-7422�ǳ�America����ʱ�����ǻ����ϡ�-����Ϊ�ָ��������449-6753�ǳ�Hi-World����Ȼ������δ��Ҫ�����е����ֶ�ת��Ϊ��ĸ������474-6635���Լǳ�iPhone-5��
��֮��һ���������ĵ绰���������ֺͳ�Q��Z���Ӣ����ĸ��ɣ����ҿ���������λ�ò��������ġ�-�����š�
���� ��������һ���б���¼����෽�����ĵ绰���롣��ͬ�ķ������ĵ绰������ܶ�Ӧ��ͬ�ı�׼���룬�����������ҳ����ǡ�


����
��һ����һ��������n1��n1 <= 100000������ʾ�б��еĵ绰��������
���n1�У�ÿ����һ���������ĵ绰���룬�������ֺͳ�Q��Z���Ӣ����ĸ����-��������ɣ��������ֺ���ĸ������һ��Ϊ7���ַ����ܳ��Ȳ�����200��
���
������������У�ÿ�а���һ����׼�绰���루xxx-xxxx���Լ����ظ����ֵĴ���k��k >= 2�����м��ÿո�ָ�������ı�׼�绰�����谴����������

���û���ظ����ֵı�׼�绰���룬�����һ�С�No duplicates.����
��������
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
�������
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
//  //����ṹ���<������
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
