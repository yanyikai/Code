#include<bits/stdc++.h>
using namespace std;
long long n,t[100005],ans,sum,i,k,p;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld",&t[i]),ans+=t[i];
	sum=ans;
	sort(t+1,t+n+1);
	for(i=1;i<n;i++) sum-=t[i],k+=sum-(n-i)*t[i];
	ans+=2*k;
	p=__gcd(ans,n);
	ans/=p;n/=p;
	printf("%lld %lld",ans,n);
	return 0;
}