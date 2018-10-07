#include<bits/stdc++.h>
using namespace std;
char maps[250][250];
int n,m,T,ans,num,i,j;
int X[8]={0,1,0,-1,1,1,-1,-1};
int Y[8]={1,0,-1,0,1,-1,1,-1};
inline int check(int x,int y,int l,int r)
{
	for(int i=0;i<=(num>>2);i++)
		for(int j=l;j<=r;j++)
			if(x+X[j]*i<0||y+Y[j]*i<0||x+X[j]*i>=n||y+Y[j]*i>=m||maps[x+X[j]*i][y+Y[j]*i]!='2')
				return 0;
	return 1;
}
void dfs(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||maps[x][y]!='1') return ;
	num++;maps[x][y]='2';
	for(short i=0;i<8;i++) dfs(x+X[i],y+Y[i]);
}
int main()
{
	for(scanf("%d",&T);T--;printf("%d\n",ans))
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(getchar(),j=0;j<m;j++)
				maps[i][j]=getchar();
		ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(maps[i][j]=='1')
				{
					num=0;dfs(i,j);
					if((num&3)||num>1000) continue;
					ans+=(check(i,j,0,1)&&check(i+(num>>2),j+(num>>2),2,3))+(check(i,j,4,5)&&check(i+(num>>1),j,6,7));
				}
	}
	return 0;
}