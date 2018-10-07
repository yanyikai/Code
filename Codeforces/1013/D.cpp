#include<cstdio>
#define N 200005
using namespace std;
int vis[N],bok[N],fat[N];
int Fin(int x){return fat[x]==x?x:fat[x]=Fin(fat[x]);}
int main()
{
	int n,m,q,res=0;scanf("%d%d%d",&n,&m,&q);
	if(n==1||m==1)return printf("%d\n",n*m-q),0;
	if(q<2)return printf("%d\n",n+m-1-q),0;
	for(int i=1;i<=m;++i)fat[i]=i;
	for(int i=0,x,y;i<q;++i)
	{
		scanf("%d%d",&y,&x);
		if(!vis[x])vis[x]=y;
		if(!bok[y])bok[y]=x;
		else
		{
			int a=Fin(bok[y]),b=Fin(x);
			if(a!=b)fat[b]=a;
		}
	}
	for(int i=1;i<=m;++i)if(fat[i]==i)++res;
	for(int i=1;i<=n;++i)
		if(!bok[i])++res;
	printf("%d\n",res-1);
	return 0;
}
