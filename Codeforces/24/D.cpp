#include<cstdio>
#define F(i,n) for(i=1;i<=n;++i)
int n,m,x,y,i,j,k,a[1001];double dp[1001][1001],*p;
main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i=--n;i>=x;--i) F(k,39) F(j,m)
	p=&dp[i][j],*p=(*(p+1)+*p+*(p-1)+*(p+1001))/(2+(j>1)+(j<m))+1;
	printf("%lf",dp[x][y]);
}
