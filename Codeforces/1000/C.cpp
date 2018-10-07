#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
using namespace std;
P a[400005];int ans[200005],n,cnt;
signed main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;++i)
	{
		int l,r;scanf("%lld%lld",&l,&r);
		a[i<<1|1]=P(l,+1);
		a[i<<1]=P(r+1,-1);
	}sort(a,a+n*2);cnt=a->second;
	for(int i=1;i<n<<1;++i)
	{
		for(;a[i].first==a[i-1].first;++i)
			cnt+=a[i].second;
		ans[cnt]+=a[i].first-a[i-1].first;
		cnt+=a[i].second;
	}++ans[cnt];
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}
