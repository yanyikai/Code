#pragma GCC optimize("inline,Ofast")
#include<bits/stdc++.h>
#define N 100005
#define P pair<int,int>
// #define int long long
using namespace std;
int a[1005];
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
	sort(a,a+n);
	printf("%d\n",a[n-1]-a[0]-n+1);
	return 0;
}
