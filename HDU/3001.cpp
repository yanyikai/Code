#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int dp[60000][15],Pow[15]={1,3,9,27,81,243,729,2187,6561,19683,59049},s[60000][15],ways[15][15];
int n,m,i,j,k,t,u,v,c,ans;
int main()  
{
    for(i=0;i<=Pow[10];i++) for(t=i,j=0;j<10;t/=3,j++) s[i][j]=t%3;
    while(~scanf("%d%d",&n,&m))  
    {  
        memset(ways,INF,sizeof ways);
        memset(dp,INF,sizeof dp);ans=INF;
        while(m--)  
        {
            scanf("%d%d%d",&u,&v,&c);  
            ways[v-1][u-1]=ways[u-1][v-1]=min(ways[u-1][v-1],c);
        }  
        for(i=0;i<n;i++) dp[Pow[i]][i]=0;
        for(i=0;i<Pow[n];i++)  
        {  
            bool p=true;  
            for(j=0;j<n;j++)  
            {  
                if(s[i][j]==0) p=false;
                if(dp[i][j]!=INF)  
                    for(k=0;k<n;k++)  
                        if(s[i][k]!=2&&ways[j][k]!=INF)
                            dp[i+Pow[k]][k]=min(dp[i+Pow[k]][k],dp[i][j]+ways[j][k]);  
            }  
            if(p)  
                for(j=0;j<n;j++)
                    ans=min(ans,dp[i][j]);
        }
        printf("%d\n",ans>=INF?-1:ans);
    }  
    return 0;  
}  
