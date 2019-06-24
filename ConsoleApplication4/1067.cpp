/*威佐夫博弈（Wythoff Game）
有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。游戏规定，每次有两种不同的取法，一是可以在任意的一堆中取走任意多的石子；二是可以在两堆中同时取走相同数量的石子。最后把石子全部取完者为胜者。现在给出初始的两堆石子的数目，如果轮到你先取，假设双方都采取最好的策略，问最后你是胜者还是败者。
输入
输入包含若干行，表示若干种石子的初始情况，其中每一行包含两个非负整数a和b，表示两堆石子的数目，a和b都不大于1,000,000,000。
输出
输出对应也有若干行，每行包含一个数字1或0，如果最后你是胜者，则为1，反之，则为0。
样例输入
2 1
8 4
4 7
样例输出
0
1
0
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
#include "main.h"
using namespace std;
int _1067()
{
	int a, b;
	while (cin >> a >> b)
	{
		int i1 = (a > b ? b : a);
		int i2 = (int)abs(a - b)*((sqrt(5) + 1) / 2);
		if (i1 == i2)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}