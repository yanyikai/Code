#include<cstdio>
#define N 100005
using namespace std;
int pow[N];long long f[N],p=1e9+7;
int main()
{
	for(int i=1,x;;++i)
	{
		x=i&1?i/2+1:-i/2;
		if((pow[i]=x*(x*3-1)/2)>N)
			break;
	}*f=1;
	for(int i=1;i<N;++i)
	{
		for(int j=1;pow[j]<=i;++j)
			f[i]+=(!(j&1)^!(j&2)?1:-1)*f[i-pow[j]];
		f[i]=(f[i]%p+p)%p;
	}int T;scanf("%d",&T);
	for(int cas=0,n,m;cas<T;++cas)
	{
		scanf("%d%d",&n,&m);
		long long ans=f[n];
		for(int j=1;pow[j]*m<=n;++j)
			ans+=(!(j&1)^!(j&2)?-1:1)*f[n-pow[j]*m];
		printf("%lld\n",(ans%p+p)%p);
	}
	return 0;
}
