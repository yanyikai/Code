#pragma GCC optimize("2,Ofast,inline")
#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n, m, a[N], b[N]; map<int, int> Map;
inline void mxn(int&a,int b){a<b?a=b:0;}
signed main()
{
	scanf("%lld%*d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
	scanf("%lld%*d", &m);
	for (int i = 1; i <= m; ++i) scanf("%lld", b+i);
	int ans = 0;
	for (int i = 1; i < 1e9 + 7; i <<= 1)
	{
		int d = i * 2; Map.clear();
		for (int j = 1; j <= n; ++j)
			mxn(ans, ++Map[(a[j] + i) % d]);
		for (int j = 1; j <= m; ++j)
			mxn(ans, ++Map[b[j] % d]);
	} Map.clear();
	for (int i = 1; i <= n; ++i) mxn(ans, ++Map[a[i]]);
	for (int i = 1; i <= m; ++i) mxn(ans, ++Map[b[i]]);
	printf("%lld\n", ans);
	return 0;
}
