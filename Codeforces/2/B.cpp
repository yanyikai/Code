#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int ma[1005][1005][2];    
int dp[1005][1005][2];    
char ways[1005][1005][2];    
void dfs(int i,int x,int y)    
{    
    if(ways[x][y][i]==' ') return;    
    if(ways[x][y][i]=='R') dfs(i,x,y-1);    
    else dfs(i,x-1,y);    
    printf("%c",ways[x][y][i]);    
}
int main()
{
	int n,xx=-1,yy=-1,x;
    scanf("%d",&n);
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<2;k++) ma[i][j][k]=0,dp[i][j][k]=inf;   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)    
        {
            scanf("%d",&x);    
            if(!x) x=10,xx=i,yy=j;
            while(x%2==0) x/=2,ma[i][j][0]++;
            while(x%5==0) x/=5,ma[i][j][1]++;
        }
    }
    dp[0][1][1]=dp[1][0][1]=dp[1][0][0]=dp[0][1][0]=0;    
    for(int i=1;i<=n;i++)    
    {    
        for(int j=1;j<=n;j++)    
        {    
            for(int k=0;k<2;k++)    
            {    
                if(dp[i-1][j][k]+ma[i][j][k]<dp[i][j][k]) dp[i][j][k]=dp[i-1][j][k]+ma[i][j][k],ways[i][j][k]='D';
                if(dp[i][j-1][k]+ma[i][j][k]<dp[i][j][k]) dp[i][j][k]=dp[i][j-1][k]+ma[i][j][k],ways[i][j][k]='R';
            }    
        }    
    }
    ways[1][1][1]=ways[1][1][0]=' ';    
    if(xx!=-1)
    {    
        if(dp[n][n][1]==0)    
        {    
            printf("%d\n",dp[n][n][1]);    
            dfs(1,n,n);    
        }    
        else
		if(dp[n][n][0]==0)    
        {    
            printf("%d\n",dp[n][n][0]);    
            dfs(0,n,n);    
        }    
        else    
        {    
            printf("1\n");    
            for(int i=1;i<yy;i++) printf("R");    
            for(int j=1;j<n;j++) printf("D");    
            for(int i=yy;i<n;i++) printf("R");    
        }    
    }    
    else    
    {    
        if(dp[n][n][1]>dp[n][n][0])    
        {    
            printf("%d\n",dp[n][n][0]);    
            dfs(0,n,n);    
        }    
        else    
        {    
            printf("%d\n",dp[n][n][1]);    
            dfs(1,n,n);    
        }
    }
    return 0;
}
