#include<cstdio>
#include<vector>
#include<cstring>
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
vector<int>fir[105];
int nex0[105],nex1[305],vis[305];
int dfs(int u)
{
	for(vector<int>::iterator it=fir[u].begin();it!=fir[u].end();++it)
		if(!vis[*it])
		{
			int v=*it;
			vis[v]=1;
			if(nex1[v]==-1||dfs(nex1[v]))
			{
				nex0[u]=v;nex1[v]=u;
				return 1;
			}
		}
	return 0;
}
int main()
{
	for(int cas=0,T=read();cas<T;++cas)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)fir[i].clear();
		for(int i=1;i<=n;++i)
			for(int j=0,l=read();j<l;++j)
				fir[i].push_back(read());
		memset(nex0,-1,sizeof nex0);
		memset(nex1,-1,sizeof nex1);
		int res=0;
		for(int i=1;i<=n;++i)
		{
			memset(vis,0,sizeof vis);
			if(dfs(i))++res;
		}
		puts(res==n?"YES":"NO");
	}
	return 0;
}

