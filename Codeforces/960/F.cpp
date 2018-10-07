#include<cstdio>
#include<algorithm>
#define N 100005
#define mid ((l+r)>>1)
using namespace std;
int T[N],lc[N*20],rc[N*20],mxn[N*20],tot;
void Ins(int l,int r,int&o,int p,int v)
{
	if(!o)o=++tot;
	mxn[o]=max(mxn[o],v);
	if(l==r)return ;
	p>mid?Ins(mid+1,r,rc[o],p,v):Ins(l,mid,lc[o],p,v);
}
int Que(int l,int r,int o,int p)
{
	if(l==r)return mxn[o];
	return p>mid?max(mxn[lc[o]],Que(mid+1,r,rc[o],p)):Que(l,mid,lc[o],p);
}
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0,u,v,w,t;i<m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		t=Que(1,N-5,T[u],w-1)+1;
		Ins(1,N-5,T[v],w,t);
		ans=max(ans,t);
	}
	printf("%d\n",ans);
	return 0;
}
