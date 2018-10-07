#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long t[2005],i,j,n,k,e,ans;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==1) t[j]=1;
			else
			{
				for(e=j+j;e<=n;e+=j)
				{
					t[j]=(t[j]+t[e])%MOD;
				}
			}
		}
	}
	for(i=1;i<=n;i++) ans=(ans+t[i])%MOD;
	printf("%lld",ans);
	return 0;
}