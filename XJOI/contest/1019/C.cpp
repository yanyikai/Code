#pragma GCC optimize(3,"inline,Ofast")
#include<set>
#include<cstdio>
#include<vector>
#include<cstring>
#define N 200005
inline int read(){
	int x=0;char ch=getchar();
	for(;ch<48||ch>57;ch=getchar());
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int n=read(),m=read(),q=read(),tim,s,tot=n;
int val[N],dfn[N],low[N],fat[N],dep[N],siz[N],top[N],son[N],pos[N],S[N];
vector<int>fir[N],hea[N];multiset<int>chd[N];

void mxn(int&a,int b){a>b?a=b:0;}
void tarjan(int u){
	dfn[u]=low[u]=++tim;S[++s]=u;
	for(int v:fir[u])if(dfn[v])
		mxn(low[u],dfn[v]);else
		{
			tarjan(v);mxn(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++tot;int x=0;
				hea[tot].push_back(u);
				hea[u].push_back(tot);
				do x=S[s--],
				hea[x].push_back(tot),
				hea[tot].push_back(x);
				while(x^v);
			}
		}
}

void dfs(int u){
	if(u<=n&&fat[u])chd[fat[u]].insert(val[u]);
	dep[u]=dep[fat[u]]+(siz[u]=1);
	for(int v:hea[u])if(v!=fat[u])
	{
		fat[v]=u;dfs(v);siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void DFS(int u){
	pos[dfn[u]=++tim]=u;
	if(son[u])top[son[u]]=top[u],DFS(son[u]);
	for(int v:hea[u])if(v!=fat[u]&&v!=son[u])
	DFS(top[v]=v);
}

#define lc o<<1
#define rc o<<1|1
#define ls l,mid,lc
#define rs mid+1,r,rc
#define mid ((l+r)>>1)
int mnn[N<<2];
void PU(int o){mnn[o]=min(mnn[lc],mnn[rc]);}
void build(int l,int r,int o){
	if(l==r)mnn[o]=val[pos[l]];else
	build(ls),build(rs),PU(o);
}
void Upd(int l,int r,int o,int p,int v){
	if(l==r)return void(mnn[o]=v);
	p>mid?Upd(rs,p,v):Upd(ls,p,v);PU(o);
}
int Que(int l,int r,int o,int L,int R){
	if(L<=l&&r<=R)return mnn[o];
	int res=2e9;
	if(L<=mid)mxn(res,Que(ls,L,R));
	if(R> mid)mxn(res,Que(rs,L,R));
	return res;
}
#undef lc
#undef rc
#undef ls
#undef rs

signed main()
{
	memset(mnn,63,sizeof mnn);
	for(int i=1;i<=n;++i)val[i]=read();
	for(int i=0,u,v;i<m;++i)
		u=read(),v=read(),
		fir[u].push_back(v),
		fir[v].push_back(u);
	for(int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i);
	tim=0;dfs(1);DFS(top[1]=1);
	for(int i=n+1;i<=tot;++i)
		val[i]=*chd[i].begin();
	build(1,tot,1);
	for(int cas=0;cas<q;++cas)
	{
		char s[3];scanf("%s",s);
		if(*s=='C')
		{
			int a=read(),w=read();
			if(fat[a])chd[fat[a]].erase(chd[fat[a]].find(val[a]));
			Upd(1,tot,1,dfn[a],val[a]=w);
			if(fat[a])
				chd[fat[a]].insert(w),
				Upd(1,tot,1,dfn[fat[a]],*chd[fat[a]].begin());
		}else{
			int u=read(),v=read(),ans=2e9;
			for(;top[u]^top[v];u=fat[top[u]]){
				if(dep[top[u]]<dep[top[v]])u^=v^=u^=v;
				mxn(ans,Que(1,tot,1,dfn[top[u]],dfn[u]));
			}
			if(dep[u]>dep[v])u^=v^=u^=v;
			mxn(ans,Que(1,tot,1,dfn[u],dfn[v]));
			if(u>n)mxn(ans,val[fat[u]]);
			printf("%d\n",ans);
		}
	}
	return 0;
}