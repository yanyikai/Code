#include<cstdio>
#include<vector>
#define N 100005
#define int long long
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
vector<int> dis[N];
signed main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;++i)
	{
		int t=read();
		dis[t].push_back(i);
	}if(dis[0].size()!=1||dis[1].size()>k)return puts("-1"),0;--k;
	for(int i=1;i<n-1;++i)
		if(dis[i+1].size()>dis[i].size()*k)return puts("-1"),0;
	printf("%lld\n",n-1);
	for(int i=1;i<N;++i)
		for(int j=0;j<dis[i].size();++j)
			printf("%lld %lld\n",dis[i-1][j%dis[i-1].size()],dis[i][j]);
}
