#include<cstdio>
#define N 1000001
using namespace std;
int num[N];
long long sum[N],ans,p=1e9+7;
long long Pow(long long x,long long y)
{
	long long res=1;
	for(;y;y/=2,x=x*x%p)if(y&1)res=res*x%p;
	return res;
}
int main()
{
	int n;scanf("%d\n",&n);
	for(int i=0,x;i<n;++i)
		scanf("%d",&x),++num[x];
	for(int i=N-1;i>1;--i)
	{
		long long cnt=0;
		for(int j=i;j<N;j+=i)
		{
			sum[i]-=sum[j];
			cnt+=num[j];
		}
		sum[i]+=cnt*Pow(2,cnt-1)%p;
		ans=(ans+sum[i]*i%p+p)%p;
	}
	printf("%lld\n",ans);
	return 0;
}