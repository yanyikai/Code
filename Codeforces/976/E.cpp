#include<bits/stdc++.h>
#define int long long
using namespace std;
struct P{
	int hp,dm,val;
}k[200005];
signed main()
{
	int n,a,b,sum=0,ans=0,tmp=0;
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&k[i].hp,&k[i].dm);
		k[i].val=max(0ll,k[i].hp-k[i].dm);
		sum+=k[i].dm;
	}
	if(!b)return printf("%lld\n",sum),0;
	b=min(n,b);
	sort(k+1,k+n+1,[](const P&x,const P&y)->bool{return x.val>y.val;});
	for(int i=1;i<=b;++i)tmp+=k[i].val;
	for(int i=1;i<=b;++i)ans=max(ans,tmp-k[i].val+k[i].hp*(1<<a)-k[i].dm);
	for(int i=b+1;i<=n;++i)ans=max(ans,tmp-k[b].val+k[i].hp*(1<<a)-k[i].dm);
	printf("%lld\n",sum+ans);
	return 0;
}
