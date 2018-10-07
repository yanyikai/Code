#include<bits/stdc++.h>
using namespace std;
int n,m,tim,maps[50][50],sx,sy,tx,ty,vis[50][50];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
char s[50];
bool dfs(int x,int y,int t)
{
	if(x==tx&&y==ty) return !t;
	if(vis[x][y]||maps[x][y]||abs(x-tx)+abs(y-ty)>t||(abs(x-tx)+abs(y-ty)-t)&1) return 0;
	vis[x][y]=1;
	for(int i=0;i<4;i++) if(dfs(x+dx[i],y+dy[i],t-1)) return 1;
	return vis[x][y]=0;
}
int main()
{
	for(;~scanf("%d%d%d",&n,&m,&tim)&&n&&m&&tim;)
	{
		memset(maps,1,sizeof maps);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				maps[i][j]=s[j]=='X';
				if(s[j]=='S') sx=i,sy=j;
				if(s[j]=='D') tx=i,ty=j;
			}
		}
		puts(dfs(sx,sy,tim)?"YES":"NO");
	}
	return 0;
}
