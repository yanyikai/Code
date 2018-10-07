#include<cstdio>
#define L long long
#define N 2005
L f[N][N],p=1e9+7;
L Pow(L x,L y){L res=1;for(;y;y>>=1,x=x*x%p)if(y&1)res=res*x%p;return res;}
main()
{
	int T;scanf("%d",&T);
	for(int n,m;T--;)
	{
		scanf("%d%d",&n,&m);
		f[1][1]=m;L ans=0;
		for(int i=2;i<=n;++i)
			for(int j=1;j<=i&&j<=m;++j)
				f[i][j]=(f[i-1][j]*j%p+f[i-1][j-1]*(m-j+1)%p)%p;
		for(int i=1;i<m;++i)(ans+=f[n][i]*Pow(m-i,n)%p)%=p;
		printf("%lld\n",ans);
	}
}
