#include<bits/stdc++.h>
using namespace std;
long long x,y,a,b,p,ans,t;
int main()
{
	scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
	p=x*y/__gcd(x,y);ans=b/p-a/p;if(a%p==0) ans++;
	printf("%lld",ans);
	return 0;
}