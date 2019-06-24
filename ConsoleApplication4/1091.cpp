/*
Z城市居住着很多只跳蚤。在Z城市周六生活频道有一个娱乐节目。一只跳蚤将被请上一个高空钢丝的正中央。钢丝很长，可以看作是无限长。节目主持人会给该跳蚤发一张卡片。卡片上写有N+1个自然数。其中最后一个是M，而前N个数都不超过M，卡片上允许有相同的数字。跳蚤每次可以从卡片上任意选择一个自然数S，然后向左，或向右跳S个单位长度。而他最终的任务是跳到距离他左边一个单位长度的地方，并捡起位于那里的礼物。
比如当N=2，M=18时，持有卡片(10, 15, 18)的跳蚤，就可以完成任务：他可以先向左跳10个单位长度，然后再连向左跳3次，每次15个单位长度，最后再向右连跳3次，每次18个单位长度。而持有卡片(12, 15, 18)的跳蚤，则怎么也不可能跳到距他左边一个单位长度的地方。
当确定N和M后，显然一共有M^N张不同的卡片。现在的问题是，在这所有的卡片中，有多少张可以完成任务。
输入
两个整数N和M(N <= 15 , M <= 100000000)。
输出
可以完成任务的卡片数。
样例输入
2 4
样例输出
12
提示
这12张卡片分别是：
(1, 1, 4), (1, 2, 4), (1, 3, 4), (1, 4, 4), (2, 1, 4), (2, 3, 4),
(3, 1, 4), (3, 2, 4), (3, 3, 4), (3, 4, 4), (4, 1, 4), (4, 3, 4)
*/

#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <iostream>  
using namespace std;
int d[100], a[100], cnt;
const int64_t mod = ((1LL) << 61) + 123456;
int n1, m1;
void getd(int m1)
{
	cnt = 0;
	for (int64_t i = 2; i*i <= m1; ++i)
	{
		if (m1%i == 0)
		{
			d[cnt++] = i;
			while (m1%i == 0) m1 /= i;
		}
	}
	if (m1 > 1) d[cnt++] = m1;
}
int64_t pows(int64_t x, int64_t n1)
{
	int64_t res = 1;
	for (int i = 0; i < n1; ++i)
		res = res*x%mod;
	return res;
}
int64_t dfs(int pos, int sp, int tot)
{
	if (pos == tot)
	{
		int64_t tmp = m1;
		for (int i = 0; i < tot; ++i)
			tmp /= a[i];
		return pows(tmp, n1);
	}
	int64_t sum = 0;
	for (int i = sp; i < cnt; ++i)
	{
		a[pos] = d[i];
		sum = (sum + dfs(pos + 1, i + 1, tot)) % mod;
	}
	return sum;
}
int _1091() {
	scanf_s("%d%d", &n1, &m1);
	getd(m1);
	int64_t ans = pows(m1, n1), tmp;
	for (int i = 1; i <= cnt; ++i)
	{
		tmp = dfs(0, 0, i);
		if (i & 1) ans = (ans - tmp) % mod;
		else ans = (ans + tmp) % mod;
	}
	printf("%lld\n1", ans%mod);
	return 0;
}
