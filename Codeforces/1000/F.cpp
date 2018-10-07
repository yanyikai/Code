#include<cstdio>
#include<vector>
#include<algorithm>
#define lc o<<1
#define rc o<<1|1
#define ls l,mid,lc
#define rs mid+1,r,rc
#define mid ((l+r)>>1)
#define N 500005
#define inf 0x3f3f3f3f
#define P pair<int,int>
using namespace std;
int n,q,a[N],pre[N],las[N],ans[N];
P tre[2000005];vector<P>fir[N];
void PU(int o){tre[o]=min(tre[lc],tre[rc]);}
void build(int l,int r,int o)
{
	if(l==r)tre[o]=P(inf,l);else
	build(ls),build(rs),PU(o);
}
void Upd(int l,int r,int o,int p,int v)
{
	if(l==r)tre[o]=P(v,p);else
	{
		mid<p?Upd(rs,p,v):Upd(ls,p,v);
		PU(o);
	}
}
P Fin(int l,int r,int o,int L,int R)
{
	if(L<=l&&r<=R)return tre[o];
	P ans(inf,inf);
	if(L<=mid)ans=min(ans,Fin(ls,L,R));
	if(R> mid)ans=min(ans,Fin(rs,L,R));
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	{
		pre[i]=las[a[i]];
		las[a[i]]=i;
	}

	scanf("%d",&q);
	for(int i=0,l,r;i<q;++i)
	{
		scanf("%d%d",&l,&r);
		fir[r].push_back(P(l,i));
	}
	for(int i=1;i<=n;++i)sort(fir[i].begin(),fir[i].end());

	build(1,n,1);
	for(int i=1;i<=n;++i)
	{
		if(pre[i])Upd(1,n,1,pre[i],inf);
		Upd(1,n,1,i,pre[i]);
		for(P j:fir[i])
		{
			P t=Fin(1,n,1,j.first,i);
			ans[j.second]=(t.first<j.first)?a[t.second]:0;
		}
	}
	for(int i=0;i<q;++i)printf("%d\n",ans[i]);
	return 0;
}
