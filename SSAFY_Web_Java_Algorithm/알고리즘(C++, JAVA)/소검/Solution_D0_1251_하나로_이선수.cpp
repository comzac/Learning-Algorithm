///*
//	풀이 :
//	N개의 섬들간의 거리를 저장하는 벡터를 만들고,
//	최저거리부터 대표자를 확인하여 연결시켜
//	간선이 N-1개 완성되면 
//	최종적으로 계산쓰
//*/
//#include <iostream>
//#include <string>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//
//typedef long long ll;
//
//using namespace std;
//struct node {
//	ll from;
//	ll to;
//	ll dis;
//	node(ll f, ll t, ll d):from(f), to(t), dis(d){}
//
//	bool operator<(const node& o)const
//	{
//		return dis < o.dis;
//	}
//};
//
//ll parent[1001];
//ll N;
//ll y[1001];
//ll x[1001];
//double E;
//
//ll edgeNums;
//vector<node> v;
//
//double answer;
//
//void make_set();
//ll getParent(ll idx);
//bool unionParent(ll a, ll b);
//bool find_set(ll a, ll b);
//void input();
//void connect();
//void make_info();
//int main()
//{
//	ll T;
//	cin >> T;
//	for (ll t = 1; t <= T; t++)
//	{
//		input();
//		make_set();
//		make_info();
//
//		connect();
//
//		cout << "#" << t << " " << ll(round(answer)) << endl;
//
//		//visitInit();
//		edgeNums = 0;
//		answer = 0;
//		v.clear();
//	}
//	
//	return 0;
//}
//
//void make_set()
//{
//	for (ll i = 0; i < N; i++)
//		parent[i] = -1;
//}
//
//ll getParent(ll idx)
//{
//	if (parent[idx] < 0)
//		return idx;
//
//	return parent[idx] = getParent(parent[idx]);
//}
//
//bool unionParent(ll a, ll b)
//{
//	ll rootA = getParent(a);
//	ll rootB = getParent(b);
//	if (rootA == rootB) // 부모가 같은 경우,
//		return false;
//
//	if (parent[rootA] < parent[rootB]) // A 집합이 더 큰 경우,
//	{
//		parent[rootA] += parent[rootB];
//		parent[rootB] = rootA;
//	}
//	else
//	{
//		parent[rootB] += parent[rootA];
//		parent[rootA] = rootB;
//	}
//	return true;
//}
//
//bool find_set(ll a, ll b)
//{
//	ll rootA = getParent(a);
//	ll rootB = getParent(b);
//	if (rootA == rootB) // 부모가 같은 경우,
//		return false;
//	return true;
//}
//
//void input()
//{
//	cin >> N;
//	for (ll i = 0; i < N; i++)
//		cin >> x[i];
//	for (ll i = 0; i < N; i++)
//		cin >> y[i];
//	cin >> E;
//}
//
//void connect()
//{
//	ll from, to;
//	double dis;
//	for (ll i = 0; i < v.size(); i++)
//	{
//		from = v[i].from;
//		to = v[i].to;
//		dis = v[i].dis;
//
//		if (unionParent(from, to)) // 서로 부모가 다르면 연결
//		{
//			answer += dis * E;
//			edgeNums++;
//			if (edgeNums == N - 1)
//				return;
//		}
//	}
//}
//
//
//void make_info()
//{
//	for (ll i = 0; i < N; i++)
//	{
//		for (ll j = i+1; j < N; j++)
//		{
//			ll dy = y[j] - y[i];
//			ll dx = x[j] - x[i];
//			v.push_back({ i,j,dy*dy + dx * dx });
//		}
//	}
//	sort(v.begin(), v.end());
//}
