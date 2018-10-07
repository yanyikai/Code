#include<cstdio>
#define N 25
#define int long long
using namespace std;
int C[N][N],f[N];
main()
{
	**C=1;f[1]=0;f[0]=1;
	for(int i=1;i<N;++i)
	{
		for(int j=0;j<=i;++j)
			C[i][j]=j?C[i-1][j-1]+C[i-1][j]:1;
		if(i>1)f[i]=(i-1)*(f[i-1]+f[i-2]);
	}
	int T;scanf("%lld",&T);
	for(int cas=0;cas<T;++cas)
	{
		int m,n;scanf("%lld%lld",&n,&m);
		printf("%lld\n",C[n][m]*f[m]);
	}
	return 0;
}
