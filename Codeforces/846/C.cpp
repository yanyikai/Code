#include<bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
long long ans=-inf,n,i,j,k,t[5007],d1,d2,d3,d1_,d2_,d3_,x,ans1,ans2,ans3;
int main()
{
	for(scanf("%lld",&n),i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		t[i]=x+t[i-1];
	}
	for(d2_=0;d2_<=n;d2_++)
	{
		d2=d2_;d1=d3=d2;
		for(d1_=0;d1_<=d2_;d1_++) if(t[d1_]>=t[d1]) d1=d1_;
		for(d3_=d2_;d3_<=n;d3_++) if(t[d3_]>=t[d3]) d3=d3_;
		if(t[d1]+t[d3]-t[d2]>=ans)
		{
			ans=t[d1]+t[d3]-t[d2];
			ans1=d1;
			ans2=d2;
			ans3=d3;
		}
	}
	printf("%lld %lld %lld",ans1,ans2,ans3);
	return 0;
}