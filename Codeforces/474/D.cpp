#include<bits/stdc++.h>
#define N 100000
#define MOD 1000000007
using namespace std;
long long t[N+5],a,b,n,k,i;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=N;i++)
	{
		if(i<k) t[i]=1;
		else
		{
			if(i==k) t[i]=2;
			else
			{
				t[i]=(t[i-1]+t[i-k])%MOD;
			}
		}
	}
	for(i=2;i<=N;i++) t[i]=(t[i]+t[i-1]);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",(t[b]-t[a-1])%MOD);
	}
	return 0;
}