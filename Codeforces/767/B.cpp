#include<bits/stdc++.h>
using namespace std;
long long ts,tf,t,n,a,m=1e12+10,ans;
int main()
{
	scanf("%lld%lld%lld%lld",&ts,&tf,&t,&n);
	while(n--)
	{
		scanf("%lld",&a);
		if(a&&a<=tf-t)
		{
			if(max(ts,a-1)<=tf-t&&ts-a+1<m) m=ts-a+1,ans=min(a-1,ts);
			ts=max(ts,a)+t;
		}
	}
	if(ts<=tf-t) ans=ts;
	printf("%lld",ans);
	return 0;
}