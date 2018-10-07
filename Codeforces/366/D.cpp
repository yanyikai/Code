#include<bits/stdc++.h>
#define M 3005
#define N 1005
using namespace std;
int n,m,i,j,fa[N],ans;
struct Edge
{
	int u,v,l,r;
}edge[M];
bool cmp(Edge x,Edge y) { return x.r==y.r?x.l<y.l:x.r>y.r; }
int find(int i) { return fa[i]==i?i:fa[i]=find(fa[i]); }
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++) scanf("%d%d%d%d",&edge[i].u,&edge[i].v,&edge[i].l,&edge[i].r);
	sort(edge,edge+m,cmp);
	for(i=0;i<m;i++)
	{
		for(j=1;j<=n;j++) fa[j]=j;
		for(j=0;j<m;j++)
		{
			if(edge[j].l>edge[i].l) continue;
			if(edge[j].r<edge[i].l) continue;
			fa[find(edge[j].u)]=find(edge[j].v);
			if(find(1)==find(n))
			{
				ans=max(ans,edge[j].r-edge[i].l+1);
				break;
			}
		}
	}
	ans?printf("%d",ans):printf("Nice work, Dima!");
	return 0;
}