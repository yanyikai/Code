#include<bits/stdc++.h>
using namespace std;
long long n,k,i,a[100000],b[100000],ans=1,f[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int main()
{
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n/k;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n/k;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(i=0;i<n/k;i++)
	{
		b[i]?ans*=(f[k]-1)/a[i]+1-(f[k-1]*(b[i]+1)-1)/a[i]+(f[k-1]*b[i]-1)/a[i]:ans*=(f[k]-1)/a[i]-(f[k-1]-1)/a[i];
		ans%=1000000007;
	}
	printf("%lld",ans);
	return 0;
}