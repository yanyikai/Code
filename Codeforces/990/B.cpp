#include<cstdio>
#define N 200005
//#include<vector>
//#include<cstring>
#include<algorithm>
//#define int long long
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int a[N],vis[N],sum;
signed main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read(),vis[i]=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		int t=i;if(a[i]==a[i-1])continue;
		for(;vis[t-1]&&t>1&&a[i]-a[t-1]<=k;--t)vis[t-1]=0;
	}
	for(int i=1;i<=n;++i)sum+=vis[i];
	printf("%d\n",sum);
	return 0;
}
