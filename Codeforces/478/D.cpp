#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long r,g,h,ans,dp[500000],i,j;
int main()
{
	scanf("%lld%lld",&r,&g);
	while(h*(h+1)/2<=r+g) h++;dp[0]=1;
	for(i=1;i<h;i++) for(j=r;j>=0;j--) dp[i+j]=(dp[i+j]+dp[j])%MOD;
	for(i=r;i>=max(h*(h-1)/2-g,0ll);i--) ans=(ans+dp[i])%MOD;
	printf("%lld",ans);
	return 0;
}