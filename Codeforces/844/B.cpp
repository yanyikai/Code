#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,ans,a[55][2],b[55][2],p;
long long pow(int k)
{
	p=1;
	while(k--)
	{
		p*=2;
	}
	return p;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	ans-=n*m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			a[i][k]++;
			b[j][k]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		ans+=pow(a[i][0])-1;
		ans+=pow(a[i][1])-1;
	}
	for(i=1;i<=m;i++)
	{
		ans+=pow(b[i][0])-1;
		ans+=pow(b[i][1])-1;
	}
	printf("%lld",ans);
	return 0;
}