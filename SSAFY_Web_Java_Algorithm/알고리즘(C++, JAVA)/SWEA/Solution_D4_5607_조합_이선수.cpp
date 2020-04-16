//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int N, R;
//int modVal = 1234567891;
//long long ft[1000001];
//long long factorial();
//long long Fermat(long long par, int a);
//int main()
//{
//	int T;
//	cin >> T;
//	ft[1] = 1;
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> N >> R;
//
//		long long son = factorial();
//		long long par = (ft[R] * ft[N - R]) % modVal;
//		long long npar = Fermat(par, modVal - 2);
//		cout << "#" << t << " " << (son*npar) % modVal << endl;
//	}
//}
//
//long long factorial()
//{
//	for (int i = 2; i <= N; i++)
//	{
//		ft[i] = (ft[i - 1] * i) % modVal;
//	}
//	return ft[N];
//}
//
//long long Fermat(long long par, int a)
//{
//	if (a == 0) return 1;
//	long long div = Fermat(par, a / 2);
//	long long mul = (div*div) % modVal;
//	if (a % 2 == 0) 
//		return mul;
//	else 
//		return (mul * par) % modVal;
//
//}
