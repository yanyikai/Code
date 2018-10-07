#include<bits/stdc++.h>
using namespace std;
bool dp[505][505][505];
vector<int> ans;
int n,k,x,i,j,e;
int main()
{
    scanf("%d%d",&n,&k);
    dp[0][0][0]=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        for(j=0;j<=500;j++) for(e=0;e<=j&&e<=k;e++) if(dp[i-1][j][e]||j>=x&&dp[i-1][j-x][e]||e>=x&&dp[i-1][j-x][e-x]) dp[i][j][e]=1;
    }
    for(i=0;i<=k;i++) if(dp[n][k][i]) ans.push_back(i);
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    return 0;
}