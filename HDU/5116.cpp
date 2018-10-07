#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 205][205
#define int long long
#define M(a) memset(a,0,sizeof a)
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int vis[N],r[N],u[N],num[N],c[N],tmp[205],cnt[N];
main()
{
	for(int i=1;i<205;++i)
		for(int j=1;j<205;++j)
		{
			int t=0;
			for(int k=1;k<=j;++k)
				t+=(__gcd(i,k)==1);
			num[i][j]=num[i-1][j]+(c[i][j]=t);
		}
	for(int cas=1,T=read();cas<=T;++cas)
	{
		M(vis);M(r);M(u);M(cnt);
		int n=read(),ans=0,del=0;
		for(int i=1;i<=n;++i)
			vis[read()][read()]=1;
		for(int i=202;i;--i)
			for(int j=202;j;--j)
				if(vis[i][j])
				{
					r[i][j]=r[i][j+1]+vis[i][j+1],
					u[i][j]=u[i+1][j]+vis[i+1][j];
					ans+=num[u[i][j]][r[i][j]];M(tmp);
					for(int k=u[i][j];k;--k)
						tmp[k-1]+=(tmp[k]+=c[k][r[i][j]]);
					for(int k=0;k<=u[i][j];++k)
						cnt[i+k][j]+=tmp[k];
				}
		for(int i=202;i;--i)
			for(int j=202;j;--j)
				if(vis[i][j])
				{
					int t=num[u[i][j]][r[i][j]],s=0;
					for(int k=1;k<=r[i][j];++k)
						s+=cnt[i][j+k],
						del+=s*c[k][u[i][j]]*2;
					del+=t*t+(cnt[i][j]-t)*t*2;
				}
		printf("Case #%lld: %lld\n",cas,ans*ans-del);
	}
	return 0;
}
