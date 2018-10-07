#include<cstdio>
#define N 45
using namespace std;
int a[N][N],s[N][N],cnt[N][N][N][N],ans[N][N][N][N];
int main()
{
	int n,m,q;scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%1d",a[i]+j),
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	for(int i=n;i;--i)for(int j=m;j;--j)
	for(int k=i;k<=n;++k)for(int e=j;e<=m;++e)
	{
		int del=s[k][e]-s[k][j-1]-s[i-1][e]+s[i-1][j-1];
		cnt[i][j][k][e]=cnt[i][j][k-1][e]+cnt[i][j][k][e-1]-cnt[i][j][k-1][e-1]+!del;
	}
	for(int i=n;i;--i)for(int j=m;j;--j)
	for(int k=i;k<=n;++k)for(int e=j;e<=m;++e)
		ans[i][j][k][e]=ans[i+1][j][k][e]+ans[i][j+1][k][e]-ans[i+1][j+1][k][e]+cnt[i][j][k][e];
	for(int i=0,a,b,c,d;i<q;++i)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",ans[a][b][c][d]);
	}
	return 0;
}