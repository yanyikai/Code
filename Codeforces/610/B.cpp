#include<bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
long long n,i,minn=inf,maxn,p,t[400001],ans;
int main()
{
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&t[i]);
		t[n+i]=t[i];
		minn=min(minn,t[i]);
	}t[2*n]=minn;
	for(i=0;i<=2*n;i++)
	{
		if(t[i]>minn) p++;
		else
		{
			maxn=max(maxn,p);
			p=0;
		}
	}
	ans=minn*n+maxn;
	printf("%lld",ans);
	return 0;
}