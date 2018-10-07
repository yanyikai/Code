#include<cstdio>
#include<vector>
#define N 300005
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
vector<int>fir[N];
int fat[N],siz[N],ans[N];
void dfs(int x)
{
	siz[x]=1;for(int i:fir[x])
	dfs(i),siz[x]+=siz[i];
}
void DFS(int x)
{
	int pos=0;
	ans[x]=x;
	for(int i=0;i<(int)fir[x].size();++i)
	{
        int v=fir[x][i];
        DFS(v);
        if(siz[v]>=siz[fir[x][pos]]) pos=i;
    }
	if(fir[x].size())
	for(ans[x]=ans[fir[x][pos]];ans[x]!=x&&siz[ans[x]]<<1<siz[x];)
		ans[x]=fat[ans[x]];
}
int main()
{
	int n=read(),q=read();
	for(int i=2;i<=n;++i)
		fir[fat[i]=read()].emplace_back(i);
	dfs(1);DFS(1);
	for(int i=0;i<q;++i)
		printf("%d\n",ans[read()]);
	return 0;
}