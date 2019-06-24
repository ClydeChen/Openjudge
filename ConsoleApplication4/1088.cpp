/*
Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。
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
