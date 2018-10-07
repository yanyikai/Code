#include<cstdio>
#include<cmath>
#include<map>
#define int long long
#define N 40005
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
map<int,int>m;
long long fac[N],inv[N],p=1e9+7;
long long Pow(long long x,int y){
	long long res=1;
	for(;y;y>>=1,x=x*x%p)if(y&1)res=res*x%p;
	return res;
}
main()
{
	fac[0]=inv[0]=1;m.clear();
	for(int i=1;i<N;++i)fac[i]=fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for(int i=N-2;i;--i)inv[i]=inv[i+1]*(i+1)%p;
	// printf("%d\n",inv[1]);
	int n=read();long long ans=1;
	for(int i=0;i<n;++i)
	{
		int a=read(),k=sqrt(a);
		for(int j=2;j<=k;++j)
			if(a%j==0)
				for(;a%j==0;a/=j)++m[j];
		if(a!=1)++m[a];
	}
	for(auto v:m)
		// printf("%d %d\n",v.first,v.second),
		ans=ans*fac[n+v.second-1]%p*inv[n-1]%p*inv[v.second]%p;
	printf("%lld\n",ans);
	return 0;
}
