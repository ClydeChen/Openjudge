/*
�����̽�ռ�������һ��ӡ�ڰ����������������������Ů���మ�ˣ����Ǳ�������ȥ���ס�����Ҫ����10000�������ΪƸ��Ŵ�Ӧ��Ů���޸�����̽�ռ��ò�����ô���ң���������������Ҫ������˵��"�ţ�������ܹ�����Ū�����˾��Ƥ�����ҿ���ֻҪ8000��ҡ�������ܹ�Ū������ˮ������ôֻҪ5000��Ҿ����ˡ�"̽�ռҾ��ܵ����˾�������Ҫ��Ƥ����ˮ���򣬴��˾Ҫ���ý����������������Ū�������Ķ����������Խ��ͼ۸�̽�ռ��������ܵ������ط���������Ҳ��������Ƶ�Ҫ�󣬻���ֱ���ý�һ��������ҵ����������Ϳ��Խ��ͼ۸񡣲���̽�ռ�û��Ҫ�ö�������ȥ��һ����������Ϊ����õ����͵ļ۸�̽�ռ����ں���Ҫ��İ�æ�����������ٵĽ��Ȣ���Լ��������ˡ�������Ҫ��������ǣ������������ȼ�����ʮ��ɭ�ϡ���λ��೬��һ�����Ƶ�������֮�䲻������κ���ʽ��ֱ�ӽӴ����������ס�����һ�������ˣ����Կ��Բ�����Щ���ơ������������ĳ����λ�ϵ͵��˽����˽��ף���λ�ϸߵĵ��˲����ٺ������ף�������Ϊ���������Ǽ�ӽӴ���������Ҳһ�����������Ҫ�ڿ������е�����Ժ�����ṩһ����õķ�����
Ϊ�˷�����������ǰ����е���Ʒ��1��ʼ���б�ţ���������ŵҲ����һ����Ʒ�����ұ������1��ÿ����Ʒ���ж�Ӧ�ļ۸�P�����˵ĵ�λ�ȼ�L���Լ�һϵ�е����ƷTi�͸����Ʒ����Ӧ��"�Ż�"Vi��������˵�λ�ȼ���೬����M���Ͳ���"��ӽ���"������������Щ�����������̽�ռ�������Ҫ���ٽ�Ҳ���Ȣ��������Ů����
����
�����һ������������M��N��1 <= N <= 100�������α�ʾ��λ�ȼ�������ƺ���Ʒ�����������������ձ�Ŵ�С�������θ�����N����Ʒ��������ÿ����Ʒ��������ͷ�������Ǹ�����P��L��X��X < N�������α�ʾ����Ʒ�ļ۸����˵ĵ�λ�ȼ������Ʒ������������X��ÿ�а�����������T��V���ֱ��ʾ���Ʒ�ı�ź�"�Żݼ۸�"��
���
���������Ҫ�Ľ������
��������
1 4
10000 3 2
2 8000
3 5000
1000 2 1
4 200
3000 2 1
4 200
50 2 0
�������
5250
*/
//��ʱ
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

