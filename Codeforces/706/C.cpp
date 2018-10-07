#include<bits/stdc++.h>
#define inf 1e17
using namespace std;
long long n,i,dp[100005][2],a[100005],minn;
string x,y,x_,y_;
int main()
{
	for(scanf("%lld",&n),i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=0;i<=n;i++)
	{
		dp[i][0]=dp[i][1]=inf;
	}
	scanf("\n");dp[1][1]=a[1];dp[1][0]=0;
	for(cin>>x,i=2;i<=n;i++)
	{
		cin>>y;
		x_=x;y_=y;
		reverse(x_.begin(),x_.end());
		reverse(y_.begin(),y_.end());
		if(y>=x) dp[i][0]=min(dp[i][0],dp[i-1][0]);  
        if(y>=x_) dp[i][0]=min(dp[i][0],dp[i-1][1]);  
        if(y_>=x) dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);  
        if(y_>=x_) dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]); 
		x=y;
	}minn=min(dp[n][1],dp[n][0]);
	minn==inf?printf("-1"):printf("%lld",minn);
	return 0;
}