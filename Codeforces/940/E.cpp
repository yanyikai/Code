#include<bits/stdc++.h>
#define N 100005
#define L long long
using namespace std;
int n,c,a[N];
L sum[N],dp[N];
struct P{
	int x,id;
//	P(int x,int y):x(x),id(y){}
	int operator<(const P&o)const{
		return x==o.x?id>o.id:x>o.x;
	}
};priority_queue<P>Q;
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		sum[i]=sum[i-1]+(L)a[i];
	}
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1]+a[i];
		Q.push(P{a[i],i});
		for(;!Q.empty()&&Q.top().id<=i-c;)Q.pop();
		if(i<c)continue;
		dp[i]=min(dp[i],dp[i-c]+sum[i]-sum[i-c]-Q.top().x);
	}
	printf("%I64d\n",dp[n]);
	return 0;
}
