#include<bits/stdc++.h>
#define N 100000
#define inf 0x3f3f3f3f
using namespace std;
struct Tree
{
	int num,l,r;
}tr[N+5];
bool p[N+5];
int n,i,ans;
map<int,int> m;
map<int,int>::iterator it;
void dfs(int i,int maxn,int minn)
{
	if(i==-1) return;
	if(tr[i].num>=maxn&&tr[i].num<=minn) m[tr[i].num]=0;
	dfs(tr[i].l,maxn,min(minn,tr[i].num));
	dfs(tr[i].r,max(maxn,tr[i].num),minn);
}
int main()
{
	m.clear();
	memset(p,true,sizeof(p));
	for(scanf("%d",&n),i=1;i<=n;i++)
	{
		scanf("%d%d%d",&tr[i].num,&tr[i].l,&tr[i].r);
		if(tr[i].l!=-1) p[tr[i].l]=false;
		if(tr[i].r!=-1) p[tr[i].r]=false;
		m[tr[i].num]++;
	}i=1;
	while(!p[i]) i++;
	dfs(i,-inf,inf);
	for(it=m.begin();it!=m.end();it++)
	{
		ans+=it->second;
	}
	printf("%d",ans);
	return 0;
}