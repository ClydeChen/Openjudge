/*
年轻的探险家来到了一个印第安部落里。在那里他和酋长的女儿相爱了，于是便向酋长去求亲。酋长要他用10000个金币作为聘礼才答应把女儿嫁给他。探险家拿不出这么多金币，便请求酋长降低要求。酋长说："嗯，如果你能够替我弄到大祭司的皮袄，我可以只要8000金币。如果你能够弄来他的水晶球，那么只要5000金币就行了。"探险家就跑到大祭司那里，向他要求皮袄或水晶球，大祭司要他用金币来换，或者替他弄来其他的东西，他可以降低价格。探险家于是又跑到其他地方，其他人也提出了类似的要求，或者直接用金币换，或者找到其他东西就可以降低价格。不过探险家没必要用多样东西去换一样东西，因为不会得到更低的价格。探险家现在很需要你的帮忙，让他用最少的金币娶到自己的心上人。另外他要告诉你的是，在这个部落里，等级观念十分森严。地位差距超过一定限制的两个人之间不会进行任何形式的直接接触，包括交易。他是一个外来人，所以可以不受这些限制。但是如果他和某个地位较低的人进行了交易，地位较高的的人不会再和他交易，他们认为这样等于是间接接触，反过来也一样。因此你需要在考虑所有的情况以后给他提供一个最好的方案。
为了方便起见，我们把所有的物品从1开始进行编号，酋长的允诺也看作一个物品，并且编号总是1。每个物品都有对应的价格P，主人的地位等级L，以及一系列的替代品Ti和该替代品所对应的"优惠"Vi。如果两人地位等级差距超过了M，就不能"间接交易"。你必须根据这些数据来计算出探险家最少需要多少金币才能娶到酋长的女儿。
输入
输入第一行是两个整数M，N（1 <= N <= 100），依次表示地位等级差距限制和物品的总数。接下来按照编号从小到大依次给出了N个物品的描述。每个物品的描述开头是三个非负整数P、L、X（X < N），依次表示该物品的价格、主人的地位等级和替代品总数。接下来X行每行包括两个整数T和V，分别表示替代品的编号和"优惠价格"。
输出
输出最少需要的金币数。
样例输入
1 4
10000 3 2
2 8000
3 5000
1000 2 1
4 200
3000 2 1
4 200
50 2 0
样例输出
5250
*/
//超时
//#include<stdio.h>
//#include<iostream>
//#include<math.h>
//#include<map>
//#include<vector>
//using namespace std;

//struct goods
//{
//	int Price, Level, SuccedaneumCount,Index;
//    map<int, int>Succedaneum;
//};
//
//map<int, goods> GoodsStore;
//map<int, int> MinPrice;
//int ClassLimit, GoodsCount;
//
//int MinLevel;
//int MinPriceOf(int GoodsIndex) {
//	int ThePrice = GoodsStore[GoodsIndex].Price;
//	if (MinPrice[GoodsIndex] == 0) {
//		if (GoodsStore[GoodsIndex].SuccedaneumCount == 0) {
//			MinPrice.insert(pair<int,int>( GoodsIndex, ThePrice));
//			return ThePrice;
//		}
//		int min = ThePrice;
//		map<int, int>::iterator data_iterator;
//		for (data_iterator = GoodsStore[GoodsIndex].Succedaneum.begin(); data_iterator != GoodsStore[GoodsIndex].Succedaneum.end(); data_iterator++) {
//			if (GoodsStore[data_iterator->first].Level < MinLevel);
//			else {
//				int newprice = data_iterator->second + MinPriceOf(data_iterator->first);
//				if (newprice < min) min = newprice;
//			}
//		}
//		MinPrice.insert(pair<int, int>(GoodsIndex, min));
//		return min;
//	}
//	else return MinPrice[GoodsIndex];
//}
//
////int GetMinPrice()
////{
////	map<int, goods>::iterator data_iterator;
////	int minprice = 0;
////
////}
//
//int main(){
//	int SuccedaneumIndex, Discount,Index=1;
//	cin >> ClassLimit >> GoodsCount;
//	for (int i = 0; i < GoodsCount; i++) {
//		goods tempgoods;
//		tempgoods.Index = Index;
//		cin >> tempgoods.Price >> tempgoods.Level >> tempgoods.SuccedaneumCount;
//		for (int j = 0; j < tempgoods.SuccedaneumCount; j++) {
//			cin >> SuccedaneumIndex >> Discount;
//			tempgoods.Succedaneum.insert(pair<int, int>(SuccedaneumIndex, Discount));
//		}
//		GoodsStore.insert(pair<int,goods>(Index,tempgoods));
//		Index++;
//	}
//	MinLevel = GoodsStore[1].Level - ClassLimit;
//	cout << MinPriceOf(1) << endl;
//    return 0;
//}
#include<iostream> 
#include<stdio.h>
#include<string>
using namespace std;
const int maxn = 110;
const int inf = 1 << 29;
int n, m, level[maxn], map[maxn][maxn], dist[maxn];
bool vis[maxn];
int Dijstra(int st)
{
	for (int i = 1; i <= n; i++)
		dist[i] = map[0][i];
	for (int i = 0; i<n; i++)
	{
		int mini = inf, pos = -1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dist[j]<mini)
			{
				mini = dist[j];
				pos = j;
			}
		if (pos == -1)
			break;
		vis[pos] = 1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dist[j]>dist[pos] + map[pos][j])
				dist[j] = dist[pos] + map[pos][j];
	}
	return dist[1];
}
int _1062()
{
	while (cin>>m>>n)
	{
		memset(level, 0, sizeof(level));
		memset(map, 0x7f, sizeof(map));
		for (int i = 1; i <= n; i++)
		{
			int k;
			map[i][i] = 0;
			cin>>map[0][i]>>level[i]>>k;
			while (k--)
			{
				int v, c;
				cin>>v>>c;
				map[v][i] = c;
			}
		}
		int ans = inf;
		for (int i = 0; i <= m; i++)
		{
			memset(vis, 0, sizeof(vis));
			for (int j = 1; j <= n; j++)
				if (level[j]<level[1] - i || level[j]>level[1] + m - i)
					vis[j] = 1;
			int  temp = Dijstra(0);
			ans = ans<temp?ans:temp;
		}
		printf("%d\n", ans);
	}
	return 0;
}

