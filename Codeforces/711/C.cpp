#include<bits/stdc++.h>
#define inf 1e15
#define LL long long
#define F(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int tree[105],n,m,k,c;
LL cost[105][105],dp[105][105][105],ans=inf;
int main()  
{
    scanf("%d%d%d",&n,&m,&k);
    F(i,1,n) scanf("%d",&tree[i]);
    F(i,1,n) F(j,1,m) scanf("%lld",&cost[i][j]);
    F(i,0,n) F(j,0,m) F(v,0,k) dp[i][j][v]=inf;
    if(tree[1]) dp[1][tree[1]][1]=0;
    else F(i,1,m) dp[1][i][1]=cost[1][i];
    F(i,2,n)
	{  
        if(tree[i]!=0) F(j,1,m) F(v,1,min(k,i)) dp[i][tree[i]][v]=(j==tree[i]?min(dp[i-1][tree[i]][v],dp[i][tree[i]][v]):min(dp[i][tree[i]][v],dp[i-1][j][v-1]));
        else F(j,1,m) F(v,1,m) F(z,1,min(k,i)) dp[i][j][z]=(j==v?min(dp[i-1][j][z]+cost[i][j],dp[i][j][z]):min(dp[i-1][v][z-1]+cost[i][j],dp[i][j][z]));
    }  
    F(i,1,m) ans=min(ans,dp[n][i][k]);  
    if(ans>=inf) printf("-1\n");  
    else printf("%lld\n",ans);  
    return 0;  
}