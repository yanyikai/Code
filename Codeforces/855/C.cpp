#include<bits/stdc++.h>
#define MOD 1000000007
#define L long long
#define M
#define N 100005
using namespace std;
L n,m,k,x,u,v;
L ans,dp[N][15][3],tmp[15][3];
vector<int> head[N];
void dfs(int fa,int now)
{
	dp[now][0][0]=k-1;
	dp[now][1][1]=1;
	dp[now][0][2]=m-k;
	for(int v=0;v<head[now].size();v++) if(head[now][v]!=fa)
	{
		dfs(now,head[now][v]);
		memset(tmp,0,sizeof tmp);
		for(int i=0;i<=x;i++)
		{
			for(int j=0;j<=i;j++)
			{
				tmp[i][0]=(tmp[i][0]+(dp[now][i-j][0]*dp[head[now][v]][j][0])%MOD)%MOD;
				tmp[i][0]=(tmp[i][0]+(dp[now][i-j][0]*dp[head[now][v]][j][1])%MOD)%MOD;
				tmp[i][0]=(tmp[i][0]+(dp[now][i-j][0]*dp[head[now][v]][j][2])%MOD)%MOD;
				tmp[i][1]=(tmp[i][1]+(dp[now][i-j][1]*dp[head[now][v]][j][0])%MOD)%MOD;
				tmp[i][2]=(tmp[i][2]+(dp[now][i-j][2]*dp[head[now][v]][j][0])%MOD)%MOD;
				tmp[i][2]=(tmp[i][2]+(dp[now][i-j][2]*dp[head[now][v]][j][2])%MOD)%MOD;
			}
		}
		for(int i=0;i<=x;i++)
		{
			dp[now][i][0]=tmp[i][0];
			dp[now][i][1]=tmp[i][1];
			dp[now][i][2]=tmp[i][2];
		}
	}
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&u,&v);
		head[u].push_back(v);
		head[v].push_back(u);
	}
	scanf("%I64d%I64d",&k,&x);
	dfs(-1,1);
	for(int i=0;i<=x;i++)
		ans=(ans+dp[1][i][0]+dp[1][i][1]+dp[1][i][2])%MOD;
	printf("%I64d",ans);
	return 0;
}
/*
0:<k;
1:=k;
2:>k;
*/
/*
dp[u][i][0]=dp[u][j][0]*dp[u][i-j][0/1/2];
dp[u][i][1]=dp[u][j][1]*dp[u][i-j][0];
dp[u][i][2]=dp[u][j][2]*dp[u][i-j][0/2];
*/ 