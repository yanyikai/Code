#include<cstdio>
#include<algorithm>
#define N 200005
#define int long long
using namespace std;
int x[N],y[N],a[N<<1],c[N<<1];
int fac[N],inv[N],p=1e9+7;
inline int Pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=x*x%p)if(y&1)res=res*x%p;
	return res;
}
inline int C(int n,int m){
	return n<m?0:fac[n]*inv[m]%p*inv[n-m]%p;
}
signed main()
{
	*fac=*inv=1;int n,k,ans=0;
	for(int i=1;i<N;++i)fac[i]=fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for(int i=N-2;i;--i)inv[i]=inv[i+1]*(i+1)%p;
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;++i)
		scanf("%lld%lld",x+i,y+i),
		a[i<<1]=x[i],a[i<<1|1]=y[i]+1;
	sort(a,a+n*2);int m=unique(a,a+n*2)-a;
	for(int i=0;i<n;++i)
		++c[lower_bound(a,a+m,x[i])-a],
		--c[lower_bound(a,a+m,y[i]+1)-a];
	for(int i=1;i<m;++i)c[i]+=c[i-1];
	for(int i=0;i+1<m;++i)
		(ans+=C(c[i],k)*(a[i+1]-a[i])%p)%=p;
	printf("%lld\n",ans);
	return 0;
}