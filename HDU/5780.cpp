#include<cstdio>
#define N 1000005
#define int long long
using namespace std;
int sum[N],p=1e9+7,phi[N],pri[N],tot;
bool vis[N];
int Pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=x*x%p)if(y&1)res=res*x%p;
	return res;
}
main()
{
	sum[1]=phi[1]=1;
	for(int i=2;i<N;++i)
	{
		if(!vis[i])pri[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*pri[j]<N;++j)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j])phi[i*pri[j]]=phi[i]*phi[pri[j]]%p;
			else{
				phi[i*pri[j]]=phi[i]*pri[j]%p;
				break;
			}
		}
	}
	for(int i=2;i<N;++i)
		(phi[i]+=phi[i-1])%=p,sum[i]=(2*phi[i]%p-1+p)%p;
	int T;scanf("%lld",&T);
	for(int cas=0;cas<T;++cas)
	{
		int x,n,ans=0;
		scanf("%lld%lld",&x,&n);
		if(x==1){puts("0");continue;}
		for(int l=1,r;l<=n;l=r+1)
		{
			r=n/(n/l);
			(ans+=sum[n/l]*((Pow(x,r+1)-Pow(x,l)+p)*Pow(x-1,p-2)%p-r+l-1+p))%=p;
		}
		printf("%lld\n",(ans%p+p)%p);
	}
	return 0;
}
