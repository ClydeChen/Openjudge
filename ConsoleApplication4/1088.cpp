/*
Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������Ļ��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������
1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����
����
����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
���
��������ĳ��ȡ�
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
vector< vector<int> > intdata;
int maxcount[100][100];
int r, c;

int getmaxcount(int row, int col) {
	int max = 0;
	if (maxcount[row][col] > 0) {
		return maxcount[row][col];
	}
	if (row - 1 >= 0) {
		if (intdata[row - 1][col] < intdata[row][col]) {
			if (max < getmaxcount(row - 1, col)) {
				max = getmaxcount(row - 1, col);
			}
		}
	}
	if (row + 1 < r) {
		if (intdata[row + 1][col] < intdata[row][col]) {
			if (max < getmaxcount(row + 1, col)) {
				max = getmaxcount(row + 1, col);
			}
		}
	}
	if (col - 1 >= 0) {
		if (intdata[row][col - 1] < intdata[row][col]) {
			if (max < getmaxcount(row, col - 1)) {
				max = getmaxcount(row, col - 1);
			}
		}
	}
	if (col + 1 < c) {
		if (intdata[row][col + 1] < intdata[row][col]) {
			if (max < getmaxcount(row, col + 1)) {
				max = getmaxcount(row, col + 1);
			}
		}
	}
	return maxcount[row][col] = max + 1;
}

int _1088()
{
	  cin >> r >> c;
		int tempint;
		int max = 0;
		for (int index = 0; index < r; index++) {
			vector<int> tempvect;
			for (int index1 = 0; index1 < c; index1++) {
				cin >> tempint;
				tempvect.push_back(tempint);
			}
			intdata.push_back(tempvect);
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (max < getmaxcount(i, j)) {
					max = getmaxcount(i, j);
				}
			}
		}
    cout << max<<endl;
	return 0;
}
