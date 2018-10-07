#include<cstdio>
#define N 105
#define int long long
using namespace std;
int f[N][N],fac[N],p=20090126;
main()
{
	**f=*fac=1;
	for(int i=1;i<N;++i)
	{
		fac[i]=i*fac[i-1]%p;
		for(int j=1;j<=i;++j)
			f[i][j]=(j*f[i-1][j]%p+f[i-1][j-1]%p)%p;
	}
	int T;scanf("%lld",&T);
	for(int cas=0;cas<T;++cas)
	{
		int n,ans=0;scanf("%lld",&n);
		for(int i=1;i<=n;++i)
			ans=(ans+f[n][i]*fac[i])%p;
		printf("%lld\n",ans);
	}
	return 0;
}
