#include<bits/stdc++.h>
#define N 50000
#define LL long long
using namespace std;
int n,k,dp[N+5][505],i,j,u,v;
LL ans;
vector<int>edge[N+5];  
void dfs(int u,int f)  
{
    dp[u][0]++;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(f==v) continue;dfs(v,u);
        for(int j=0;j<k;j++) ans+=(LL)dp[v][j]*dp[u][k-j-1];
        for(int j=0;j<=k;j++) dp[u][j+1]+=dp[v][j];
    }
}

int main()  
{  
    scanf("%d%d",&n,&k);
    for(i=1;i<n;i++)  
    {  
        scanf("%d%d",&u,&v);  
        edge[u].push_back(v);  
        edge[v].push_back(u);  
    }
    dfs(1,1);
    printf("%lld",ans);
    return 0;  
}