#include<bits/stdc++.h>
#define P pair<int,int>
#define N 3005
using namespace std;
priority_queue<int>pq[N],sum;
int p[N],c[N],n,m,cnt=0;
long long check(int x)
{
	long long res=0;int tmp=0;
	for(;!pq[1].empty();)pq[1].pop();
	for(;!sum.empty();)sum.pop();
	for(int i=1;i<=n;++i)
		pq[p[i]].push(-c[i]);	
	for(int i=2;i<=m;++i)
		for(;pq[i].size()>=x;)
			res-=pq[i].top(),pq[i].pop(),++tmp;
	for(int i=2;i<=m;++i)
		for(;!pq[i].empty();)
			sum.push(pq[i].top()),pq[i].pop();
//	for(;!sum.empty();)printf("%d\n",sum.top()),sum.pop();
	for(int i=pq[1].size()+tmp+1;i<=x;++i)
	{
		if(sum.empty())return 2e18;
		res-=sum.top(),sum.pop();
	}
//	printf("%lld\n",res);
	return res;
}
int main()
{
	long long ans=2e18;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",p+i,c+i);
		if(p[i]==1)++cnt;
	}
	for(int i=max(1,cnt);i<=n;++i)
		ans=min(ans,check(i));
	printf("%lld\n",ans);
	return 0;
}
