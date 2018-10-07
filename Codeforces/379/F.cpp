#include<cstdio>
#define N 1000100
int dep[N],n=4,fat[N][20],q,p,i,a=2,b=3,d=2;
using namespace std;
int lca(int x,int y)
{
	if(dep[x]<dep[y])x^=y^=x^=y;
	int del=dep[x]-dep[y];
	for(i=0;1<<i<=del;++i)
		if(del&(1<<i))
			x=fat[x][i];
	for(i=19;~i;--i)
		if(fat[x][i]!=fat[y][i])
			x=fat[x][i],
			y=fat[y][i];
	return *fat[x];
}
int main()
{
	dep[2]=dep[3]=dep[4]=1;
	*fat[2]=*fat[3]=*fat[4]=1;
	scanf("%d",&q);
	for(int e=0;e<q;++e)
	{
		scanf("%d",&p);
		dep[n+1]=dep[n+2]=dep[p]+1;
		*fat[n+1]=*fat[n+2]=p,n+=2;
		for(i=1;i<20;++i)
			fat[n][i]=fat[fat[n][i-1]][i-1],
			fat[n-1][i]=fat[fat[n-1][i-1]][i-1];
		if(dep[n]+dep[a]-2*dep[lca(n,a)]>d)b=n,++d;
		if(dep[n]+dep[b]-2*dep[lca(n,b)]>d)a=n,++d;
		printf("%d\n",d);
	}
}
