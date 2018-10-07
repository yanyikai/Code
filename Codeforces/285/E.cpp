#include<cstdio>
#define N 1005
#define int long long
using namespace std;
int c[N][N],p=1e9+7,f[N][N][2][2],ans[N];
main()
{
	int n,k;**c=1;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
			c[i][j]=j?(c[i-1][j]+c[i-1][j-1])%p:1;
	f[0][0][1][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j)
		{
			(f[i][j+1][0][0]+=f[i-1][j][0][0])%=p;
			(f[i][j+1][1][0]+=f[i-1][j][0][1])%=p;
			if(i<n)
			{
				(f[i][j+1][0][1]+=f[i-1][j][0][0])%=p;
				(f[i][j+1][0][1]+=f[i-1][j][1][0])%=p;
				(f[i][j+1][1][1]+=f[i-1][j][0][1])%=p;
				(f[i][j+1][1][1]+=f[i-1][j][1][1])%=p;
			}
			(f[i][j][0][0]+=f[i-1][j][0][0])%=p;
			(f[i][j][0][0]+=f[i-1][j][1][0])%=p;
			(f[i][j][1][0]+=f[i-1][j][0][1])%=p;
			(f[i][j][1][0]+=f[i-1][j][1][1])%=p;
		}
	for(int i=0;i<=n;++i)
	{
		(ans[i]+=f[n][i][0][0]+f[n][i][0][1]+f[n][i][1][0]+f[n][i][1][1])%=p;
		for(int j=2;j<=n-i;++j)ans[i]=ans[i]*j%p;
	}
	for(int i=k+1;i<=n;++i)
		(ans[k]+=((k+i)&1?-1:+1)*c[i][k]*ans[i]%p+p)%=p;
	printf("%lld\n",ans[k]);
	return 0;
}