#include<cstdio>
#define N 35005
using namespace std;
int vis[N],p[N],tot,fac[355],n,cnt;
long long get(long long x)
{
	long long res=0;
	for(int i=1;i<1ll<<cnt;++i)
	{
		int sum=1;
		for(int j=0;j<cnt;++j)
			if(i&(1ll<<j))sum*=fac[j];
		__builtin_popcount(i)&1?res+=x/sum:res-=x/sum;
	}
	return res;
}
int main()
{
	for(int i=2;i<N;++i)
		if(!vis[i])
		{
			p[++tot]=i;
			for(int j=i+i;j<N;j+=i)
				vis[j]=1;
		}
	int T;scanf("%d",&T);
	for(int cas=1;cas<=T;++cas)
	{
		long long A,B;cnt=0;
		scanf("%lld%lld%d",&A,&B,&n);
		for(int i=1;i<=tot&&p[i]*p[i]<=n;++i)
			if(n%p[i]==0)
				for(fac[cnt++]=p[i];n%p[i]==0;n/=p[i]);
		if(n!=1)fac[cnt++]=n;
		printf("Case #%d: %lld\n",cas,B-get(B)-A+1+get(A-1));
	}
	return 0;
}
