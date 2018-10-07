#include<bits/stdc++.h>
#define MOD 1000000007
#define N 5005
#define LL long long
using namespace std;
LL dp[N][N],n,a,b,k,i,j;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	if(a<b)
	{
		for(i=1;i<b;i++) dp[i][0]=i;
		for(j=1;j<=k;j++) for(i=1;i<b;i++) dp[i][j]=(dp[b-1][j-1]-dp[i][j-1]+dp[i-1][j-1]-dp[max(2*i-b,0ll)][j-1]+dp[i-1][j]+2*MOD)%MOD;
		printf("%lld",(dp[a][k]-dp[a-1][k]+MOD)%MOD);
	}
	else
	{
		for(i=n;i>b;i--) dp[i][0]=n-i+1;
		for(j=1;j<=k;j++) for(i=n;i>b;i--) dp[i][j]=(dp[b+1][j-1]-dp[i][j-1]+dp[i+1][j-1]-dp[min(2*i-b,n+1)][j-1]+dp[i+1][j]+2*MOD)%MOD;
		printf("%lld",(dp[a][k]-dp[a+1][k]+MOD)%MOD);
	}
	return 0;
}