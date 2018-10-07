#include<bits/stdc++.h>
using namespace std;
int n,i,place[6][1005],t[6][1005],ans,m,j,dp[1005];
bool check(int a,int b)
{
	for(int i=2;i<=m;i++) if(place[i][a]<place[i][b]) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) for(j=1;j<=n;j++) scanf("%d",&t[i][j]),place[i][t[i][j]]=j;
	for(i=1;i<=n;i++) dp[i]=1;
	for(i=2;i<=n;i++) for(j=1;j<i;j++) if(check(t[1][i],t[1][j])) dp[i]=max(dp[j]+1,dp[i]);
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}