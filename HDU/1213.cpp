#include<cstdio>
#include<iostream>
using namespace std;
int fa[1005],n,i,m,x,y,a,b,ans,T;
int find(int i) { return fa[i]==i?i:fa[i]=find(fa[i]); }
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) fa[i]=i;
		for(i=1;i<=m;i++) scanf("%d%d",&x,&y),fa[find(x)]=find(y);
		for(i=1;i<=n;i++) if(fa[i]==i) ans++;
		printf("%d\n",ans);
	}
    return 0;
}
