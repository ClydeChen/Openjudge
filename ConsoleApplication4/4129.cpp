/*
��������һ��R*C ���Թ��У����λ����"S" ��ʾ���Թ��ĳ�����"E" ��ʾ��

�Թ�����һЩʯͷ����"#" ��ʾ������һЩ���������߶���������"." ��ʾ��

��ʼʱ��Ϊ0 ʱ����վ�ڵ�ͼ�б��Ϊ"S" ��λ���ϡ���ÿ�ƶ�һ�������������ҷ����ƶ����Ứ��һ����λʱ�䡣�����һֱ�����ƶ�������ͣ����ԭ�ز��ߡ�

��ǰʱ����K �ı���ʱ���Թ��е�ʯͷ�ͻ���ʧ����ʱ������ߵ���Щλ���ϡ��������ʱ����㲻���ߵ�ʯͷ���ڵ�λ�á�

����ӳ�ʼλ���ߵ��Թ�����������Ҫ���Ѷ��ٸ���λʱ�䡣

����޷��ߵ����ڣ������"Oop!"��

����
��һ����һ�������� T����ʾ�� T �����ݡ�
ÿ�����ݵĵ�һ�а��������ÿո�ֿ������������ֱ�Ϊ R��C��K��
�������� R ���У�ÿ�а����� C ���ַ����ֱ������ "S"��"E"��"#" �� "."��
���У�0 < T <= 20��0 < R, C <= 100��2 <= K <= 10��
���
����ÿ�����ݣ�����ܹ��ߵ��Թ��ĳ��ڣ������һ������������ʾ������Ҫ���ѵĵ�λʱ�䣬������� "Oop!"��
��������
1
6 6 2
...S..
...#..
.#....
...#..
...#..
..#E#.
�������
7
*/

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int MinDataSave;
int _4129()
{
	int num;
	cin >> num;
	for (int i1 = 0; i1 < num; i1++)
	{
		int R, C, K;
		cin >> R >> C >> K;
		vector<string> data;
		string tempstr;
		int si, sj, ei, ej;
		for (int i2 = 0; i2 < R; i2++)
		{
			cin >> tempstr;
			int j = 0;
			for each (char c in tempstr)
			{
				if (c == 'S') {
					si = i2;
					sj = j;
				}
				if (c == 'E') {
					ei = i2;
					ej = j;
				}
				j++;
			}
			data.push_back(tempstr);
		}

	}
	return 0;
}

int GetMin(int i, int j, int ei,int ej)
{
	//if(MinDataSave[i][j])
	return 0;
}
