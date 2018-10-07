#include<cstdio>
#include<algorithm>
#define int long long
const int N=1005,p=1e9+7;
using namespace std;
int fac[N],inv[N],x[N],f[N][N];
inline int C(int n,int m){
	return fac[n]*inv[m]%p*inv[n-m]%p;
}
signed main()
{
	*fac=*inv=1;int ans=1;
	for(int i=1;i<N;++i)fac[i]=fac[i-1]*i%p;
	inv[N-1]=353370556ll;
	for(int i=N-2;i;--i)inv[i]=inv[i+1]*(i+1)%p;
	int n;scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",x+i);
		ans=ans*inv[x[i]]%p;
		x[i]+=x[i-1];
	}
	ans=ans*fac[x[n]]%p;**f=1;
	// printf("!%lld\n",ans);
	for(int i=1,y;i<=n;++i)
	{
		scanf("%lld",&y);
		for(int j=0;j<=x[i];++j)
			for(int k=0;k<=min(y,j);++k)
				(f[i][j]+=f[i-1][j-k]*C(x[i]-j+k,k)%p)%=p;
	}printf("%lld\n",ans*f[n][x[n]]%p);
	return 0;
}