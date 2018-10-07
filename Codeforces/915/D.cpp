#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int rd[505],cnt,n,m;
vector<int> fir[505];
int dfs(int x)
{
	rd[x]=2;
	for(int i:fir[x]) rd[i]==2?++cnt:!rd[i]?dfs(i):0;
	rd[x]=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		fir[u].push_back(v);
	}
	for(int i=1;i<=n;++i)
	{
		memset(rd,0,sizeof rd);cnt=0;dfs(i);
		for(int j=1;j<=n;++j)if(!rd[j])dfs(j);
		if(cnt<2)return puts("YES"),0;
	}
	return puts("NO");
}
