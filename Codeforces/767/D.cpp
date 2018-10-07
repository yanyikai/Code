#include<bits/stdc++.h>
using namespace std;
struct Milk { long long time,num; }milk[1000005];
long long n,m,k,i,m1[10000005],ans[1000005],minn,x,p;
bool cmp(Milk x,Milk y) { return x.time>y.time; }
int main()
{
	for(scanf("%lld%lld%lld",&n,&m,&k),i=1;i<=n;i++) scanf("%lld",&x),m1[x]++;
	for(i=0;i<=10000002;i++)
	{
		if(i) m1[i]+=m1[i-1];
		if(m1[i]>(i+1)*k&&i<=n)
		{
			printf("-1");
			return 0;
		}
	}
	for(i=0;i<=10000002;i++) m1[i]=(i+1)*k-m1[i];
	for(i=1;i<=m;i++) scanf("%lld",&milk[i].time),milk[i].num=i;
	sort(milk+1,milk+m+1,cmp);minn=m1[milk[1].time];
	for(i=1;i<=m&&minn;i++) if(minn&&m1[milk[i].time]) ans[++p]=milk[i].num,minn=min(--minn,--m1[milk[i].time]);
	sort(ans+1,ans+p+1);
	for(printf("%lld\n",p),i=1;i<=p;i++) printf("%lld ",ans[i]);
	return 0;
}